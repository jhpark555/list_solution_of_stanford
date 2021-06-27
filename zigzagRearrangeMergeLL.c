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
void reverseLL(struct node **headref)
{
   struct node *next=NULL;
   struct node *prev=NULL;
   struct node *curr=*headref;

   while(curr!=NULL)
   {
     next=curr->next;
     curr->next=prev;
     prev=curr;
     curr=next;
   }
   *headref=prev;
}
#if 1
struct node *rearrangeMerge(struct node *a,struct node *b)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    struct node *temp=NULL;
    struct node *current=newNode;   // newnode is moving to the last.

    newNode->data=0;
    newNode->next=NULL;

    while(a!=NULL && b!=NULL)
    {
      //  temp=a;
      //  a=a->next;
      //  temp->next=newNode;
      //printf("*%d %d \n",a->data,b->data);
        newNode->next=a;
        newNode=a;
        a=a->next;

      //  temp=b;
      //  b=b->next;
      //  temp->next=newNode;
        newNode->next=b;
        newNode=b;
        b=b->next;
      }
    return current->next;
}
#else
struct node *rearrangeMerge(struct node *a,struct node *b)
{
     struct node *tempa=a;
     struct node *tempb=b;
     struct node *newNode=NULL;//(struct node*)malloc(sizeof(struct node));


     while(tempa!=NULL && tempb!=NULL)
     {
          movenode(&newNode,&tempa);
          movenode(&newNode,&tempb);

     }
    // printf("\n%d  %d \n",tempa,tempb);
       while(tempb!=NULL)
       {

       movenode(&newNode,&tempb);

       }
       while(tempa!=NULL)
       {

        movenode(&newNode,&tempa);

      }
     reverseLL(&newNode);
     return newNode;

}
#endif
int main()
{
  int i;

  int arr[]={1,2,3,4};

  int n = sizeof(arr)/sizeof(arr[0]);

  struct node* a = NULL;
  struct node *b=NULL;

  // construct the first list
  for (i = 3; i >= 0; i--) {
        push(&a, i);
  }

    // construct the second list
  for (i = 10; i >= 4; i--) {
        push(&b, i);
  }

printList(a); printf("  "); printList(b);
struct node *new=  rearrangeMerge(a,b);
printf("\n");
  printList(new);
  return 0;

}
