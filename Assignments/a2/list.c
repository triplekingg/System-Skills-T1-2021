/* Name: Manit Gandhi
 * ID: 6280004 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include "ctype.h"


// Helper function for sort
void swap(Node *a, Node *b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}


void sort(struct Node *start) {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


int search(int num) {
    Node *current = front;
    while (current != NULL) {
        if (current->value == num) {
            printf("Found %d\n", num);
            return 1;
        }
        current = current->next;
    }
    printf("Cannot find %d\n", num);
    return 0;
}

void insert(int num) {
    Node *new = malloc(sizeof(Node));
    new->value = num;
    new->next = (front);
    front = new;
}

int delete(int num) {
    // Store head node
    Node *temp = front;
    Node *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->value == num) {
        front = temp->next; // Changed head
        free(temp); // free old head
        return 1;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->value != num) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return 0;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

void print() {
    Node *tmp = front;
    sort(tmp);
    while (tmp != NULL) {
        if (tmp->next == NULL) {
            printf("%d", tmp->value);
        } else {
            printf("%d, ", tmp->value);
        }
        tmp = tmp->next;
    }
    printf("\n");
}

void parser(char *path) {
    FILE *ptr;
    ptr = fopen(path, "r");
    char *command = malloc(sizeof(char) * 4); //to store each line of command
    char c = fgetc(ptr);
    while (c != EOF) {
        int i = 0;
        if (c == '\n') {
            c = fgetc(ptr);
        }
        while (c != '\n') {
            if (c == EOF) {
                break;
            }
            command[i] = c;
            i++;
            c = fgetc(ptr);
        }
        char *c1 = malloc(sizeof(char) * 2);
        for (int j = 0; j < strlen(command); j++) {
            if (strlen(command) == 1) {
                if (command[j] == 'P') {
                    print();
                    break;
                }
            }
            if (isalpha(command[j])) {
                c1[0] = command[j];
            } else if (isdigit(command[j])) {
                if (c1[0] == 'I') {
                    int num = command[j] - '0';
                    insert(num);
                    free(c1);
                } else if (c1[0] == 'D') {
                    int num = command[j] - '0';
                    delete(num);
                    free(c1);
                } else if (c1[0] == 'S') {
                    int num = command[j] - '0';
                    search(num);
                    free(c1);
                }
            }
        }
        memset(command, 0, sizeof command);
    }
    fclose(ptr);
    free(command);
}

/*Ajarn krub, I can parse the input from the input file, however not from the stdin.
 * All the functions that were given in the starter that are implemented correctly.*/

//When testing please use ./list <path to input file>
int main(int argc, char *argv[]) {
    front = NULL;
    parser(argv[1]);
}

