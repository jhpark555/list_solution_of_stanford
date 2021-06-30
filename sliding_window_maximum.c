#include <stdio.h>
#include <stdlib.h>

int max(int a[],int n)
{
  int i, max=-1;

  for(i=0; i<n ;i++)
  {
    printf("%d ",a[i]);
    if ( a[i] > max ) max=a[i];
  }
  printf("\n");
  return max;
}

int *slidingWindow(int arr[],int n,int k)
{
  int i,j,x=0;
  static int ret[20];

  for(i=0; i <n-k; i+=k+1)
   for( j=i; j<=k+i; j++)
   {
    // printf("***%d  %d\n",arr[j],arr[n-2]);
     if(arr[j]==arr[n-2]) break;
      ret[x++]=max(&arr[j],k);
   }

  return ret;
}

int main()
{
  //int arr[]= { 1,2,3,1,4,5,2,3,6};
//  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int arr[]={9, 7, 2, 4, 6, 8, 2, 1, 5};
//int arr[] = {6, 7, 5, 2, 1, 7, 2, 1, 10};
//int  arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
  int n = sizeof(arr)/sizeof(arr[0]);
  //int k=3;
//  int k=4;
int k=3;
  int i;

int *ret=  slidingWindow(arr,n,k);

for(i=0; ret[i]!=0 ;i++) printf("%d ",ret[i]);

return 0;
}
