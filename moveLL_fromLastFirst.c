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


void swap(struct node *a,struct node *b)    //data swap only
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

struct node *reverseNodes(struct node **headref)
{
     struct node *Next=NULL;;
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

     return (prev);
}

int compare(struct node *a,struct node *b)
{
   struct node *tempa=a;
   struct node *tempb=b;

   while(tempa->next!=NULL || tempb->next !=NULL)
   {

     if(tempa->data != tempb->data) return 0;
    //printf("\n%d %d ",tempa->data,tempb->data);
    tempa=tempa->next;
    tempb=tempb->next;
   }

   return 1;
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

  int arr[]={1,2,3,4,3,2,1};

  int n = sizeof(arr)/sizeof(arr[0]);

  struct node* head = NULL;
  struct node *test=NULL;
  struct node *org=NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, arr[i]);
      push(&org,arr[i]);
  }

  printList(head); printf("\n");
  struct node *result=reverseNodes(&head);
  printList(head);
  int r= compare(result,org);
  printf("\nresult:");  printList(result);
  printf("Palindrome= %s \n",r ? "yes":"no");
  return 0;

}
