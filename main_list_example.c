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
void MoveNode(struct node** destref,struct node** sourceref)
{
    struct node* newnode=*sourceref;
    *sourceref=newnode->next;
    newnode->next=*destref;
    *destref=newnode;

    //length(*sourceref); printf("\n");
    //length(*destref);
}

void Movenodetest()
{
    struct node* a=buildonetwothree();
    struct node* b=buildonetwothree();

    MoveNode(&a,&b);
}

void AlternatingSplit(struct node* source,struct node** aref,struct node** bref)
{
    struct node* current = source;
    struct node* a=NULL;
    struct node* b=NULL;
    int count=0;
    length(source); printf("++++++\n");

  #if 0
    for(count; current!=NULL; current=current->next,count++ ){
        if(count %2 ==0) {
          a=current;
          a=a->next;
         //MoveNode(&a,&current);
        // printf("E");
        }
        else{
         b=current;
         b =b->next;
        //MoveNode(&b,&current);
         // printf("O");
        }
    }
    *aref=a;
    *bref=b;
 #else
    while(current!=NULL){
        MoveNode(&a,&current);
        if(current!=NULL){
            MoveNode(&b,&current);
        }
    }
    *aref=a;
    *bref=b;
 #endif
    length(*aref);printf("**\n"); length(*bref);
}


struct node* ShuffleMerge(struct node* a, struct node* b)
{
    struct node dumy;
    struct node* newnode= &dumy;
    dumy.next=NULL;

    while(1){
         if(a==NULL){
             newnode->next=b;
              break;
         }
         else if(b==NULL){
             newnode->next=a;
             break;
         }
         else{
             newnode->next=a;
             newnode=a;
             a=a->next;
             newnode->next=b;
             newnode=b;
             b=b->next;
         }

    }
    return(dumy.next);


}


struct node* ShuffleMerge2(struct node* a, struct node* b)
{
    struct node dumy;
    struct node* newnode= &dumy;
    dumy.next=NULL;

    while(1){
         if(a==NULL){
             newnode->next=b;
              break;
         }
         else if(b==NULL){
             newnode->next=a;
             break;
         }
         else{
           MoveNode(&(newnode->next),&a);
           newnode=newnode->next;
           MoveNode(&(newnode->next),&b);
           newnode=newnode->next;
         }

    }
    return(dumy.next);


}


struct node* ShuffleMerge3(struct node* a, struct node* b)
{
    struct node* result;
    struct node** ptrref=&result;


    while(1){
         if(a==NULL){
             *ptrref=b;
              break;
         }
         else if(b==NULL){
             *ptrref=a;
             break;
         }
         else{
           MoveNode(ptrref,&a);
           ptrref=&((*ptrref)->next);
           MoveNode(ptrref,&b);
           ptrref= &((*ptrref)->next);
         }

    }
    return(result);
}

struct node* ShuffleMerge4(struct node* a, struct node* b)
{
    struct node* result;
    struct node* recur;

    if(a==NULL) return(b);
    else if(b==NULL) return(a);
    else{
        recur = ShuffleMerge4(a->next,b->next);
        result=a;
        a->next=b;
        b->next=recur;
        return( result);
    }
}

struct node* SortedMerge(struct node* a,struct node* b)
{
    struct node dummy;
    struct node *tail=&dummy;
    dummy.next=NULL;

    while(1){
        if(a==NULL){
            tail->next=b;
            printf("a null\n");
            break;
        }
        else if(b==NULL){
            tail->next=a;
              printf("b null\n");
            break;
        }
        else{
           // printf("*a=%d b=%d \n",a->data,b->data);
            if(a->data<=b->data) {
                MoveNode(&(tail->next),&a);
            }
            else{
                MoveNode(&(tail->next),&b);
            }
            tail=tail->next;
        }
    }
    return(dummy.next);
}

struct node* SortedMerge2(struct node* a,struct node* b)
{
    struct node* result=NULL;
    struct node** ptrref=&result;


