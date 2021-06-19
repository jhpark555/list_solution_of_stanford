#include<stdio.h>
#include<stdlib.h>

#define swap(a,b)  a^=b^=a^=b

int main()
{
   int arr[]={1,4,2,-1,6,5};
  //int arr[]={1,2,3,4};
   int  n= sizeof(arr)/sizeof(arr[0]);

   int i,j,temp;

   for(i=0;i<n;i++) for(j=0;j<n-i-1;j++)
   {
     if(arr[j]>arr[j+1]) {
       swap(arr[j],arr[j+1]);
     }
   }
   int this=0;
   for(i=0;i<n;i++)
   {
     if(arr[i+1]-arr[i]>1 && arr[i]>0 ){
        this=arr[i]+1; break;
     }
   }
printf("**this =%d \n",this);
//  for(i=0;i<n;i++) printf("%d ",arr[i]);
}
