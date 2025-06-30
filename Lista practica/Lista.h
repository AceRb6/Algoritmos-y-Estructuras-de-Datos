#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
typedef int element;

typedef struct node{
	element e;
	struct node*prev;
	struct node*next;
}node;

typedef struct listD{
	node*head;
	node*tail;
}listD;

void create(listD *l);
void insertatfirst(listD *l,element e);
void insertatend(listD *l,element e);
void insertbeforenodeD(listD *l,element e,int n);
void insertafternodeD(listD *l,element e,int n);
void Bnode(listD *l,int i);
void clear(listD *l);
void borrarlista(listD *l);
element borrarnodo(listD*l,int n);

#include "Fun_List.c"
#endif
