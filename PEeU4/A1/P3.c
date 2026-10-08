#include<stdio.h>
int main() {
        int n[100]={0},m,i;
        printf("Lista numeros pares y múltiplos de 7\n");
        for (m=1,i=0;m<=100;m++){
                   if(m%2!=0 && m%7==0){
                    n[i]=m;
                     if(i==0)
                      printf("%d",n[i]);
                     else
                      printf(",%d",n[i]);
                      i++;
        }
        }
        printf("\n");
        return 0;
}
