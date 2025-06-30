#include "P3_Pila.h"
#include <stdio.h>
#include <string.h>
#define Max 100000

int main(){
	char numero1[Max], numero2[Max], resultado[Max];
	int i, tamano_num1, tamano_num2;
	printf("ingrese dos numeros positivos\n");
	printf("ingrese el numero 1: ");
	scanf("%s",numero1);
	
	printf("ingrese el numero 2: ");
	scanf("%s",numero2);
	
	tamano_num1=strlen(numero1);
	tamano_num2=strlen(numero2);
	
	node *num1,*num2,*Resul;
	create(&num1);
	create(&num2);
	create(&Resul);
	for(i=0; i<tamano_num1;i++){
		push(&num1,numero1[i]-'0');
	}
	
	for(i=0; i<tamano_num2;i++){
		push(&num2,numero2[i]-'0');
	}
	Resul=sumarNums(&num1,&num2);

	mostrar(&Resul);
	
	vaciar_pila(&num1);
	vaciar_pila(&num2);
	vaciar_pila(&Resul);
	return 0;
	}
