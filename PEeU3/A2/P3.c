#include<stdio.h>
int main(){
int n,pos,neg;
int i;
for(i=0,pos=0,neg=0;i<10;i++){
printf("Ingrese el numero %d de 10: ", i + 1);
scanf("%d", &n);
if (n>=0)
pos++;
else
neg++;
}
printf("Son %d positivos y %d negativos\n",pos,neg);
return 0;
}
