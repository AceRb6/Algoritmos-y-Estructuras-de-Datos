#ifndef PILA_H
#define PILA_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef int element;

typedef struct node{
    element e;
    struct node*n;
}node;

bool is_empty(node **st);
void createP(node **st);
void push(node **st, element e);
element pop(node **st);
void mostrar(node **st);
void vaciar_pila(node **st);

void copy(node **st1,node **st2);

#include "pila.c"

#endif
