#include "Cabecera2.h" /*Es editable al nombre que quieran yo solo le puse cabezera para que se entendiera, y si se cambia este igual el del archivo*/
#include <stdio.h>
#include <string.h>
#define MAX_TAM 1000000

int main(){
	int i,tamano;
	char formula[MAX_TAM];
	printf("ingrese la formula que se quiere analizar: ");
	scanf("%s",&formula);
	tamano=strlen(formula);
	Nodo *form;
	crear(&form);
	for(i=tamano-1; i>=0;i--){
		insertar(&form,formula[i]);
	}
	formula_balanceada(&form,tamano);
	liberar_pila(&form);
	return 0;
	}
