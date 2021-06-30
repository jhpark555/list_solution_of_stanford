#include <stdio.h>
#include <stdlib.h>

#define GAP 2
#define EVEN 0
#define ODD 1
int main()
{
  int arr[]= { 0,1,2,3,4,5,6,7,8,9,10};
  int n=sizeof(arr)/sizeof(arr[0]);

  int i,j;
  int count=0;

 for( i=EVEN,j=EVEN ; j<n ; i++,j +=GAP )
  {
    arr[i]=arr[j];
    count++;
  }
  for(i=0;i<count;i++) printf("%d ",arr[i]);
}
