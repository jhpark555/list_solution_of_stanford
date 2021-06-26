
#include <stdio.h>
#include <stdlib.h>

int *findDuplicate(int arr[],int n)
{
  int ret[2];
  int i,j,k=0;

  for(i=0;i<n;i++)
  for(j=i+1;j<=n;j++)
  {
  //  printf("%d %d =%d \n",arr[i],arr[j],arr[i]^arr[j]);
    if(!(arr[i]^arr[j])){    // if same value , then XOR is '0'
      ret[k++]=arr[i];
    }
  }
  return ret;

}
int main()
{
  int arr[]={4,3,6,5,2,4,1,1};
  int n=8;

  int *p;

  p= findDuplicate(arr,n);

printf("%d %d \n",p[0],p[1]);

}
