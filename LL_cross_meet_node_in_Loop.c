
#include <stdio.h>
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

struct node *detectionNodes(struct node *a)
{
  struct node *slow=a;
  struct node *fast=a;

  while(slow && fast)
  {
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast) break;
  }
  //printf("%d  %d",slow->data,fast->data);
  return fast;
}

struct node *findCrossNodes(struct node *head,struct node *loop)
{
   while(head && loop )
   {
     head=head->next;
     loop=loop->next;
     if(head==loop) return loop;
   }
}
int main()
{
  // input keys
  int keys[] = { 1, 2, 3, 4, 5,6,7 };
  int n = sizeof(keys) / sizeof(keys[0]);
  int i;
  struct node * head = NULL;
  for (i = n - 1; i >= 0; i--) {
      push(&head, keys[i]);
  }
  // insert cycle
 head->next->next->next->next->next->next->next = head->next->next->next;

 struct node *CP=detectionNodes(head);
 printf("Cross point=%d \n",CP->data);       //meet nodes in loop
//printList(head); printf("  ");

 struct node *curr=findCrossNodes(head,CP);   //cross nodes in loop

 printf("Start node= %d \n",curr->data);
return 0;

}
