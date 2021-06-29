#include <stdio.h>

void findNextElement(int arr[],int n)
{
   int i,j;
   int max=-1;

   for( i =0 ;i< n; i++)
   {
      max=-1;
       for( j=i+1; j<n ; j++)
       {

         if(arr[j]>= arr[i] ) {
             max=arr[j];
             break;
        }
       }
          printf("%d ",max);
   }
}

int main()
{
  int arr[]={3,5,2,4};    // we need to think this is circular array
  int n=sizeof(arr)/sizeof(arr[0]);

  findNextElement(arr,n);

return 0;
}
