#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secreto=0;
    int n=0;
    int intentos=0;

    srand(time(NULL));
    secreto = rand() % 1001;

    printf("=== Adivina el numero (0 a 1000) ===\n");
    do
    {
        printf("Escribe tu intento: ");
        scanf("%d", &n);
        intentos++;
        
        if (n>secreto)
        {
            printf("El numero secreto es mas pequeño.\n");
        }
        if (n<secreto)
        {
            printf("El numero buscado es mas grande.\n");
        }
    } while (n!=secreto);

    printf("\n¡Correcto! El numero secreto era %d.\n", secreto);
    printf("Total de intentos realizados: %d\n", intentos);

    return 0;
}
