#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;  
    int m = 0;  
    int a = 0;  
    float b = 0;

    float vector1[10], vector2[10], vector3[10];

    do {
        printf("\n--- MENU DE VECTORES ---\n");
        printf("1. Suma de vectores\n");
        printf("2. Resta de vectores\n");
        printf("3. Suma de vector y escalar\n");
        printf("4. Resta de vector y escalar\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &n);

        system("clear");

        if (n >= 1 && n <= 4) {
            printf("Ingrese la dimension del vector: ");
            scanf("%d", &m);
            system("clear");

            for (a = 0; a < m; a++) {
                printf("Ingrese el valor del primer vector [%d]: ", a + 1);
                scanf("%f", &vector1[a]);
            }
            system("clear");
        }

        switch (n) {
            case 1:
                for (a = 0; a < m; a++) {
                    printf("Ingrese el valor del segundo vector [%d]: ", a + 1);
                    scanf("%f", &vector2[a]);
                }
                system("clear");

                for (a = 0; a < m; a++) {
                    vector3[a] = vector1[a] + vector2[a];
                }

                printf("El resultado de la suma es:\n(");
                for (a = 0; a < m - 1; a++) {
                    printf("%.2f, ", vector3[a]);
                }
                printf("%.2f)\n", vector3[m - 1]);
                break;

            case 2:
                for (a = 0; a < m; a++) {
                    printf("Ingrese el valor del segundo vector [%d]: ", a + 1);
                    scanf("%f", &vector2[a]);
                }
                system("clear");

                for (a = 0; a < m; a++) {
                    vector3[a] = vector1[a] - vector2[a];
                }

                printf("El resultado de la resta es:\n(");
                for (a = 0; a < m - 1; a++) {
                    printf("%.2f, ", vector3[a]);
                }
                printf("%.2f)\n", vector3[m - 1]);
                break;

            case 3:
                printf("Ingrese el valor escalar: ");
                scanf("%f", &b);
                system("clear");

                for (a = 0; a < m; a++) {
                    vector3[a] = vector1[a] + b;
                }

                printf("El resultado de sumar el escalar es:\n(");
                for (a = 0; a < m - 1; a++) {
                    printf("%.2f, ", vector3[a]);
                }
                printf("%.2f)\n", vector3[m - 1]);
                break;

            case 4:
                printf("Ingrese el valor escalar: ");
                scanf("%f", &b);
                system("clear");

                for (a = 0; a < m; a++) {
                    vector3[a] = vector1[a] - b;
                }

                printf("El resultado de restar el escalar es:\n(");
                for (a = 0; a < m - 1; a++) {
                    printf("%.2f, ", vector3[a]);
                }
                printf("%.2f)\n", vector3[m - 1]);
                break;

            case 5:
                system("clear");
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
                break;
        }

        getchar();
    } while (n >= 1 && n <= 4);

    return 0;
}
