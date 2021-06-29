#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 8
int main()
{
//  int arr[]= { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
//int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
int arr[]={ 5, 6, -5, 5, 3, 5, 3, -2, 0 };
  int n=sizeof(arr)/sizeof(arr[0]);
  int i,j,k;
  int sum=0;
  int max=0,maxmax=-1;

  for(i=0;i<n;i++) for(j=i;j<n;j++)
  {
    sum=0;
    for(k=i;k<=j;k++){
    //  printf("%d->",arr[k]);
    printf("(%d %d )\n",i,j);
      sum +=arr[k];

    }
    if(sum==MAX){
        printf("\nsubarray sum %d : ",MAX);
        max=j-i+1;
      //  printf("max=%d \n",max);
        if(max>maxmax) maxmax=max;
        for(k=i;k<=j;k++) printf("%d ",arr[k]);
    }

  }
printf("\n**max=%d \n",maxmax);
}
