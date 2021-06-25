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

struct node *sortedMerge(struct node *a,struct node *b)
{
  if(a==NULL) return b;
  else if(b==NULL) return a;

  struct node* result=NULL;

  if(a->data < b->data )
  {
    result =a;
    result->next=sortedMerge(a->next,b);
  }
  else {
    result =b;
    result->next =sortedMerge(a,b->next);
  }
 return result;

}
void FrontBackSplit2(struct node *source,struct node **frontRef,struct node **backRef)
{
   struct node *slow=NULL;
   struct node *fast=NULL;

   if(source==NULL || source->next==NULL){
    *frontRef=source;
    *backRef=NULL;
  }
  else {
    slow=source;
    fast=source->next;
    while(fast!=NULL)
    {
      fast=fast->next;
      if(fast!=NULL)
      {
        slow=slow->next;
        fast=fast->next;
      }
    }

    *frontRef=source;
    *backRef=slow->next;
    slow->next=NULL;

  }
}

void mergesort(struct node **headref)
{
  if(*headref==NULL || (*headref)->next==NULL)
   return;

  struct node *a;
  struct node *b;

  FrontBackSplit2(*headref,&a,&b);
  mergesort(&a);
  mergesort(&b);

  *headref=sortedMerge(a,b);

}
int main()
{
  int i;

  int arr[] = {6, 8, 4, 3, 1, 9 };

  int n = sizeof(arr)/sizeof(arr[0]);

  struct node* head = NULL;
  struct node *F=NULL;
  struct node *B=NULL;
  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, arr[i]);
  }

//  printList(head);   printf("\n");
//  FrontBackSplit2(head,&F,&B);
  mergesort(&head);
  //printList(F);   printf("\n"); printList(B);
  printList(head);
  return 0;

}
