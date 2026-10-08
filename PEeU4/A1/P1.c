#include<stdio.h>
int main() {
        int n[100]={0},m,i,j;
        int primo;
n[0]=2;
printf("Posición:%d \t Numero primo:%d \n",1,n[0]);
        for (m=3,i=1;m<=100;m++){
          primo=1;
                for (j=2;j<m;j++){
                  if (m%j==0)
                  primo=0;
}
                   if(primo){
                   n[i]=m;
                   printf("Posición:%d \t Numero primo:%d\n",i+1,n[i]);
                    i++;
}
}
return 0;
}
