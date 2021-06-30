#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[]={10,15,3,7};
  int n=sizeof(arr)/sizeof(arr[0]);
  int k=17;

  int i,j;

  for( i=0; i<n; i++)
  for(j=i+1;j<n;j++)
   {
    if(  arr[i]+arr[j] ==k ) {
      printf("%d %d \n",arr[i],arr[j]);
      break;
    }
   }

}
