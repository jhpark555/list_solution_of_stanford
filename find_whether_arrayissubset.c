#include <stdio.h>
#include <stdlib.h>

int findsubset(int a[],int b[],int m,int n)
{
  int i,j,k,count=0;

  for( i=0; i< n;i ++)
  {
     for( j=0;j< m; j++)
     {
       if(b[i] ==a[j]) {
          if(++count==n) return 1;
         break;
       }
     }

  }


  return 0;
}
int main()
{
  int arr1[]={11,1,13,21,3,7};
  int arr2[]={11,3,7,1};

  int m=sizeof(arr1)/sizeof(arr1[0]);
  int n=sizeof(arr2)/sizeof(arr2[0]);

 int r=  findsubset(arr1,arr2,m,n);
 if( r>0 ) printf("*yes \n");

}
