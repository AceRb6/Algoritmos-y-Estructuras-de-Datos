#include "cola.h"

bool isempty(Qu* cola){
	if(cola->tail==cola->head && cola->tail==NULL)
		return true;
	else
		return false;
}

void createQ(Qu *cola){
	cola->head=cola->tail=NULL;
}

void enqueue(Qu *cola,element e){
	Node *n;
	n=(Node*)malloc(sizeof(Node));
	if (isempty(cola)){
		cola->head=n;
		cola->head->e=e;
		cola->head->next=NULL;
		cola->tail=n;
	}
	else{
		cola->tail->next=n;
		cola->tail=n;
		cola->tail->next=NULL;
		cola->tail->e=e;
	}
}

element dequeue(Qu *cola){
	element e;
	if (isempty(cola)){
		printf("\ncola vacia\n");
		return -1;
	}
	else{
		if(cola->head->next==NULL)
			cola->tail=NULL;
		Node* aux = cola->head;
		e=aux->e;
		cola->head=cola->head->next;
		free(aux);
		return e;
	}
}

void show(Qu cola) {
    if (isempty(&cola)) {
        printf("\nLa cola esta vacia\n");
        return;
    }
    Node* aux=cola.head;
    printf("\nElementos en la cola: ");
    while (aux!=NULL) {
        printf("%i ",aux->e);
        aux=aux->next;
    }
    printf("\n");
}

void purge(Qu* cola){
	while(!isempty(cola)){
    dequeue(cola);
    }
}

////funcion extra para el juego

void copyQueue(Qu* cola, Qu* copia){
    createQ(copia);
    Node* aux=cola->head;
    while (aux!=NULL) {
        enqueue(copia,aux->e);
        aux=aux->next;
    }
}

