#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a>b ? a:b)

int maxProfit(int arr[],int start, int end)
{
  int i,j;
  int profit=0;

  for(i=start; i<end; i++)
  {
    for( j=i+1;j<=end;j++)
    {
      if(arr[j] > arr[i])
      {
        int curr_profit = arr[j]-arr[i] +maxProfit(arr,start,i-1) +maxProfit(arr,j+1,end);
        profit=max(profit,curr_profit);
      }
    }
  }
  return profit;
}

int main()
{
  int arr[]={100,180,260,310,40,535,695};
  int n=sizeof(arr)/sizeof(arr[0]);

  printf("Max=%d \n",maxProfit(arr,0,n-1));

}
