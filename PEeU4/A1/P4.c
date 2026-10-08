#include<stdio.h>
int main() {
        int n[10]={0},i,N,s,p,r,M,m,k,j;
        for(i=0,s=0,r=0,p=1;i<10;i++){
          printf("Introduce un valor: ");
           scanf("%d",&n[i]);
        s=s+n[i];
        p=p*n[i];
        r=r-n[i];
        if(i==0) {
         M=n[0];
         m=n[0];
        }
        else {
         if (n[i]>M){
          M=n[i];
          k=i;
        }
         if (n[i]<m){
          m=n[i];
          j=i;
        }
        }
        }
        printf("El mayor es %d y esta en la pasición %d\n",M,k+1);
        printf("El menor es %d y esta en la pasición %d\n",m,j+1);
        printf("La suma es %d, la resta es %d y la multiplicacón es %d\n",s,r,p);
        return 0;
}
