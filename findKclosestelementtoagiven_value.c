// array중에서 k 숫자만큼 일렬로 된, x만큼의 subarray를 찾는

#include <stdio.h>
#include <stdlib.h>


int *findClosestArr( int arr[],int n, int k, int x)
{
   int abb[n];
   int i,j;
   int min=100;
   int sum=0;
   int start=0;

   for(i=0; i<n ;i++){      //   difference between x and element.
    abb[i]=abs(x-arr[i]);
   }

   for( i=0 ; i< n ; i++)
   {
     if(i+k> n) break;     // if i+k over end , then finish

     sum=0;
     for( j=i ; j<i+k && j< n ; j++ ) {
      //printf("%d %d \n",i,j);
       sum +=abb[j];
     }
     if(sum < min){ min=sum; start=i;}
     //printf("%d %d\n",sum,i);
   }

   printf("Min=%d %d \n",min,start);

   return &arr[start];
 }

int main()
{
  int arr[]={10,12,15,17,18,20,25};
  //int arr[]={2, 3, 4, 5, 6, 7};
  int n=sizeof(arr)/sizeof(arr[0]);
  int i;

  int x=16,k=4;
//int x=8,k=2;

  int *xx = findClosestArr(arr,n,k,x);
 for(i=0;i<k;i++) printf("%d ",xx[i]);
}
