#include <stdio.h>

int main() {
    int n = 0;
    int m = 0;
    int a = 0;

    printf("Introduce el primer valor: ");
    scanf("%d", &n);

    printf("Introduce el segundo valor: ");
    scanf("%d", &m);

    printf("Introduce el tercer valor: ");
    scanf("%d", &a);

    if (n == m && n == a) {
        printf("Todos los numeros son iguales.\n");
        return 0;
    }

    if (n == m || m == a || n == a) {
        printf("Hay dos numeros iguales.\n");
        return 0;
    }

    printf("Todos los numeros son diferentes.\n");

    return 0;
}
