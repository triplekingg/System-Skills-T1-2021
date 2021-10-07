//Manit Gandhi
//6280004


#include <stdio.h>


void prefix_sum(int *a, int *b, int *c) {

    int tempb = *b;
    *b = *a + tempb;
    int tempc = *c;
    *c = *b + tempc;
}


void main() {
    void (*func_ptr)(int *, int *, int *) = &prefix_sum;
    int a = 3;
    int b = 4;
    int c = 5;
    int *ptr_a = &a;
    int *ptr_b = &b;
    int *ptr_c = &c;

    printf("Before calling the function: a=%d, b=%d, c=%d\n", a, b, c);
    (*func_ptr)(ptr_a, ptr_b, ptr_c);
    printf("After calling the function: a=%d, b=%d, c=%d\n", a, b, c);
}
