//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
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

void push(struct node **head,int data)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));

  newNode->data=data;
  newNode->next=*head;
  newNode->prev=NULL;

  if(*head!=NULL)
  (*head)->prev=newNode;

  *head=newNode;
}
void swap(struct node *head)
{
  struct node *prev=head->prev;
  head->prev=head->next;
  head->next=prev;
}
void reverseDLL(struct node **head)
{
   struct node *prev=NULL;
   struct node *current=*head;

   while(current!=NULL)
   {
     swap(current);
     prev=current;
     current=current->prev;
   }
   if(prev!=NULL)
    *head=prev;

}

int main()
{
  int i;
  int key[] = { 1, 2, 3, 4, 5 };
  int n = sizeof(key)/sizeof(key[0]);

  struct node* head = NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, key[i]);
  }
reverseDLL(&head);
  printList(head);

  return 0;

}
