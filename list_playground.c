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

void display(struct node *head)
{
  struct node *current=head;

  while( current!=NULL)
  {
    printf("%d ->",current->data);
    current=current->next;
  }
}
struct node *addathead(struct node *head)
{
  int i;

  for(i=0;i<6;i++)
  push(&head,i);

  return head;
}

struct node *buildwithspecial()
{
  struct node *head=NULL;
//  struct node *tail;
struct node **lastptrref=&head;

//  push(&head,1);
//  tail=head;

  int i;

//  for(i=2;i<6;i++)
for(i=1;i<6;i++)
  {
  //  push(&(tail->next),i);
  push(lastptrref,i);
  //  tail=tail->next;
  lastptrref=&((*lastptrref)->next);
  }

  return(head);
}

void deletelist(struct node **headref)  //delete linke list
{
  struct node *current=*headref;
  struct node *next;

  while(current!=NULL)
  {
    next=current->next;    //important
    free(current);
    current=next;
  }
  *headref=NULL;
}

struct node *builddumynode()
{
  struct node dummy;
  struct node *tail=&dummy;
  int i;

  dummy.next=NULL;
  for(i=1;i<6;i++)
  {
    push(&(tail->next),i);
    tail=tail->next;
  }
  return(dummy.next);
}

int pop1(struct node **headref)
{
  struct node *current=*headref;

  int data = current->data;
  *headref= current->next;
  free(current);

  return data;
}

void insertNth(struct node **headref,int index,int data)
{
  struct node *current=*headref;
  int i=0;

//  for(i=0;i<index-1;i++)
while(i!=index-1)
  {
    i++;
    current=current->next;
  }

  push(&(current->next),data);

}
void sortedinsert(struct node **headref,struct node *newnode)
{
  if(*headref==0 || (*headref)->data>= newnode->data){
   newnode->next=*headref;
   *headref=newnode;
 }
 else{
   struct node *current=*headref;
   while(current->next !=NULL && current->data < newnode->data)
   {
     current=current->next;
   }
   newnode->next=current->next;
   current->next=newnode;

 }
}

void sortedinsert2(struct node **headref,struct node *newnode)
{
  struct node **currentref=headref;
  if(*currentref==0 || (*currentref)->data >=newnode->data)
  {
    newnode->next=*currentref;
    *currentref=newnode;
  }
 else{
  while((*currentref)->next !=NULL && (*currentref)->data < newnode->data)
  {
    currentref=&(*currentref)->next;
  }
  newnode->next= (*currentref)->next;
  (*currentref)->next=newnode;
 }
}

void insertsort(struct node **headref)
{
  struct node *current=*headref;
  struct node *next;
  struct node *result=NULL;

  while(current!=NULL)
  {
    next=current->next;
    sortedinsert2(&result,current);
    current=next;
  }
}

void append(struct node **aref,struct node **bref)
{
    struct node *current=*aref;

    if(*aref==NULL) *aref=*bref;
    else {
    while(current->next!=NULL)
    {
      current=current->next;
    }
    current->next=*bref;
   }
    *bref=NULL;

}

#if 0
void frontbacksplit(struct node *source,struct node **frontref,struct node **backref)
{
  struct node *current=source;
  int count=0,mid;
  int i;

  while(current!=NULL)
  {
    count++;
    current=current->next;
  }
  mid=count/2;
  current=source;
  *frontref=source;

  for(i=0;i<mid;i++){
    current=current->next;
  }
  *backref=current->next;
  current->next=NULL;
}
#else
int Length(struct node *head)
{
  struct node *current=head;
  int i=0;

  while(current!=NULL){
    i++;
    current=current->next;
  }
  return i;
}
void frontbacksplit(struct node *source,struct node **frontref,struct node **backref)
{
  int len = Length(source);
  int i;
  struct node* current = source;
  if (len < 2) {
  *frontref = source;
  *backref = NULL;
  }
  else {
  int hopCount = (len-1)/2; //(figured these with a few drawings)
  for (i = 0; i<hopCount; i++) {
  current = current->next;
  }
  // Now cut at current
  *frontref = source;
  *backref = current->next;
  current->next = NULL;
  }
}



#endif
void removedup(struct node *head)
{
  struct node *current=head;
  struct node *Next;

  while(current->next!=NULL)
  {
    if(current->data==current->next->data)
    {
      Next=current->next->next;
      free(current->next);
      current->next=Next;
    }
    else
    current=current->next;
  }

}
#if 1
void movenode(struct node **destref, struct node **sourceref)
{
   struct node *newnode=NULL;

   newnode=*sourceref;
  //  printf("**%d \n",(newnode)->data);
   *sourceref=(*sourceref)->next;
   newnode->next=*destref;
   *destref=newnode;
   //printf("**%d \n",(*destref)->data);
}
#else
void movenode(struct node **a,struct node **b)
{
  struct node *temp = *b;

  *b=(*b)->next;
  temp->next=*a;
  *a=temp;
}
#endif
void alternatingsplit(struct node *source,struct node**aref,struct node **bref)
{
  struct node *a=NULL;
  struct node *b=NULL;

  struct node *current=source;

  while(current!=NULL)
  {
    movenode(&a,&current);
    if(current!=NULL);
     movenode(&b,&current);
  }
  *aref=a;
  *bref=b;
}
struct node *shufflemerge(struct node *a,struct node *b)
{
  struct node *result=NULL;
  struct node **lastptrref=&result;

