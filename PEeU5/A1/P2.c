#include <stdio.h>

void sumaMatrices() {
    int f, c, i, j;
    int A[10][10], B[10][10], C[10][10];
    
    printf("Ingrese el numero de filas: ");
    scanf("%d", &f);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &c);
    
    printf("\n--- Matriz A ---\n");
    for(i = 0; i < f; i++) {
        for(j = 0; j < c; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("\n--- Matriz B ---\n");
    for(i = 0; i < f; i++) {
        for(j = 0; j < c; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    
    printf("\nMatriz Resultante (Suma):\n");
    for(i = 0; i < f; i++) {
        for(j = 0; j < c; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
}

void productoMatrices() {
    int f1, c1, f2, c2, i, j, k;
    int A[10][10], B[10][10], C[10][10];
    
    printf("Ingrese filas de la Matriz 1: ");
    scanf("%d", &f1);
    printf("Ingrese columnas de la Matriz 1: ");
    scanf("%d", &c1);
    
    printf("Ingrese filas de la Matriz 2: ");
    scanf("%d", &f2);
    printf("Ingrese columnas de la Matriz 2: ");
    scanf("%d", &c2);
    
    if(c1 != f2) {
        printf("Error: El numero de columnas de M1 debe ser igual a las filas de M2.\n");
        return;
    }
    
    printf("\n--- Matriz A ---\n");
    for(i = 0; i < f1; i++) {
        for(j = 0; j < c1; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("\n--- Matriz B ---\n");
    for(i = 0; i < f2; i++) {
        for(j = 0; j < c2; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    
    for(i = 0; i < f1; i++) {
        for(j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(k = 0; k < c1; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    
    printf("\nMatriz Resultante (Producto):\n");
    for(i = 0; i < f1; i++) {
        for(j = 0; j < c2; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
}

void sumaElementos() {
    int f, c, i, j, suma = 0;
    int A[10][10];
    
    printf("Ingrese el numero de filas: ");
    scanf("%d", &f);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &c);
    
    printf("\n--- Matriz ---\n");
    for(i = 0; i < f; i++) {
        for(j = 0; j < c; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
            suma = suma + A[i][j];
        }
    }
    
    printf("\nLa suma de todos los elementos es: %d\n", suma);
}

int main() {
    int o;
    printf("--- MENU OPERACIONES CON MATRICES ---\n");
    printf("1. Suma de dos matrices\n");
    printf("2. Producto de dos matrices\n");
    printf("3. Suma de elementos de una matriz\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &o);
    
    switch(o) {
        case 1: sumaMatrices(); break;
        case 2: productoMatrices(); break;
        case 3: sumaElementos(); break;
        default: printf("Opcion invalida\n");
    }
    return 0;
}
