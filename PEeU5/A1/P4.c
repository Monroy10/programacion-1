#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void rectAPolar() {
    float x, y, r, theta;
    printf("Ingrese la coordenada x: ");
    scanf("%f", &x);
    printf("Ingrese la coordenada y: ");
    scanf("%f", &y);

    r = sqrt(x * x + y * y);
    theta = atan2(y, x) * (180.0 / PI); // Convertir a grados

    printf("\nCoordenadas polares:\n");
    printf("Radio (r): %.2f\n", r);
    printf("Angulo (theta): %.2f grados\n", theta);
}

void polarARect() {
    float r, theta, theta_rad, x, y;
    printf("Ingrese el radio (r): ");
    scanf("%f", &r);
    printf("Ingrese el angulo (theta en grados): ");
    scanf("%f", &theta);

    theta_rad = theta * (PI / 180.0); // Convertir grados a radianes
    x = r * cos(theta_rad);
    y = r * sin(theta_rad);

    printf("\nCoordenadas rectangulares:\n");
    printf("x: %.2f\n", x);
    printf("y: %.2f\n", y);
}

int main() {
    int o;
    printf("--- MENU CONVERSION DE COORDENADAS ---\n");
    printf("1. Coordenadas rectangulares a polares\n");
    printf("2. Coordenadas polares a rectangulares\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &o);

    switch(o) {
        case 1: rectAPolar(); break;
        case 2: polarARect(); break;
        default: printf("Opcion invalida\n");
    }
    return 0;
}
