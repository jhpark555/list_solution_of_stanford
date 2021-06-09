#include<stdio.h>
void swap(int *a,int *b)
{
  *a^=*b;
  *b^=*a;
  *a^=*b;
}

int findpeak(int arr[],int n)
{
  int i;
  if(n==1) return 0;
  if(arr[0]>=arr[1]) return 0;

  for(i=1;i<n-1;i++)
  {
    if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1])  return i;   // peak value
  }
}
int main()
{
 int arr[] = { 1, 3, 4, 5, 2, 0} ;
 int i, j,n=sizeof(arr)/sizeof(arr[0]);

 int min= -1, k=3;

 for(i=0;i<n;i++)
  if( arr[i]==k) {
      min=i;
      break;
    }
min=findpeak(arr,n);
  printf("**%d \n",min);

}
