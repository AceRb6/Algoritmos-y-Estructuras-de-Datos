#include "juego.h"
#include "cola.h"

void presentacion() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	colorS(c,114);
    printf("\n\n\n\n\n						      ::::::::::       ::::::::       ::::::::       ::::::::         :::   ::: \n");
    Sleep(500);  // Pausa de 500 milisegundos (medio segundo)
    printf("						     :+:             :+:    :+:     :+:    :+:     :+:    :+:       :+:+: :+:+: \n");
    Sleep(500);  // Pausa de 500 milisegundos (medio segundo)
    printf("						    +:+             +:+            +:+            +:+    +:+      +:+ +:+:+ +:+ \n");
    Sleep(500);  // Pausa de 500 milisegundos (medio segundo)
    printf("						   +#++:++#        +#++:++#++     +#+            +#+    +:+      +#+  +:+  +#+  \n");
    Sleep(500);  // Pausa de 500 milisegundos (medio segundo)
    printf("						  +#+                    +#+     +#+            +#+    +#+      +#+       +#+   \n");
    Sleep(500);  // Pausa de 500 milisegundos (medio segundo)
    printf("						 #+#             #+#    #+#     #+#    #+#     #+#    #+#      #+#       #+#    \n");
    Sleep(500);  // Pausa de 500 milisegundos (medio segundo)
    printf("						##########       ########       ########       ########       ###       ###     \n");
    Sleep(500);  // Pausa de 500 milisegundos (medio segundo)
    printf("\n\n");
    Sleep(500);  // Pausa de 500 milisegundos (medio segundo)
    printf("										presenta\n");
}


void instrucciones(){
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	colorS(c,114);
	printf("\n\n\n\n\n		El juego de Simón dice es un emocionante desafío de memoria que pondrá a prueba tus habilidades de atención y concentración.\n");
	printf("		El objetivo del juego es recordar y reproducir correctamente la secuencia de colores iluminados generados al azar por el programa.\n");
	printf("		Cada nivel del juego presenta una serie de colores que se iluminan en un orden específico, y tu tarea es repetir esa secuencia\n");
	printf("		exactamente como la viste. \n		Al comienzo del juego, estarás en el nivel 1, donde solo se mostrará un color iluminado.\n\n");
	printf("		A medida que avances en los niveles, la dificultad aumentará, ya que se agregarán más colores a la secuencia y el \n");
	printf("		orden se volverá más complejo.\nDebes estar atento y concentrado para recordar cada color en el orden correcto, \n¡porque cualquier error terminara tu turno\n\n");
	printf("		Recuerda, el juego terminará si cometes el primer error, es decir, si indicas un color iluminado incorrectamente, o si logras llegar al nivel 15, \n\n");
	printf("		Prepárate para poner a prueba tu memoria, concentración y agilidad mental en este desafiante juego de Simón dice. ¡Buena suerte y diviértete!\n\n");				
	printf("		cuando indica un color iluminado incorrecto) o cuando llego al nivel 15.\n\n");
	mostrar_tablero(0);
}

void menu(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	colorS(c,114);
	printf("\n\n\n				 ad88888ba   88                                                    88888888ba,    88                          \n");
	printf("				d8^     ^8b  ^^                                                    88      ^8b    ^^                          \n");
	printf("				Y8,                                                                88        `8b                              \n");
	printf("				`Y8aaaaa,    88  88,dPYba,,adPYba,    ,adPPYba,   8b,dPPYba,       88         88  88   ,adPPYba,   ,adPPYba,  \n");
	printf("				  `^^^^^8b,  88  88PL   L88L    ^8a  a8^     ^8a  88P'   `^8a      88         88  88  a8^     ^^  a8P_____88  \n");
	printf("				        `8b  88  88      88      88  8b       d8  88       88      88         8P  88  8b          8PP^^^^^^^  \n");
	printf("				Y8a     a8P  88  88      88      88  ^8a,   ,a8^  88       88      88      .a8P   88  ^8a,   ,aa  ^8b,   ,aa  \n");
	printf("				 QY88888PQ   88  88      88      88   `QYbbdPQ'   88       88      88888888YQ'    88   `QYbbd8Q'   `QYbbd8Q'  \n");
	colorS(c,reset);
	printf("\n							1. Juego\n");
	printf("							2. Instrucciones\n");
	printf("							3. Salir\n");
	printf("							Ingrese una opcion: ");
}

