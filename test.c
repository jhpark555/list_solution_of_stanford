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


int main()
{
  // input keys
  int keys[] = {6, 3, 4, 8, 2, 9};
  int n = sizeof(keys)/sizeof(keys[0]);
  int i;
  // points to the head node of the linked list
  struct Node* head = NULL;

  // construct a linked list
  for (i = n-1; i >= 0; i--) {
      push(&head, keys[i]);
  }

  //insertSort(&head);

  // print linked list
  printList(head);

  return 0;

}
