//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  int x,y;
  struct node *next;
};

void printList(struct node *head)
{
  struct node *current=head;
  while(current!=NULL)
  {
    printf("(%d,%d)->",current->x,current->y);
    current=current->next;
  }
}

void push(struct node **head,int x,int y)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));

  newNode->x=x;
  newNode->y=y;
  newNode->next=*head;
  *head=newNode;
}

void removeNodes(struct node **headref)
{
  struct node *current=*headref;
  struct node *Next=NULL;
  int x1,y1;

while(current->next!=NULL && current->next->next!=NULL ){
  Next=current->next->next;
  if((current->x ==current->next->x )&& (current->x== Next->x ))
  {
      free(current->next);
      current->next=Next;
  }
  else if((current->y==current->next->y ) &&( current->y == Next->y))
  {
     free(current->next);
     current->next=Next;
  }
  else {
    current=current->next;
  }
       //printf("(%d %d) ",current->x,current->y);
  }
  //*headref=Next;
}

int main()
{
  int i;
  int key[][2]={{0,1},{0,5},{0,8},{2,8},{5,8},
                {7,8},{7,10},{7,12}
              };
  int n=sizeof(key)/sizeof(key[0]);

  struct node* head = NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, key[i][0],key[i][1]);
  }
  removeNodes(&head);
  printList(head);

  return 0;

}
