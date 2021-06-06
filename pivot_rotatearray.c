#include<stdio.h>

void swap( int *a,int *b)
{
  *a^=*b;
  *b^=*a;
  *a^=*b;

}

//1.  reverse from 0 to pivot, pivot to n-1
//2.  reverse 0 to n-1
//

int main()
{

  int arr[]={2,4,3,5,6,7,8};
  int n=sizeof(arr)/sizeof(arr[0]);

  int i,j;
  int pivot=2;

//  for(i=0,j=n-1; i<j; i++,j--)
//  {
//     swap(&arr[i],&arr[j]);
//  }
   for(i=0,j=pivot-1 ;i<j;i++,j--)   swap(&arr[i],&arr[j]);
   for(i=pivot,j=n-1;i<j;i++,j--) swap(&arr[i],&arr[j]);
   for(i=0,j=n-1;i<j;i++,j--) swap(&arr[i],&arr[j]);

  for(i=0;i<n;i++)
  printf("%d ",arr[i]);
}
