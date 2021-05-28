/******************************************************************************



*******************************************************************************/

#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *Buildonetwothree(){
    struct node *head = NULL;
    struct node *second=NULL;
    struct node *third = NULL;

    head=malloc(sizeof(struct node));
    second=malloc(sizeof(struct node));
    third =malloc(sizeof(struct node));

    head->data=1;
    head->next= second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    return head;


}

int length(struct node *head)
{
    struct node* current =head;
    int count =0;

    while(current !=NULL)
    {
        printf("%d ->",current->data);
        count++;
        current=current->next;

    }

    //for(current=head ; current!=NULL ;current=current->next ) count++;
    return count;
}

void push(struct node **head,int data)    //push pass point
{
    struct node* newnode =malloc(sizeof(struct node));

    newnode->data=data;
    newnode->next=*head;
    *head=newnode;

}
void pushtest()
{
    struct node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    length(head);
}

void changetonull(struct node **head)
{
    *head=NULL;
}

struct node * addathead()
{
    struct node *head=NULL;
    int i;

    for(i=0;i<6;i++){
        push(&head,i);
    }

    return(head);
}

struct node * buildspecialcase()
{
    struct node *head=NULL;
    struct node *tail=NULL;
    int i;

    push(&head,1);
    tail=head;

    for(i=2;i<6;i++){
        push(&(tail->next),i);
        tail=tail->next;
    }

    return(head);
}

struct node* builddummynode()
{
    struct node dummy;
    struct node *tail=&dummy;    //start at the dummy
                                //build the list on dummy.next

    int i;
    dummy.next=NULL;

    for(i=1;i<6;i++){
        push(&(tail->next),i);
        tail=tail->next;
    }

    //return(dummy.next);      // why tail->next is not working ??? pjh

}

struct node* buildwithlocalref()
{
    struct node *head=NULL;
    struct node **lastptrref=&head;
    int i;

    for(i=1;i<6;i++){
        push(lastptrref,i);
        lastptrref=&((*lastptrref)->next);
    }

    return(head);
}

struct node *appendnode(struct node **headref,int num)
{
    struct node *current=*headref;
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=num;

    if(current==NULL)
      *headref=newnode;
    else{
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newnode;
    }

    return(newnode);
}

struct node *appendpush(struct node **headref,int num)
{
    struct node *current = *headref;

    if(current==NULL)
      push(headref,num);
    else{
        while(current->next!=NULL){
            current=current->next;
        }
      }
      push(&(current->next),num);

    return(current->next);
}


struct node *copylist(struct node*head)
{
    struct node *current=head;
    struct node* newlist=NULL;
    struct node* tail=NULL;

    while(current!=NULL){
        if(newlist==NULL){
        newlist=malloc(sizeof(struct node));
        newlist->data=current->data;
        newlist->next=NULL;
        tail=newlist;
       }
       else{
           tail->next=malloc(sizeof(struct node));
           tail=tail->next;
           tail->data=current->data;
           tail->next=NULL;
       }
       current=current->next;
    }

    return(newlist);
}

struct node* copylistpush(struct node* head)
{
    struct node *current=head;
    struct node *newlist=NULL;
    struct node *tail=NULL;

    while(current!=NULL){
        if(newlist ==NULL){
            push(&newlist,current->data);
            tail=newlist;
        }
        else{
            push(&(tail->next),current->data);
            tail=tail->next;
        }
        current=current->next;
    }

    return(newlist);
}
struct node *copydummy(struct node *head)
{
    struct node *current=head;
    struct node *tail=NULL;
    struct node dummy;

    dummy.next=NULL;
    tail=&dummy;
    while(current!=NULL){
        push(&(tail->next),current->next);
        tail=tail->next;
        current=current->next;
    }
    return(dummy.next);
}

struct node *copylocal(struct node *head)
{
    struct node *current=head;
    struct node *newlist=NULL;
    struct node **lastptr;

    lastptr= &newlist;

    while(current!=NULL){
        push(lastptr,current->data);
        lastptr= &((*lastptr)->next);
        current=current->next;
    }
    return(newlist);

}

struct node *copyrecur(struct node *head)
{
    struct node *current=head;

    if(head ==NULL) return NULL;
    else{
        struct node *newlist =malloc(sizeof(struct node));
        newlist->data=current->data;
        newlist->next=copylocal(current->next);
        return(newlist);
    }
}
int main()
{
    struct node *mylist =Buildonetwothree();
    struct node *newnode;

    newnode= malloc(sizeof(struct node));
    newnode->data=0;

    newnode->next=mylist;
    mylist=newnode;

    push(&mylist,-1);
    push(&mylist,-2);

  //  changetonull(&mylist);
  //  pushtest();
    mylist= addathead();
    mylist = buildspecialcase();
    mylist =builddummynode();
    mylist =buildwithlocalref();

   appendpush(&mylist,10);
    int len= length(mylist);

   struct node *this= copyrecur(mylist);//copylocal(mylist);//copylistpush(mylist);
    printf("\n");
    length(this);
   //printf("\n%d \n",len);
    return 0;


}
