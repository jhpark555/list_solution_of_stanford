/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
int length(struct node *head){
    int count =0;

    struct node *current =head;
    while(current!=NULL){
        count++;
          printf("%d ",current->data);
        current=current->next;
    }

    return (count);
}




void push(struct node **headref, int data)
{
    struct node *newnode = malloc(sizeof (struct node));
    newnode->data=data;
    newnode->next=*headref;
    *headref=newnode;
    //printf("%d ",(*headref)->data);
}

void changetonull(struct node **headref)
{
    *headref=NULL;
}


void changecaller()
{
    struct node *head1;
    struct node* head2;
    changetonull(&head1);
    changetonull(&head2);
}

struct node *addathead()
{
    struct node *head =NULL;
    int i;

    for(i=1;i<6;i++){
       push(&head,i);
    }
    return(head);

}


struct node* buildwithspecialcase()
{
    struct node *head=NULL;
    struct node *tail;
    int i;

    push(&head,1);
    tail=head;

    for(i=2;i<6;i++){
        push(&(tail->next),i);
        tail=tail->next;

    }
    return(head);
}

 struct node dummy;
struct node* builddummynode()
{
    //struct node dummy;
    struct node* tail=&dummy;

    int i;

    for(i=1;i<6;i++){
        push(&(tail->next),i);
        tail=tail->next;
    }
    return(dummy.next);
}

struct node *buildlocalref()
{
    struct node *head=NULL;
    struct node **lastptrref = &head;
    int i;

    for(i=1;i<6;i++){
        push(lastptrref,i);
        lastptrref = &((*lastptrref)->next);
    }
    return (head);
}

struct node *appendnodeA(struct node **headref,int num)
{
    struct node *current =*headref;
    struct node *newnode =malloc(sizeof(struct node));

    newnode->data=num;
    newnode->next=NULL;
    if( current==NULL){
      *headref=newnode;
      // printf("#");
    }
    else{
        while(current->next !=NULL){
            current=current->next;
        }
        //printf("*");
        current->next=newnode;
    }
}


struct node* appendnodeB(struct node **headref,int num)
{
    struct node *current = *headref;

    if(current ==NULL){
        push(headref,num);
    }
    else{
        while(current->next !=NULL){
            current=current->next;
        }
        push(&(current->next),num);
    }
}

struct node *copylist(struct node *head)
{
    struct node *current = head;
    struct node *newnode=NULL;
    struct node *tail=NULL;

    while(current!=NULL){
     if(newnode==NULL){
         newnode=malloc(sizeof(struct node));
         newnode->data=current->data;
         newnode->next= NULL;
         tail=newnode;
     }
     else{
         tail->next =malloc(sizeof(struct node));
         tail=tail->next;
         tail->data=current->data;
         tail->next=NULL;

     }
      current=current->next;
    }
    return(newnode);
}


struct node *copylistpush(struct node *head)
{
    struct node *current = head;
    struct node *newnode = NULL;
    struct node *tail=NULL;

    while( current !=NULL){
        if(newnode ==NULL){
            newnode=malloc(sizeof(struct node));
            push(&newnode,current->data);
            newnode->next= NULL;
            tail=newnode;
        }
        else{
            push(&tail->next,current->data);
            tail=tail->next;
        }

        current=current->next;
    }

    return(newnode);
}

struct node *copylistdummy(struct node *head)
{
    struct node *current=head;
    struct node *tail=NULL;
    struct node dummy;

    dummy.next = NULL;
    tail=&dummy;

    while(current!=NULL){
        push(&(tail->next),current->data);
        tail=tail->next;
        current=current->next;
    }
    return(dummy.next);
}

struct node *copyref(struct node *head)
{
    struct node *current = head;
    struct node *newlist= NULL;
    struct node **lastptr;

    lastptr= &newlist;
    while(current!=NULL){
        push(lastptr,current->data);
        lastptr = &( (*lastptr)->next);
        current=current->next;
    }
    return(newlist);
}

struct node *recursive(struct node *head)
{
    struct node *current= head;
    if(head == NULL) return NULL;
    else{
        struct node *newlist = malloc(sizeof( struct node));
        newlist->data=current->data;
        newlist->next=copylistdummy(current->next);

        return(newlist);
    }

}


void basiccaller(){
    struct node *head=malloc(sizeof(struct node));
    int len;
   // head->data=100;
    head= buildonetwothree();
    push(&head,13);
    push(&(head->next),42);

    len=length(head);

}
int main()
{
    struct node *myhead;
    struct node *newnode;

   // myhead=addathead();
   // myhead=buildwithspecialcase();
 //  myhead = builddummynode();
 myhead = buildlocalref();
  appendnodeB(&myhead,0);
   length(myhead);
   printf("\n_________\n");
  newnode = recursive(myhead);//copyref(myhead);//copylistdummy(myhead);
  basiccaller();
 length(newnode);
 printf("\n_________\n");
 //newnode= builddummynode(); //buildwithspecialcase(newnode);
 newnode = buildlocalref();
 length(newnode);
    return 0;
}
