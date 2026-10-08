#include <stdio.h>

int main() {
    int n = 0;
    int m = 0;
    int r = 0;

    printf("Introduce el primer valor: ");
    scanf("%d", &n);

    printf("Introduce el segundo valor: ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("Los datos deben ser enteros positivos.\n");
        return 0;
    }

    if (n > m) {
        r = n % m;
        if (r == 0) {
            printf("El numero mayor (%d) es multiplo del menor (%d).\n", n, m);
            return 0;
        }
    }

    if (n < m) {
        r = m % n;
        if (r == 0) {
            printf("El numero mayor (%d) es multiplo del menor (%d).\n", m, n);
            return 0;
        }
    }

    printf("Los valores ingresados no son multiplos.\n");

    return 0;
}
