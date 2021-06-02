#include <stdio.h>

int main()
{
    int arr[]={10, 20, 30, 40 ,50 ,60 ,70 ,80 ,90 ,100};
    int arr1[10];
    int *src;
    int *des;
    int i,j;

    int n=sizeof(arr)/sizeof(arr[0]);
  //  printf("**%d \n",n);
    src=arr+n-1;
    des=arr1;
    int temp;
#if 0 //method 1 swap
   for(i=0,j=n-1;j>=0;i++,j--){
    //  arr1[i]=arr[j];
    *des=*src;
      // printf("%d ",arr[j]);
      des++; src--;
    }
#else
   int *right=&arr[n-1];
   int *left=arr;

   for(i=0,j=n;i<j;i++,j--)
   {
     *left ^=*right;
     *right ^=*left;
     *left ^=*right;
     right--;left++;
   }
#endif
   for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;
}
