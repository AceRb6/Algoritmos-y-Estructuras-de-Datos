#include <stdlib.h>
#include <stdio.h> 
#include <windows.h> 
#include "cola.h"
#include "juego.h"
#include <time.h>
typedef int element;

int main() {
    int opcion;
    Sleep(3500);
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    WORD originalAttributes;
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(c,&consoleInfo);
	originalAttributes=consoleInfo.wAttributes;
	colorS(c,reset);
	system("cls");
	presentacion();
	sleep(1);
    srand(time(NULL));
    Qu* Cola = malloc(sizeof(Qu));
    createQ(Cola);
    do {
    	system("cls");
    	menu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                juego(Cola);
                break;
            case 2:
            	instrucciones();	
                break;
            case 3:
                break;
            default:
                printf("Opción no valida.\n");
                break;
        }
        system("pause");
        system("cls");
    } while (opcion != 3);
    free(Cola);
    return 0;
}
