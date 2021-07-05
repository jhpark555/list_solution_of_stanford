//subset of array : 내가 아는 subset은 일련의 연속된 array element이고, 이 문제는 b[]의
//element가 arr[]에 있는가의 질문임.  따라서 sorting은 필요엄ㅅ음.

#include <stdio.h>

#define swap(a,b) (a^=b^=a^=b)

void sortA(int arr[],int n)
{
  int i,j;

  for( i=0; i<n ;i++)
    for(j =0;j < n-i-1;j++)
    {
      if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    }

    //for( i=0; i<n ;i++) printf("%d ",arr[i]);
}

int isSubset(int arr[],int b[],int m,int n)
{
  int i,j;
  int count=0;

//  sortA(arr,m);
  for(j=0;j<n;j++)
  for(i=0; i<m ;i++)
  {
    if(b[j]==arr[i]) {
      printf("%d %d \n",b[j],arr[i]);
      count++;
    }
  }
  if(count==n) return 1;
  else return 0;
}

int main()
{
  int arr[]={3,5,7,12,1,9,10,0,2};
  int b[]={1,3,5,9};
//  int arr[]= { 3, 5, 7, 12, 1, 9, 10, 0, 2 };
//  int b[]={6,3,8};

  int n=sizeof(arr)/sizeof(arr[0]);
  int m=sizeof(b)/sizeof(b[0]);

  int r= isSubset(arr,b,n,m);
  printf("Subset is %d \n",r);
}
