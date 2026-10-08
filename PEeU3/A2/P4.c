#include<stdio.h>
int main(){
int max,n;
int k=0;
int i=0;
do{
printf("Ingrese un valor:");
scanf("%d",&n);
if (i==0)
max=n;
else{
if (n>=max){
if (n==max)
k++;
else
max=n;
}
}
i++;
}while(n!=0);
printf("El numero maximo es %d y se repitio %d veces\n",max,k);
return 0;
}
