//Manit Gandhi
//6280004

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    //assuming the input file name is 'input .txt', here is the path for the input file
    FILE *fp=fopen("/Users/manitgandhi/CLionProjects/untitled/input .txt","r");
    int num;
    printf("================================\n");
    char c[10];
    while((fscanf(fp, "%s\t %d", c, &num))!=EOF)
    {
        if(num>=10 && num<100)
        {
            printf("%-15s %d%d\n", c, 0, num);
        }
        else
        {
            printf("%-15s %d\n", c, num);
        }


    }
    printf("================================\n");

}