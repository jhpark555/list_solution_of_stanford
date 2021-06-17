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

void movenode(struct node **dst, struct node **src)
{
    struct node *New=*src;

    *src=New->next;
    New->next=*dst;
    *dst=New;
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
