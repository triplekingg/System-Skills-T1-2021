#include <stdio.h>
#include <stdlib.h>

void dotProduct(int *a, int *b, int *result, int size) {
    int *products = malloc(sizeof(int) * size);
    int i;
    int sum = 0;
    for (i = 0; i < size; i++) {
        products[i] = a[i] * b[i];
    }
    for (int i = 0; i < size; i++) {
        sum += products[i];
    }
    *result = sum;
    free(products);
}

void printVector(int vect[], int size) {
    printf("vect = {");
    for (int i = 0; i < size; i++) {
        printf(" %d ", vect[i]);
    }
    printf("}\n");
}

int main() {

    //Creating a function pointer for dotProduct
    void (*func_ptr)(int *, int *, int *, int) = &dotProduct;


    //Test case 1
    int a[3] = {1, 3, -5};
    int b[3] = {4, -2, -1};
    int c;
    int *ptr_a = &a;
    int *ptr_b = &b;
    int *ptr_c = &c;
    (*func_ptr)(ptr_a, ptr_b, ptr_c, 3);
    printVector(a, 3);
    printVector(b, 3);
    printf("Vector sum: %d \n", c);

    //Test case 2
    int x[5] = {1, 3, -5, 0, 1};
    int y[5] = {4, 2, 3 - 2, -1};
    int z;
    int *ptr_x = &x;
    int *ptr_y = &y;
    int *ptr_z = &z;
    (*func_ptr)(ptr_x, ptr_y, ptr_z, 5);
    printVector(x, 5);
    printVector(y, 5);
    printf("Vector sum: %d \n", z);

}
