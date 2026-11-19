#include <stdio.h>
#include <math.h>

void menu();
float aRadianes(int grados);
float seno(float rad);
float coseno(float rad);
float tangente(float rad);
float cotangente(float rad);
float secante(float rad);
float cosecante(float rad);

int main(){
    menu();
    return 0;
}

void menu(){
    int op, grados;
    float rad;

    printf("\nEste es un programa que realiza operaciones trigonometricas\n");
    printf("Escoge la operacion que deseas realizar:\n");
    printf("1. Seno\n");
    printf("2. Coseno\n");
    printf("3. Tangente\n");
    printf("4. Cotangente\n");
    printf("5. Secante\n");
    printf("6. Cosecante\n");
    printf("7. Salir\n");
    printf("Opcion: ");
    scanf("%d", &op);

    if(op == 7){
        printf("Saliendo del programa...\n");
        return;
    }

    if(op < 1 || op > 7){
        printf("Opcion no valida, intenta de nuevo.\n");
        menu();
        return;
    }

    printf("Escribe el valor en grados: ");
    scanf("%d", &grados);

    rad = aRadianes(grados);
    printf("Equivalencia en radianes: %.4f rad\n", rad);

    switch(op){
        case 1:
            printf("Seno: %.4f\n", seno(rad));
            break;
        case 2:
            printf("Coseno: %.4f\n", coseno(rad));
            break;
        case 3:
            if(grados % 90 == 0 && grados % 180 != 0){
                printf("No se puede calcular la tangente de %d grados, debido a indeterminación. \n", grados);
            } else {
                printf("Tangente: %.4f\n", tangente(rad));
            }
            break;
        case 4:
            if(grados % 180 == 0){
                printf("No se puede calcular la cotangente de %d grados, debido a indeterminación.\n", grados);
            } else {
                printf("Cotangente: %.4f\n", cotangente(rad));
            }
            break;
        case 5:
            if(grados % 90 == 0 && grados % 180 != 0){
                printf("No se puede calcular la secante de %d grados, debido a indeterminación.\n", grados);
            } else {
                printf("Secante: %.4f\n", secante(rad));
            }
            break;
        case 6:
            if(grados % 180 == 0){
                printf("No se puede calcular la cosecante de %d grados, debido a indeterminación.\n", grados);
            } else {
                printf("Cosecante: %.4f\n", cosecante(rad));
            }
            break;
    }

    menu();
}

float aRadianes(int grados){
    return grados * (M_PI / 180.0);
}

float seno(float rad){
    return sin(rad);
}

float coseno(float rad){
    return cos(rad);
}

float tangente(float rad){
    return tan(rad);
}

float cotangente(float rad){
    return cos(rad) / sin(rad);
}

float secante(float rad){
    return 1.0 / cos(rad);
}

float cosecante(float rad){
    return 1.0 / sin(rad);
}
