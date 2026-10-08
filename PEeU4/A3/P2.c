#include <stdio.h>

typedef struct {
    int coef[21];
    int grado;
    int prod[21];
} polinomio;

int main() {
    polinomio a = {0};
    polinomio b = {0};
    polinomio s = {0};
    polinomio p = {0};
    int i = 0;
    int k = 0;

    printf("Introduce el grado del primer polinomio: ");
    scanf("%d", &a.grado);

    for (i = a.grado; i >= 0; i--) {
        printf("Valor del coeficiente x^%d: ", i);
        scanf("%d", &a.coef[i]);
    }

    printf("Introduce el grado del segundo polinomio: ");
    scanf("%d", &b.grado);

    for (i = b.grado; i >= 0; i--) {
        printf("Valor del coeficiente x^%d: ", i);
        scanf("%d", &b.coef[i]);
    }

    for (i = 20; i >= 0; i--) {
        s.coef[i] = a.coef[i] + b.coef[i];
    }

    printf("\nSuma resultante:\n");
    for (i = 20; i >= 0; i--) {
        if (s.coef[i] != 0) {
            printf("%d x^%d +  ", s.coef[i], i);
        }
    }
    printf("\n");

    for (i = a.grado; i >= 0; i--) {
        for (k = b.grado; k >= 0; k--) {
            p.prod[i + k] += a.coef[i] * b.coef[k];
        }
    }

    p.grado = a.grado + b.grado;

    printf("\nProducto resultante:\n");
    for (i = p.grado; i >= 0; i--) {
        if (p.prod[i] != 0) {
            printf("%d x^%d +  ", p.prod[i], i);
        }
    }
    printf("\n");

    return 0;
}
