#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) ( a^=b^=a^=b)

void sortarr(int arr[],int n)
{
  int i,j;

  for(i=0;i<n;i++)
  for(j=0;j<n-i-1;j++)
  {
    if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
  }
}

int findsubArray(int arr[],int n)
{
  int i,j,k;
  int l;
  int max=-1;
  int count=0;

  for(i=0;i<n;i++)
  for(j=i;j<n;j++)
  {
    printf("(");
    count=0;
    for(k=i;k<=j;k++)
    {
      count++;
      printf("%d ",arr[k]);
      if(arr[k+1]>arr[k]+1){
        break;
      }

    }
    printf(")");
  if(count > max ) max= count;
  //printf("*max=%d \n",max);
  }

  return max;

}
int findLongestSubs(int arr[],int n)
{
  sortarr(arr,n);
  int i;
  findsubArray(arr,n);

}
int main()
{
  int arr[]={2,0,6,1,5,3,7};
  int n=sizeof(arr)/sizeof(arr[0]);
  int i;

int r=  findLongestSubs(arr,n);
printf("Max length= %d \n",r);
}
