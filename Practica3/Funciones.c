#include "Cabecera.h" /*Es editable al nombre que quieran yo solo le puse cabezera para que se entendiera, y si se cambia este igual el del archivo*/
bool is_empty(Nodo *stack){
	if(stack == NULL)
		return true;
	else
		return false;
}
void crear(Nodo **stack){
	*stack=NULL;
}
void insertar(Nodo **stack, element e){
	Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->nuevo=*stack;
	*stack=nuevo;
	nuevo->elem=e;
}
int eliminar(Nodo **stack){
	element e;
	if(is_empty(*stack)){
		printf("\nla pila esta vacia\n");
		return 0;
	}
	else{
		e=(*stack)->elem;
		Nodo*Lib=*stack;
		*stack=Lib->nuevo;
		free(Lib);
		return e;
	}
}
void mostrar(Nodo **stack){
	if(*stack==NULL){
		printf("No hay suma\n");
		return;
	}
	printf("\nEl numero sumado es:");
	Nodo*temp=*stack;
	while(temp != NULL){
		printf("%i",temp->elem);
		temp=temp->nuevo;
	}
}
void liberar_pila(Nodo **stack){
	while(!is_empty(*stack)){
		eliminar(stack);
	}
}

Nodo* sumatoria_numeros(Nodo **num_1, Nodo **num_2) {
    Nodo *Resul=NULL;
    int suma, acar=0, dig1, dig2;
    while ( *num_1!=NULL && *num_2!=NULL) {
        dig1=eliminar(num_1);
        dig2=eliminar(num_2);
        suma=dig1+dig2+acar;
        acar=suma/10;
        insertar(&Resul,suma%10);
    }
    while (*num_1!=NULL) {
        dig1=eliminar(num_1);
        suma=dig1+acar;
        acar=suma/10;
        insertar(&Resul,suma%10);
    }
    while (*num_2!=NULL) {
        dig2=eliminar(num_2);
        suma=dig2+acar;
        acar=suma/10;
        insertar(&Resul,suma%10);
    }
    if (acar!=0) {
        insertar(&Resul,acar);
    }
    return Resul;     
}
