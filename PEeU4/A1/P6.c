#include<stdio.h>
int main() {
    int n[10]={0}, i, b, f=0;

    for(i=0; i<10; i++) {
        printf("Introduce un valor: ");
        scanf("%d", &n[i]);
    }
    printf("Introduce el valor a encontrar: ");
    scanf("%d", &b);
    for(i=0; i<10; i++) {
        if(n[i] == b) {
            printf("El numero %d esta en la posicion %d\n", b, i+1);
            f = 1;
    }
    }
    if(!f) {
        printf("El numero no existe en el arreglo\n");
    }
    return 0;
}
