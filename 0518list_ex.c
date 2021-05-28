/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

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

struct node *append(struct node *l1,struct node *l2)
{
    struct node *current=l1;

    if(current==NULL) l1=l2;

    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=l2;
   // l2=current;
    //l2=NULL;
    return(l1);
}
struct node *lasttofirst(struct node *head)
{
    struct node *current=head;
    struct node *prev;

    while(current->next!=NULL)
    {
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
    current->next=head;
    head=current;

    return(head);
}

struct node *firsttolast(struct node *head)
{
    struct node *current=head;
    struct node *first=head;

    head=first->next;

    while(current->next !=NULL){
        current=current->next;
    }
    current->next=first;
    first->next=NULL;

    return( head);

}

struct node *sortlist(struct node *head)
{
 struct node *current=head;
 struct node *ahead;
 int temp;

 while(current->next !=NULL)
 {
     ahead=current->next;

     while(ahead!=NULL)
     {
         if(current->data > ahead->data)
         {
             temp=current->data;
             current->data=ahead->data;
             ahead->data=temp;
         }
         ahead=ahead->next;
     }
     current=current->next;
 }
 return(head);
}

struct node * push(struct node *head,int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;
    newnode->next=head;
    head=newnode;

  return(head);

}

int pop(struct node **head)
{
    struct node *current=*head;
    int data;

    if(current!=NULL) data=current->data;
    else data=0;

    *head=current->next;
    free(current);

    return(data);

}
int main()
{
    struct node *l1,*l2;

    l1=buildonetwothree(2,45,66);
    l2=buildonetwothree(40,30,10);
    display(l1);
    printf("\n");
    l1=append(l1,l2);
   display(l1);
   printf("\n");
  l1=lasttofirst(l1);
display(l1);
printf("\n");
  l1=firsttolast(l1);
  display(l1);
  printf("\n");
 l1= push(l1,100);
 display(l1);

 int val=pop(&l1);
 printf("\n val=%d : list ==>",val); display(l1); printf("\n");
 l1=sortlist(l1);
  display(l1);
    return 0;
}
