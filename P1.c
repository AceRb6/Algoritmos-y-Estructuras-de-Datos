#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


void generar_ar(int *array,int n){
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++){
		array[i]=rand()%1001;
	}
}

void imprimir_ar(int *array,int n){
	int i;
	printf("lista del arreglo: ");
	for(i=0;i<n;i++){
		printf("|%i",array[i]);
	}
}

void ordenar(int *ar, int n,int k){
	int i,j, aux;
	for(i=k;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(ar[i]>ar[j]){
				aux=ar[i];
				ar[i]=ar[j];
				ar[j]=aux;
			}
		}
	}
}
	
int main(){
	int *arreglo;
	int n;
	printf("ingrese el tamano del arreglo: ");
	scanf("%i",&n);
	arreglo=(int *)malloc(n*sizeof(int));
	
	generar_ar(arreglo,n);
	printf("\narreglo generado\n");
	imprimir_ar(arreglo,n);
	
	ordenar(arreglo,n,0);
	
	printf("\narreglo ordenado\n");
	imprimir_ar(arreglo,n);
	
	free(arreglo);
	return 0;
}
