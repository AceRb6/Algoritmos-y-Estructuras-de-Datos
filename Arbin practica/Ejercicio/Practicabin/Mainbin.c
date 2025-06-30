#include <stdio.h>
#include <stdlib.h>
#include "arb_bin.h"

int main() {
    BinaryTree root1, a1, a2, root2, root3;
    newTree(&a1, NULL, NULL, 2);
    strcpy(a1->nombre, "Maria");
    newTree(&root1,a1,NULL,18);
    strcpy(root1->nombre, "Jorge");
    newTree(&a2, NULL, NULL, 20);
    strcpy(a2->nombre, "Claudia");
    newTree(&root2, root1, a2, 19);
    strcpy(root1->nombre, "Luis");
    newTree(&a1, NULL, NULL, 63);
    strcpy(a1->nombre, "Fernando");
    newTree(&a2, NULL, NULL, 70);
    strcpy(a2->nombre, "Laura");
    newTree(&root3, a1, a2, 66);
    strcpy(root2->nombre, "Pedro");
    newTree(&a1, root2, root3, 22);
    strcpy(a1->nombre, "Miguel");

    BinaryTree root = a1;

    int opcion = 0;
    do {
        printf("\nOpciones:\n");
        printf("1 - Ver arbol\n");
        printf("2 - Buscar por ID\n");
        printf("3 - Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nRecorrido en inorden: ");
                inorder(root);
                break;
            case 2:
                printf("\nIngrese el ID a buscar: ");
                element id;
                scanf("%d", &id);
                BinaryTree result = buscarElemento(root, id);
                if (result != NULL) {
                    printf("Elemento encontrado: %d\nNombre: %s\n", result->e,result->nombre);
                } else {
                    printf("Elemento no encontrado.\n");
                }
                break;
            case 3:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\nOpción inválida. Por favor, ingrese una opción válida.\n");
        }
    } while (opcion != 3);
    liberarArbol(root);
    return 0;
}

