
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node{
  int data;
  int coeff;
  struct node* next;

};

struct node* start=NULL;
struct node* start1=NULL;
struct node* start2=NULL;
struct node* start3=NULL;



struct node* create_all(struct node*,char a[]);
struct node* display(struct node*);
struct node* add_poly(struct node*, struct node*,struct node*);
struct node* sub_poly(struct node*, struct node*,struct node*);
struct node* add_node(struct node*, int,int);



#define MAX 4
char T1[MAX] ={ 6,9,7,1};
char T2[MAX]= { 3,5,2,6};


int main(int argc,char *argv)
{
	int option;
    struct node* head =NULL ;    // NULL is important here!!!!
     struct node* head1 =NULL ;    // NULL is important here!!!!
      struct node* head2 =NULL ;    // NULL is important here!!!!

	start =create_all(head,T1);
	display(start);

	start1 = create_all(head1,T2);
	display(start1);

    start3 = sub_poly(start,start1,start3);
	display(start3);

  return 0;
}



struct node* create_all(struct node* start,char a[])
{
    int i;
    struct node*new_node,*ptr;

  for(i=0;i<MAX;i++){
      new_node=(struct node*)malloc(sizeof(struct node));
	  new_node->data=a[i];
	  new_node->coeff=MAX-i-1;
	  if(start==NULL){
	  	  new_node->next=NULL;
		  start=new_node;
	  }
	  else
	  {
	      ptr=start;
         while(ptr->next!=NULL)
		 	ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;
	  }
	}
      return ( start);
}



struct node* display(struct node* start)
{
   struct node* ptr=start;

   while(ptr!=NULL){
    printf("%d X %d +",ptr->data,ptr->coeff);
	ptr=ptr->next;
   }
   printf("\n");

   return(start);

}


struct node* add_node(struct node* start,int num,int coeff)
{
     struct node *ptr=start;
	 struct node* new_node=(struct node*)malloc(sizeof(struct node));

     new_node->data=num;
	 new_node->coeff=coeff;

    if(start==NULL){
	   new_node->next=NULL;
	   start=new_node;
    	}
	else{
	 while(ptr->next!=NULL)
	 	ptr=ptr->next;

		new_node->next=NULL;
		ptr->next=new_node;
	}

	 return(start);


}

struct node* add_poly(struct node* start1,struct node* start2, struct node* start3)
{
    struct node* ptr1=start1,*ptr2=start2;
	int sum_num,c;

	while(ptr1!=NULL && ptr2!=NULL){

	   if(ptr1->coeff==ptr2->coeff){
	   	  sum_num=ptr1->data+ptr2->data;
		  start3 = add_node(start3,sum_num,ptr1->coeff);
		  ptr1=ptr1->next;
	      ptr2=ptr2->next;

	   	}
	   else if(ptr1->coeff > ptr2->coeff){
         sum_num=ptr1->data;
		 start3 =add_node(start3,sum_num,ptr1->coeff);
		 ptr1=ptr1->next;
	   	}
	   else if(ptr1->coeff < ptr2->coeff){
         sum_num=ptr2->data;
		 start3 =add_node(start3,sum_num,ptr2->coeff);
		 ptr2=ptr2->next;
	   	}
	}

	if(ptr1==NULL)
	{
      while(ptr2!=NULL){
	  	start3=add_node(start3,ptr2->data,ptr2->coeff);
		ptr2=ptr2->next;
      }
	}

	if(ptr2==NULL)
	{
      while(ptr1!=NULL){
        start3 =add_node(start3,ptr1->data,ptr1->coeff);
		ptr1=ptr1->next;
      }
	}

	return start3;

}


struct node* sub_poly(struct node* start1,struct node* start2, struct node* start3)
{
  struct node* ptr1=start,*ptr2=start2;
  int sub_num,c;

  while(ptr1!=NULL||ptr2!=NULL){
       if(ptr1->coeff==ptr2->coeff){
           sub_num=ptr1->data-ptr2->data;
		   start3= add_node(start3,sub_num,ptr1->coeff);
		   ptr1=ptr1->next;
		   ptr2=ptr2->next;
       	}
	   else if( ptr1->coeff> ptr2->coeff){
	   	   sub_num=ptr1->data;
		   start3 =add_node(start3,sub_num,ptr1->coeff);
		   ptr1=ptr1->next;
	   	}
	   else if(ptr1->coeff < ptr2->coeff){
	   	   sub_num=ptr2->data;
		   start3 =add_node(start3,sub_num,ptr2->coeff);
		   ptr2=ptr2->next;
	   	}
  	}
	if(ptr1==NULL){
		 while(ptr2!=NULL){
         start3 = add_node(start3,ptr2->data,ptr2->coeff);
		 ptr2=ptr2->next;
		 }
	}
	if(ptr2==NULL){
       while(ptr1!=NULL){
	   	start3 =add_node(start3,ptr1->data,ptr1->coeff);
		 ptr1=ptr1->next;
       	}
	}

   return (start3);

}
