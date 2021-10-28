/* Name: Manit Gandhi
 * ID: 6280004
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (k < (nL + nR)){
        if ((i < nL && L[i].data < R[j].data) || j >= nR ){
            output[k] = L[i];
            i++;
        } else{
            output[k] = R[j];
            j++;
        }
        k++;
    }
}

void merge_sort(Entry *entries, int n) {
    if (n > 1){
        int mid = n / 2;
        int cR = 0;
        int cL = 0;
        Entry * L = malloc(n*sizeof(Entry));
        Entry * R = malloc(n*sizeof(Entry));
        int i;
        for(i = 0; i < mid; i++){
            L[i] = entries[i];
            cL++;
        }
        for(int i = mid; i < n; i++){
            R[cR] = entries[i];
            cR++;
        }
        merge_sort(L, cL);
        merge_sort(R, cR);

        Entry * temp = malloc(n*sizeof(Entry));
        merge(temp, L, cL, R, cR);
        int j  =0;
        while(j<n){
            entries[j] = temp[j];
            j++;
        }
        free(temp);
        free(L);
        free(R);
    }
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    //Reading the first line that contains the size of the array
    int size;
    scanf("%d", &size);

    //Allocating memory of the given size
    Entry* in = malloc(size * sizeof(Entry));

    int data;
    char str[MAX_NAME_LENGTH];
    int i=0;
    while(i<size){
        scanf("%d %s", &data, str);
        in[i].data = data;
        in[i].name = malloc(MAX_NAME_LENGTH);
        strcpy(in[i].name, str);
        i++;
    }
    i=0;
    //Performing mergesort on in and printing the results
    merge_sort(in, size);
    while(i<size){
        printf("%d %s\n", in[i].data, in[i].name);
        i++;
    }

    //Freeing the in that we called malloc on in the first place
    //to prevent memory leak
    for(int i =0; i < size ; ++i){
        free(in[i].name);
    }
    free(in);
    return 0;
}

