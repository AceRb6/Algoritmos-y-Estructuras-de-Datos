#include <stdlib.h>
#include "Lista.h"
int main() {
    listD lista;
    create(&lista);

    int opcion;
    element elemento;
    int posicion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insertar al principio\n");
        printf("2. Insertar al final\n");
        printf("3. Insertar antes de un nodo\n");
        printf("4. Insertar después de un nodo\n");
        printf("5. Borrar un nodo\n");
        printf("6. Imprimir lista\n");
        printf("7. Borrar lista\n");
        printf("8. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &elemento);
                insertatfirst(&lista, elemento);
                break;
            case 2:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &elemento);
                insertatend(&lista, elemento);
                break;
            case 3:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &elemento);
                printf("Ingrese la posición antes de la cual insertar: ");
                scanf("%d", &posicion);
                insertbeforenodeD(&lista, elemento, posicion);
                break;
            case 4:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &elemento);
                printf("Ingrese la posición después de la cual insertar: ");
                scanf("%d", &posicion);
                insertafternodeD(&lista, elemento, posicion);
                break;
            case 5:
                printf("Ingrese la posición del nodo a borrar: ");
                scanf("%d", &posicion);
                borrarnodo(&lista, posicion);
                break;
            case 6:
                printf("Lista: ");
                printList(&lista);
                break;
            case 7:
                borrarlista(&lista);
                printf("Lista borrada\n");
                break;
            case 8:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida\n");
        }
    system("pause");
	system("cls");
    } while (opcion != 8);
	borrarlista(&lista);
    return 0;
}
