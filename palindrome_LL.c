//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
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

void push(struct node **head,int key)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));

  newNode->data=key;
  newNode->next=*head;
  *head=newNode;
}

int compare(struct node *head,struct node *rhead)
{
   struct node *current=head;

   while(head!=NULL)
   {
     if(head->data != rhead->data) { return -1; }
     head=head->next;
     rhead=rhead->next;
  //   current=current->next;
   }
  return 0;
}
struct node* reverseNode(struct node *head)
{
   struct node *prev=NULL;
   struct node *current=head;
   struct node *Next=NULL;

   while(current!=NULL)
   {
     Next=current->next;
     current->next=prev;
     prev=current;
     current=Next;
   }
   head=prev;

   return(head);
}

int main()
{
  int i;
  // points to the head node of the linked list
  struct node* head = NULL;

  // construct a linked list
  //for (i = 6; i > 0; i--) {
  //    push(&head, i);
  //}
  push(&head,'A');
  push(&head,'B');
  push(&head,'C');
  push(&head,'B');
  push(&head,'A');

  struct node *rhead=reverseNode(head);

  int x= compare(head,rhead);
  //printf("**x=%d \n",x);
  if(x>=0) printf("LL is palindrome\n");
  else printf("LL is not palindrome\n");
//  printList(head);

  return 0;

}
