#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int isSkewedBST(int arr[],int n)
{
   int min=INT_MIN, max=INT_MAX;
   int i;

   for(i=1;i<n;i++)
   {
     if(arr[i]>min && arr[i]<=max)
     {
        if(arr[i]>arr[i-1]) min=arr[i-1]+1;
        else max=arr[i-1]-1;

        //printf("%d %d \n",min,max);
     }
     else  return 0;
   }
  return 1;
}



int main()
{
  int arr[]={15,30,25,18,20};
  int n=sizeof(arr)/sizeof(arr[0]);

  int isSkewed = isSkewedBST(arr,n);

  if(isSkewed) printf("Yes skewed \n");
  else printf("No not skewed \n");

  return 0;
}
