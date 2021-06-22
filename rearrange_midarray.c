#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define M 5
#define N 5

void printSpiralOrder(int mat[M][N])
{
  int top=0,bottom=M-1;
  int left=0,right=N-1;
  int i,j;

  while(1)
  {
   if(left>right){ break;}

   //print top row
   for(i= left;i<=right;i++){
     printf("%d ",mat[top][i]);
   }
   top++;
   if(top>bottom) break;
   //print righ colomn
   for(i=top;i<=bottom;i++){
     printf("%d ",mat[i][right]);
   }
   right--;
   //print bottom row
   for(i=right;i>=left;i--){
     printf("%d ",mat[bottom][i]);
   }
   bottom--;

   if(top>bottom) break;
   //print left colomn
   for(i=bottom;i>=top;i--){
     printf("%d ",mat[i][left]);
   }
   left++;


  }

}
int main()
{
  int mat[M][N] =
     {
         { 1, 2, 3, 4, 5},
         {16, 17, 18, 19, 6},
         {15, 24, 25, 20, 7},
         {14, 23, 22, 21, 8},
         {13, 12, 11, 10, 9}
     };

     printSpiralOrder(mat);
  return 0;
}
