#include <stdio.h>
#include <stdlib.h>


void printincreasingorder(int arr[],int low,int high)
{
  if(low>high)  return;

  printincreasingorder(arr,low*2+1,high);

  printf("%d ",arr[low]);

  printincreasingorder(arr,low*2+2,high);

}
int main()
{
  int arr[]={15,10,20,8,12,18,25};
  int n=sizeof(arr)/sizeof(arr[0]);

  printincreasingorder(arr,0,n-1);

  return 0;

}
