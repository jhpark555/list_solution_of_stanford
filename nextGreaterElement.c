#include <stdio.h>
#include <stdlib.h>

int *NextGE(int  arr[], int n)
{
   int max= -1;
   int i,j;
   static int ret[4];
   int count=0;

   for(i=0;i < n;i++)
   {
     max=-1;
     for(j =i+1; j< n;j++)
     {
       if(arr[j] > arr[i] ){
          max =arr[j];
          break;
        }
     }
    // printf("max;%d \n", max);
     ret[count++]= max;
   }
  return ret;
}
int main()
{

  //int arr[]= { 4,5,2,25};
  //int arr[]= { 13,7,6,12};
  int arr[]={4,5,2,25,10};
  int n=sizeof(arr)/sizeof(arr[0]);
  int *ret;
  int i;


  ret=NextGE(arr,n);
  for(i=0;i<n;i++)
 printf("*%d \n",ret[i]);


}
