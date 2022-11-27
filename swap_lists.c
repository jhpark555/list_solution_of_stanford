#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

void pushlist(struct node **head,int data)
{
  struct node *newnode=(struct node*)malloc(sizeof(*newnode));

  newnode->data=data;
  newnode->next =(*head);
  newnode->prev=NULL;

  if(*head !=NULL){
    (*head)->prev=newnode;
  }
  *head=newnode;

}

void printlist(struct node **head)
{
  struct node *curr=(*head);

  while(curr!=NULL)
  {
    printf("%d->",curr->data);
    curr=curr->next;
  }
}

struct node *revnodeLL(struct node **head)
{
  struct node *prev=NULL;
  struct node *curr=(*head);
  struct node *Next=NULL;

  while(curr!=NULL){
   Next =curr->next;
   curr->next=prev;
   prev=curr;
   curr=Next;
 }
 (*head)=prev;

  return prev;
}

void swap(struct node *head)
{
  struct node *prev=NULL;

  prev= head->prev;
  head->prev=head->next;
  head->next=prev;

}
struct node *revnodeDL(struct node **head)
{
  struct node *prev=NULL;
  struct node *curr=(*head);

  while(curr!=NULL){
    swap(curr);
    //printf("%d ->",curr->data);
    prev=curr;
    curr=curr->prev;
  }
  if(prev!=NULL)
   (*head)=prev;

   return (prev);

}
int main(int argc,char* argv[])
{
  struct node *head=NULL;

  pushlist(&head,10);
  pushlist(&head,20);
  pushlist(&head,30);
  pushlist(&head,40);

  //revnodeLL(&head);
  revnodeDL(&head);
  printlist(&head);
}
