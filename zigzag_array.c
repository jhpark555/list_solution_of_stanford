//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define swap( a ,b )  (a^=b^=a^=b)
#define GAP 2

int main()
{
//  int arr[]= {1, 2, 3, 4, 5, 6, 7};
int arr[]={ 9, 6, 8, 3, 7 };
  int n=sizeof(arr)/sizeof(arr[0]);
  int i,k;


for(k=0;k<n;k+=GAP)
{
    int mid=k+1;
    if(arr[mid] < arr[mid-1] )
    {
      swap(arr[mid],arr[mid-1]);
    }
    if(arr[mid]<arr[mid+1])
    {
      swap(arr[mid],arr[mid+1]);
    }

}

for(i=0;i<n;i++) printf("%d ",arr[i]);
  return 0;
}
