#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
   int data;
   int priority;
   struct node *next;
};


struct node *start=NULL;

void display(struct node *);

struct node *insert( struct node *start,int num,int pri)
{
    struct node *ptr,*p;

	ptr=(struct node*)malloc(sizeof(struct node));

	ptr->data=num;
    ptr->priority = pri;
	
	if(start==NULL || pri< start->priority){
		ptr->next=start;
	    start=ptr;
	}
    else
    {
      p=start;
	  while(p->next!=NULL && p->next->priority <=pri)
	  	 p=p->next;

	  ptr->next=p->next;
	  p->next=ptr;

    }
	return (start);


}
struct node *delete(struct node *start)
{
    struct node *ptr=start;

	if(start==NULL)
		{
          printf("Underflow \n");
		  return;
		}
	else{
         start=start->next;
		 free(ptr);
		}
    return (start);
}


void display(struct node *start)
{
    struct node *ptr=start;
   if(start == NULL) printf(" Empty\n");
   	else
   		{
          while(ptr!=NULL){
                printf("%d[priority=%d] \n",ptr->data,ptr->priority);
				ptr=ptr->next;
          	}
   		}
}

int main()
{
   start= insert(start,10,1);
   start= insert(start,20,3);
   start= insert(start,30,2);

	display(start);

   return 0;
}
