#include <stdio.h>
#include <stdlib.h>

void findPrevSmaller(int arr[],int n,int arr2[])
{
   int i,j;

   for ( i=0; i< n ;  i++)
   {
    arr2[i]=-1;
    for(j=i-1 ; j>=0; j--)
    {
       if(arr[j] < arr[i] ) {
         arr2[i]=arr[j];
         break;
       }
    }
  // printf("%d ",arr2[i]);
  }
}


int main()
{
  int arr[]={2,5,3,7,8,1,9};
  int n= sizeof(arr)/sizeof(arr[0]);
  int arr2[n];
  int i;

  findPrevSmaller(arr,n,arr2);
for(i=0;i<n;i++) printf("%d ",arr2[i]);
  return 0;

}
