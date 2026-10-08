#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int n = 0;
    int m = 0;
    float a = 0;
    int b = 0;
    int i = 0;
    bool k = false;

    printf("Introduce la coordenada X del centro: ");
    scanf("%d", &n);

    printf("Introduce la coordenada Y del centro: ");
    scanf("%d", &m);

    printf("Introduce la coordenada X del punto a evaluar: ");
    scanf("%d", &b);

    printf("Introduce la coordenada Y del punto a evaluar: ");
    scanf("%d", &i);

    printf("Introduce la medida del radio: ");
    scanf("%f", &a);

    if (sqrt(((n - b) * (n - b)) + ((m - i) * (m - i))) == a) {
        k = true;
    }

    k ? printf("El punto se encuentra sobre la circunferencia.\n") 
      : printf("El punto no se encuentra sobre la circunferencia.\n");

    return 0;
}
