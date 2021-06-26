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

int IsThere(int arr[],int data,int n)
{
  int i;

  for(i=0;i<n;i++)
   if(data == arr[i]){
      return 1;
    }
  return 0;
}

void removeDuplicate(struct node **headref,int n)
{
   struct node *prev;
   struct node *current=*headref;
   int Stack[n];
   int i=0;

   while( current!=NULL)
   {
     if(IsThere(Stack,current->data,i-1))
     {
       prev->next=current->next;
     }
     else
     {
       Stack[i++]=current->data;
       prev=current;
     }

     current=current->next;
   }

}

int main()
{
  int i;

  int arr[]={5,3,4,2,5,4,1,3};

  int n = sizeof(arr)/sizeof(arr[0]);

  struct node* head = NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, arr[i]);
  }
  removeDuplicate(&head,n);  printf("\n");
  printList(head);
  return 0;

}
