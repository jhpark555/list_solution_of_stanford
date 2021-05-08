#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int st[MAX], top=-1;

void push(int st[],int val);
int pop(int st[]);

void display(int st[]);

void push(int st[],int val)
{
  if( top==MAX-1)
  	printf("Stakc is overflow \n");
  else{
    st[++top]=val;

  	}
}

int pop(int st[])
{
  int val;
  if(top ==-1) printf("Stack underflow\n");
  
  val=st[top--];

  return(val);
}

void display(int st[])
{
  int i;

  if(top==-1) printf(" Stakc is empty\n");

  for(i=top;i>-1;i--)
  	printf("%d ",st[i]);
  printf("\n");
}


void main(int argc,char *argv[])
{
     push(st,10);
	 push(st,20);
	 push(st,30);
	 int x=pop(st);
	 pop(st);
	 pop(st);
	// printf("x=%d \n",x);
	 
	 display(st);
   
}
