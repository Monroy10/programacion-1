#include<stdio.h>
int main(){
int N,n;
int i;
int sum=0;
printf("Introduce la cantidad de numeros a sumar:");
scanf("%d",&N);
for(i=1;i<=N;i++){
printf("Ingrese un valor:");
scanf("%d",&n);
sum=sum+n;
}
printf("la suma total es:%d\n",sum);
return 0;
}
