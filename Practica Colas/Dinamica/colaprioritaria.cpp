#include <stdio.h>
#include <stdlib.h>
#include "colap.h"
#include "coladin.h"

int main() {
    int cantidadProducto;
    printf("Ingrese la cantidad inicial del producto: ");
    scanf("%d", &cantidadProducto);

    queueP colaPrioridad;
    createQP(&colaPrioridad);

    recibirPedidos(&colaPrioridad, cantidadProducto);
    printf("\n--- Atendiendo pedidos ---\n");
    atenderPedidos(&colaPrioridad, &cantidadProducto);

    printf("\nProceso de recepcion de pedidos finalizado.\n");

    return 0;
}

