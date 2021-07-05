
#include <stdio.h>
#include <stdlib.h>

int countDistinct(int arr[],int n)
{
  int i,j;
  int count=0;
  int array[n];


    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
        if(arr[i]==arr[j]) break;
      }
      if(j==n) {
         array[count++]=arr[i];
         printf("%d ",arr[i]);
       }
    }
  //printf("count=%d \n",count);

  return count;
}

int main()
{
//  int arr[]={10,20,20,10,30,10};
  int arr[] = { 12, 10, 9, 45, 2, 10, 10, 45 };
  int n=sizeof(arr)/sizeof(arr[0]);
  int i,j;

  int r=countDistinct(arr,n);
  printf("Count=%d \n",r);
}
