#include "Cabecera2.h" /*Es editable al nombre que quieran yo solo le puse cabezera para que se entendiera, y si se cambia este igual el del archivo*/
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
		printf("No hay formula\n");
		return;
	}
	printf("\nLa formula es:");
	Nodo*temp=*stack;
	while(temp != NULL){
		printf("%c",temp->elem);
		temp=temp->nuevo;
	}
}
void liberar_pila(Nodo **stack){
	while(!is_empty(*stack)){
		eliminar(stack);
	}
}

void formula_balanceada(Nodo **form,int tamano){
	int i,comp_1=0, comp_2=0, comp_3=0;
	Nodo*temp=*form;
	while(temp != NULL){
		if(temp->elem==40)
			comp_1++;
		if(temp->elem==41)
			comp_1--;
		if(temp->elem==91)
			comp_2++;
		if(temp->elem==93)
			comp_2--;
		if(temp->elem==123)
			comp_3++;
		if(temp->elem==125)
			comp_3--;
		temp=temp->nuevo;
	}
	if(comp_3==0){
		if(comp_2==0){
			if(comp_1==0){
				mostrar(form); 
				printf("\nla formula esta balanceada");
			}
			else{ /// si falta parentesis
				printf("\nla formula no esta balanceada fatla: ");
				if(comp_1==1)
					printf(")");
				else
					if(comp_1==-1)
						printf("(");
				}
		}
		else{ /// si falta corchete
			printf("\nla formula no esta balanceada fatla: ");
			if(comp_1==0){ /// si solo falta corchete
				if(comp_2==1)
					printf("]");
				else
					if(comp_2==-1)
						printf("[");
			}
			else{ /// si falta corchete y parentesis
				if(comp_2==1)
					printf("]");
				else
					if(comp_2==-1)
						printf("[");
				printf(" y ");
				if(comp_1==1)
					printf(")");
				else
					if(comp_1==-1)
						printf("(");
				}
			}
		}
		else{ /// si falta alguna llave
			printf("\nla formula no esta balanceada fatla: ");
			if(comp_2==0){
				if(comp_1==0){ /// si falta solo llave
					if(comp_3==1)
						printf("}");
					else
						if(comp_3==-1)
							printf("{");
				}
				else{ /// si falta llave y parentesis
					if(comp_3==1)
						printf("}");
					else
						if(comp_3==-1)
							printf("{");
					printf(" y ");
					if(comp_1==1)
						printf(")");
					else
						if(comp_1==-1)
							printf("(");
				}
			}
			else{/// si falta llave y corchete
				if(comp_1==0){
					if(comp_2==1)
						printf("]");
					else
						if(comp_2==-1)
							printf("[");
					printf(" y ");
					if(comp_3==1)
						printf("}");
					else
						if(comp_3==-1)
							printf("{");
				}
			else{ /// si falta llave, corcheta y parentesis
				if(comp_3==1)
					printf("}");
				else
					if(comp_3==-1)
						printf("{");
				printf(", ");
				if(comp_2==1)
					printf("]");
				else
					if(comp_2==-1)
						printf("[");
				printf(" y ");
				if(comp_1==1)
					printf(")");
				else
					if(comp_1==-1)
						printf("(");
			}
		}
	}
}
