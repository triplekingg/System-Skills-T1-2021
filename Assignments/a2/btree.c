/* Name: Manit Gandhi
 * ID: 6280004
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"


void insert(Node **tree, int val) {
    if (*tree == NULL) {
        Node *node = malloc(sizeof(Node));
        node->data = val;
        node->left = NULL;
        node->right = NULL;
        *tree = node;
        return;
    }
    if ((*tree)->data < val)
        insert(&((*tree)->right), val);
    else if ((*tree)->data > val)
        insert(&((*tree)->left), val);
}

void printer(Node *root, int depth) {
    if (root == NULL)
        return;
    int i=0;
    while(i < depth){
        printf(i == depth - 1 ? "|-" : "  ");
        i++;
    }
    printf("%d\n", root->data);
    printer(root->left, depth + 1);
    printer(root->right, depth + 1);
}


void print(Node *tree) {
    printer(tree, 0);
}

void delete(Node *tree) {
    if (tree == NULL) {
        return;
    }
    delete(tree->right);
    delete(tree->left);
    free(tree);
}

Node *lookup(Node **tree, int val) {
    if (*tree == NULL) {
        return NULL;
    }
    if ((*tree)->data == val)
        return tree;
    if ((*tree)->data > val)
        return lookup(&((*tree)->left), val);
    return lookup(&((*tree)->right), val);

}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv) {
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);

    // Lets see how the tree looks
    print(root);

    // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Now let's free up the space
    delete(root);
}

