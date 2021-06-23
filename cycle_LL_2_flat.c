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

// Function to identify a cycle in a linked list using
// Floyd’s cycle detection algorithm

struct node * detectCycle(struct node *head)
{
  struct node *slow=head;
  struct node *fast=head;
  struct node *prev=NULL;

  while(fast && fast->next)
  {
    slow=slow->next;
  //  prev=fast;
    fast=fast->next->next;

    if(slow==fast) {
    //  printf("%d ",slow->data);
    //  prev->next=NULL;
     fast->next=NULL;
      return head;        // fast will be overlap after rotation
    }
  }
  return NULL;
}

int main()
{
  int i;
  // points to the head node of the linked list
  struct node* head = NULL;

  // construct a linked list
  for (i = 6; i > 0; i--) {
      push(&head, i);
  }

  // link tail of the second list to the fourth node of the first list
  head->next->next->next->next->next->next = head->next;

  head=detectCycle(head);

  printList(head);

  return 0;

}
