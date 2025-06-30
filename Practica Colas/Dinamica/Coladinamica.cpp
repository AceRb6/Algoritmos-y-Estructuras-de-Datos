#include <stdlib.h>
#include <stdio.h>
#include "coladin.h"

int main(){
	int opcion=0,element;
	Qu cola;
	create(&cola);
    do {
        printf("1. Agregar\n");
        printf("2. Eliminar\n");
        printf("3. Imprimir\n");
        printf("4. Limpiar\n");
        printf("5. Salir\n");
        
        printf("Ingrese la opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("ingrese el elemento a introducir a la cola: ");
                scanf("%d", &element);
                enqueue(&cola,element);
                break;
            case 2:
                dequeue(&cola);
                break;
            case 3:
                show(cola);
                break;
            case 4:
            	purge(&cola);
            	printf("\nLimpieza completada\n");
            	break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
        system("pause");
        system("cls");
    } while (opcion != 5);
    
	purge(&cola);
    return 0;
}
