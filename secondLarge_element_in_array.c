
// Next max element in array . start form the left mot and end right most.

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[]={2,7,3,5,4,6,8};
//  int arr[]={5,4,3,2,1};
  int n= sizeof(arr)/sizeof(arr[0]);
  int i,j;
  int max=-1;

  //for(i=0;i<n;i++) printf("%d ", arr[i]);

  for(i =0;i< n; i++)
  {
    max=-1;
     for(j=i+1 ; j< n;j++)
     {

       if(arr[j]>=arr[i]){
          max=arr[j];       // from i+1 to last find max value.
          //printf("%d \n",arr[i]);
           break;       // break inner loop
          }

     }
     printf("%d ",max);
  }

}
