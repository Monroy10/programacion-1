#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int n = 0;
    int m = 0;
    float a = 0;

    printf("Introduce la base del rectangulo: ");
    scanf("%d", &n);

    printf("Introduce la altura del rectangulo: ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("Las dimensiones deben ser mayores a cero.\n");
        return 0;
    }

    a = sqrt(pow(n, 2) + pow(m, 2));

    printf("Area del rectangulo: %d\n", n * m);
    printf("Perimetro total: %d\n", n + n + m + m);
    printf("Longitud de la diagonal: %.2f\n", a);

    return 0;
}
