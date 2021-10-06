//Manit Gandhi
//6280004

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float convert(float temp){
    return (temp * 9/5)+32;
}

int main()
{
    int lb;
    int ub;
    printf("Enter lower limit: ");
    scanf("%d", &lb);
    printf("Enter upper limit: ");
    scanf("%d", &ub);
    printf("%-15s %s\n", "Celcius","Farenheit");
    printf("=========================\n");
    for(float i=lb;i<=ub;i=i+5){
        printf("%-15 0.0f %0.1f\n",i, convert(i));
    }
    printf("-------------------------");
}