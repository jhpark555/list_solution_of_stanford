//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
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

void push(struct node **head,int key)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));

  newNode->data=key;
  newNode->next=*head;
  *head=newNode;
}

#if 1
void reverseNode(struct node **headref,int start,int end)
{
  struct node *Next=NULL;
  struct node *current=*headref;
  struct node *prev=NULL;
//printf("==%d \n",current->data);

while(current!=NULL && current->data <start)
{
  //printf("%d ",current->data);
  prev=current;
  current=current->next;
}
//  printf("%d ",current->data);
struct node *Start=current;
struct node *End=NULL;

int N=end-start+2;
int i=start;

 while(current!=NULL && i++<=N)
 {
  // printf("%d ",current->data);
    Next=current->next;
    current->next=End;
    End=current;
    current=Next;
 }

 Start->next=current;
 if(prev!=NULL){
   prev->next=End;
 }
 else {
   *headref=End;
 }

}
#else
// Iteratively reverse a linked list from position `m` to `n`
// Note that the head is passed by reference
void reverseNode(struct node **head, int m, int n)
{
    struct node* prev = NULL;        // the previous pointer
    struct node* curr = *head;        // the main pointer
    int i;

    // 1. Skip the first `m` nodes
    for (i = 1; curr != NULL && i < m; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    // prev now points to position the (m-1)'th node
    // `curr` now points to position the m'th node

    struct node* start = curr;
    struct node* end = NULL;

    // 2. Traverse and reverse the sublist from position `m` to `n`
    for (i = 1; curr != NULL && i <= n - m + 1; i++)
    {
        // Take note of the next node
        struct node* next = curr->next;

        // move the current node onto the `end`
        curr->next = end;
        end = curr;

        // move to the next node
        curr = next;
    }

    /* `start` points to the m'th node
    `end` now points to the n'th node
    `curr` now points to the (n+1)'th node */

    // 3. Fix the pointers and return the head node
    start->next = curr;
    if (prev != NULL) {
        prev->next = end;
    }
    // when `m = 1` (`prev` is null)
    else {
        // fix the head pointer to point to the new front
        *head = end;
    }
}
#endif
int main()
{
  // input keys
  int keys[] = {1, 2, 3, 4, 5, 6,7};
  int n = sizeof(keys)/sizeof(keys[0]);
  int i;
  // points to the head node of the linked list
  struct node* head = NULL;
  int start=2,end=5;

  // construct a linked list
  for (i = n-1; i >= 0; i--) {
      push(&head, keys[i]);
  }

  reverseNode(&head,start,end);
  // print linked list
  printList(head);

  return 0;

}
