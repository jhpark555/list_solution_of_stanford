
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *buildonetwothree()
{
    struct node *head=malloc(sizeof(struct node));
    struct node *second=malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=2;
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

struct node *reversenode(struct node *head)
{
    struct node *prev=NULL;
    struct node *current=head;
    struct node *next=NULL;

    while(current!=NULL)
    {
      next=current->next;
      current->next=prev;
      prev=current;
      current=next;
    }
    head=prev;

    return(head);
}

int compare( struct node *l1,struct node *l2)
{
    struct node *current=l1;

    while(l1!=NULL/*current!=NULL*/)
    {
        if(l1->data!=l2->data) return -1;
        l1=l1->next;
        l2=l2->next;
      //  current=current->next;
    }
    return 0;
}
int main()
{
    struct node *test=buildonetwothree();
    struct node *test1;

    display(test);
    printf("***\n");
   test1= reversenode(test);
    display(test1);

    int c=compare(test,test1);

    printf("\n**c= %d \n",c);
    return 0;
}
