
#include <stdio.h>
#include <stdlib.h>

void findPair(int arr[],int n,int sum)
{
    int *curr,*prev=arr;

    for(prev;prev< arr+n-1; prev++)
    for(curr=prev+1 ;curr < arr+n; curr++)
    {
      if(*prev+*curr == sum){
        printf("%d %d\n",*prev,*curr);
      //   return;
       }
    }


}
int main()
{
  int arr[] = { 8, 7, 2, 5, 3, 1 };
  int sum = 15;

  int n = sizeof(arr)/sizeof(arr[0]);

  findPair(arr, n, sum);
}
