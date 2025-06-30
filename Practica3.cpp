#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 9

struct elemt{
	int w;
	int v;
};

void binario_reset(int binario[]){
	int i;
	for(i=0;i<n;i++)
		binario[i]=0;
}

void copiar_bin(int binario[],int copy_bin[]){
	int i;
	for(i=0;i<n;i++)
		copy_bin[i]=binario[i];
}

void imprimir_combinacion(int ganador_bin[]){
	int i,j;
	printf("la conbinacion en binario es: ");
    for (j = n - 1; j >= 0; j--) {
        printf("%d", ganador_bin[j]);
    }
    printf("\n");
}

void problema_mochila(struct elemt *E){
	int peso,valor,cociente,sobra,i,j,z,peso_moch=100;
	int binario[n],ganador_bin[n];
	struct elemt ganador={0,0};
	for(i=0;i<=(pow(2,n))-1;i++){
		binario_reset(binario);
		cociente=i;
		z=0;
		while(cociente!=0){
			sobra=cociente%2;
			binario[z++]=sobra;
			cociente=cociente/2;
			}
		peso=valor=0;
		for(j=0;j<n;j++){
			if(binario[j]==1){
				peso+=E[j].w;
				valor+=E[j].v;
			}
		}
		if(peso<=peso_moch && valor>ganador.v){
			copiar_bin(binario,ganador_bin);
			ganador.w=peso;
			ganador.v=valor;
		}
	}
	printf("peso:%i  valor:%i\n",ganador.w,ganador.v);
	imprimir_combinacion(ganador_bin);
}

int main(){
struct elemt E[9]={{20,4500},{15,1200},{2,400},{30,800},{2,1500},{40,2000},{28,1900},{5,1500},{10,900}};
problema_mochila(E);
return 0;
}
