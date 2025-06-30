#ifndef ARB_BIN_H
#define ARB_BIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef int element;

struct nodeT {
    element e;
    char nombre[20];
    struct nodeT* left;
    struct nodeT* right;
};
typedef struct nodeT* BinaryTree;

BinaryTree createNode(element e);
void newTree(BinaryTree* root, BinaryTree ramaizq, BinaryTree ramader, element e);
void preorder(BinaryTree root);
void inorder(BinaryTree root);
void postorder(BinaryTree root);
BinaryTree buscarElemento(BinaryTree root, element buscado);
BinaryTree deleteElement(BinaryTree root, element e);
void liberarArbol(BinaryTree root);
#include "fun_bin.c"
#endif

