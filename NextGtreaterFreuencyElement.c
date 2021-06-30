
// https://www.geeksforgeeks.org/next-greater-frequency-element/

#include <stdio.h>
#include <stdlib.h>

int *Max(int arr[],int n)
{
  int i,j,count=0;
  static int ret[100];

  for(i=0;i<n;i++)
  {
     count=0;
    for( j=i+1; j< n;j ++)
    {
      if(arr[j]>arr[i]) count++;
    }
    if(count ==0) count=-1;
    ret[i]=count;
    //printf("%d ",ret[i]);
  }
  //printf("\n");
  return ret;
}

int *NextFreq( int arr[],int n)
{
  int i,j,max=-1;
  int count=0;
  static int ret[100];
  int *pret=ret;

  for(i=0; i< n;i ++)
  {
    count=0;
   for( j=0 ; j< n;j++)
   {
     if(arr[i] == arr[j]){
        count++;
      }
   }
    ret[i]=count;
    //printf("%d ",ret[i]);
  }
//  printf("\n");
  pret=Max(ret,n);
  return pret;
}
int main()
{
// int arr[]={1,1,2,3,4,2,1};
int arr[] = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
 int n=sizeof(arr)/sizeof(arr[0]);
 int i;

 int *ret=NextFreq(arr,n);

 for(i=0;i<n;i++) printf("%d ",ret[i]);
}
