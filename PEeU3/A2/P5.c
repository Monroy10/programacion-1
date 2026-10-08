#include <stdio.h>
int main(){
float x,y;
int c1=0,c2=0,c3=0,c4=0;
do{
printf("Ingrese las coordenadas (x y): ");
scanf("%f %f", &x, &y);
if (x>0 && y>0)
c1++;
if (x<0 && y>0)
c2++;
if (x<0 && y<0)
c3++;
if (x>0 && y<0)
c4++;
}while(x!=0 && y!=0);
printf("\n--- Conteo por Cuadrante ---\n");
printf("Cuadrante I:   %d\n", c1);
printf("Cuadrante II:  %d\n", c2);
printf("Cuadrante III: %d\n", c3);
printf("Cuadrante IV:  %d\n", c4);
return 0;
}
