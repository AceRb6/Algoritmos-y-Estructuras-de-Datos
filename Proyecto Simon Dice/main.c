#include <stdlib.h>
#include <stdio.h> 
#include "cola.h"
#include "juego.h"
#include <time.h>
#include <ncurses.h>
typedef int element;

int main() {
    int opcion, seleccion=0,max_opc=3;
    srand(time(NULL));
    Qu* Cola = malloc(sizeof(Qu));
    createQ(Cola);
    
    ///inicica ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    
    while(1) {
        mvprintw(5,10,"\n[1]. Juego\n");
        mvprintw(7,10,"[2]. Instrucciones\n");
        mvprintw(9,10,"[3]. Salir\n");
        
        mvprintw(5 + (seleccion * 2), 9, "->");
        
        refresh();
        
        opcion=getch()
        switch (opcion) {
            case KEY_UP:
                seleccion = (seleccion - 1 + max_opciones) % max_opciones;
                break;
            case KEY_DOWN:
                seleccion = (seleccion + 1) % max_opciones;
                break;
            case '\n':
                switch (seleccion) {
                    case 0:
                        juego(Cola);
                        break;
                    case 1:
                        instrucciones();
                        break;
                    case 2:
                        salir(Cola);
                        break;
                }
                break;
            default:
                break;
        }
    }
	free(Cola);
    endwin();
    return 0;
}
