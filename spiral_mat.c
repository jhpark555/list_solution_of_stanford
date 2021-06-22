#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 5
#define N 5
#define max(a,b) ( a>b?  a:b )

void printMatrix(int mat[M][N])
{
  int i,j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++) {
            printf("%d ",mat[i][j] );
        }
        printf("\n");
    }
      printf("\n");
  }

int main()
{
  int mat[M][N] =
     {
       { 5, 3, 0, 8, 1 },
           { 8, 1, 8, 4, 7 },
           { 2, 6, 5, 0, 3 },
           { 1, 4, 2, 7, 9 },
           { 0, 1, 3, 6, 5 }
     };
int i,j,k;
int row,col;
int x[M],y[N];
int xs=0,ys=0;
int size;

for(i=0;i<M;i++) for(j=0;j<N;j++)
{
  if(mat[i][j]==0) {
    x[xs++]=i;
    y[ys++]=j;
  }
}
i=j=0;
  while(i<xs || j<ys){
    row=x[i]; col=y[j];
  //  printf("*%d %d \n",row,col);
    for(k=0;k<M;k++)
    mat[row][k]=0;
    for(k=0;k<N;k++)
    mat[k][col]=0;
    i++;j++;
 }

    printMatrix(mat);
  return 0;
}
