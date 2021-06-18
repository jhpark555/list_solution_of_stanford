// Online IDE - Code Editor, Compiler, Interpreter

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *buildonetwothree(int num1,int num2,int num3)
{
    struct node *head=malloc(sizeof(struct node));
    struct node *second=malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));

    head->data=num1;
    head->next=second;

    second->data=num2;
    second->next=third;

    third->data=num3;
    third->next = NULL;

    return head;

}

void display(struct node *head)
{
    struct node* current=head;

    while(current!=NULL)
    {
        printf("%d ->",current->data);
        current=current->next;
    }

}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the node from the front of the
   source, and move it to the front of the dest.
   It is an error to call this with the source list empty.

   Before calling MoveNode():
   source == {1, 2, 3}
   dest == {1, 2, 3}

   Affter calling MoveNode():
   source == {2, 3}
   dest == {1, 1, 2, 3} */
   // Function takes the node from the front of the source and moves it
   // to the front of the destination

   // new를 src로 만들고,
   // src는 다음으로 진행하고,
   //new의 next는 dst가 되고,
   //dst가 new의 header가 되고..

   void movenode(struct node** destRef, struct node** sourceRef)
   {
       // if the source list empty, do nothing
       if (*sourceRef == NULL) {
           return;
       }

       struct node* newNode = *sourceRef;  // the front source node
       *sourceRef = (*sourceRef)->next;    // advance the source pointer
       newNode->next = *destRef;           // link the old dest off the new node
       *destRef = newNode;                 // move dest to point to the new node
   }


int main()
{
      struct node *test;
      struct node *dst=NULL;

      test=buildonetwothree(1,2,3);
      movenode(&dst,&test);
      movenode(&dst,&test);
      movenode(&dst,&test);

      display(dst);
    return 0;

}
