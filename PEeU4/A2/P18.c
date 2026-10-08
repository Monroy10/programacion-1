#include<stdio.h>
int main () {
        int fil_in=1,fil_f=2,col_in=2,col_f=1,n=1,i,j;
        int arre[4][4];
        while (n<=16) {
                for (i=fil_in;i<=fil_f && n<=16;i++) {
                        arre[i][col_in]=n++;
                }

                for (j=col_in-1;j>=col_f && n<=16;j--) {
                        arre[fil_f][j]=n++;
                }

                for (i=fil_f-1;i>=fil_in-1 && n<=16;i--) {
                        arre[i][col_f]=n++;
                }

                for (j=col_f+1;j>=col_in && n<=16;j--) {
                        arre[fil_in-1][j]=n++;
                }

                fil_in--;
                fil_f++;
                col_in++;
                col_f--;

        }

        for (i=0;i<4;i++){
                for (j=0;j<4;j++){
                        printf("%3d",arre[i][j]);
                }
                printf("\n");
        }
        return 0;

}
