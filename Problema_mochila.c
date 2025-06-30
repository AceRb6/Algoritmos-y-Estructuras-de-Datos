#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM_VECTOR 9

struct producto {
    int peso;
    int valor;
};

void cargar(struct producto vector[]) {
    vector[0].valor = 4500;
    vector[1].valor = 1200;
    vector[2].valor = 4000;
    vector[3].valor = 800;
    vector[4].valor = 1500;
    vector[5].valor = 2000;
    vector[6].valor = 1900;
    vector[7].valor = 1500;
    vector[8].valor = 900;
    vector[0].peso = 20;
    vector[1].peso = 15;
    vector[2].peso = 2;
    vector[3].peso = 30;
    vector[4].peso = 2;
    vector[5].peso = 40;
    vector[6].peso = 28;
    vector[7].peso = 5;
    vector[8].peso = 10;
}

void reinicio_binario(int binario[]){
	int i;
	for(i=0;i<TAM_VECTOR;i++)
		binario[i]=0;
}

void llenar_binario(int binario[],int i){
	int k,cocien,resta;
	cocien=i;
	k=0;
	while(cocien!=0){
		resta=cocien%2;
		binario[k++]=resta;
		cocien=cocien/2;
	}
}

void copiar_binario(int binario[],int ganador[]){
	int i;
	for(i=0;i<TAM_VECTOR;i++)
		ganador[i]=binario[i];
}
 
void problema_mochila(struct producto vector[],int peso_mochila){
	int peso,valor,i,j;
	int binario[TAM_VECTOR], binario_ganador[TAM_VECTOR];
	struct producto ganador={0.0};
	for(i=0;i<pow(2,TAM_VECTOR);i++){
		reinicio_binario(binario);
		llenar_binario(binario,i);
		peso=valor=0;
		for(j=0;j<TAM_VECTOR;j++){
			if(binario[j]==1){
				peso+=vector[j].peso;
				valor+=vector[j].valor;
			}
		}
		if(peso<=peso_mochila && valor>ganador.valor){
			copiar_binario(binario,binario_ganador);
			ganador.peso=peso;
			ganador.valor=valor;
		}
	}
	printf("El peso ganador es: %i\nEl valor ganador es: %i\n\n",ganador.peso,ganador.valor);
	printf("de la combinacion:");
	for(i=1;i<TAM_VECTOR;i++){
		printf("%i",binario_ganador[i]);
	}
	printf("\nElementos ocupados: \n");
    for(i=0;i<TAM_VECTOR;i++){
    	if(binario_ganador[i]==1){
    		printf("Elemento: %i\nValor: %i\nPeso: %i\n\n",i+1,vector[i].valor,vector[i].peso);
		}
	}
}

int main() {
	int i, mochila_max=50;
    struct producto vector[TAM_VECTOR];
    
    cargar(vector);
    problema_mochila(vector,mochila_max);

    return 0;
}
