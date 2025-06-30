#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct compras{
        char nombre[25];
        int numero;
        int indice[10];
};

int busqueda_indexada(struct compras *ventas,int n, int m, int ganador){
    int G,i,b=0,ini,fin;
    G=n/m;
    for(i=0;i<(n/G);i++){
        ventas[i].indicei*m;
        }
        if(ganador<ventas[0].indice)
            return -1;
        else
        {
            for(i=1;i<G-1;i++){
                if(ganador<ventas[i].numero){
                    ini=ventas[i-1].indice
                    fin=ventas[i].indice-1;
                    b=1;
                    break;
                }
            }
        if(b==0){
            ini=ventas[G-1].indice;
            fin=n-1;
        }
    }
    return -1;
}

int main(){
        int ganador=0,i,premio;
        struct compras ventas[50]={
                {"Pedro",1},{"Juan",2},{"Sin asignar",3},{"Sin asignar",4},{"Sebastian",5},{"Sin asignar", 6},{"Raul",7},{"Byron",8},{"Cesar",9},{"Fernanda",10},{"Evelyn",11},
                {"Oscar",12},{"Alan",13},{"Eduardo",14},{"Paola",15},{"Sin asignar",16},{"Sin asignar",17},{"Sin asignar",18},{"Sin asignar",19},{"Sin asignar",20},{"Maria",21},
                {"Marlene",22},{"Liliana",23},{"Sin asignar",24},{"Sin asignar",25},{"Ambar",26},{"Isaac",27},{"Israel",28},{"Sin asignar",29},{"Daniela",30},{"Sin asignar",31},
                {"Nadia",32},{"Marisol",33},{"Enrique",34},{"Silvia",35},{"Ariel",36},{"Sin asignar",37},{"Ivonne",38},{"Sin asignar",39},{"Sin asignar",40},{"Leslie",41},
                {"Valeria",42},{"Alfonso",43},{"Saul",44},{"Ximena",45},{"Sin asignar",46},{"Sin asignar",47},{"Jose",48},{"Danny",49},{"Arturo",50}
                };        
        srand(time(NULL));
        do{
                ganador=1+rand()%50;
                printf("El numero ganador es: %i\n",ganador);
                premio=busqueda_indexada(ventas,50,10,ganador);
        }while(premio>=0);
}
