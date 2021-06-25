#include <stdio.h>

int main()
{
    int i;
    int arr[]={1,2,3,4,5,6,7,8};
    int *slow,*fast;
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=0;

    slow=arr;fast=arr;

    while(count++ <n)
    {
        *slow=*fast;
        slow++;
        fast +=2;
    }

     for(i=0;i<n/2;i++) printf("%d ",arr[i]);



    //for ( i=0,j=0;i<n;i+=2,j++)
    //  arr[j]=arr[i];

    //for(i=0;i<n/2;i++) printf("%d ",arr[i]);


    return 0;
}
