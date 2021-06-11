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

int countlist(struct node *head,int n)
{
  struct node *current=head;
  int count=0;

  while(current!=NULL)
  {
    count++;
    current=current->next;
  }

  int first=count-n-1;
//  printf("**first=%d \n",first);
  current=head;

  for(count=0; count!=first;count++)
    current=current->next;
  int ret=current->data;

  return ret;
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

void movetofront(struct node **headref)
{
  struct node *current=*headref;
  struct node *prev;

  while(current->next!=NULL)
  {
    prev=current;
    current=current->next;
  }
  prev->next=NULL;
  current->next=*headref;
  *headref=current;

}

#if 0
void movezeros(struct node **headref)
{
  struct node *temp=(*headref)->next;
  struct node *prev=*headref;
  struct node *curr;

  while(temp!=NULL)
  {
    if(temp->data==0) {
      curr=temp;
      temp=temp->next;
      prev->next=temp;
      curr->next=*headref;
      *headref=curr;
    }
    else {
      prev=temp;
      temp=temp->next;
    }
  }
}
#else
void movezeros(struct node **headref)     //very good examples.
{
  struct node *current=(*headref)->next;
  struct node *prev=*headref;
  struct node *temp;

  while( current !=NULL)
  {
     if( current->data==0)
     {
       temp=current->next;
       current->next=*headref;
       *headref=current;
       prev->next=temp;
       current=temp;

       //prev->next=current->next->next;
     }
     else{
     prev=current;
     current=current->next;
     }
  }
  headref=&current;
}
#endif

// 1-3-5-6-4-2
void rearrange(struct node *odd)
{
  struct node *even=odd->next;

  odd->next=odd->next->next;
  odd=odd->next;

  even->next=NULL;

  while(odd && odd->next)
  {
    struct node *temp=odd->next->next;
    odd->next->next=even;
    even=odd->next;
    odd->next=temp;
    if(temp!=NULL)  odd=temp;
  }
  odd->next=even;
}


struct node *rearrangeevenodd(struct node *head)
{
   struct node *odd=head;
   struct node *even=head->next;

   struct node *evenfirst=even;

   while(1)
   {
     if(odd==NULL || even==NULL || even->next==NULL)
     {
       odd->next=evenfirst;
       break;
     }
     odd->next=even->next;
     odd=even->next;

     if(odd->next==NULL)
     {
       even->next=NULL;
       odd->next=evenfirst;
       //printf("**%d \n",evenfirst->data);
       break;
     }

     even->next=odd->next;
     even=odd->next;
   }
   return(head);
}
//rearrange with eve as reverse format
struct node *rearrangeevenoddreverse(struct node *head)
{
   struct node *odd=head;
   struct node *even=head->next;

   struct node *evenfirst=even;

   while(1)
   {
     if(odd==NULL || even==NULL || even->next==NULL)
     {
       break;
     }
     odd->next=even->next;
     odd=even->next;

     if(odd->next==NULL)
     {
       even->next=NULL;
       //printf("**%d \n",evenfirst->data);
       break;
     }
     even->next=odd->next;
     even=odd->next;
   }

    struct node *current=evenfirst;
    struct node *prev=NULL;
    struct node *Next=NULL;

    while(current!=NULL)
    {
      Next=current->next;
      current->next=prev;
      prev=current;
      current=Next;
    }
    evenfirst=prev;

    odd->next=evenfirst;

   return(head);
}

#if 0
void segregateevenodd(struct node **head)
{
   struct node *current=*head;
   struct node *prev=NULL;
   struct node *end=*head;

   //get pointer at last nodes
   while(end->next!=NULL)
    end=end->next;

   struct node *new_end=end;

   //consider all odd nodes before the first even nodes

   while(current->data %2 !=0 && current!=end)
   {
    new_end->next=current;
    current=current->next;
    new_end->next->next=NULL;
    new_end=new_end->next;
   }

   if(current->data %2 ==0)
   {
     *head=current;
     while(current!=end)
     {
       if(current->data%2 ==0)
       {
         prev=current;
         current=current->next;
       }
       else
       {
         prev->next=current->next;
         current->next=NULL;
         new_end->next=current;
         new_end=current;
         current=prev->next;
       }
     }
   }
   else
   {
     prev=current;
   }

   if(new_end !=end && end->data%2 !=0)
   {
     prev->next=end->next;
     end->next=NULL;
     new_end->next=end;
   }

}
#else
void segregateevenodd(struct node **head)
{
  struct node *evenstart=NULL;
  struct node *evenend=NULL;
  struct node *oddstart=NULL;
  struct node *oddend=NULL;

  struct node *current=*head;

  while(current!=NULL)
  {
    int val=current->data;

    if(val %2 ==0)    //even
    {
        if(evenstart==NULL)
          {
          evenend=evenstart=current;
        }
        else
        {
          evenend->next=current;
          evenend=evenend->next;
        }
  }
   else
   {
         if(oddstart==NULL)
         {
           oddend=oddstart=current;
         }
         else
         {
           oddend->next=current;
           oddend=oddend->next;
         }
   }
    current=current->next;

  }
    if(oddstart==NULL || evenstart ==NULL)
     return;

#if 1 //evenstart
     evenend->next=oddstart;
     oddend->next=NULL;
     *head=evenstart;
#else
    oddend->next=evenstart;
    evenend->next=NULL;
    *head=oddstart;
#endif

}
#endif

#if 1
int **countsumpair(struct node *a,struct node *b,int x)
{
    struct node *p1=a;
    struct node *p2=b;
    int a_buf[10]={0};
    int b_buf[10]={0};
    int i=0,j;
    int counta=0,countb=0;

    while(p1!=NULL)
    {
      a_buf[i++]=p1->data;
    //  printf("%d ",p1->data);
      p1=p1->next;
      counta++;
    }
    i=0;

    while(p2!=NULL)
    {
      b_buf[i++]=p2->data;
      p2=p2->next;
      countb++;
    }
int **v ;
v= (int**)malloc(sizeof(int*)*4);   //row
for(i=0;i<4;i++)
  v[i]=(int*)malloc(4*sizeof(int)); //COL

  int k=0;
  int ret=0;
   for(i=0;i<counta;i++)
     for(j=0;j<countb;j++)
     {
      // if(a_buf[i]+b_buf[j] == x) {v[k][0]=i,v[k][1]=j; k++};
       if(a_buf[i]+b_buf[j] == x)
       {
         v[k][0]=a_buf[i]; v[k][1]=b_buf[j];  k++;
         ret++;
       }
     }
//  for(i=0;i<k;i++) printf("i:j=%d  %d\n",v[i][0],v[i][1]);

return v;
  //return ret;

}
#else
int countsumpair(struct node *a,struct node *b,int x)
{
  int count=0;
  struct node *p1;
  struct node *p2;

  for(p1=a;p1!=NULL;p1=p1->next)
    for(p2=b;p2!=NULL;p2=p2->next)
    {
      if(p1->data + p2->data ==x) count ++;
    }

  return count;
}
#endif
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
printf("move to front last one :");  movetofront(&next);
 display(next);
 printf("\n-----------------------------\n");
 front=NULL;
 push(&front,1);push(&front,0);push(&front,0);push(&front,10);push(&front,3);
printf("\nmove zeros to front before :");  display(front);
printf("\nmove zeros to front after :"); movezeros(&front);
 display(front);
 printf("\n-----------------------------\n");
 front=0;
 push(&front,7);push(&front,6);push(&front,5);push(&front,4);push(&front,3);
 push(&front,2); push(&front,1);
  display(front);
//rearrange(front);
front=rearrangeevenodd(front);
printf("\nrearrange :");display(front);
 printf("\n-----------------------------\n");
front=rearrangeevenoddreverse(front);
printf("\nrearrange rever :");display(front);
printf("\n-----------------------------\n");
segregateevenodd(&front);
printf("\nsegregate :");display(front);
printf("\n-----------------------------\n");
//int x= countlist(front,3);
//printf("**%d \n",x);
front=0; back=0;
push(&front,7);push(&front,5);push(&front,1);push(&front,3);push(&back,8);
push(&back,2);push(&back,5);push(&back,3);
//display(front);
int **v=countsumpair(front,back,10);
int i,j;
for(i=0;i<2;i++)
for(j=0;j<2;j++) printf("%d ",v[i][j]);
    return 0;
}
