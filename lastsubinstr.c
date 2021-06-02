#include <stdio.h>

int main()
{
    char str[]="I love programming. I love Codeforwin.";
    int i;
    char toFind[]="love";
    int size=sizeof(str)/sizeof(str[0]);
    int j=0,count=0,k;
    int wordsize=sizeof(toFind)/sizeof(toFind[0])-1;


        for(i=0; str[i]!='\0'; i++)
        {
            if(str[i]==toFind[0]){
                //printf("@%d",i);
                for(j=0,k=i; toFind[j]!='\0';j++,k++)
                 if( toFind[j]==str[k]) count++;

                 if(count==wordsize){
                     count=0;
                     printf("Yes:%dth\n",i);
                 }
            }
        }


    return 0;
}
