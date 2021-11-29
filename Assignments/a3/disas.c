#include <stdio.h>
#include <stdint.h>

void print_hex_bytes(int len, const unsigned char *data) {

    int i =0;
    while(i<len){
        printf("%02x ", data[i]);
        i++;
    }
    printf("   ");

}

void disassemble(const unsigned char *raw_instr) {

    const char registers[8][5] = {"%rax", "%rcx", "%rdx", "%rbx", "%rsp", "%rbp", "%rsi", "%rdi"};
    unsigned char op = raw_instr[0];

    //The below variables are to be used in the switch statements
    int s;
    unsigned int and = (op & 0x78) == 0x50;
    unsigned char regist = raw_instr[1];
    int index;
    int index1;
    int index2;

    if (and) {
        print_hex_bytes(1, raw_instr);
        char* reg = registers[op & 0x7];
        printf("pushq %s", reg);
        printf("\n");
    }

    switch (op) {
        case 0x68:
            print_hex_bytes(5, raw_instr);
            uint32_t *value = (uint32_t *)(raw_instr + 1);
            printf("pushq $%#x",  *value);
            printf("\n");
            break;

        case 0xff:
            regist = raw_instr[1];
            switch (regist) {
                case 0x32:
                    print_hex_bytes(2, raw_instr);
                    index = regist & 0x7;
                    printf("pushq (%s)", registers[index]);
                    printf("\n");
                    break;

                case 0x70:
                    print_hex_bytes(3, raw_instr);
                    index = regist & 0x7;
                    printf("pushq %#x(%s)", raw_instr[2], registers[index]);
                    printf("\n");
                    break;

                case 0x74:
                    s = 1 << (raw_instr[2] >> 6);
                    print_hex_bytes(4, raw_instr);
                    index1 = regist & 0x7;
                    index2 = (raw_instr[2] >> 3) & 0x7;
                    printf("pushq %#x(%s,%s,%d)", raw_instr[3], registers[index1], registers[index2], s);
                    printf("\n");
                    break;
                default:
                    break;
            }

    }
}

