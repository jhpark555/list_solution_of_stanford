int main()
{
  char str1[100]="Hello that is mine";
  char str2[100]="is";

  int i=0,j=0,n=0;

  while( str1[i]!= '\0')
  {
      j=0;
      if( str1[i]==str2[j] )
      	{
           n=i;

	while(str2[j]!='\0')
	{
           str1[n]=str1[j];
	    j++;
            printf("%c",str1[n]);
	}

      	}
      
      i++;
      n++;
	  
  }
 // printf("%s ",str1);

}

