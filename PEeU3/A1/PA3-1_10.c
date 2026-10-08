#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char n[10] = "";

    printf("Escribe una letra: ");
    scanf("%9s", n);

    int m = strlen(n);

    if (m > 1) {
        printf("Por favor introduce unicamente un caracter.\n");
        return 0;
    }

    if (strcmp(n, "a") == 0) {
        printf("El caracter ingresado es una vocal.\n");
        return 0;
    }
    if (strcmp(n, "e") == 0) {
        printf("El caracter ingresado es una vocal.\n");
        return 0;
    }
    if (strcmp(n, "i") == 0) {
        printf("El caracter ingresado es una vocal.\n");
        return 0;
    }
    if (strcmp(n, "o") == 0) {
        printf("El caracter ingresado es una vocal.\n");
        return 0;
    }
    if (strcmp(n, "u") == 0) {
        printf("El caracter ingresado es una vocal.\n");
        return 0;
    }

    printf("El caracter no corresponde a una vocal.\n");

    return 0;
}
