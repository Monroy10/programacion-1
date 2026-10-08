#include <stdio.h>

int main() {
    int n = 0;
    int m = 0;
    printf("Ingresa el primer numero: ");
    scanf("%d", &n);
    printf("Ingresa el segundo numero: ");
    scanf("%d", &m);
    if (n == m) {    
        printf("Son iguales\n");
    }
    if (n < m) {
        printf("El segundo numero es mayor\n");
    }
    if (n > m) {
        printf("El primer numero es mayor\n");
    }
    return 0;
}
