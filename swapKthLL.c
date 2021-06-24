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

void traverseSwap(struct node **headref,int n)
{
  struct node *current=*headref;
  struct node *prev=NULL;
  struct node *prev2=NULL;
  struct node *X=NULL;
  struct node *Y=NULL;
  int count=0;
  int length=0;

  while(current!=NULL) {
    length++;
    current=current->next;
  }

  current=*headref;
  while(current->next!=NULL && count++<=n-2)
  {
    prev=current;
    current=current->next;
  }
  X=current;     //target node
  struct node *temp=current->next;   //point target next

  current=*headref; count =0;
  while(current!=NULL && count++ <=length-n-1)
  {
    prev2=current;
    current=current->next;
  }
  Y=current;       // target from end
  struct node *temp2=current->next;    //point target from end

  X->next=temp;
  Y->next=temp2;

  prev->next=Y;
  Y->next=temp;
  prev2->next=X;
  X->next=temp2;

//printf("*%d \n",Y->data);

}

int main()
{
  int i;

  int arr[] = {1,2,3,4,5,6,7,8 };
  int n = sizeof(arr)/sizeof(arr[0]);

  struct node* head = NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, arr[i]);
  }
  printf("Before :");
  printList(head);   printf("\n");
  traverseSwap(&head,2);
  printf("After :");
  printList(head);

  return 0;

}