    while(1){
        if(a==NULL){
            *ptrref=b;
            printf("a null\n");
            break;
        }
        else if(b==NULL){
            *ptrref=a;
              printf("b null\n");
            break;
        }
        else{
           // printf("*a=%d b=%d \n",a->data,b->data);
            if(a->data<=b->data) {
                MoveNode(ptrref,&a);
            }
            else{
                MoveNode(ptrref,&b);
            }
            ptrref=(&(*ptrref)->next);
        }
    }
    return(result);
}

struct node* SortedMerge3(struct node* a,struct node* b)
{
    struct node* result=NULL;


        if(a==NULL){
            return(b);
            printf("a null\n");
        }
        else if(b==NULL){
            return(a);
              printf("b null\n");
        }

           // printf("*a=%d b=%d \n",a->data,b->data);
            if(a->data<=b->data) {
            result =a;
            result->next= SortedMerge3(a->next,b);
            }
            else{
                result=b;
                result->next=SortedMerge3(a,b->next);
            }

    return(result);
}


void MergeSort(struct node** headref)
{
    struct node* head= *headref;
    struct node* a;
    struct node* b;

    if( (head==NULL) || (head->next==NULL) ) return;

    FrontBackSplit(head,&a,&b);
    MergeSort(&a);
    MergeSort(&b);
    *headref = SortedMerge(a,b);

}

struct node* SortedIntersect(struct node*a , struct node* b)
{
    struct node dummy;
    struct node* tail=&dummy;
    dummy.next=NULL;

    while(a!=NULL && b!=NULL){
        if(a->data == b->data){
            push((&tail->next),a->data);
            tail=tail->next;
            a=a->next;
            b=b->next;
        }
        else if(a->data < b->data){
            a=a->next;
        }
        else{
            b=b->next;
        }
    }
    return(dummy.next);
}

struct node* SortedIntersect2(struct node*a , struct node* b)
{
    struct node* result=NULL;
    struct node** ptrref = &result;

    while(a!=NULL && b!=NULL){
        if(a->data == b->data){
            push(ptrref,a->data);
            ptrref= &((*ptrref)->next);
            a=a->next;
            b=b->next;
        }
        else if(a->data < b->data){
            a=a->next;
        }
        else{
            b=b->next;
        }
    }
    return(result);
}
void Reverse(struct node** ptrref)
{
    struct node* prev=NULL;
    struct node *current = *ptrref;
    struct node* next;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
   *ptrref=prev;

    length(*ptrref);
}

void Reverse2(struct node** ptrref)
{
    struct node* prev=NULL;
    struct node *current = *ptrref;

    while(current!=NULL){
      MoveNode(&prev,&current);
    }
   *ptrref=prev;

    length(*ptrref);
}

void Reverse3(struct node** ptrref)
{
    struct node* middle = *ptrref;
    struct node* front =middle->next;
    struct node* back=NULL;

    while(1){
        middle->next = back;
        if(front ==NULL) break;
        back=middle;
        middle=front;
        front=front->next;

    }
   *ptrref=middle;

    length(*ptrref);
}



void ReverseTest()
{
    struct node* head;

    head=buildonetwothree();
    Reverse3(&head);

    DeleteList(&head);

}

void RecursiveReverse(struct node** headref)
{
    struct node* first;
    struct node* rest;

    if(*headref ==NULL) return;

    first=*headref;     // 1,2,3
    rest=first->next;   //2.3

    if(rest==NULL) return;

    RecursiveReverse(&rest);

    first->next->next=first;
    first->next=NULL;

    *headref =rest;


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
 // push(&head,4); push(&head,5);push(&head,5);push(&head,7);
 // FrontBackSplit2(head,&front,&back);
 // length(front);
 // RemoveDuplicates(head);
 // length(head);
 //Movenodetest();

 //AlternatingSplit(head,&front,&back);
 //length(head); printf(":");
 //length(tail); printf("\n");
// struct node* res=ShuffleMerge3(head,tail);
//struct node* res= SortedMerge3(head,tail);
//struct node* res = SortedIntersect2(head,tail);
// length(res);
 // printf("--------\n");
  //length(back);
  //ReverseTest();
  RecursiveReverse(&head);  length(head);
    return 0;
}
