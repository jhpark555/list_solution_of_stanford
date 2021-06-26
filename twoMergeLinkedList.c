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

struct node *reverseMerge(struct node *a,struct node *b)
{
     struct node *tempa=a;
     struct node *tempb=b;
     struct node *newNode=NULL;


     while(tempa!=NULL && tempb!=NULL)
     {
        if(tempa->data < tempb->data)
        {
          //printf("* %d %d \n",tempa->data,tempb->data);
          movenode(&newNode,&tempa);
        }
        else
        {
          //printf("# %d %d \n",tempa->data,tempb->data);
          movenode(&newNode,&tempb);
        }
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
     return newNode;
}

int main()
{
  int i;

  int arr[]={1,2,3,4};

  int n = sizeof(arr)/sizeof(arr[0]);

  struct node* a = NULL;
  struct node *b=NULL;

  for (i = 6; i > 0; i = i - 2) {
        push(&a, i);
  }

  for (i = 9; i >= 1; i = i - 2) {
        push(&b, i);
  }
printList(a); printf("  "); printList(b);
struct node *new=  reverseMerge(a,b);
printf("\n");
  printList(new);
  return 0;

}
