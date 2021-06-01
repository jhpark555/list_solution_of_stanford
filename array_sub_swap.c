#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[]={3,5,2,6,7,4,50,49,88};
  int size=sizeof(arr)/sizeof(arr[0]);
  int i,j;
  int temp;

for(i=0;i<size;i++)    // arr sorting assending order
 for(j=0;j<size-i-1;j++)
  if(arr[j]>arr[j+1])
  {
    temp=arr[j+1];
    arr[j+1]=arr[j];
    arr[j]=temp;
  }

for(i=0;i<size;i++)
printf("%d ",arr[i]);
printf("\n#####################\n");

for(i=0,j=size-1;i<j;i++,j--)     // swap array
{
  temp=arr[j];
  arr[j]=arr[i];
  arr[i]=temp;

}
for(i=0;i<size;i++)
printf("%d ",arr[i]);

printf("\n#####################\n");

int k=2;      // sub array is k=2, swap by k from the array
int x=0;

for(x=0 ; x<size ; x+=k )
for(i=x,j=k+x-1;i<j;i++,j--)
{
  temp=arr[j];
  arr[j]=arr[i];
  arr[i]=temp;
}

for(i=0;i<size;i++)
printf("%d ",arr[i]);
printf("\n#####################\n");
return 0;
}
