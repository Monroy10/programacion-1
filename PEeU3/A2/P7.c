#include <stdio.h>
int main (){
int a=0, b=1, c,d,N,i;
	printf("¿Hasta que termino quiere de la serie de Fibonnaci?  ");
	scanf("%d", &N);
	if (N==1)
	printf("El primer termino es %d\n",a);

	if (N==2) 
	printf("Los terminos son %d y %d\n",a,b);

	if (N>2){
	printf("Los terminos son %d,%d",a,b);
	for (i=2; i<N; i++){
	c=a+b;
	a=b;
	b=c;
	printf(",%d",c);
	}
	printf("\n");
	}
return 0;
}
