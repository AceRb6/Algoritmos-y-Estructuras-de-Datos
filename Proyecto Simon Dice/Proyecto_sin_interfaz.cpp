#include <stdlib.h>
#include <stdio.h> 
#include "cola.h"
#include "juego.h"
#include <time.h>
typedef int element;

int main() {
    int opcion;
    srand(time(NULL));
    Qu* Cola = malloc(sizeof(Qu));
    createQ(Cola);
    do {
        printf("\n1. Juego\n");
        printf("2. Instrucciones\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
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
        printf("\n");
        system("pause");
        system("cls");
    } while (opcion != 3);
    free(Cola);
    return 0;
}
