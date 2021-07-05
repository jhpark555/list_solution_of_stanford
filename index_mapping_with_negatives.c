#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

bool has[MAX+1][2];

bool search(int x)
{
  if( x >0 ){
    if(has[x][0] ==1 ) return true;
    else return false;
  }

  x=abs(x);
  if(has[x][1] ==1 ) return true;

  return false;
}

void insert(int a[],int n)
{
  int i,j;
  for(i=0; i< n; i++) {
    if( a[i] >=0 ) has[a[i]][0]=1;
    else has[abs(a[i])][1] =1;

  }
}

int main()
{
  int arr[]={-1,9,-5,-8,-5,-2};
  int n= sizeof(arr)/sizeof(arr[0]);

  insert(arr,n);
  int X=-5;

  if(search(X) ==true)   printf("Present \n");
  else printf("Not present \n");
  return 0;

}
