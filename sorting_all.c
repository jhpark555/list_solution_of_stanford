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

void insertion_sort(int arr[],int n)
{
  int i,j,temp;
  for(i=1;i<n;i++)
  {
     temp=arr[i];
     j=i-1;
     while(temp<arr[j] && j>=0)
     {
       arr[j+1]=arr[j];
       j--;
     }
     arr[j+1]=temp;
  }
}

void merge(int arr[],int beg,int mid,int end)
{
  int i=beg,j=mid+1,index=beg,size=end-beg+2, temp[size],k;
  while(i<mid && j<=end)
  {
    if(arr[i]<arr[j])
    {
      temp[index]=arr[i];
      i++;
    }
    else
    {
      temp[index]=arr[j];
      j++;
    }
    index++;
  }
  if(i>mid)
  {
    while(j<=end)
    {
      temp[index]=arr[j];
      j++;
      index++;
    }
  }
  else
  {
    while(i<=mid)
    {
      temp[index]=arr[i];
      i++;
      index++;
    }
  }
  for(k=beg;k<index;k++)
  arr[k]=temp[k];
}
void merge_sort(int arr[],int beg,int end)
{
  int mid;
  if(beg<end)
  {
    mid=(beg+end)/2;
    merge_sort(arr,beg,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,beg,mid,end);
  }
}
int main()
{
 int arr[]={11, 12, 21, 22, 25, 12, 3};
 int n=sizeof(arr)/sizeof(arr[0]);
 int i;

 //selection_sort(arr,n);
 //insertion_sort(arr,n);
 merge_sort(arr,0,n);

  for(i=0;i<n;i++) printf("%d ",arr[i]);


  return 0;
}
