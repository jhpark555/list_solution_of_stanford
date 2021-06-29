#include <stdio.h>
#include <stdlib.h>

int max(int a[],int n)
{
   int i,j,max=-1;

   for( i=0; i<n;i ++)
   {
     if(a[i]> max) max=a[i] ;
   }
   printf("Max=%d ",max);
  return max;
}

void maxSumSubarray(int arr[],int l,int r)
{
  int i,j,k;
  int sum=0;

  for( i =0; i <r ; i++ )
  {
  //  sum=0;
   for ( j=i; j < r; j++)
   {
     printf("(");
     sum +=max(&arr[i],j-i+1);
     printf("%d ",sum);
     printf(")");
   }
   printf("sum=%d \n",sum);
 }
}
int main()
{
  int arr[]= {1,3,1,7};
  int n= sizeof(arr)/sizeof(arr[0]);
  int l=0,r=n;

//  buildMaxTree(arr,n-1,0,arr);

  maxSumSubarray(arr,l,r);

  return 0;
}
