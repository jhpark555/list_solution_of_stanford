#include <stdio.h>

void initialize(int ***A, int r)
{
  int i,j;
   *A = (int **)malloc(sizeof(int *)*r);
   for(i = 0; i< r; i++) {
            (*A)[i] = 10*i;
   }

}
int main()
{
    int **A;
    int i, r=10;

    initialize(&A, r);

    for(i=0;i<r;i++) printf("%d ",A[i]);
}
