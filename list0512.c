
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *buildonetwothree(int num1,int num2,int num3)
{
    struct node *head=malloc(sizeof(struct node));
    struct node *second=malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    
    head->data=num1;
    head->next=second;
    
    second->data=num2;
    second->next=third;
    
    third->data=num3;
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
  
    
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=new;
      new->next=NULL;
      
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

struct node *insertbeg(struct node *head,int num)
{
    struct node *current=head;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    
      new->data=num;
       
       new->next=head;
       head=new;
     
       
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

struct node *reverse(struct node* head)
{
    struct node *current=head;
	int j;
    
    int Data[20]={0};
    int i=0;
    
    while(current !=NULL)
    {
        Data[i] = current->data;
        //  printf("%d ",Data[i]);
        current=current->next;
        i++;
      
    }
    current=head;
    for( j=0;j<i;j++)
    {
        current->data=Data[i-j-1];
        current=current->next;
    }
    
    return(head);
    
}

struct node* reverselist(struct node *head)
{
    struct node *current=head;
    struct node *prev=NULL;
    struct node *Next=NULL;
    
    while(current!=NULL){
      Next=current->next;
      current->next=prev;
      prev=current;
      current=Next;
    }
  head=prev;
    
    return(head);
}

void movenode(struct node **dst, struct node **src)
{
   struct node *new=*src;
   
       *src=new->next;
       new->next=*dst;
       *dst=new;
  
   
}
struct node *mergetwolist(struct node *L1, struct node *L2)
{
    struct node dumy;
    struct node *prev=&dumy;
    struct node *tmp=NULL;
    dumy.next=NULL;
    
    
    while(1)
    {
        if(L1==NULL){prev->next=L2; break;}
        else if(L2==NULL) { prev->next=L1; break;}
        
        if( L1->data <= L2->data){
            movenode(&(prev->next),&L1);
        }
        else{
            movenode(&(prev->next),&L2);
        }
        prev=prev->next;
    }
  
     return(dumy.next);
    
}


int main()
{
    struct node *test;
    struct node *myfile=(struct node*)malloc(sizeof(struct node));
    struct node *l1=NULL,*l2=NULL;
    
    myfile->data=2;
    
    test=buildonetwothree(1,2,3);
    l1=buildonetwothree(1,2,3);
    l2=buildonetwothree(4,5,6);
    
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
test=insertbeg(test,20);

    int l= length(test);
    //printf("Hello World %d\n",l);
   display(test);
   printf("***\n");
  test=reverse(test);
    display(test);
    printf("**\n");
  test= reverselist(test);
 // l1=test;
     display(test);
     printf("*\n");
  // test=insertend(test,0);
   //l2=test;
     display(test);
     printf("**\n");
   
  // movenode(&l1,&l2);
  // display(l1);
    test= mergetwolist(l1,l2);
   display(test);
    return 0;
}





