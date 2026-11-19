#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void iniciarArreglo(int *a, int n, int rango);

int main() {
    int tam, rango;

    printf("Cantidad de elementos del arreglo: ");
    scanf("%d", &tam);

    printf("Valor maximo del rango (0 a rango): ");
    scanf("%d", &rango);

    int vec[tam];

    srand(time(NULL));
    iniciarArreglo(vec, tam, rango);

    printf("\nArreglo generado:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");

    return 0;
}

void iniciarArreglo(int *a, int n, int rango) {
    for (int i = 0; i < n; i++) {
        *(a + i) = rand() % (rango + 1);
    }
}
