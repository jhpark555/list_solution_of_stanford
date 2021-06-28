
#include <stdio.h>
#include <stdlib.h>

void findPair(int arr[],int n,int sum)
{
    int *curr,*prev=arr,*next;

    for(prev;prev< prev+n-1; prev++)
    for(curr=prev+1 ;curr < arr+n; curr++)
    for(next=curr+1 ;next < arr+n; next++)
    {
      if(*prev+*curr+*next == sum){
        printf("%d %d %d\n",*prev,*curr,*next);
       }
    }
}
int main()
{
  int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
  int sum = 8;

  int n = sizeof(arr)/sizeof(arr[0]);

  findPair(arr, n, sum);
}
