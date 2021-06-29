#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 8
int main()
{
  int arr[]= { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
  int n=sizeof(arr)/sizeof(arr[0]);
  int i,j,k;
  int sum=0;
  int max=0,maxmax=-1;

  for(i=0;i<n;i++) for(j=i;j<n;j++)
  {
    sum=0;
    printf("(");
    for(k=i;k<=j;k++){
      printf("%d->",arr[k]);
      sum +=arr[k];
    }
    printf(")\n");
    if(sum==MAX){
        //printf("\nsubarray sum %d : ",MAX);
        max=j-i+1;       // how many element is there
      //  printf("max=%d \n",max);
        if(max>maxmax) maxmax=max;
      //  for(k=i;k<=j;k++) printf("%d ",arr[k]);
    }

  }
printf("**max=%d \n",maxmax);
}
