//Manit Gandhi
//6280004
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sum=0;
    for(int i=0;i<argc;i++)
    {
        sum=sum+atoi(argv[i]);
    }
    printf("%d\n", sum);
}