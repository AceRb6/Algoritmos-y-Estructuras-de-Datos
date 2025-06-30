#include <stdlib.h>
#include "P6_pila.h"
#include <string.h>

int main(){
	char candea[100000];
	int tamano, i;
	
	printf("ingrse la cadena de caracteres: ");
	scanf("%s",&candea);
	
	tamano=strlen(candea);
	node* cadena;
	create(&cadena);
	
	for(i=0;i<tamano;i++)
		push(&cadena,candea[i]);
	
	mostrar(&cadena);
	vaciar_pila(&cadena);
}
