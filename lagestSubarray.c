#include <stdio.h>
#include <stdlib.h>

void subarraysum(int arr[],int start,int end,int *sum)
{
  int i;

//printf("(");
//for(i=start;i<=end;i++) printf("%d ",arr[i]);
//printf(")");

 *sum=0;    // very important it should be reset here
  for(i=start; i<=end; i++)
   *sum +=arr[i];
}

int maxSubArraySum(int arr[],int n)
{
  int i,j;
  int k;
  int sum;
  int max=-1;

  for(i=0 ; i < n ; i ++ )
  {
      for(j =i ; j< n ; j ++ )
      {
         subarraysum(arr,i,j,&sum);
           //printf("sum=%d \n",sum);
         if(sum>max) {
            max=sum;
            printf("(");
            for(k=i;k<=j;k++) printf("%d ",arr[k]); printf(")\n");
          }
      }
  }
  printf("max=%d \n",max);
}

int main()
{
  int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, n);
    return 0;
}
