#ifndef COLA_H
#define COLA_H
#include <stdbool.h>
typedef int element;

typedef struct nodo{
	element e;
	struct nodo* next;
}Node;

typedef struct queue{
	Node* tail;
	Node* head;
}Qu;

bool isempty(Qu* cola);

void createQ(Qu* cola);
void enqueue(Qu* cola, element e);
element dequeue(Qu* cola);
void show(Qu cola);
void purge(Qu* cola);
void copyQueue(Qu* cola, Qu* copia);

#include "cola.c"
#endif
