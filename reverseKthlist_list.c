
#include <stdio.h>
#include <stdlib.h>


struct node
{
  int data;
  struct node *next;
};

void printList(struct node *head)
{
  struct node *current=head;
  while(current!=NULL)
  {
    printf("%d->",current->data);
    current=current->next;
  }
}
//DLL push
void push(struct node **head,int data)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));

  newNode->data=data;
  newNode->next=*head;

  *head=newNode;
}

void movenode(struct node **dst, struct node **src)
{
    struct node *temp=*src;

    (*src)=(*src)->next;
    temp->next=*dst;
    *dst=temp;

}
void reverseLL(struct node **headref)
{
   struct node *next=NULL;
   struct node *prev=NULL;
   struct node *curr=*headref;

   while(curr!=NULL)
   {
     next=curr->next;
     curr->next=prev;
     prev=curr;
     curr=next;
   }
   *headref=prev;
}

struct node *rearrangeMerge(struct node *a,struct node *b)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    struct node *temp=NULL;
    struct node *current=newNode;   // newnode is moving to the last.

    //newNode->data=0;
    //newNode->next=NULL;

    while(a!=NULL && b!=NULL)
    {
      //  temp=a;
      //  a=a->next;
      //  temp->next=newNode;
      //printf("*%d %d \n",a->data,b->data);
        newNode->next=a;
        newNode=a;
        a=a->next;

      //  temp=b;
      //  b=b->next;
      //  temp->next=newNode;
        newNode->next=b;
        newNode=b;
        b=b->next;
      }
    return current->next;
}

struct node *reverseAlternatingKNodes(struct node *head,int k)
{
    struct node *current=head;
    struct node *next=NULL;

    while(current->data !=k)
    {
      current=current->next;
    }
    next=current->next;
    current->next=NULL;
    reverseLL(&head);
    current=head;
    while(current->next!=NULL)
    {
      current=current->next;
    }
    current->next=next;

    return (head);
}

int main()
{
  int i;
  int n=10;
  struct node* head = NULL;

  while(n){
    push(&head,n--);
  }
int k=4;

printList(head); printf("  ");
struct node *new=  reverseAlternatingKNodes(head,k);
printf("\n");
printList(new);

return 0;

}
