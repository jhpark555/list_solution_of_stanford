#include<stdio.h>
#include<stdlib.h>

void printSUbarray(int arr[],int start,int end)
{
  int i;
  printf("[");

  for(i=start;i<=end;i++)
   printf("%d ",arr[i]);

   printf("]");
}

void printAllsubarray(int arr[],int n)
{
  int i,j;
  for(i=0;i<n;i++)
   for(j=i;j<n;j++)
    printSUbarray(arr,i,j);
}
int main()
{
  int arr[] = { 1, 2, 3, 4, 5 };
   int n = sizeof(arr)/sizeof(arr[0]);

   printAllsubarray(arr, n);
return 0;

}
