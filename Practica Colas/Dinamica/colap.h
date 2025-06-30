#ifndef COLAP_H
#define COLAP_H
#include <stdio.h>
#include <stdbool.h>
#define size_p 3
#include "coladin.h"
typedef int elemento;

typedef struct element {
    int value;
    int priority;
} element;

typedef struct queueP {
    int sqp;
    Qu QP[size_p];
} queueP;

bool isEmptyQP(queueP *qp);
void atenderPedidos(queueP *colaPrioridad, int *cantidadProducto);
void recibirPedidos(queueP *colaPrioridad, int cantidadProducto);
void createQP(queueP *qp);
void insertinpriority(queueP *qp, element e);
int deletex(queueP *qp);
void deleteQP(queueP *qp);

#include "colapfun.c"
#endif

