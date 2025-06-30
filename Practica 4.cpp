#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct stack{
	int top;
	int* S;
	int tamano;
}stack;

bool is_full(stack S){
	if(S.top==S.tamano-1)
		return true;
	else
		return false;	
}
bool is_empty(stack S){
	if(S.top<0)
		return true;
	else
		return false;
}

stack* create_stack(int n){
	stack* s=(stack*)malloc(sizeof(stack));
	s->tamano=n;
	s->S=(int*)malloc(n*sizeof(int));
	s->top=-1;
	return s;
}

void push(stack* S, int element) {
    if (is_full(*S)) {
        printf("La pila esta llena\n");
    }
    else{
    	S->top++;
    	S->S[S->top] = element;
	}
}

int pop(stack* S) {
	int e;
    if (is_empty(*S)) {
        printf("La pila esta vacia\n");
    }
    else{
    	e=S->S[S->top];
    	S->top--;
    	return e;
	}
    
}

void display(stack* S) {
    if (S->top < 0) {
        printf("Pila vacia\n");
        return;
    }
    printf("Elementos de la pila:\n");
    for (int i = S->top; i >= 0; i--) {
        printf("%d\n", S->S[i]);
    }
}

int main() {
    int opcion, element,n;
    printf("ingrese el tamaño de la pila: ");
    scanf("%i",&n);
    stack* Mstack=create_stack(n);
    Mstack->top=-1;
    
    do {
        printf("\n1. Agregar\n");
        printf("2. Eliminar\n");
        printf("3. Imprimir\n");
        printf("4. Salir\n");

        printf("Ingrese la opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(Mstack,element);
                break;
            case 2:
                pop(Mstack);
                break;
            case 3:
                display(Mstack);
                break;
            case 4:
                printf("Saliendo...\n");
                exit(0);
            default:
                printf("Opcion no valida\n");
                break;
        }
        system("pause");
        system("cls");
    } while (opcion != 4);
    
    
    free(Mstack);
    return 0;
}
