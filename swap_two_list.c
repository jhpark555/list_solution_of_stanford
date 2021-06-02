/******************************************************************************


*******************************************************************************/
#include <stdio.h>


struct node{
    int data;
    struct node *next;
};

struct node *buildonetwothree()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *forth=( struct node*) malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next = forth;

    forth->data=4;
    forth->next=NULL;

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

#if 0 //pjh
struct node* swap(struct node*head)
{
  struct node *current=head;
  struct node *Next;
  struct node *temp;

  head=current->next;

  while(1)
  {
    Next=current->next;
    temp=Next->next;
    Next->next=current;

   if(temp==NULL){
    current->next=NULL;
    break;
   }
    if(temp->next==NULL){
      current->next=temp;
      break;
    }
    current->next=temp->next;
    current=temp;
  }

  current = head;
 return current;
}
#else
 struct node *swap( struct node *head)
 {
   struct node *current=head;
   struct node *Next=current->next;
   struct node *temp;

   head=current->next;

   while(1)
   {                  // before current->Next->temp->current->next...
     Next=current->next;
     temp=Next->next;


     Next->next=current;
    if(temp==NULL){
     current->next=NULL;
     break;
    }
     if(temp->next==NULL){
       current->next=temp;
       break;
     }
                     // after : next->current->temp->Next->current
    current->next=temp->next;
     current=temp;
   }

   current = head;
  return current;
 }
#endif

int main()
{
    struct node *test=buildonetwothree();

    display(test);
    printf("\n***\n");
    test=swap(test);
      display(test);
//   test1= reversenode(test);
//    display(test1);

//    int c=compare(test,test1);

//    printf("\n**c= %d \n",c);
    return 0;
}
