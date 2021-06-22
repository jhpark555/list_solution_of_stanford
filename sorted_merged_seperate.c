//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define swap( a ,b )  (a^=b^=a^=b)
int main()
{
  int x[]= { 1, 4, 7, 8, 10 };
  int y[]= { 2, 3, 9 };
  int nx=sizeof(x)/sizeof(x[0]);
  int ny=sizeof(y)/sizeof(y[0]);
  int nz=nx+ny;
  int z[nz];

  int i,j,k;
  int sum=0;

  for(i=0;i<nx;i++)
  {
    z[i]=x[i];
  }

  for(j=i,i=0; i<ny ;i++,j++)
  {
    z[j]=y[i];

  }

  for(i=0;i<nz;i++)
   for(j=0;j<nz-i-1;j++)
    if(z[j]>z[j+1])swap(z[j],z[j+1]);    //bubble sort

//for(i=0;i<nz;i++) printf("%d ",z[i]);

  for(i=0;i<nz;i++){      //seperate to each arrays
    if(i<nx)
     x[i]=z[i];
     else
     y[i-nx]=z[i];
   }

    for(i=0;i<nx;i++) printf("%d ",x[i]);  printf("\n");
    for(i=0;i<ny;i++) printf("%d ",y[i]);

  return 0;
}
