#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool arePermutation(int a[],int b[],int n,int m)
{
  int sum1=0,sum2=0,mul1=1,mul2=1;
  int i;

  for(i=0;i<n;i++) {

    sum1 +=a[i];
    mul1 *=a[i];
  }
  for(i=0;i<m;i++){
    sum2 +=b[i];
    mul2 *=b[i];
  }
  //printf("sum1==%d %d mul1=%d %d \n",sum1,sum2,mul1,mul2);
  return ((sum1==sum2)&&(mul1==mul2));

}
int main()
{
  int arr1[]={2,1,3,5,4,3,2};
  int arr2[]={3,2,2,4,5,3,1};

  int n= sizeof(arr1)/sizeof(arr1[0]);
  int m =sizeof(arr2)/sizeof(arr2[0]);

  int r=arePermutation(arr1,arr2,n,m);

  if(r) printf("Yes");
  else printf("No");
}
