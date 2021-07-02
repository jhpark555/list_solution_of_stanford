#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) (a^=b^=a^=b)

#if 0
int main()
{
  int arr[]={1,4,2,-1,6,5};
  int n =sizeof(arr)/sizeof(arr[0]);
  int i,j;
  int count=0;
  int missing=-1;
  int min=100;


  for(i=0;i<n;i++) for(j=0;j<n-i-1;j++)     // sort
  {
    if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
  }

  for(i=0;i<n;i++) {
    if(arr[i] < min) min=arr[i];      // what is min
  }
  printf("min=%d \n",min);

  i=0;
  if(min<0) i=i-min;
  for(j=i;j<n;j++)       //from the min , what value is missing
  {
    if(j!=arr[j]) { missing= j; break;}
  }
  //for(j=i;j<n;j++) printf("%d ",arr[j]);
  printf("Missing= %d \n",missing);

}
#else

int findSmallestMissing(int arr[],int n)
{
  int aux[n+1];
  int i;

  for(i=0;i<n+1;i++) {
    aux[i]=0;
  }
  for(i=0;i<n;i++) {
     // ignore all non-positive elements and elements greater than `n`
    if(arr[i]>0 && arr[i]<=n) {
      aux[arr[i]]=1;
      printf("(%d %d) ",arr[i],aux[arr[i]]);
    }

  }
  printf("\n");
 // check for the smallest missing number between 1 and `n`
  for(i=1;i<=n;i++)
  {
    printf("%d ",aux[i]);
    if(!aux[i]) return i;
  }

  return n+1;
}




int main()
{
  int arr[]={1,4,2,-1,6,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  int r= findSmallestMissing(arr,n);
  printf("**Missing =%d \n",r);
  return 0;

}

#endif
