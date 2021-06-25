//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a,b) ( a^=b^=a^=b)
int count;

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
#if 0
void movenode(struct node** destRef, struct node** sourceRef)
{
    // if the source list empty, do nothing
    if (*sourceRef == NULL) {
        return;
    }

    struct node* current = *sourceRef;  // the front source node
    *sourceRef = (*sourceRef)->next;    // advance the source pointer
    current->next = *destRef;           // link the old dest off the new node
    *destRef = current;                 // move dest to point to the new node

}
#endif
void movenode(struct node **destRef,struct node **sourceRef)
{
    struct node *current=*sourceRef;

    *sourceRef=(*sourceRef)->next;
    current->next=*destRef;
    *destRef=current;
}
void reverseNode(struct node** headref)
{
  struct node *Next=NULL;
  struct node *current=*headref;
  struct node *prev=NULL;

  while(current!=NULL)
  {
    Next=current->next;
    current->next=prev;
    prev=current;
    current=Next;
  }
  *headref=prev;
}

#if 1
void traverseEvenOdd(struct node **headref)
{
  struct node *oddnew=NULL;
  struct node *evennew=NULL;
  struct node *current=*headref;
  struct node *even=NULL;
  struct node *odd=NULL;
  int count=1;

  while(current!=NULL)
  {
   if(count++%2==1){    //odd
    movenode(&oddnew,&current);
   }
   else
   {
    movenode(&evennew,&current);
   }
  }

  //current=evennew;
  current=oddnew;
  while(current->next!=NULL)
  {
    current=current->next;
  }
  //  current->next=oddnew;
  current->next=evennew;
  //  *headref=evennew;
  *headref=oddnew;

  reverseNode(headref);

}
#else
void traverseEvenOdd(struct node **headref)
{
  struct node *current=*headref;
  struct node *even=NULL; struct node *eventail=NULL;
  struct node *odd=NULL; struct node *oddtail=NULL;
  int count=1;

  while(current!=NULL)
  {
     if(count++%2 ==1)      //odd node
     {
      if(odd==NULL)
      {
        oddtail=odd=current;
      }
      else {
        oddtail->next=current;
        oddtail=oddtail->next;
      }

     }
     else                 // even node
     {
       if(even==NULL)
       {
         eventail=even=current;
       }
       else
       {
         eventail->next=current;
         eventail=current;
       }
     }
     current=current->next;
  }
  if(even)
  {
    *headref=even;
    eventail->next=odd;
  }
  else {
    *headref=odd;
  }

  if(oddtail) {
    oddtail->next=NULL;
  }

}
#endif
int main()
{
  int i;

  int arr[] = {1,2,3,4,5,6,7 };

  int n = sizeof(arr)/sizeof(arr[0]);

  struct node* head = NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, arr[i]);
  }
  traverseEvenOdd(&head);
  //printf("Before :");
  printList(head);   printf("\n");


  return 0;

}
