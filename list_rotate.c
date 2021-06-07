
//
// linked list rotate wrt pivot data
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *buildonetwothree()
{
    struct node *head=malloc(sizeof(struct node));
    struct node *second=malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
      struct node *forth = malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next = forth;

    forth->data=4;
    forth->next = NULL;

    return head;

}

int length(struct node* start)
{
    int i=0;

    while(start!=NULL){
        i++;
        start=start->next;
    }
    return i;

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

int main()
{
    struct node *head;

    head=buildonetwothree();

    display(head);
    printf("\n******\n");
    int pivot = 2;

   struct node *current=head;
   struct node *new_current;

   while(current->data!=pivot)
   {
     current=current->next;
   }

   struct node* new_head;

   new_head=current->next;
   current->next=NULL;

   new_current=new_head;
   while(new_current->next!=NULL)
   {
     new_current=new_current->next;
   }
   new_current->next=head;

   display(new_head);

    return 0;
}
