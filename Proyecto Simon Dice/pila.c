#include "pila.h"

bool is_empty(node **st){
	if(st == NULL)
		return true;
	else
		return false;
}


void createP(node **st){
	*st=NULL;
}

void push(node **st, element e){
	node *n;
	n=(node*)malloc(sizeof(node));
	n->n=*st;
	*st=n;
	n->e=e;
}

element pop(node **st){
	int e;
	if(is_empty(st))
		printf("la pila esta vacia\n");
	else{
		e=(*st)->e;
		node*d=*st;
		*st=d->n;
		free(d);
		return e;
	}
}

void mostrar(node **st){
	if(*st==NULL){
		printf("pila vacia\n");
		return;
	}
	printf("\nElementos de la pila:\n");
	node*t=*st;
	while(t != NULL){
		printf("%c\n",t->e);
		t=t->n;
	}
}

void vaciar_pila(node **st){
	while(!is_empty(st)){
		pop(st);
	}
}

void copy(node **st1, node **st2) {
    node*t=*st1;
    node *temp=NULL; // Pila temporal para almacenar los elementos en orden inverso
    
    while (t!=NULL){
        push(&temp,t->e); // Agregar elementos a la pila temporal
        t=t->n;
    }
    // Transfiera los elementos de la pila temporal (en orden inverso) a st2
    while(temp!=NULL) {
        push(st2, temp->e);
        temp=temp->n;
    }
}

