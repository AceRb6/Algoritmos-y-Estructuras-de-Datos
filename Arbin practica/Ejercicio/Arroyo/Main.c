#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    Tree raiz1, a1, a2, raiz2;
    createTree(&a1, NULL, NULL, 2);
    strcpy(a1->name, "Maria");
    createTree(&a2, NULL, NULL, 20);
    strcpy(a2->name, "Claudia");
    createTree(&raiz1, a1, a2, 18);
    strcpy(raiz1->name, "Jorge");
    createTree(&a1, NULL, NULL, 63);
    strcpy(a1->name, "Fernando");
    createTree(&a2, NULL, NULL, 70);
    strcpy(a2->name, "Laura");
    createTree(&raiz2, a1, a2, 66);
    strcpy(raiz2->name, "Pedro");
    createTree(&a1, raiz1, raiz2, 22);
    strcpy(a1->name, "Miguel");

    Tree root = a1;

    int opcion = 0;
    do {
        printf("\nMenu:\n");
        printf("1 - Mostrar Arbol\n");
        printf("2 - Buscar ID\n");
        printf("3 - Salir\n");
        printf("Ingrese la seleccion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nLos elementos son: ");
                inorderTraversal(root);
                break;
            case 2:
                printf("\nIngrese el ID a buscar: ");
                int id;
                scanf("%d", &id);
                Tree result = searchElement(root, id);
                if (result != NULL) {
                    printf("Elemento encontrado: %d Nombre del ID: %s\n", result->d,result->name);
                } else {
                    printf("No se encuentra el elemento.\n");
                }
                break;
            case 3:
                printf("\nADIOS\n");
                freeTree(root);
                break;
            default:
                printf("\nOpción inválida. Por favor, ingrese una opción válida.\n");
        }
        system("pause");
        system("cls");
    } while (opcion != 3);
    return 0;
}

