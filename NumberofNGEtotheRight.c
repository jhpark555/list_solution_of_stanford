
// https://www.geeksforgeeks.org/number-nges-right/

#include <stdio.h>
#include <stdlib.h>

int *NextFreq( int arr[],int n,int l,int r)
{
  int i,j,max=-1;
  int count=0;
  static int ret[2];
  int *pret=ret;

   for( i=l+1 ; i< n;i++)
   {
     if(arr[i] > arr[l]){
        count++;
        ret[0]=count;
     }
   }
   count=0;
   for(i=r+1;i < n;i++)
   {
     if(arr[i]> arr[r]) {
       count++;
       ret[1]=count;
     }
   }
   return pret;
}
int main()
{
 int arr[] = {3,4,2,7,5,8,10,6};
 int n=sizeof(arr)/sizeof(arr[0]);
 int i;
 int l=0,r=5;
 int *ret=NextFreq(arr,n,l,r);

 for(i=0;i<2;i++) printf("%d ",ret[i]);
}
