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
#if 0
int detectCycle(struct node *head)
{
   struct node *current =head;
   int data[10];
   int i=0,k;

   while(current!=NULL)
   {
    data[i++]=current->data;

    for(k=0;k<i;k++)
    {
      if(data[k]==current->next->data) {
        printf("*cycle data =%d \n",data[k]);
        return 1;
      }
    }
     current=current->next;
   }
   printf("No cycle here\n");
   return 0;
}
#else
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
#endif
int main()
{
  // input keys
  int keys[] = {1, 2, 3, 4, 5};
  int n = sizeof(keys)/sizeof(keys[0]);
  int i;
  // points to the head node of the linked list
  struct node* head = NULL;
  int start=2,end=5;

  // construct a linked list
  for (i = n-1; i >= 0; i--) {
      push(&head, keys[i]);
  }

  // insert cycle
  head->next->next->next->next->next=head->next->next;
  // print linked list

  if (detectCycle(head)) {
      printf("Cycle Found\n");
    }
  else {
      printf("No Cycle Found\n");
  }

  //printList(head);

  return 0;

}
