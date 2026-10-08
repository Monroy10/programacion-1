#include<stdio.h>
int main() {
    int n[10]={0}, i=0, j, f;

    while(i<10) {
        printf("Introduce un valor: ");
        scanf("%d", &n[i]);
        f = 0;
        for(j=0; j<i; j++) {
            if(n[i] == n[j]) {
                f = 1;
                break;
        }
        }
        if(f) {
            printf("Ese valor ya se encuentra, introduzca otro\n");
        } else {
            i++;
        }
    }
    printf("El arreglo es:\n");
    for(i=0; i<10; i++) {
        if(i==0)
            printf("%d", n[i]);
        else
            printf(",%d", n[i]);
    }
    printf("\n");
    return 0;
}
