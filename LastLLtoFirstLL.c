//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdint.h>


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


void swap(struct node *a,struct node *b)
{
  int temp;

  temp=b->data;
  b->data=a->data;
  a->data=temp;

}


void traverseNodes(struct node **headref)
{
   struct node *current=*headref;
   struct node *prev;
   while(current->next!=NULL)
   {
     prev=current;
     current=current->next;
   }
   current->next= *headref;
   *headref=current;
   prev->next=NULL;
   //movenode(headref,&prev);
}

void movenode(struct node **dst, struct node **src)
{
    struct node *temp=*src;

    (*src)=(*src)->next;
    temp->next=*dst;
    *dst=temp;

}

int main()
{
  int i;

  int arr[]={1,2,3,4};

  int n = sizeof(arr)/sizeof(arr[0]);

  struct node* head = NULL;
  struct node *test=NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, arr[i]);
  }

  traverseNodes(&head);
  printList(head);
  return 0;

}
