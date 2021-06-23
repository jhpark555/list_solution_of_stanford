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

int detectCycle(struct node *head)
{
  struct node *slow=head;
  struct node *fast=head;

  while(fast && fast->next)
  {
    slow=slow->next;
    fast=fast->next->next;

    if(slow==fast) {
      printf("%d ",slow->data);
      return 1;        // fast will be overlap after rotation
    }
  }
  return 0;
}

struct node *findIntersection(struct node *first,struct node *second)
{
 struct node *x=first;
 struct node *y=second;

 while(x!=y)
 {
   // When the first list reaches its end, redirect it to the
   // head of the second list
   if(x==NULL) x=second;
   else x=x->next;

   // When the second list reaches its end, redirect it to the
   // head of the first list
   if(y==NULL) y=first;
   else y=y->next;

 }

  return x;
}

int main()
{
  int i;
  // points to the head node of the linked list
  struct node* first = NULL;

  // construct a linked list
  for (i = 7; i > 0; i--) {
      push(&first, i);
  }

  struct node *second=NULL;
  // insert cycle
  // construct a linked list
  for (i = 3; i > 0; i--) {
      push(&second, i);
  }

  // link tail of the second list to the fourth node of the first list
  second->next->next->next = first->next->next->next;

  struct node *head= findIntersection(first,second);

  if(head)  printf("Intersection is %d \n",head->data);
  else printf("No intersection \n");
//  printList(first); printf("\n");
//  printList(second);

  return 0;

}
