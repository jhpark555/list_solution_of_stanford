#include <stdio.h>
#include <stdlib.h>

int getStr(char *str)
{
  int i;
  int sum=0;

  for(i=0;str[i] !='\0';i++)
  {
    sum +=str[i]-48;
    //printf("%d ",str[i]-48);
  }
  return sum;
}

int getSum(int n)      // all digit summation
{
  int sum=0;
  while(n!=0)
  {
    sum +=n%10;
    n=n/10;
  }
  return sum;
}

int digSum(int n)
{
   int sum=0;

while(n>0 || sum >9)
{
  if( n==0)
  {
    n=sum;
    sum=0;
     //printf("**n=%d sum=%d \n ",n,sum);
  }
   sum += n % 10;
   n=n/10;
   //printf("n=%d sum=%d \n ",n,sum);
 }
 return sum;
}

int main()
{
   int n=5674;//1234;
   char *str="123456789123456789123422";
   printf("%d ", digSum(n));
   printf("sum=%d",getSum(n));
   printf("\n");
   printf("str=%d", getStr(str));
   return 0;
}
