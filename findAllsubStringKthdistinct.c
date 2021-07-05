#include <stdio.h>
#include <stdlib.h>

int findDistinctSubstrings(char *s,int start,int end,char *ret)
{
   int i,j,k;
   int n=end-start+1;
   int count=0;
   //char ret[10];

   for(i =start ; i <n ; i++)
   {
     for( j=i+1 ; j< n ; j++)
     {
        if(s[i]==s[j]) break;
     }
     if(j==n){
       ret[count++]=s[i];
     }
   }
//printf("*count=%d ",count);
printf("(");
for(k=0;k<count;k++) printf("%c",ret[k]);
printf(")\n");
   return count;
}

void substrings(char *s,int n, char *ret)
{
  int i,j;

  for(i =0;i <n; i++)
  for(j =i;j <n; j++)
  {
    findDistinctSubstrings(s,i,j,ret);
  }

}

int main()
{
  char str[]="abcadce";
  int k=4;
  int n=strlen(str);
  char ret[20];
  int i;

  substrings(str,n,ret);//findDistinctSubstrings(str,k,ret);

//  for(i=0;i<r;i++) printf("%c",ret[i]);

  return 0;
}
