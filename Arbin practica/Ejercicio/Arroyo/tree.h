#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data;

typedef struct node {
    data d;
    char name[15];
    struct node* left;
    struct node* right;
} *Tree;

Tree createNode(data d);
void createTree(Tree* root, Tree leftChild, Tree rightChild, data d);
void preorderTraversal(Tree root);
void inorderTraversal(Tree root);
void postorderTraversal(Tree root);
Tree searchElement(Tree root, data target);
Tree deleteElement(Tree root, data d);
void freeTree(Tree root);
#include "tree.c"
#endif

