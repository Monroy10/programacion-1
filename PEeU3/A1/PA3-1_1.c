#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    float r = 0.0f; 
    printf("Ingresa el numerador: ");
    scanf("%d", &a);
    printf("Ingresa el denominador: ");
    scanf("%d", &b);
    if (b == 0) {    
        printf("El denominador debe ser distinto de 0\n");
        return 0;
    }
    if ((a % b) == 0) {
        printf("La division es exacta \n");
    }
    r = (float)a / b; 
    printf("El resultado es %.2f\n", r); 
    return 0;
}
