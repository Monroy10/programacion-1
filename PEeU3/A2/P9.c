#include<stdio.h>
int main() {
	int N,n,i,s,p;
	printf("Ingrsar el total de numeros: ");
	scanf("%d",&N);
	   for (i=1,s=0,p=1;i<=N;i++) {
	printf("Ingrese un valor: "); 
	scanf("%d",&n);
	   if (n%2==0)
  	s=s+n;
	   else
 	p=p*n;
	}
	printf("La suma de pares es %d y el producto de impares es %d\n", s,p);
	return 0;
}
