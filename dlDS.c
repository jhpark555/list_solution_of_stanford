
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node{
  int data;
  struct node* prev;
  struct node* next;

};

struct node* start=NULL;
struct node* create_all(struct node*);
struct node* display(struct node*);
struct node* insert_beg(struct node*,int);
struct node* insert_end(struct node*,int);
struct node* insert_before(struct node*,int , int);
struct node* insert_after(struct node*,int,int);
struct node* delete_beg(struct node*);
struct node* delete_end(struct node*);
struct node* delete_node(struct node*,int);
struct node* delete_after(struct node*,int);
struct node* delete_before(struct node*,int);
struct node* delete_list(struct node*);
struct node* sort_list(struct node*);




int main(int argc,char *argv)
{
	int option;
    struct node* head =NULL ;    // NULL is important here!!!!

	start =create_all(head);
	display(start);

	//head=insert_beg(start,0);
	//display(head);

	//head=insert_end(start,99);
	//display(head);

	//head=insert_before(start,8,88);
	//display(head);

	//head=insert_after(start,8,88);
	//display(head);

	//head=delete_beg(start);
	//display(head);

	//head=delete_end(start);
	//display(head);

	//head =delete_node(start,4);
	//display(head);

	//head=delete_after(start,2);
	//display(head);

	//head=delete_before(start,5);
	//display(head);

	head=delete_list(start);
	display(head);

	//head=sort_list(start);
	//display(head);

  return 0;
}


struct node* create_all(struct node* start)
{
    int i;
    struct node*new_node,*ptr;
	char num[10]={4,5,6,2,3,4,7,8,9,10};

  for(i=0;i<10;i++){
      new_node=(struct node*)malloc(sizeof(struct node));
	  new_node->data=num[i];
	  if(start==NULL){
	  	  new_node->next=NULL;
		  new_node->prev=NULL;
		  start=new_node;
	  }
	  else
	  {
	      ptr=start;
         while(ptr->next!=NULL)
		 	ptr=ptr->next;
			ptr->next=new_node;
			new_node->prev=ptr;
			new_node->next=NULL;
	  }
	}
      return ( start);
}



struct node* display(struct node* start)
{
   struct node* ptr=start;

   while(ptr!=NULL){
    printf("%d ",ptr->data);
	ptr=ptr->next;
   }
   printf("\n");

   return(start);

}


struct node* insert_beg(struct node* start,int num)
{
    struct node* new_node=(struct node*) malloc(sizeof(struct node));

    new_node->data=num;
    new_node->next=start;
	new_node->prev=NULL;
	start=new_node;

	return(start);
}

struct node* insert_end(struct node* start,int num)
{
   struct node* new_node=(struct node*)malloc(sizeof(struct node));
   struct node* ptr;

   ptr=start;
   while(ptr->next!=NULL){
      ptr=ptr->next;
   	}
   ptr->next=new_node;

   new_node->data=num;
   new_node->next=NULL;
   new_node->prev=ptr;

   return( start);

}

struct node* insert_before(struct node* start,int which, int num)
{
   struct node* new_node=(struct node*)malloc(sizeof(struct node));
   struct node* ptr;

   ptr=start;
   while(ptr->data!=which){
   	ptr=ptr->next;
   }
   new_node->next=ptr;
   new_node->prev=ptr->prev;
   new_node->data=num;

   ptr->prev->next=new_node;
   ptr->prev=new_node;

   return(start);

}

struct node* insert_after(struct node* start,int which,int num)
{
   struct node* new_node=(struct node*)malloc(sizeof(struct node));
   struct node *ptr;

   ptr=start;

   while(ptr->data!=which){
     ptr=ptr->next;
   	}
   new_node->data=num;

   new_node->next=ptr->next;
   new_node->prev=ptr;
   ptr->next=new_node;
   ptr->next->prev=new_node;

   return(start);
}

struct node* delete_beg(struct node* start)
{
   struct node* ptr= start;

   start=start->next;
   start->prev=NULL;

   free(ptr);

   return(start);

}

struct node* delete_end(struct node* start)
{
   struct node* ptr=start;

   while(ptr->next !=NULL){
   	ptr = ptr->next;
   	}
   ptr->prev->next=NULL;

   free(ptr);

   return(start);

}

struct node* delete_node(struct node* start,int which)
{
   struct node* ptr=start;
   struct node* preptr;

   if(ptr->data=which){
	  start=start->next;
	  free(ptr);
	  return(start);
   	}
   else{
   while(ptr->data !=which){
   	preptr=ptr;
	ptr=ptr->next;
   }
   preptr->next=ptr->next;
   free(ptr);
   return(start);
   	}

}

struct node* delete_after(struct node*start,int which)
{
  struct node *ptr=start,*temp;

   while(ptr->data!=which){
	ptr=ptr->next;
   	}
    temp=ptr->next;

	ptr->next=temp->next;
	temp->next->prev=ptr;


   free(temp);
  return(start);

}

struct node* delete_before(struct node*start,int which)
{
  struct node *ptr=start,*temp;

   while(ptr->data!=which){
	ptr=ptr->next;
   	}

    temp=ptr->prev;

	if(temp==start)  start=delete_beg(start);
	else{
	ptr->prev=temp->prev;
	temp->prev->next=ptr;
		}

   free(temp);
  return(start);

}


struct node* delete_list(struct node* start)
{
   struct node* ptr=start;

  // while(ptr!=NULL){
	//start=start->next;
	//start->prev=NULL;
	//free(ptr);
	//ptr=start;
   //	}
   while(ptr!=NULL) start=delete_beg(start);

   return(start);
}

struct node* sort_list(struct node* start)
{
   struct node* ptr1=start,*ptr2;
   int temp;

   while(ptr1->next !=NULL){
      ptr2=ptr1->next;
	  while(ptr2!=NULL){
	  	if(ptr1->data>ptr2->data) {
			temp=ptr1->data;
			ptr1->data=ptr2->data;
			ptr2->data=temp;
	  	}
		ptr2=ptr2->next;
	  	}
	  ptr1=ptr1->next;
   	}
   return(start);
}
