/******************************************************************************


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node *List;

int Count(struct node *head,int searchfor);
int GetNth(struct node *head,int index);
void DeleteList(struct node **head);
int Pop(struct node **headrf);
void InsertNth(struct node **headref,int nth,int num);

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
int counttest()
{
    //struct node *mylist = buildonetwothree();
    List mylist= buildonetwothree();

    int count =Count(mylist,2);

    return count;
}

int Count(struct node *head,int searchfor)
{
    struct node *current= head;
    int count=0;

    while(current!=NULL){
        if(current->data==searchfor) count++;
        current=current->next;
    }
    return (count);
}

int GetNthtest(){
    struct node *mylist= buildonetwothree();
    int lastnode = GetNth(mylist,2);

    return(lastnode);
}

int GetNth(struct node *head,int index)
{
    struct node *current=head;
    int count=0;

    while(current!=NULL){
        if(count ==index ) return(current->data);
        count++;
        current=current->next;
    }

}

void DeleteListTest(){
    struct node *mylist =buildonetwothree();

    DeleteList(&mylist);
}

void DeleteList(struct node **head)
{
    struct node *current =*head;
    struct node *dumy;

    while(current !=NULL){
        dumy=current->next;
        free(current);
        current=dumy;
    }
    *head=NULL;
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
void PopTest(){
    struct node *head = buildonetwothree();
   //int a = Pop(&head);
    //int b= Pop(&head);
   // int c = Pop(&head);

    int len=length(head);
}
void push(struct node **headref, int data)
{
    struct node *newnode = malloc(sizeof (struct node));
    newnode->data=data;
    newnode->next=*headref;
    *headref=newnode;
    //printf("%d ",(*headref)->data);
}
void InsertNthTest(){
    struct node *head= NULL;

    InsertNth(&head,0,13);
    InsertNth(&head,1,42);
    InsertNth(&head,1,5);

    int len=length(head);
    DeleteList(&head);

}

void InsertNth(struct node **headref,int index,int data)
{
    struct node *current = *headref;
    int i=0;

    if(index ==0) push(headref,data);
    else{
        for( i=0 ; i<index-1 ; i++ )
           current=current->next;
        push(&(current->next),data);    //  important to -1.

    }


}
int Pop(struct node **headref)
{
    struct node *head = *headref;
  //  struct node *temp;
    int ret;


    ret= head->data;
    *headref= (*headref)->next;
   // temp=head;
   // current= head->next;
    free(head);
   // *headref= (*headref)->next;
  //  *headref=current->next;

 //printf("**ret=%d \n",ret);
    return ret;
}

void SortedInsert(struct node **headref, struct node *newnode)
{
    struct node *current = *headref;

    if(*headref==NULL || (*headref)->data == newnode->data){
        newnode->next = *headref;
        *headref= newnode;
    }
    else{
        while(current->next !=NULL && current->next->data < newnode->data){
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
    }

}
void SortedInsert2(struct node **headref, struct node *newnode)
{
    struct node dumy;
    struct node *current= &dumy;

    dumy.next=*headref;

    while(current->next !=NULL & current->next->data < newnode->data){
        current=current->next;
    }

    newnode->next=current->next;
    current->next=newnode;

    *headref=dumy.next;

}

void SortedInsert3(struct node **headref, struct node *newnode)
{
    struct node **currentref=headref;

    while(*currentref!=NULL && (*currentref)->data<newnode->data){
        currentref= &((*currentref)->next);
    }
    newnode->next= *currentref;
    *currentref= newnode;
}

void InsertSort(struct node** headref)
{
    struct node *result = NULL;
    struct node* current =*headref;
    struct node* next;

    while(current!=NULL){
        next=current->next;
        SortedInsert(&result,current);
        current=next;
    }
    *headref=result;
}

struct node *Append(struct node** aref, struct node ** bref)
{
    struct node *current=*aref;

    if(*aref==NULL){
        *aref=*bref;
    } else{
       while(current->next!=NULL){
          current=current->next;
       }
      current->next=*bref;

    }
   *bref=NULL;

    return (*aref) ;// length(*aref);
}

void FrontBackSplit(struct node* source,struct node**frontref,struct node** backref)
{
    struct node* current=source;
    int count=1,fh,bh;

    while(current->next!=NULL){
        count++;
        current=current->next;
    }
   // fh=(count+1)/2;   bh=count-fh;

   // count = length(source);
   // printf("*****%d \n",count);

    current=source;
    if(count<2){
        *frontref=source;
        *backref=NULL;
    }
    else{
        int hopcount=(count-1)/2;
        for(int i=0;i<hopcount;i++){
            current=current->next;
              printf("**data=%d \n",current->data);
        }
        *frontref=source;
        *backref=current->next;
        current->next=NULL;

    }
}


void FrontBackSplit2(struct node* source,struct node**frontref,struct node** backref)
{
    struct node* fast;
    struct node* slow;

    if(source==NULL ||source->next==NULL){
        *frontref=source;
        *backref=NULL;
    }
    else{
        slow=source;
        fast=source->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        *frontref=source;
        *backref=slow->next;
        slow->next=NULL;

    }

}

void RemoveDuplicates(struct node* head)
{
    struct node* current=head;
    struct node* temp;

    while(current->next!=NULL){
        if(current->data == current->next->data) {
            temp=current->next->next;
            free(current->next);
            current->next=temp;
        }
        else{
        current=current->next;
        }
    }
}


int main()
{
    int x=counttest();

    struct node *head=buildonetwothree();
    struct node *tail=buildonetwothree();
    struct node *mylist=malloc(sizeof(struct node));
    struct node* front=malloc(sizeof(struct node));;
    struct node* back=malloc(sizeof(struct node));;

  //  x= GetNthtest();
  //  DeleteListTest();
   // PopTest();
 //   printf("count x = %d ",x);
   // InsertNthTest();

 // SortedInsert3(&head,mylist);
  // mylist = Append(&head,&tail);
  // length(mylist);
  push(&head,4); push(&head,5);push(&head,5);push(&head,7);
 // FrontBackSplit2(head,&front,&back);
 // length(front);
  RemoveDuplicates(head);
  length(head);
 // printf("--------\n");
  //length(back);
    return 0;
}
