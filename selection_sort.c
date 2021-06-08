#include<stdio.h>


int smallest(int arr[],int k,int n)
{
  int i,small=arr[k];
  int pos=k;
  for(i=k+1;i<n;i++)
  {
    if(arr[i]<small)
     small=arr[i];
     pos=i;
  }
  return pos;
}
#define SWAP(a,b)  ( a^=b^=a^=b)
void selection_sort(int arr[],int n)
{
  int k,pos,temp;

  for(k=0;k<n;k++)
  {
    pos=smallest(arr,k,n);
    SWAP(arr[k],arr[pos]);
  }
}

int main()
{
 int arr[]={11, 12, 21, 22, 25, 12, 3};
 int n=sizeof(arr)/sizeof(arr[0]);
 int i;

 selection_sort(arr,n);

  for(i=0;i<n;i++) printf("%d ",arr[i]);


  return 0;
}
