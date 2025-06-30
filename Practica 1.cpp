#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int *arreglo,int n);
void insertion_sort(int *arreglo,int n);
void merge_sort(int *arreglo,int ini,int fin);
void merge(int *arreglo,int ini,int medio,int fin);
void arreglo_aleatorio(int *arreglo,int n);
void imprimir(int *arreglo,int n);

int main()
{
	srand(time(NULL));
	clock_t inicio,fin;
	double time_t;
	int n,i;
	int *arreglo;
	printf("Determine tamano del Arreglo\n");
	scanf("%d", &n);
	arreglo=(int*)malloc(n*sizeof(int));
	///////////////
	arreglo_aleatorio(arreglo,n);
	printf("arreglo aleatorio: \n");
	imprimir(arreglo,n);
	inicio=0;
	inicio=clock();
	printf("arreglo selection sort: \n");
	selection_sort(arreglo, n);
	fin=clock();
	time_t = ((double) (fin - inicio)) / CLOCKS_PER_SEC; 
	imprimir(arreglo, n);
	printf("\nTiempo de ejecucion: %f seg\n", time_t);
	system("pause");
	///////////////
	arreglo_aleatorio(arreglo,n);
	printf("arreglo aleatorio: \n");
	imprimir(arreglo,n);
	inicio=0;
	fin=0;
	inicio=clock();
	printf("arreglo insertion sort: \n");
	insertion_sort(arreglo, n);
	fin=clock();
	time_t = ((double) (fin - inicio)) / CLOCKS_PER_SEC; 
	imprimir(arreglo, n);
	printf("\nTiempo de ejecucion: %f seg\n", time_t);
	system("pause");
	/////////////////
	arreglo_aleatorio(arreglo,n);
	printf("arreglo aleatorio: \n");
	imprimir(arreglo,n);
	inicio=0;
	fin=0;
	inicio=clock();
	printf("arreglo merge sort: \n");
	merge_sort(arreglo,0,n-1);
	time_t = ((double) (fin - inicio))/ CLOCKS_PER_SEC; 
	imprimir(arreglo, n);
	printf("\nTiempo de ejecucion: %f seg\n", time_t);
	system("pause");
	
	free(arreglo);
	return 0;
}

void arreglo_aleatorio(int *arreglo,int n){
	int i;
	for(i = 0; i < n; i++){
 		arreglo[i]= rand() % (n*2)+1;
	}
}

void imprimir(int *arreglo,int n){
	int i;
	for(int i=0;i<n;i++){
	    printf("[%d]--%d\n",i+1,*(arreglo+i));
	}printf("\n");
}

void selection_sort(int *arreglo,int n){
    int i,j,aux,m;
    for (i=0;i<n-1;i++){
        aux=i;
        for (j=i+1;j<n;j++){
            if (arreglo[j]<arreglo[aux]){
                aux=j;
            }
        }
        // intercambiamos los elementos 
        m=arreglo[i];
        arreglo[i]=arreglo[aux];
        arreglo[aux]=m;  
	}
   }
   
   void insertion_sort(int *arreglo,int n){
    int i, j, k;
    for (i=1;i<n;i++){
        k=arreglo[i];
        j=i-1;
        while(j>=0 && arreglo[j]>k){
            arreglo[j+1]=arreglo[j];
            j=j-1;
        }
        arreglo[j+1]=k;
    }
}

void merge(int *arreglo,int ini,int medio,int fin) {
    int i,j,k,num1,num2;
    num1=medio-ini+1;
    num2=fin-medio;
    int *I=(int*)malloc(num1*sizeof(int));
	int *D=(int*)malloc(num2*sizeof(int));
    for (i=0;i<num1;i++)
        I[i]=arreglo[ini+i];
    for (j=0;j<num2;j++)
        D[j]=arreglo[medio+1+j];
    i=0;
	j=0;
	k=ini;
    while(i<num1 && j<num2){
        if(I[i]<=D[j]){
            arreglo[k]=I[i];
            i++;
        }
        else {
            arreglo[k]=D[j];
            j++;
        }
        k++;
    }
    while(i<num1){
        arreglo[k]=I[i];
        i++;
        k++;
    }
    while(j<num2){
        arreglo[k]=D[j];
        j++;
        k++;
    }
    free(I);
    free(D);
}

void merge_sort(int *arreglo, int ini, int fin) {
    int n, medio;
	if (ini<fin) {
        medio=ini+(fin-ini)/2;
        merge_sort(arreglo,ini,medio);
        merge_sort(arreglo,medio+1,fin);
        merge(arreglo,ini,medio,fin);
    }
}

