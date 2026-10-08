#include <stdio.h>

int main() {
    int n = 0;
    int m = 0;

    printf("Introduce el año actual: ");
    scanf("%d", &n);

    printf("Introduce el año con el que quieres comparar: ");
    scanf("%d", &m);

    if (n == m) {
        printf("Ambos años son exactamente iguales.\n");
    }
    if (n < m) {    
        printf("Aun restan %d años para alcanzar el año %d.\n", m - n, m);
    }
    if (n > m) {
        printf("Ya han transcurrido %d años desde el %d.\n", n - m, m);
    }

    return 0;
}
