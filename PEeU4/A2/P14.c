#include<stdio.h>
int main(){
  int arre[4][4];
  int fil_in=0,fil_f=3,col_in=0,col_f=3,n=1,i,j;
       while(n<=16){
	 for(i=fil_in;i<=fil_f && n<=16;i++){
	      arre[i][col_in]=n++;
	    }
	    col_in++;

	 for(j=col_in;j<=col_f && n<=16;j++){
	     arre[fil_f][j]=n++;
          }
	    fil_f--;

	 for(i=fil_f;i>=fil_in && n<=16;i--){
	     arre[i][col_f]=n++;
	  }
	    col_f--;
	 
	 for(j=col_f;j>=col_in && n<=16;j--){
	     arre[fil_in][j]=n++;
	  }
	    fil_in++;
  
  	}
         for(i=0;i<4;i++){
         for(j=0;j<4;j++){
          printf("%3d",arre[i][j]);
        }
        printf("\n");
        }
        return 0;
        }
