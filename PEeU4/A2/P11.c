#include<stdio.h>
int main(){
  int arre[4][4];
  int fil,col,n=1,i,j;
        for(i=6;i>=0;i--){
         for(fil=3;fil>=0;fil--){
          for(col=3;col>=0;col--){
        if (fil+col==i){
         arre[fil][col]=n++;
        }
        }
        }
        }
        for(fil=0;fil<4;fil++){
         for(col=0;col<4;col++){
          printf("%3d",arre[fil][col]);
        }
        printf("\n");
        }
        return 0;
        }
