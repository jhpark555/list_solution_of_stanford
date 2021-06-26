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

#if 0
void traverseNodes(struct node **headref)
{
    struct node *current=(*headref)->next;
    struct node *prev=*headref;

    while(current!=NULL)
    {
       if(prev->data > current->data){
          swap(prev,current);
       }

       if(current->next->data>current->data)
          swap(current->next,current);

       prev=current->next;
       current=current->next->next;
    }
  }
#else
void traverseNodes(struct node **headref)
{
   struct node *current=*headref;

   while(current->next!=NULL)
   {
    // printf("##%d %d\n",current->data,current->next->data);
     if(current->data> current->next->data)
       swap(current,current->next);

     if(current->next->data < current->next->next->data)
       swap(current->next,current->next->next);

      current=current->next->next;
    //  printf("##%d %d\n",current->data,current->next->data);
   }

}
#endif

int main()
{
  int i;

  int arr[]={1,2,3,4,5,6,7,8,6};

  int n = sizeof(arr)/sizeof(arr[0]);

  struct node* head = NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, arr[i]);
  }
  traverseNodes(&head);
  printList(head);
  return 0;

}
