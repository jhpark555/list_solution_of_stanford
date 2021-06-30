#include <stdio.h>
#include <stdlib.h>

int maxIJ(int arr[], int n)
{
  int i,j;
  int max=-1;
  int diff,gap;
  int r,l;

  for( i= 0; i< n; i++)
  {
    for( j=i+1; j< n; j++)
    {
      diff = arr[j]-arr[i] ;
      if( diff >0)
      {
        gap=j-i;
          //printf("%d %d = %d\n",j,i,gap);
        if(gap > max) max=gap;
      }
    }
  }
  return (max);
}

int main()
{
 int arr[]={34,8,10,3,2,80,30,33,1};
//int arr[]={9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
//int arr[]={1, 2, 3, 4, 5, 6};
//int arr[]={6, 5, 4, 3, 2, 1};
  int n= sizeof(arr)/sizeof(arr[0]);

  int r= maxIJ(arr,n);
  printf("Max= %d ", r);
}
