#include <stdio.h>
#include <stdlib.h>

void maxTwo(int arr[],int n,int *ret)
{
   int i,j,k;
   int max=0;
   int diff;

   for(i =0;i <n;i++)
   for(j=i+1;j<n;j++)
   {

      diff=arr[j]-arr[i];
      if( diff > max){
        //printf("%d \n",diff);
         max=diff;
         ret[0]=arr[i]; ret[1]=arr[j];
       }

   }
}
int main()
{
   int arr[]={2,3,10,6,4,8,1};
  //int arr[]={7, 9, 5, 6, 3, 2};
   int n= sizeof(arr)/sizeof(arr[0]);
   int ret[2];
   maxTwo(arr,n,ret);
   printf("%d %d \n",ret[0],ret[1]);

}
