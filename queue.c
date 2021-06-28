
/* Circular Array ueue and Linked list QUeue test */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void insert(int num);
int delete(void);
void display(void);


struct node{
   int data;
   struct node *next;
};

struct Q
{
   struct node *front;
   struct node *rear;

};

struct Q *q;
void create_queue(struct Q *);
struct Q *insertq(struct Q *,int);
struct Q *deleteq(struct Q *);
struct Q *displayq(struct Q *);

void create_queue(struct Q *q)
{
   q->rear=NULL;
   q->front=NULL;
}

struct Q *insertq(struct Q *q,int num)
{
   struct node *new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=num;

   if(q->front==NULL)
   	{
      q->front=new_node;
	  q->rear=new_node;
	  q->front->next=q->rear->next=NULL;
   	}
   else{
      q->rear->next=new_node;
	  q->rear=new_node;
	  q->rear->next=NULL;
   	}

   return(q);

}


struct Q *deleteq(struct Q *q)
{
   struct node *ptr= q->front;

  if(q->front ==NULL) {
  	printf(" Empth \n");
	return NULL;
  	}
  else
  	{
     q->front=q->front->next;
	 printf("being deleted is %d \n ",ptr->data);
	 free(ptr);
  	}
   return (q);

}


struct Q *displayq(struct Q *q)
{
   struct node *ptr=q->front;

   if(ptr==NULL) printf("Empty \n");
   else{
     while( ptr !=q->rear){
	 	printf("%d ",ptr->data);
	 	ptr=ptr->next;
     	}
	   printf("%d ",ptr->data);
   	}
   return(q);
}



void insert(int num)
{
  if(front==0 && front==MAX-1){
  	 printf(" Overflow\n");
	 return;
  	}
  else if( front==-1 && rear==-1) front=rear=0;
  else if( rear==MAX-1 && front !=0) rear =0;
  else rear++;

  queue[rear]=num;

}

int delete(void)
{
  int val;

  if(front==-1 && rear ==-1){
  	printf(" Underflow \n");
	return -1;
  	}
   val= queue[front];

  if(front==rear) front=rear=-1;
  else{
     if(front ==MAX-1) front =0;
	 else front++;
  	}

  return (val);
}

void display()
{
  int i;
  if( front==-1 || rear==-1) printf("Empty\n");
  else{
  //	printf("f=%d r=%d \n",front,rear);
  	if( front<=rear)
      for(i=front;i<=rear;i++) printf("%d ", queue[i]);
	else
		{
         for(i=front;i<MAX;i++)  printf("%d ",queue[i]);
		 for(i=0;i<=rear;i++) printf("%d ",queue[i]);

		}

  	}

}

int main()
{
  //array queue
  //insert(10);
//  insert(20);
//  insert(30);
  //  insert(40);
 //delete();
// delete();
 //delete();

//  display();

// linked list queue
   q= (struct Q*)malloc(sizeof(struct Q));

  create_queue(q);
  q= insertq(q,10);
  q= insertq(q,20);
  //  deleteq(q);

  displayq(q);

  free(q);
}
