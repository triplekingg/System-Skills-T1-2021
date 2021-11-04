#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decimalToBinary(int decimalnum) {
    int binarynum = 0;
    int rem, temp = 1;

    while (decimalnum != 0) {
        rem = decimalnum % 2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem * temp;
        temp = temp * 10;
    }
    return binarynum;
}

int parity_check(int x) {
    long bin = decimalToBinary(x);
    int ones = 0;
    int zeroes = 0;
    for (int i = 0; i < 4; i++) {
        /* If LSB is set then increment ones otherwise zeros */
        if (x & 1)
            ones++;
        else
            zeroes++;

        /* Right shift bits of num to one position */
        x >>= 1;
    }
    if (ones % 2 != 0) {
        return 1;
    }
    return 0;
}

int main() {
    printf("%d\n", parity_check(10));
    printf("%d\n", parity_check(14));
    return 0;
}
