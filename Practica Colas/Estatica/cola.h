#ifndef COLA_H
#define COLA_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define sizeQ 9
typedef int element;

typedef struct queue{
	int tail;
	int head;
	element Q[sizeQ];
	/*int s;*/
}Qu;

bool is_empty(Qu* cola);
bool is_full(Qu* cola);

void create(Qu* cola);
int next(int x);
void enqueue(Qu* cola, element e);
int dequeue(Qu* cola);
void show(Qu cola);

#include "fun_colas.c"
#endif
