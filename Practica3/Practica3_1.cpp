#include "Cabecera.h" /*Es editable al nombre que quieran yo solo le puse cabezera para que se entendiera, y si se cambia este igual el del archivo*/
#include <stdio.h>
#include <string.h>
#define MAX_TAM 1000000

int main(){
	char num_1[MAX_TAM];
	char num_2[MAX_TAM];
	char resul[MAX_TAM];
	int i, tam_num1, tam_num2;
	printf("Inserte el primer numero: ");
	scanf("%s",&num_1);
	printf("Inserte el segundo numero: ");
	scanf("%s",&num_2);
	tam_num1=strlen(num_1);
	tam_num2=strlen(num_2);
	Nodo *numero_1;
	Nodo *numero_2;
	Nodo *Resultado;
	crear(&numero_1);
	crear(&numero_2);
	crear(&Resultado);
	for(i=0; i<tam_num1;i++){
		insertar(&numero_1,num_1[i]-48);
	}
	for(i=0; i<tam_num2;i++){
		insertar(&numero_2,num_2[i]-48);
	}
	Resultado=sumatoria_numeros(&numero_1,&numero_2);
	mostrar(&Resultado);
	
	liberar_pila(&numero_1);
	liberar_pila(&numero_2);
	liberar_pila(&Resultado);
	return 0;
	}