void opciones_color(){
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	printf("		1 - Verde - "); colorS(c, verde); printf("MMMMM\t"); colorS(c, reset);
	printf("		2 - Rojo -    "); colorS(c, rojo); printf("MMMMM\t"); colorS(c, reset);
	printf("	3 - Amarillo - "); colorS(c, amarillo); printf("MMMMM\n"); colorS(c, reset);
	printf("		4 - Azul -  "); colorS(c, azul); printf("MMMMM\t"); colorS(c, reset);
	printf("		5 - Cial -    "); colorS(c, morado); printf("MMMMM\t"); colorS(c, reset);
	printf("	6 - Morado -   "); colorS(c, cian); printf("MMMMM\n"); colorS(c, reset);
}

void game_over(){
	system("cls");
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	colorS(c,116);
	printf("\n\n\n\n\n\n");
	printf("\n				 .d8888b.         d8888 888b     d888 8888888888      .d88888b.  888     888 8888888888 8888888b.  ");     
	printf("\n				d88P  Y88b       d88888 8888b   d8888 888            d88P^ ^Y88b 888     888 888        888   Y88b ");     
	printf("\n				888    888      d88P888 88888b.d88888 888            888     888 888     888 888        888    888 ");     
	printf("\n				888            d88P 888 888Y88888P888 8888888        888     888 Y88b   d88P 8888888    888   d88P ");     
	printf("\n				888  88888    d88P  888 888 Y888P 888 888            888     888  Y88b d88P  888        8888888P^  ");     
	printf("\n				888    888   d88P   888 888  Y8P  888 888            888     888   Y88o88P   888        888 T88b   ");     
	printf("\n				Y88b  d88P  d8888888888 888   ^   888 888            Y88b. .d88P    Y888P    888        888  T88b  ");     
	printf("\n				 ^Y8888P88 d88P     888 888       888 8888888888      ^Y88888P^      Y8P     8888888888 888   T88b ");
	printf("\n\n");
}

void winner(){
	system("cls");
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	colorS(c,114);
	printf("\n		      # ###              ##             ##### #     ##            ##              ##### ##          # ###         ##### /##  ");
	printf("\n		    /  /###  /        /####          ######  /#    #### /      /####           /#####  /##        /  /###      ######  / ##  ");
	printf("\n		   /  /  ###/        /  ###         /#   /  / ##    ###/      /  ###         //    /  / ###      /  /  ###    /#   /  /  ##  ");
	printf("\n		  /  ##   ##            /##        /    /  /  ##    # #          /##        /     /  /   ###    /  ##   ###  /    /  /   ##  ");
	printf("\n		 /  ###                /  ##           /  /    ##   #           /  ##            /  /     ###  /  ###    ###     /  /    /   ");
	printf("\n		##   ##                /  ##          ## ##    ##   #           /  ##           ## ##      ## ##   ##     ##    ## ##   /    ");
	printf("\n		##   ##   ###         /    ##         ## ##     ##  #          /    ##          ## ##      ## ##   ##     ##    ## ##  /     ");
	printf("\n		##   ##  /###  /      /    ##         ## ##     ##  #          /    ##          ## ##      ## ##   ##     ##    ## ###/      ");
	printf("\n		##   ## /  ###/      /      ##        ## ##      ## #         /      ##         ## ##      ## ##   ##     ##    ## ##  ###   ");
	printf("\n		##   ##/    ##       /########        ## ##      ## #         /########         ## ##      ## ##   ##     ##    ## ##    ##  ");
	printf("\n		 ##  ##     #       /        ##       #  ##       ###        /        ##        #  ##      ##  ##  ##     ##    #  ##    ##  ");
	printf("\n		  ## #      /       #        ##          /        ###        #        ##           /       /    ## #      /        /     ##  ");
	printf("\n		   ###     /       /####      ##     /##/          ##       /####      ##     /###/       /      ###     /     /##/      ### ");
	printf("\n		    ######/       /   ####    ## /  /  #####               /   ####    ## /  /   ########/        ######/     /  ####    ##  ");
	printf("\n		      ###        /     ##      #/  /     ##               /     ##      #/  /       ####            ###      /    ##     #   ");
	printf("\n		                 #                 #                      #                 #                                #               ");
	printf("\n		                  ##                ##                     ##                ##                               ##             \n		");
}

