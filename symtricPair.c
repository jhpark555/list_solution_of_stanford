#include <stdio.h>
#include <stdlib.h>

struct Pair{
   int x,y;
};

int  findPair(struct Pair p[],int n)
{
  int i,j;
  int ret=0;
  for(i=0;i <n; i++)
   for(j=i; j<n ;j++)
  {
    if(p[i].x ==p[j].y && p[i].y==p[j].x ) {
      printf("x=%d y=%d | x=%d y=%d\n",p[i].x,p[i].y, p[j].x,p[j].y);
       ret++;
     }
  }

 return ret;
}
int main()
{
  struct Pair pair[]={{3,4},{1,2},{5,2},{7,10},{4,3},{2,5}};
  int n =sizeof(pair)/sizeof(pair[0]);

  int ret=findPair(pair,n);
 printf("Pair= %d \n",ret);

}
