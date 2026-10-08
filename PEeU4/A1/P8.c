#include<stdio.h>
int main() {
    int a[10]={0}, b[10]={0}, i, j, c=0;

    printf("Primer conjunto\n");
    for(i=0; i<10; i++) {
        printf("Introduce un valor: ");
        scanf("%d", &a[i]);
    }
    printf("Segundo conjunto\n");
    for(i=0; i<10; i++) {
        printf("Introduce un valor: ");
        scanf("%d", &b[i]);
    }
    printf("Elementos en comun:\n");
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            if(a[i] == b[j]) {
                if(c==0)
                    printf("%d", a[i]);
                else
                    printf(",%d", a[i]);
                c++;
                break;
        }
        }
    }
    printf("\n");
    return 0;
}
