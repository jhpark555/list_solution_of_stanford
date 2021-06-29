//Kadane's algorithm for maximum sub array calclation

#include <stdio.h>
#include <stdlib.h>

int maxSubArraySum(int arr[], int n)
{
   int max=-1;
   int i;
   int sum =0;

   for(i=0;i< n; i++)
   {
      sum +=arr[i];
      if( sum <0 ) sum =0;
      else if( sum> max ) max=sum;
   }
  return max;
}
int main()
{
   int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
  // int a[]={-2, 1, -3, 4, -1, 2, 1, -5, 4};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
  printf("%d ",max_sum);
   return 0;
}
