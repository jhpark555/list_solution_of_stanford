#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int arr[]={0, -3, 5, -4, -2, 3, 1, 0};
  int index;
  int i,j;
  int sum1,sum2;
  int n=sizeof(arr)/sizeof(arr[0]);

  for(i=0;i<n;i++)
  {
    sum1=0; sum2=0;
    for(j=0;j<i;j++)  {
      sum1 +=arr[j];
    }
    for(j=i+1;j<n;j++){
      sum2+=arr[j];
    }

    if(sum1==sum2) printf("*equ=%d \n",i);
  }

  return 0;
}