  while(1)
  {
    if(a==NULL){
       *lastptrref=b;
    break;
  }
    else if(b==NULL){
      *lastptrref=a;
      break;
    }
    movenode(lastptrref,&a);
    lastptrref=&((*lastptrref)->next);
    movenode(lastptrref,&b);
    lastptrref=&((*lastptrref)->next);
  }
  return (result);
}

struct node *shufflemerge1(struct node *a,struct node *b)
{
  struct node dummy;
  struct node *tail=&dummy;
while(1)
{
  if(a==NULL){
    tail->next=b;
    break;
  }
  else if(b==NULL)
  {
    tail->next=a;
    break;
  }
  else{
    tail->next=a;
    tail=a;
    a=a->next;
    tail->next=b;
    tail=b;
    b=b->next;
  }

}
  return( dummy.next);
}

struct node *sortedmerge(struct node *a,struct node *b)
{
  struct node *result=NULL;
  struct node **lastptrref=&result;

  while(1)
  {
     if(a==NULL)
     {
       *lastptrref=b;
       break;
     }
     else if(b==NULL)
     {
       *lastptrref=a;
       break;
     }
 //printf("*%d %d \n",a->data,b->data);
       if(a->data<= b->data)
       {
         movenode(lastptrref,&a);
       }
       else
       {
         movenode(lastptrref,&b);
       }
       lastptrref=&((*lastptrref)->next);

  }
  return result;
}

struct node *sortedmerge2(struct node *a,struct node *b)
{
  struct node dummy;
  struct node *tail=&dummy;

  dummy.next=NULL;
  while(1)
  {
     if(a==NULL){
       tail->next=b;
       break;
     }
     else if(b==NULL)
     {
       tail->next=a;
       break;
     }

     if(a->data <=b->data)
     {
       movenode(&(tail->next),&a);
     }
     else {
       movenode(&(tail->next),&b);
     }
     tail=tail->next;

  }
   return(dummy.next);
}

void mergesort(struct node **headref)
{
    struct node *head=*headref;
    struct node *a;
    struct node *b;

    if(head==NULL || head->next==NULL) return;

    frontbacksplit(head,&a,&b);
  //  printf("*%d \n",a->data);
    mergesort(&a);
    mergesort(&b);
    *headref=sortedmerge(a,b);
}
/* reverse linked list */
void reverse(struct node **headref)
{
  struct node *current=*headref;
  struct node *prev=NULL;
  struct node *newnode;

  while(current!=NULL)
  {
    newnode=current->next;
    current->next=prev;
    prev=current;
    current=newnode;
  }
*headref=prev;
}

void reverse2(struct node **headref)
{
  struct node *prev=NULL;
  struct node *current=*headref;

  while(current!=NULL)
  {
    movenode(&prev,&current);
  }
  *headref=prev;
}

int main()
{
  struct node *head;
  struct node *next=NULL;
  struct node *front=NULL;
  struct node *back=NULL;
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=4;
  newnode->next=NULL;

  //head=buildonetwothree();
//  next=buildonetwothree();
//  push(&head,13);
//  push(&head,42);

//  head=addathead(head);

//  head =builddumynode();
//head =buildwithspecial();
//deletelist(&head);

//int data= pop1(&head);
//insertNth(&head,2,88);
//sortedinsert2(&head,newnode);
//insertsort(&head);
  //display(head);  printf("\n");
  //append(&head,&next);
//  display(head);
  //printf("\n");
//frontbacksplit(head,&front,&back);
//  display(head);
//  display(front);
//  display(back);
//  removedup(head);
//  printf("\n");
//  display(head);
//  movenode(&next,&head);
//push(&head,15);push(&head,20);push(&head,10);push(&head,3);push(&head,5);
//push(&head,2);
  //display(head);    printf("\n");
  //alternatingsplit(head,&front,&back);

  push(&front,15);push(&front,10);push(&front,5);push(&back,20);push(&back,3);
  push(&back,2);
printf("\nfront: ");  display(front); printf("\n back: "); display(back);
//printf("\n");
  next=shufflemerge1(front,back);  printf("\n\t");
//next=sortedmerge(front,back);  printf("\n\t");
  display(next);
   printf("\n-----------------------------\n");
printf("Reverse list :");   reverse(&next);
   display(next);
    printf("\n-----------------------------\n");
//push(&front,15);push(&front,10);push(&front,5);push(&front,20);
//push(&front,3);push(&front,2);
//  printf("\n\t");
  //mergesort(&front);
  //  display(front);


    return 0;
}
