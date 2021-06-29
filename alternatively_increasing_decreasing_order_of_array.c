#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) ( a^=b^=a^=b)

void inc_arr(int *arr,int n)
{
  int i,j;

  for(i=0;i<n;i++) for(j=0;j<n-i-1;j++)
  {
    if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
  }

}

void Zarr(int *arr, int n)
{
   int l=0, r=n-1, flag=0,i;

   //start wit h2 elements
   int k=2;

   while(l<= r)
   {
    // printf("k=%d \n",k);
     //flag 0 means increaing order
     if(flag==0){
       for( i=l; i< l+k && i <=r; i++)
        printf("%d ",arr[i]);
        flag=1;
        l=i;
     }   // decreasing order
     else
     {
       for(i=r;i>r-k && i>=l; i--)
         printf("%d ",arr[i]);
         flag=0;
         r=i;
     }
     k++;
   }
   //printf("\n");
}
int main()
{
  int arr[]={2,6,2,4,0,1,4,8,2,0,0,5};
//  int arr[]={1, 2, 3, 4, 5, 6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int i;

  inc_arr(arr,n);
  for(i=0;i<n;i++) printf("%d ",arr[i]); printf("\n");
  Zarr(arr,n);

  //for(i=0;i<n;i++) printf("%d ",arr[i]);
}
