//A Simple Solution is to first sort the array.
// After sorting, exclude the first element,
//swap the remaining elements in pairs.
//(i.e. keep arr[0] as it is, swap arr[1] and arr[2],
//swap arr[3] and arr[4], and so on).


#include<stdio.h>
void swap(int *a,int *b)
{
  *a^=*b;
  *b^=*a;
  *a^=*b;
}
int main()
{
 int arr[] = {4, 3, 7, 8, 6, 2, 1} ;
 int i, j,n=sizeof(arr)/sizeof(arr[0]);

 for(i=0;i<n;i++)
 for(j=0;j<n-i-1;j++)
  {
    if(arr[j]>arr[j+1])
    {
      swap(&arr[j],&arr[j+1]);
    }
  }
  for(i=0;i<n;i++) printf("%d ",arr[i]);

   printf("\n Zig Zag array: ");
  for(i=1;i<n-1;i+=2)
   swap(&arr[i],&arr[i+1]);

for(i=0;i<n;i++) printf("%d ",arr[i]);


}