void mostrar_tablero(int nivel){
	printf("\n										Nivel:  %i\n", nivel);
	printf("\n\n");
	int i, color_set;
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	printf("					");
	colorS(c, blanco);
	printf(espacio);
	colorS(c, reset);
	printf("\n");
	for(i=0;i<30;i++){
		if(i<10)
			color_set=1;
		else
			if(i<20)
				color_set=2;
			else
				if(i<30)
					color_set=3;
		switch(color_set){
			case 1:
				printf("					");
				colorS(c, blanco);
				printf(orilla);
				colorS(c, verde);
				printf(espcolor);
				colorS(c, blanco);
				printf(salto);
				colorS(c, rojo);
				printf(espcolor);
				colorS(c, blanco);
				printf(orilla);
				break;
			case 2:
				printf("					");
				colorS(c, blanco);
				printf(orilla);
				colorS(c, amarillo);
				printf(espcolor);
				colorS(c, blanco);
				printf(salto);
				colorS(c, azul);
				printf(espcolor);
				colorS(c, blanco);
				printf(orilla);
				break;
			case 3:
				printf("					");
				colorS(c, blanco);
				printf(orilla);
				colorS(c, morado);
				printf(espcolor);
				colorS(c, blanco);
				printf(salto);
				colorS(c, cian);
				printf(espcolor);
				colorS(c, blanco);
				printf(orilla);
				break;
			default: break;
		}
		colorS(c, reset);
		printf("\n");
		if(i==9 || i==19 || i==29){
			printf("					");
			colorS(c, blanco);
			printf(espacio);
			colorS(c, reset);
			printf("\n");
		}
		//system("cls");
	}
}

void imprimir_colores (Qu* color,int nivel){
	int i=0,j;
	element option;
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	for(i=0;i<nivel;i++){
		printf("\n										Nivel:  %i\n", nivel);
		printf("\n\n");
		option=dequeue(color);
		printf("					");
		colorS(c, blanco);
		printf(espacio);
		colorS(c, reset);
		printf("\n");
		switch(option){
			case 1:
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, verde_B);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, rojo);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, amarillo);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, azul);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, morado);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, cian);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				break;
			case 2:
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, verde);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, rojo_B);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, amarillo);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, azul);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, morado);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, cian);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				break;
			case 3:
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, verde);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, rojo);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, amarillo_B);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, azul);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, morado);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, cian);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				break;
			case 4:
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, verde);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, rojo);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, amarillo);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, azul_B);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, morado);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, cian);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				break;
			case 5:
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, verde);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, rojo);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, amarillo);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, azul);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, morado_B);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, cian);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				break;
			case 6:
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, verde);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, rojo);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, amarillo);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, azul);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				for(j=0;j<10;j++){
					printf("					");
					colorS(c, blanco);
					printf(orilla);
					colorS(c, morado);
					printf(espcolor);
					colorS(c, blanco);
					printf(salto);
					colorS(c, cian_B);
					printf(espcolor);
					colorS(c, blanco);
					printf(orilla);
					colorS(c, reset);
					printf("\n");
				}
				printf("					");
				colorS(c, blanco);
				printf(espacio);
				colorS(c, reset);
				printf("\n");
				break;
			default: break;
		}
		colorS(c, reset);
		printf("\n");
		Sleep(1500);
		system("cls");
		mostrar_tablero(nivel);
		Sleep(1500);
		system("cls");
	}
}

void juego(Qu* cola){
	element random;
	element color;
	int nivel=1, win=0, cont;
	Qu* copia=malloc(sizeof(Qu));
	Qu* colores=malloc(sizeof(Qu));
	while(1){
		system("cls");
		cont=0;
		random=rand()%6+1;
		enqueue(cola, random);
		copyQueue(cola,copia);
		copyQueue(cola,colores);
		mostrar_tablero(nivel);
		printf("\n");
		Sleep(1500);
		system("cls");
		imprimir_colores(colores,nivel);
		while(1){
			mostrar_tablero(nivel);
			opciones_color();
			do{
				printf("					ingrese el color: ");
				scanf("%i",&color);
				if(color<1 || color>6)
					printf("el color no existe vuelva a ingresar\n");
			}while(color<1 || color>6);
			if(color!=dequeue(copia)){
				win=-1;
				break;
			}
			else
				cont++;	
			if(cont==nivel){
				nivel++;
				break;
			}
			system("cls");
		}
		if(nivel==16){
			winner();
			break;
		}
		if(win==-1){
			game_over();
			break;
		}
	}
	purge(cola);
	purge(copia);
	purge(colores);
	free(colores);
	free(copia);
}
