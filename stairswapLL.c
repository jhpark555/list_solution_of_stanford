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
//DLL push
void push(struct node **head,int data)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));

  newNode->data=data;
  newNode->next=*head;

  *head=newNode;
}
//stair swap
void swap(struct node **head)
{
   struct node *current=*head;
   struct node *prev=NULL;

   while( current!=NULL)
   {
     struct node *temp=current->next;
     current->next=temp->next;
     temp->next=current;

     if(prev==NULL)  *head=temp;   //curr->temp
     else prev->next=temp;     // prev->curr->temp

     prev=current;
     current=current->next;
   }
}


int main()
{
  int i;
  int key[] = { 1, 2, 3, 4, 5 ,6 ,7 ,8};
  int n = sizeof(key)/sizeof(key[0]);

  struct node* head = NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, key[i]);
  }
  swap(&head);
  printList(head);

  return 0;

}
