
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

    third->data=3;
    third->next = NULL;

    return head;

}

int length(struct node* start)
{
    int i=0;

    while(start!=NULL){
        i++;
        start=start->next;
    }
    return i;

}

void push(struct node** head,int num)
{
    struct node * new_node=(struct node*)malloc(sizeof(struct node));

    new_node->data=num;
    new_node->next=*head;
    *head=new_node;


}

int pop(struct node **head)
{
    struct node *current=*head;

    if(current==NULL) return;
    else{
        *head=(*head)->next;
        free(current);
    }

    return (current->data);

}

struct node *append(struct node* head,int num)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    struct node *current=head;

    new_node->data=num;
    new_node->next=NULL;

    if(current==NULL)
     current=new_node;
     else{
        while(current->next!=NULL)
        {
            current=current->next;
        }
       // new_node->next=(*head)->next;
        current->next=new_node;
     }
    return(head);
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

struct node* sortedinsert(struct node *head,struct node *newnode)
{
     struct node *current = head;


        while(current->next !=NULL && current->next->data < newnode->data){
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;

    return (head);
}
struct node *deleteend(struct node* head)
{
    struct node *current=head;
    struct node *ptr=current;

    while(current->next!=NULL)
    {
        ptr=current;
        current=current->next;
    }
    ptr->next=NULL;//current->next;
    free(current);
   // current->next=NULL;

    return(head);

}
struct node *deletebeg(struct node *head)
{
    struct node *current=head;

   // if(current->next!=NULL){
        head=head->next;

        free(current);
    //}


    return(head);
}

void removedup(struct node* head)
{
    struct node *current=head;
    struct node *temp;

    while(current->next !=NULL){
        if(current->data==current->next->data)
        {
            temp=current->next->next;
            free(current->next);
            current->next=temp;
        }
        else
        {
            current=current->next;
        }
    }
}

struct node *insertend(struct node* head,int num)
{
    struct node *current=head;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    new->next=NULL;

    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=new;

    return(head);
}

struct node *insertbef(struct node* head,int cnt,int num)
{
    struct node *current=head;
    struct node *ptr;
    struct node *new=(struct node*)malloc(sizeof(struct node));

    new->data=num;

   while( current->data!=cnt)
   {
       ptr=current;
       current=current->next;
   }
   ptr->next=new;
   new->next=current;
 //  current=new;

   return(head);

}

struct node *insertaft(struct node* head,int cnt,int num)
{
    struct node *current=head;
    struct node *ptr=current;
    struct node *new=(struct node*)malloc(sizeof(struct node));

    new->data=num;

    while(ptr->data!=cnt)
    {
        ptr=current;
        current=current->next;
    }
    new->next=current;
    ptr->next=new;
    return(head);
}

struct node *sortlist(struct node *head)
{
    struct node *current=head;
    struct node *ahead;
    int temp;

    while(current->next!=NULL)
    {
       ahead=current->next;
       while(ahead!=NULL)
       {
           if(current->data>ahead->data)
           {
               temp=current->data;
               current->data=ahead->data;
               ahead->data=temp;
           }
           ahead=ahead->next;
       }
        current=current->next;
    }
    return(head);
}

int main()
{
    struct node *test;
    struct node *myfile=(struct node*)malloc(sizeof(struct node));

    myfile->data=2;

    test=buildonetwothree();

    push(&test,10);
     push(&test,2);
   test= append(test,4);
   // pop(&test);
    //  pop(&test);
   test=sortedinsert(test,myfile);
   removedup(test);
 // test= insertend(test,9);
 insertbef(test,4,8);
 insertaft(test,4,9);
 deleteend(test);
test=deletebeg(test);
test=sortlist(test);
    int l= length(test);
    printf("Hello World %d\n",l);
   display(test);
    return 0;
}
