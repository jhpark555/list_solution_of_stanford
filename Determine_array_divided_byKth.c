#include <stdio.h>
#include <stdlib.h>

int *findPairs(int arr[],int n,int k)
{
  int i,j,count=0;
  int visited[n];
//  static int ret[10][2];
  for(i=0;i<n;i++) visited[i]=0;

  static int ret[100];
  for(i=0;i<n;i++)
  {
   if(visited[i]) continue;

    for(j=i+1;j<n;j++)
    {
      if(!visited[j] && (arr[i] +arr[j] )% k ==0) {
      //  ret[i][0]=arr[i];ret[i][1]=arr[j];
      visited[j]=1;
      ret[count++]=arr[i];ret[count++]=arr[j];
      //printf("%d %d\n",ret[i][0],ret[i][1]);
      printf("**%d %d \n",arr[i],arr[j]);
      }
    }
}
//return 1;
return ret;
}

int main()
{
//  int arr[]={3,1,2,6,9,4};
int arr[] = { 2, 9, 4, 1, 3, 5 };
  int n=sizeof(arr)/sizeof(arr[0]);
  int k=6;
  int i;

int *ret= findPairs(arr,n,k);
for(i=0;i< 2*n ;i+=2) printf("(%d %d)\n",ret[i],ret[i+1]);
}
