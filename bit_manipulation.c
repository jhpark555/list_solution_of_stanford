#include <stdio.h>

void swap(int *x,int *y)
{
  if( x != y)
  {
    *x=*x ^ *y;
    *y=*x ^ *y;
    *x=*x ^ *y;
  }
}

int turnoffKthBit(int n,int k)
{
  return n& ~(1<<(k-1));
}
int turnonKthBit(int n,int k)
{
  return n | (1<<(k-1));
}
int toggleKthBit(int n, int k)
{
  return n ^ ( 1<<(k-1));
}

int positionofRightmostSetBit(int n)
{
  if(n &1 ) return 1;// Odd

// unset rightmost bit and xor with the number itself
  n= n ^(n &(n-1));
  // find the position of the only set bit in the result;
     // we can directly return `log2(n) + 1` from the function
  int pos=0;
  while(n)
  {
    n = n>>1;
    pos++;
  }
  return pos;
}

// Function to compute `n % d` without using division and modulo operator
unsigned int compute(const unsigned int n, const unsigned int d) {
    return n & (d - 1);
}

int countBits(int n)
{
  int count=0;
  while(n)
  {
    n =n & (n-1);
    count++;
  }
  return count;
}

// Function to compute `n % d` without using division and modulo operator
unsigned int compute1(const unsigned int n, const unsigned int d) {
    return n & (d - 1);
}

// Function to compute `n % d` without using division and modulo operator
int compute2(int n, int d)
{
    while (n > 0) {
        n = n - d;
    }
    return n + d;
}

int main()
{
  int n=5;

  if( n&1) printf(" Odd number \n");
  else printf("Even number \n");

  int x=4, y=-8;
  if( x^y <0 )  printf(" Opposite sign \n");
  else printf(" Same sign \n");


  //-x = ~x + 1;
  //-~x = x + 1 (by replacing x by ~x)

  x=4;
  printf(" %d  %d  %d  %d\n",-~x,x+1,~x+1,-x);
  x=-5;
  printf("%d \n",-~x);

  x=3;y=4;
  swap(&x,&y);
  printf("%d %d \n",x,y);


 n=20;
 int k=3;
 n= turnoffKthBit(n,k);
 printf("n=%d \n",n);

 n=20; k=4;
 n= turnonKthBit(n,k);
 printf("n=%d \n",n);

 n=20,k=3;
 n=toggleKthBit(n,k);
 printf("n=%d \n",n);

 n=20;
 n=positionofRightmostSetBit(n);
 printf("position of right most set bit is %d \n",n);

 n=-1;
 n=countBits(n);   printf("Bit counts= %d \n",n);

n=-20;
n= ((n>>31)&1) ? (~n+1):n;   //absolute value of n
printf("%d \n",n);

n=18;
int s=3;
int d=8;   // d should be 1,2,4,8,16,32...
printf("%d %%  %d = %d\n",n,d,compute1(n,d));   // in case d is 2's

n=38;
d=7;
printf("%d %%  %d = %d\n",n,d,compute2(n,d));

}
