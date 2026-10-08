#include <stdio.h>

void celsiusFarenheit() {
    float c, f;
    printf("Ingrese los grados Celsius: ");
    scanf("%f", &c);
    f = (c * 9.0 / 5.0) + 32.0;
    printf("Equivalente en Farenheit: %.2f\n", f);
}

void farenheitCelsius() {
    float f, c;
    printf("Ingrese los grados Farenheit: ");
    scanf("%f", &f);
    c = (f - 32.0) * 5.0 / 9.0;
    printf("Equivalente en Celsius: %.2f\n", c);
}

void celsiusKelvin() {
    float c, k;
    printf("Ingrese los grados Celsius: ");
    scanf("%f", &c);
    k = c + 273.15;
    printf("Equivalente en Kelvin: %.2f\n", k);
}

void kelvinCelsius() {
    float k, c;
    printf("Ingrese los grados Kelvin: ");
    scanf("%f", &k);
    c = k - 273.15;
    printf("Equivalente en Celsius: %.2f\n", c);
}

int main() {
    int o;
    printf("--- MENU CONVERSIONES DE TEMPERATURA ---\n");
    printf("1. Grados Celsius a Farenheit\n");
    printf("2. Grados Farenheit a Celsius\n");
    printf("3. Grados Celsius a Kelvin\n");
    printf("4. Grados Kelvin a Celsius\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &o);

    switch(o) {
        case 1: celsiusFarenheit(); break;
        case 2: farenheitCelsius(); break;
        case 3: celsiusKelvin(); break;
        case 4: kelvinCelsius(); break;
        default: printf("Opcion invalida\n");
    }
    return 0;
}
