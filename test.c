//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a,b) ( a^=b^=a^=b)
int count;

struct node
{
  int data;
  struct node *next;
};

void printList(struct node *head)
{
  struct node *current=head;
  while(current!=NULL)
  {
    printf("%d->",current->data);
    current=current->next;
  }
}
//DLL push
void push(struct node **head,int data)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));

  newNode->data=data;
  newNode->next=*head;

  *head=newNode;
}

struct node *sortedMerge(struct node *a,struct node *b)
{
  if(a==NULL) return b;
  else if(b==NULL) return a;

  struct node* result=NULL;

  if(a->data < b->data )
  {
    result =a;
    result->next=sortedMerge(a->next,b);
  }
  else {
    result =b;
    result->next =sortedMerge(a,b->next);
  }
 return result;

}
void FrontBackSplit2(struct node *source,struct node **frontRef,struct node **backRef)
{
   struct node *slow=NULL;
   struct node *fast=NULL;

   if(source==NULL || source->next==NULL){
    *frontRef=source;
    *backRef=NULL;
  }
  else {
    slow=source;
    fast=source->next;
    while(fast!=NULL)
    {
      fast=fast->next;
      if(fast!=NULL)
      {
        slow=slow->next;
        fast=fast->next;
      }
    }

    *frontRef=source;
    *backRef=slow->next;
    slow->next=NULL;

  }
}

void mergesort(struct node **headref)
{
  if(*headref==NULL || (*headref)->next==NULL)
   return;

  struct node *a;
  struct node *b;

  FrontBackSplit2(*headref,&a,&b);
  mergesort(&a);
  mergesort(&b);

  *headref=sortedMerge(a,b);

}

int length(struct node *head)
{
  int count=0;
  struct node *current=head;

  while(current!=NULL)
  {
    count++;
    current=current->next;
  }
return count;
}

void sortint(struct node *head,int n,struct node **a,struct node **b)
{
  struct node *current=head;
  int count=0;
  *a=head;

  while(current!=NULL && count++< n)
  {
    current=current->next;
  }
  *b=current->next;
  //current->next=NULL;
  //current->next=*b;
  //current->next=NULL;
//  *b=current;

}

int main()
{
  int i;

  //int arr[] = {6, 8, 4, 3, 1, 9 };
  int a[]={2,6,9,10,15};
  int b[]={1,4,5,20};

  int na = sizeof(a)/sizeof(a[0]);
  int nb = sizeof(b)/sizeof(b[0]);

  struct node* head = NULL;
  struct node *arr=NULL;
  struct node *brr=NULL;

  // construct a linked list
  for (i = na-1; i >=0; i--) {
      push(&arr, a[i]);
  }
  // construct a linked list
  for (i = nb-1; i >=0; i--) {
      push(&brr, b[i]);
  }

 int La=length(arr);
 int Lb=length(brr);

// printf("**%d %d\n",La,Lb);
  head=sortedMerge(arr,brr);
  arr=brr=NULL;
  sortint(head,La-1,&arr,&brr);
  printList(arr); printf("\n");
  printList(brr);
  return 0;

}
