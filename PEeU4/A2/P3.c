#include<stdio.h>
#define max 4
int main(){
        int fil,col,n=1,i,j;
        int arre[max][max];
        for(fil=0;fil<max;fil++){

	 if (fil%2==0) {
           for(col=0;col<max;col++){
            arre[fil][col]=n++;
         }
	}
	 else {
	  for(col=3;col>=0;col--){
           arre[fil][col]=n++;
         }	

	 }
        }

        for(fil=0;fil<max;fil++){
         for(col=0;col<max;col++){
          printf("%3d",arre[fil][col]);
        }
        printf("\n");
        }
        return 0;
        }
