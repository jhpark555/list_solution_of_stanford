#include <stdio.h>
#include <stdlib.h>

int isPalindrome(unsigned n)
{
  unsigned rev=0;

  unsigned k=n;

  while(k)
  {
    rev=(rev<<1)|(k&1);
    k = k>>1;
    printf("rev=%d k=%d \n",rev,k);
  }
  return n==rev;
}
int main()
{
  int n=2;

  int i= isPalindrome(n);
  printf("**i=%d \n",i);

}
