#include <stdio.h>

int main() {
    int numero, cociente, resto, i = 1, j;
    int binario[100];

    printf("Introduzca un numero entero: ");
    scanf("%d", &numero);

    cociente = numero;

    while (cociente != 0) {
        resto = cociente % 2;
        binario[i++] = resto;
        cociente = cociente / 2;
    }

    printf("El numero %d en binario es: ", numero);
    for (j = i - 1; j > 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");

    return 0;
}
