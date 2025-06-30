#include "Lista.h"

void create(listD *l){
	l->head=l->tail=NULL;
}

void insertatfirst(listD *l,element e){
	node*n=(node*)malloc(sizeof(node));
	if (l->head==NULL){
		n->prev=NULL;
    	n->next=NULL;
        n->e=e;
	    l->head=n;
        l->tail=n;
	}
	else{
		l->head->prev=n;
		n->next=l->head;
		n->prev=NULL;
		l->head=n;
		n->e=e;
	}
}

void insertatend(listD* l, element e) {
    node*n=(node*)malloc(sizeof(node));
    n->e=e;
    n->prev=l->tail;
    n->next=NULL;
    if (l->head!=NULL) {
        l->tail->next=n;
        l->tail=n;
    } else {
        l->head=l->tail=n;
    }
}


void insertbeforenodeD(listD *l,element e,int n){
	node*nN=(node*)malloc(sizeof(node));
    nN->e=e;
    if (n==1) {
        free(nN);
        insertatfirst(l,e);
    }
    else{
    	node *aux,*aux2;
		aux=l->head;
    	int cont=1;
    	while (aux->next!=NULL) {
        	aux=aux->next;
        	cont++;
    	}
    	if(n>cont){
    		free(nN);
    		printf("fuera de rango\n");
    		return;
		}
    	else{
    		aux=l->head;
    		cont=1;
    		while(cont<n-1){
    			aux=aux->next;
    			cont++;
			}
			aux2=aux->next;
			aux->next=nN;
			nN->prev=aux;
			nN->next=aux2;
			aux2->prev=nN;
			nN->e=e;
		}
	}
}

void insertafternodeD(listD *l,element e,int n){
	node*nN=(node*)malloc(sizeof(node));
	nN->e=e;
    if (l->head==NULL){
        l->head=nN;
        l->tail=nN;
	    l->head->prev=NULL;
    	l->tail->next=NULL;
    }
    else{
    	node*aux=l->head;
    	int i=1;
    	while(aux->next!=NULL && i!=n){
    		aux=aux->next;
    		i++;
		}
		if(i!=n){
			printf("fuera de rango\n");
			return;
		}
		if(aux->next==NULL)
			insertatend(l,e);
		else{
			node*aux2=aux->next;
			aux->next=nN;
			nN->prev=aux;
			nN->next=aux2;
			aux2->prev=nN;
		}
	}
}

void Bnode(listD *l,int i){
	int aux=0;
	node*auxn=(node*)malloc(sizeof(node));
	while(aux!=i){
		auxn=auxn->next;
		aux++;
	}
	node *prev,*next;
	prev=auxn->prev;
	next=auxn->next;
	prev->next=auxn->next;
	next->prev=auxn->prev;
	free(auxn);
}

void clear(listD *l){
	int cont=1;
	while(l->head!=NULL){
		Bnode(l,cont);
		cont++;
	}
	l->head=l->tail=NULL;
}

void borrarlista(listD *l){
	node*act=l->head;
	node*sig;
	while(act!=NULL){
		sig=act->next;
		free(act);
		act=sig;
	}
	l->head=l->tail=NULL;
}

element borrarnodo(listD*l,int n){
	if(l->head==NULL){
		printf("lista vacia\n");
		return -1;
	}
	node*act=l->head;
	int cont=1;
	while(act!=NULL && cont<n){
		act=act->next;
		cont++;
	}
	if(act==NULL){
		printf("Nodo inexistente\n");
		return -1;
	}
	if(act==l->head)
		l->head=act->next;
	else{
		act->prev->next=act->next;
		act->next->prev=act->prev;
	}
	element d=act->e;
	free(act);
	return d;
}

void printList(listD* l) {
    node* current = l->head;
    while (current != NULL) {
        printf("%d ", current->e);
        current = current->next;
    }
    printf("\n");
}
