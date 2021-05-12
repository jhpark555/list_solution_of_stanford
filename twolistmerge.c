
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};


struct node *buildonetwothree(int num1,int num2,int num3)
{
    struct node *head=malloc(sizeof(struct node));
    struct node *second=malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    
    head->data=num1;
    head->next=second;
    
    second->data=num2;
    second->next=third;
    
    third->data=num3;
    third->next = NULL;
    
    return head;
    
}

void display(struct node *head)
{
    struct node* current=head;
    
    while(current!=NULL)
    {
        printf("%d ->",current->data);
        current=current->next;
    }
    
}

void movenode(struct node **dst, struct node **src)
{
   struct node *new=*src;
   
       *src=new->next;
       new->next=*dst;
       *dst=new;
       new=new->next;
    
   
}


struct node *firsttolast(struct node *head)
{
    struct node *current=head;
    struct node *first=head;
    
    while(current->next!=NULL)
    {
        current=current->next;
    }
     head=first->next;
    current->next=first;
    first->next=NULL;
   
    
    return(head);
    
    
}

struct node *lasttofirst(struct node *head)
{
    struct node *current=head;
    struct node *prevlast=current;   //prev of current pointer
    
    while(current->next!=NULL){
        prevlast=current;
      current=current->next;
    }
      prevlast->next=NULL;
      current->next=head;
      head=current;
   
   return(head);   
    
}

void push(struct node **headref, int data)
{
    struct node *newnode = malloc(sizeof (struct node));
    newnode->data=data;
    newnode->next=*headref;
    *headref=newnode;
    //printf("%d ",(*headref)->data);
}

struct node *Append(struct node** aref, struct node ** bref)
{
    struct node *current=*aref;
    
    if(*aref==NULL){
        *aref=*bref;
    } else{
       while(current->next!=NULL){
          current=current->next;
       }
      current->next=*bref;
 
    }
   *bref=NULL;
    
    return (*aref) ;// length(*aref);
}

struct node *lasttofirstwithnum(struct node *head,int num)
{
    struct node *current=head;
    struct node *tailstart=head;
    struct node *tailend=head;
    int count=0;
  
   while(count < num-1)
   { 
       count++;
       current=current->next;
   }
 
   tailstart=current->next;
   current->next=NULL;
   tailend=tailstart;
   
   while(tailend->next!=NULL){
    tailend=tailend->next;
   }
   tailend->next=head;
    
    return(tailstart);
}
int main()
{
    
      struct node *test=NULL;
      struct node *l1=NULL,*l2=NULL;
      
      l1=buildonetwothree(1,2,3);
      l2=buildonetwothree(4,5,6);
     
    //  movenode(&test,&l2);
    //  test =firsttolast(l1);
   // test =lasttofirst(l1);
    //  display(test);
      
      Append(&l1,&l2);
      display(l1);
      printf("**\n");
    test=lasttofirstwithnum(l1,4);  
     display(test);
    return 0;
}
