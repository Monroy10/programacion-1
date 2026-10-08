#include<stdio.h>
int main(){
int max,min,N,n;
float p;
int i=1;
int k=0;
int s=0;
printf("Ingrese el numero de datos:");
scanf("%d",&N);
do{
printf("Ingrese un valor:");
scanf("%d",&n);
s=s+n;
if (i==1){
max=n;
min=n;
}
else{
if (n>max)
max=n;
if (n<min)
max=n;
}
i++;
}while(i<=N);
p=(float)s/N;
printf("El numero maximo es %d, el minimo es %d y el promedio es %.2f \n",max,min,p);
return 0;
}
