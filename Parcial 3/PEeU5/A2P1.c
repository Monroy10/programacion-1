#include<stdio.h>
int pas(int, int);


int main(){
        int n,i,c,f;
        printf("Ingrese el numero de filas: ");
        scanf("%d",&n);
        for(f=0;f<n;f++){
         for(c=0;c<=f;c++){
         printf("%d\t" ,pas(f,c));
        }
        printf("\n");
        }
        return 0;
        }

        int pas (int f,int c){
         if (c==0 || c==f){
          return 1; }
           return (pas(f-1,c-1)+ pas(f-1,c));
        }
