#ifndef ARB_BIN_H
#define ARB_BIN_H
#include <stdio.h>
typedef char element;

typedef struct nodeT{
	element e;
	struct nodeT*left;
	struct nodeT*right;
}BinaryTree;

BinaryTree createNode(element e);
void newTree(BinaryTree *root,BinaryTree ramaizq,BinaryTree ramader,elemenet e);
void preorder(BinaryTree root);
void inorder(BinaryTree root);
void postorder(BinaryTree root);
BinaryTree buscarElemento(BinaryTree root, element e);
int isBalanced(BinaryTree root);
BinaryTree deleteElement;

#include "Fun_Bin.c"
#endif
