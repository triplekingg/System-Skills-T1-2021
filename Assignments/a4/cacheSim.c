#include "cacheSim.h"
#include "string.h"

/// I attempted Part 1: Getting Tags, SetID and Performing a Cache Lookup (20 points) and it works
/// However I ran into some problems while doing the second part, the function read_fifo().
/// Please grade leniently krub thankyou :'(


// In this question, we will assume DRAM will take a 4-byte values starting from 0 to
void init_DRAM()
{
    unsigned int i=0;
    DRAM = malloc(sizeof(char) * DRAM_SIZE);
    for(i=0;i<DRAM_SIZE/4;i++)
    {
        *((unsigned int*)DRAM+i) = i;
    }
}

void printCache()
{
    int i,j,k;
    printf("===== L1 Cache Content =====\n");
    for(i=0;i<2;i++)
    {
        printf("Set %d :", i);
        for(j=0;j<2;j++)
        {
            printf(" {(TAG: 0x%x)", (unsigned int)(L1_cache[i][j].tag));
            for(k=0;k<16;k++)
                printf(" 0x%x,", (unsigned int)(L1_cache[i][j].data[k]));
            printf(" |");
        }
        printf("\n");
    }
    printf("===== L2 Cache Content =====\n");
    for(i=0;i<4;i++)
    {
        printf("Set %d :", i);
        for(j=0;j<4;j++)
        {
            printf(" {(TAG: 0x%x)", (unsigned int)(L2_cache[i][j].tag));
            for(k=0;k<16;k++)
                printf(" 0x%x,", (unsigned int)(L2_cache[i][j].data[k]));
            printf(" |");
        }
        printf("\n");
    }
}

u_int32_t read_fifo(u_int32_t address)
{
///// IMPLEMENT THIS /////
    // Could do for L1 but

    //Getting set and tag for L1
    unsigned int setL1 = getL1SetID(address);
    unsigned int tagL1 = getL1Tag(address);
    //Getting set and tag for L2
    unsigned int setL2 = getL2SetID(address);
    unsigned int tagL2 = getL2Tag(address);
    int fifo_for_l1 = 0;
    int i=0;

    //Evaluate fifo for l1 below
    while(i<2){
        if (((tagL1 ^ L1_cache[setL1][i].tag)) == 0) {
            u_int32_t result = (u_int32_t)L1_cache[setL1][i].data[address & 15];
            return result;
        }

        if (L1_cache[setL1][fifo_for_l1].timeStamp > L1_cache[setL1][i].timeStamp) {
            fifo_for_l1 = i;
        }
        i++;
    }

}

int L1lookup(u_int32_t address)
{
///// IMPLEMENT THIS /////
    int i = 0;
    while(i<2){
        if ( (!(getL1Tag(address) ^ L1_cache[getL1SetID(address)][i].tag)) != 0 ) {
            return 1;
        }
        i+=1;
    }
    return 0;
}

int L2lookup(u_int32_t address)
{
///// IMPLEMENT THIS /////
    int i=0;
    while(i<4){
        if ( ((getL2Tag(address) ^ L1_cache[getL2SetID(address)][i].tag)) != 0 ) {
            return 1;
        }
        i+=1;
    }
    return 0;
}

unsigned int getL1SetID(u_int32_t address)
{
///// IMPLEMENT THIS /////
    return ((address >> 4) & 1);
}

unsigned int getL2SetID(u_int32_t address)
{
///// IMPLEMENT THIS /////
    return ((address >> 4) & 3);
}

unsigned int getL1Tag(u_int32_t address)
{
///// IMPLEMENT THIS /////
    return address >> 5;
}

unsigned int getL2Tag(u_int32_t address)
{
///// IMPLEMENT THIS /////
    return address >> 6;
}


void write(u_int32_t address, u_int32_t data)
{
///// REPLACE THIS /////
    read_fifo(address);
    return;
}


int main()
{
    init_DRAM();
    cacheAccess buffer;
    int timeTaken=0;
    FILE *trace = fopen("/Users/manitgandhi/CLionProjects/untitled9/input.trace","r");
    int L1hit = 0;
    int L2hit = 0;
    cycles = 0;
    while(!feof(trace))
    {
        fscanf(trace,"%d %x %x", &buffer.readWrite, &buffer.address, &buffer.data);
        printf("Processing the request for [R/W] = %d, Address = %x, data = %x\n", buffer.readWrite, buffer.address, buffer.data);

        // Checking whether the current access is a hit or miss so that we can advance time correctly
        if(L1lookup(buffer.address))// Cache hit
        {
            timeTaken = 1;
            L1hit++;
        }
        else if(L2lookup(buffer.address))// L2 Cache Hit
        {
            L2hit++;
            timeTaken = 5;
        }
        else timeTaken = 50;
        if (buffer.readWrite) write(buffer.address, buffer.data);
        else read_fifo(buffer.address);
        cycles+=timeTaken;
    }
    printCache();
    printf("Total cycles used = %ld\nL1 hits = %d, L2 hits = %d", cycles, L1hit, L2hit);
    fclose(trace);
    free(DRAM);
    return 0;
}




