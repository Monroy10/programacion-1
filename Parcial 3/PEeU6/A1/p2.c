#include <stdio.h>

void iniciarArreglo2(int *a, int n, int valor);

int main() {
    int tam, val;

    printf("Tamaño del arreglo: ");
    scanf("%d", &tam);

    printf("Valor con el que se llenara: ");
    scanf("%d", &val);

    int datos[tam];

    iniciarArreglo2(datos, tam, val);

    printf("\nArreglo inicializado:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    return 0;
}

void iniciarArreglo2(int *a, int n, int valor) {
    for (int i = 0; i < n; i++) {
        *(a + i) = valor;
    }
}
