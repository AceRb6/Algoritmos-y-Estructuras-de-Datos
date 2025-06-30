#include "colap.h"
#include "coladin.h"

bool isEmptyQP(queueP *qp) {
    int i;
    for (i = 0; i < qp->sqp; i++) {
        if (!is_empty(qp->QP[i]))
            return false;
    }
    return true;
}

void recibirPedidos(queueP *colaPrioridad, int cantidadProducto) {
    char nombreCliente[100];
    int cantidad, prioridad;

    while (1) {
        printf("\nIngrese el nombre del cliente (o 'q' para salir): ");
        scanf("%s", nombreCliente);

        if (nombreCliente[0] == 'q')
            break;

        printf("Ingrese la cantidad de producto que desea: ");
        scanf("%d", &cantidad);

        printf("Ingrese la prioridad del pedido (0 - Alta, 1 - Media, 2 - Baja): ");
        scanf("%d", &prioridad);

        if (cantidad > cantidadProducto) {
            printf("No hay suficiente producto disponible para este pedido. El pedido se ha descartado.\n");
        } else {
            element pedido;
            pedido.value = cantidad;
            pedido.priority = prioridad;
            insertinpriority(colaPrioridad, pedido);
            cantidadProducto -= cantidad;
            printf("Pedido agregado a la cola de prioridad.\n");
        }
    }
}

void atenderPedidos(queueP *colaPrioridad, int *cantidadProducto) {
    while (!isEmptyQP(colaPrioridad)) {
        int pedido = deletex(colaPrioridad);
        if (pedido == -1) {
            printf("Error al atender el pedido.\n");
            break;
        }
        printf("Se ha atendido un pedido de cantidad %d.\n", pedido);
        (*cantidadProducto) += pedido;
    }
}

void createQP(queueP *qp) {
    int i;
    qp->sqp = size_p;
    for (i = 0; i < qp->sqp; i++)
        create(&qp->QP[i]);
}

void insertinpriority(queueP *qp, element e) {
    if (e.priority < 0 || e.priority >= qp->sqp)
        printf("Error de prioridad fuera de rango\n");
    else
        enqueue(&qp->QP[e.priority], e.value);
}

int deletex(queueP *qp) {
    int i;
    element e;
    if (isEmptyQP(qp)) {
        printf("La cola de prioridad esta vacia\n");
        return -1;
    } else {
        for (i = 0; i < qp->sqp; i++) {
            if (!is_empty(qp->QP[i]))
                return dequeue(&qp->QP[i]);
        }
    }
    return e.value;
}

void deleteQP(queueP *qp) {
    int i;
    if (!isEmptyQP(qp)) {
        for (i = 0; i < qp->sqp; i++)
            deletex(qp);
    }
}

