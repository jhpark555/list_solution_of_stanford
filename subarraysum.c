#include<stdio.h>
#include<stdlib.h>

void SUbarraySum(int arr[],int start,int end,int sum)
{
  int i,j;
  //int sum=0;

  for(i=start;i<=end;i++)
  {
  // printf("%d ",arr[i]);
   sum += arr[i];
  }

if(sum==0){
    printf("\nsubarray sum 0 : ");
    for(i=start;i<=end;i++) printf("%d ",arr[i]);
  }
}

void printAllsubarray(int arr[],int n,int sum)
{
  int i,j;
  for(i=0;i<n;i++)
   for(j=i;j<n;j++)
    SUbarraySum(arr,i,j,sum);
}
int main()
{
  //int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
  int arr[]={ 4, 2, -3, -1, 0, 4 };
  int n = sizeof(arr)/sizeof(arr[0]);
  int sum=0;

   printAllsubarray(arr, n,sum);
return 0;

}
