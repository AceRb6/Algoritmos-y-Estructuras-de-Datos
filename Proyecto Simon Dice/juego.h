#ifndef JUEGO_H
#define JUEGO_H
#include "cola.h"
#define colorS SetConsoleTextAttribute
#define c hConsole
#define verde 34
#define amarillo 102
#define rojo 68
#define azul 17
#define morado 51 //85
#define cian 85 //51
#define verde_B 170
#define amarillo_B 238
#define rojo_B 204
#define azul_B 153
#define morado_B 187 //221
#define cian_B 221 //187
#define blanco 0 //136
#define reset 112
#define espacio "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
#define espcolor "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
#define salto "MMMMM"
#define orilla "MM"

typedef int element;

void presentacion();
void instrucciones();
void juego(Qu* cola);
void imprimir_colores (Qu* color,int nivel);
void mostrar_tablero(int nivel);
void menu();
void opciones_color();
void game_over();
void winner();

#include "juego.c"
#endif
