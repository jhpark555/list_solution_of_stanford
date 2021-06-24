//In-place merge two sorted arrays


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a,b) ( a^=b^=a^=b)

int count;

struct node
{
  char s[50];
  struct node *next;
};

void printList(struct node *head)
{
  struct node *current=head;
  while(current!=NULL)
  {
    printf("%s->",current->s);
    current=current->next;
  }
}
//DLL push
void push(struct node **head,char *str)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));

  strcpy(newNode->s,str);
  newNode->next=*head;

  *head=newNode;
}

void reversestr(char arr[],int n)
{
  int i,j;
  for(i=0,j=n-1;i<j;i++,j--)
  {
    swap(arr[i],arr[j]);
  }
  //printf("+++++%s\n",arr);
}

void traverseNode(struct node **headref,char X[],int rev)
{
   struct node *current=*headref;
   int i;
   int cnt=0;


   while(current!=NULL)
   {

    if( rev){
     for(i=0; current->s[i] !='\0';i++) {
       //if(current->s[i] == '\0') break;
     }
     //printf("count=%d \n",i);
     cnt=i;
     reversestr(current->s,cnt);
    }
     for(i=0; current->s[i] !='\0';i++){
       X[count++]= current->s[i];
     }
       current=current->next;
   }
    X[count]='\0';
}

void reverseSTR(struct node **headref)
{
   struct node *prev=NULL;
   struct node *Next=NULL;
   struct node *current=*headref;

   while(current!=NULL)
   {
     Next = current->next;
     current->next=prev;
     prev=current;
     current=Next;
   }
   *headref=prev;

}

int main()
{
  int i;
  char T[20]={0};
  char R[20]={0};

  char key[][4] = { "AA", "XYZ", "CD", "C","ZYX","AA"};
  int n = sizeof(key)/sizeof(key[0]);

  struct node* head = NULL;

  // construct a linked list
  for (i = n-1; i >=0; i--) {
      push(&head, key[i]);
  }
//reversestr(key[1],3); //test
  //printList(head);

  traverseNode(&head,T,0);
  printf("\n%s\n",T);
  count=0;
  reverseSTR(&head);
  traverseNode(&head,R,1);
  printf("\n%s\n",R);
  int s= strcmp(T,R);
  printf("This linked list is Palindrome= %d \n",s);
  //printList(head);

  return 0;

}
