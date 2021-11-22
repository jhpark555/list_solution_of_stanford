#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *buildonetwothree()
{
    struct node *head=malloc(sizeof(struct node));
    struct node *second=malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next = fourth;

    fourth->data=4;
    fourth->next = NULL;


    return head;

}

void display(struct node *head)
{
    struct node *curr=head;

    while(curr!=NULL)
    {
        printf("%d->",curr->data);
        curr=curr->next;
    }
}

void swap(struct node **head)
{
    struct node *temp=NULL;
    struct node *curr=*head;
    struct node *prev=NULL;


    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=temp->next;
        temp->next=curr;

        if(prev==NULL) *head=temp;
        else prev->next=temp;

        prev=curr;
        curr=curr->next;

    }
}

void reverse(struct node **head)
{
    struct node *Next=NULL;
    struct node *prev=NULL;
    struct node *curr=*head;

    while(curr!=NULL)
    {
        Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    *head=prev;

}

void movenode(struct node **src,struct node** dst)
{
    struct node *temp=*src;

    *src=(*src)->next;
    temp->next=*dst;
    *dst=temp;
}

void SortedInsert(struct node **headref,struct node *newNode)
{
   struct node **curr=headref;

   while(*curr!=NULL && (*curr)->data < newNode->data)
   {
       //printf("%d %d \n",(*curr)->data,newNode->data);
     curr =&(*curr)->next;
   }
   newNode->next=*curr;
   *curr=newNode;
}

void sortedlist(struct node **headref)
{
   struct node *result=NULL;
   struct node *curr=*headref;
   struct node *next;

   while(curr!=NULL)
   {
     next=curr->next;
     SortedInsert(&result,curr);
     curr=next;
   }
  *headref=result;
}

void push(struct node **head,int data)
{
    struct node *temp=(struct node *)malloc(sizeof *temp);

    temp->data=data;
    temp->next=*head;
    *head=temp;
}

void pop(struct node **head, int *data )
{
    struct node *temp=*head;

    *data= temp->data;
    (*head)=(*head)->next;
    free(temp);
}


struct node *copylist(struct node *head)
{
   struct node *newlist=NULL;
   struct node *curr=head;
   struct node *Next=NULL;

   while(curr!=NULL)
   {
       if(newlist==NULL)
       {
         newlist=(struct node*)malloc(sizeof(*newlist));
         newlist->data=curr->data;
         newlist->next=NULL;
         Next=newlist;
       }
       else    // should know where is current tail because we have to insert data at Next.
       {
           Next->next=(struct node *)malloc(sizeof(struct node));
           Next=Next->next;
           Next->data=curr->data;
           Next->next=NULL;
       }

       curr=curr->next;

   }
   return newlist;

}

int main()
{
    struct node *head=NULL;
    struct node *dst=NULL;
    struct node *temp=NULL;

    head=buildonetwothree();
    display(head);

    printf("\n");
    swap(&head);

    display(head);

    printf("\n");
    reverse(&head);
    display(head);

    printf("\n");

    while(head!=NULL)
    movenode(&head,&dst);

    display(dst);

    printf("\n sorted :");

    sortedlist(&dst);
    display(dst);

    printf("\n");

    push(&dst,10);
    display(dst);

    printf("\n");
    int data;
     pop(&dst,&data);

     printf("data: %d , rest:",data);
     display(dst);

     printf("\n copylist: ");
     struct node *result=copylist(dst);
  // struct node *result=(struct node*)malloc(sizeof *result);
   //while(dst!=NULL) movenode(&dst,&result);
     display(result);
    return 0;
}
