#include <stdlib.h>
#include <stdio.h> 
#include <windows.h> 
#define color SetConsoleTextAttribute
#define c hConsole

int main(){
	int i;
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	for(i=0;i<16*16;i++){
		color(c,i);
		printf("%i - color\n",i);
	}
	color(c,15);
	return 0;
}
