#include "coladin.h"

bool is_empty(Qu cola){
	if(cola.tail==cola.head && cola.tail==NULL)
		return true;
	else
		return false;
}

void create(Qu *cola){
	cola->head=cola->tail=NULL;
}

void enqueue(Qu *cola,elemento e){
	Node *n;
	n=(Node*)malloc(sizeof(Node));
	if (is_empty(*cola)){
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

int dequeue(Qu *cola){
	elemento e;
	if (is_empty(*cola)){
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
    if (is_empty(cola)) {
        printf("\nLa cola esta vacia\n");
        return;
    }
    Node* aux=cola.head;
    printf("\nElementos en la cola: ");
    while (aux!=NULL) {
        printf("%d ",aux->e);
        aux=aux->next;
    }
    printf("\n");
}

void purge(Qu* cola){
	while(!is_empty(*cola)){
    dequeue(cola);
    }
}
