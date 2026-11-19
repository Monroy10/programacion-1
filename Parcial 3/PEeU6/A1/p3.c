#include <stdio.h>

void imprimirArreglo(const int *a, int n, int c);

int main() {
    int tam, cols;

    printf("Cuantos elementos tendra el arreglo: ");
    scanf("%d", &tam);

    int lista[tam];

    for (int i = 0; i < tam; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &lista[i]);
    }

    printf("Cuantos elementos mostrar por renglon: ");
    scanf("%d", &cols);

    printf("\nResultado:\n");
    imprimirArreglo(lista, tam, cols);

    return 0;
}

void imprimirArreglo(const int *a, int n, int c) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", *(a + i));
        if ((i + 1) % c == 0) {
            printf("\n");
        }
    }
    printf("\n");
}
