#include <stdio.h>

int main() {
    float n = 0;

    printf("Introduce la longitud en centimetros: ");
    scanf("%f", &n);

    if (n < 0) {
        printf("La distancia no puede ser negativa.\n");
        return 0;
    }

    printf("Equivalente en kilometros: %.5f\n", n / 100000);
    printf("Equivalente en metros: %.2f\n", n / 100);
    printf("Valor en centimetros: %.2f\n", n);

    return 0;
}
