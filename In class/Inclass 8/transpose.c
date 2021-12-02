#include<stdio.h>
#include<stdlib.h>

#define DEBUG 0


void printMatrix(int **a, int sizex, int sizey) {
    /*TODO*/
    int i, j;
    if (DEBUG)
        printf("In printMatrix\nmatrix address = (%x),addr of a[0]: %x | val of a[0] = %x| addr of a[0][0] = %x \n", a,
               &a[0], a[0], &a[0][0]);
    for (i = 0; i < sizex; i++) {
        printf("[");
        for (j = 0; j < sizey; j++) {
            printf("%3d, ", *(*(a + i) + j));
        }
        printf("]\n");
    }
}

void transpose(int **a, int **b, int sizex, int sizey) {
    int i, j;
    int row = sizey;//row for transposed matrix
    int col = sizex;//column for transposed matrix
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            b[i][j] = a[j][i];
        }
    }


}


int main() {
    int **a;
    int **b;
    int i;
    a = malloc(sizeof(int *) * 3);
    b = malloc(sizeof(int *) * 2);
    for (i = 0; i < 3; i++) {
        *(a + i) = malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < 2; i++) {
        *(b + i) = malloc(sizeof(int) * 3);
    }
    if (DEBUG)
        printf("Outside of my function call: A (%x), addr of a[0] = %x, val of a[0] = %x, addr of a[0][0] %x, %d: ", a,
               &a[0], a[0], &a[0][0], a[0][0]);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    a[2][0] = 5;
    a[2][1] = 6;
    //Before Transpose
    printf("A:\n");
    printMatrix(a, 3, 2);

    //Transpose
    transpose(a, b, 3, 2);

    //After transpose
    printf("B:\n");
    printMatrix(b, 2, 3);

    for (i = 0; i < 3; i++) {
        free(*(a + i));
    }
    for (i = 0; i < 2; i++) {
        free(*(b + i));
    }
    free(a);
    free(b);
}

