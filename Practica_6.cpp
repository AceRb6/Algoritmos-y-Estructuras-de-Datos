#include <stdio.h>
#include "P6_pila.h" 

int main(){
	int opcion;
	element e;
	node *s;
	create(&s);
	do{
		printf("\n1 Agregar elemento");
		printf("\n2 Eliminar elemento");
		printf("\n3 Mostrar elementos");
		printf("\n4 Salir\n");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				printf("ingrese el elemento a agregar: ");
				scanf("%i",&e);
				push(&s,e);
				break;
			case 2:
				pop(&s);
				break;
			case 3:
				mostrar(&s);
				break;
			case 4:
				break;
			default:
				printf("opcion no valida");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion!=4);
	return 0;
}

