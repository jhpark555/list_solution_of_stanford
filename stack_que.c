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


struct stack{
	int data;
	struct stack* next;
};

struct stack *top_link=NULL;
struct stack *push_link(struct stack**,int);
struct stack *pop_link(struct stack **);
struct stack *display_link(struct stack *);

struct stack *push_link(struct stack **top,int val)
{
   struct stack *new_node=(struct stack*)malloc(sizeof(struct stack));
   new_node->data=val;
   
   if(*top==NULL){
   	new_node->next=NULL;
    *top=new_node;
   	}
   else
   	{
    new_node->next=*top;
	*top=new_node;
   	}
  return(*top);
}

struct stack *pop_link(struct stack **top)
{
   struct stack *ptr=*top;

   if(ptr==NULL) printf("Stack is Empty\n");
   else
   	{
     	//printf("%d ",top->data);		
   	    *top=(*top)->next;	   	
		free(ptr);      
   	}

   return (*top);
}

struct stack *display_link(struct stack* top)
{
   struct stack *ptr=top;

   if(top==NULL) printf("Stack is Empty \n");
   else{
     while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
    }
   	}
  return(top);
}

void main(int argc,char *argv[])
{
     //push(st,10);
	// push(st,20);
	// push(st,30);
	// int x=pop(st);
	// pop(st);
	// pop(st);
	// printf("x=%d \n",x);
	 
	// display(st);

	//top_link= push_link(top_link,10);
	//top_link= push_link(top_link,20);   // regular pointer
		//top_link= push_link(top_link,30);
		
	 push_link(&top_link,10);
	  push_link(&top_link,20);     // reference pointer
	   push_link(&top_link,30);
	//   push_link(&top_link,40);
   
	//top_link= pop_link(top_link);
	//top_link= pop_link(top_link);
	 pop_link(&top_link);
	pop_link(&top_link);
	
	 display_link(top_link);
   
}
