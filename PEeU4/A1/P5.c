#include<stdio.h>

int main() {
    int n[10]={0}, i, j, a;

    for(i=0; i<10; i++) {
        printf("Introduce un valor: ");
        scanf("%d", &n[i]);
    }

    for(i=0; i<10; i++) {
        for(j=i+1; j<10; j++) {
            if(n[i] > n[j]) {
                a = n[i];
                n[i] = n[j];
                n[j] = a;
            }
        }
    }

    printf("Lista en orden ascendente:\n");
    for(i=0; i<10; i++) {
        if(i==0)
            printf("%d", n[i]);
        else
            printf(",%d", n[i]);
    }
    printf("\n");

    return 0;
}
