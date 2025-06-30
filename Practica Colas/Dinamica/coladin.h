#ifndef COLADIN_H
#define COLADIN_H
typedef int elemento;

typedef struct nodo{
	elemento e;
	struct nodo* next;
}Node;

typedef struct queue{
	Node* tail;
	Node* head;
}Qu;

bool is_empty(Qu cola);

void create(Qu* cola);
void enqueue(Qu* cola, elemento e);
int dequeue(Qu* cola);
void show(Qu cola);
void purge(Qu* cola);

#include "fun_coladin.c"
#endif
