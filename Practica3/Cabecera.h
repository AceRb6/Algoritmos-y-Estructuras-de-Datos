#ifndef CABECERA_H /*Es editable al nombre que quieran yo solo le puse cabezera para que se entendiera, y si se cambia este igual el del archivo*/
#define CABECERA_H /*Es editable al nombre que quieran yo solo le puse cabezera para que se entendiera, y si se cambia este igual el del archivo*/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef int element;

typedef struct Nodo{
    element elem;
    struct Nodo*nuevo;
}Nodo;

bool is_empty(Nodo **stack);
void crear(Nodo **stack);
void insertar(Nodo **stack, element e);
int eliminar(Nodo **stack);
void imprimir_numeros(Nodo **stack);
void liberar_pila(Nodo **stack);
Nodo *sumatoria_numeros(Nodo **num_1, Nodo **num_2);
#include "Funciones.c" /*Es editable al nombre que quieran yo solo le puse funciones para que se entendiera, y si se cambia este igual el del archivo*/
#endif
