#include<stdio.h>
int main(){
int N,n;
int i;
int sum=0;
printf("Introduce la cantidad de numeros a sumar:");
scanf("%d",&N);
for(i=1,n=1;i<=N;i++){
sum=sum+3*n;
n++;
}
printf("la suma total es:%d\n",sum);
return 0;
}
