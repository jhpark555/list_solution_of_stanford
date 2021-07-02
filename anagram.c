#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) (a^=b^=a^=b)

void sortStr(char *s1,int n)
{
  int i,j;

  for(i=0;i<n;i++)
  for(j=0;j<n-i-1;j++)
  {
    if(s1[j]>s1[j+1]) swap(s1[j],s1[j+1]);
  }
}

int findAnagram(char *s1,char *s2,int m,int n)
{
  int i,j;
  int count=0;

  sortStr(s1,m);   sortStr(s2,n);
  for(i=0;i<m;i++)
  {
    if(*s1++==*s2++) count++;
    if(count==m) {
      printf("Yes anagram \n");
      return 1;
    }
  }
  return 0;
}
int main()
{
//  char str1[]="actors";
//  char str2[]="costar";
  char str1[]="auctioned";
  char str2[]="education";
  int i;
  int m = sizeof (str1)/sizeof(str1[0]);
  int n= sizeof(str2)/sizeof(str2[0]);

  //sortStr(str1,m);
  //for(i=0;i<m;i++) printf("%c ",str1[i]);

  printf("Anagram=%d \n",findAnagram(str1,str2,m,n));
}
