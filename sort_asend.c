#include <stdio.h>

int main()
{
    int arr[]={10, -1 ,0, 4, 2 ,100 ,15 ,20 ,24 ,-5};

    int *src;
    int size = sizeof(arr)/sizeof(arr[0]);

    int i,j,temp;

    for(i=0;i<size;i++)
     for(j=0;j<size-i-1;j++)
      if( arr[j]> arr[j+1])   // asending order
      {
  #if 0
        temp=arr[j];
        arr[j]=arr[j+1];
       arr[j+1]=temp;
  #else
      arr[j] ^=arr[j+1];
      arr[j+1] ^=arr[j];
      arr[j] ^=arr[j+1];
  #endif
      }
   for(i=0;i<size;i++) printf("%d ",arr[i]);
    return 0;
}
