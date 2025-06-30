#include "cola.h"

bool is_empty(Qu* cola){
	if (cola->head==next(cola->tail))
		return true;
	else
		return false;
}

bool is_full(Qu* cola){
	if (cola->head==next(next(cola->tail)))
		return true;
	else
		return false;
}

void create(Qu* cola){
	cola->head=0;
	cola->tail=sizeQ-1;
}

int next(int x){
	return (x+1)%sizeQ;
}

void enqueue(Qu* cola, element e){
	if (is_full(cola))
		printf("\ncola llena\n");
	else{
		cola->tail = next(cola->tail);
		cola->Q[cola->tail] = e;
	}
}

int dequeue(Qu* cola){
	int aux;
	if(is_empty(cola)){
		printf("\nCola vacia\n");
		return 0;
	}
	else{
		aux=cola->Q[cola->head];
		cola->head=next(cola->head);
		return aux;
	}
}

void show(Qu cola) {
	int save;
    if (is_empty(&cola)) {
        printf("\nLa cola esta vacia\n");
        return;
    }
    printf("\nElementos en la cola: ");
    save = cola.head;
    while (save != cola.tail+1) {
        printf("%d ", cola.Q[save]);
        save = next(save);
    }
}

/*void show(Qu cola){
	i=cola.head;
	j=0;
	while(j<cola.s){
		printf("%i",cola.Q[i]);
		i=next(i);
		j++;
	}
}*/

/*void enqueue(Qu cola, element e){
	if(!is_full(cola))
		printf("cola llena");
	else{
		cola.tail=next(cola.tail);
		cola.Q[cola.tail]=e;
		cola.s++;
	}
}

int dequeue(Qu cola){
	if(!is_empty(cola)){
		printf("Cola vacia");
		return 0;
	}
	else{
		element e=cola.Q[cola.head];
		cola.head=next(cola.head);
		cola.s--;
		return e;
	}
}*/
