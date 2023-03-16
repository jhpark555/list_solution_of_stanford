/**
*      playlist making code
*      Programmed by Philip Park @ Ess technology
*      10/13/2022
**/
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdint.h>

struct node
{
  char *FileName;
  char *realName;
  int  listnum;
  struct node *next;
  struct node *prev;
};

void AddListFrontName(struct node **head,char* fullfile,char *filename, int count)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));

  newNode->FileName=strdup(fullfile);
  newNode->realName=strdup(filename);

  newNode->listnum=count;
  newNode->next=(*head);
  newNode->prev=NULL;

  if(*head !=NULL)
   (*head)->prev=newNode;

  (*head)=newNode;
 //printf("0x%x->",*head);
}
void printList(struct node *head)
{
  struct node *current=head;
  while(current!=NULL)
  {
    //printf("%s[%02d]->",current->FileName, current->listnum);
    printf("%x->",current);
    current=current->next;
  }
}

void swap(struct node *head)
{
  struct node *prev=head->prev;
    head->prev=head->next;
    head->next = prev;

}
struct node *revNodes(struct node **headref)
{
   struct node *prev=NULL;
   struct node *curr=*headref;

   while(curr!=NULL){
     swap(curr);
     prev=curr;
     curr=curr->prev;
   }

   if(prev!=NULL)
    *headref = prev;
}

void free_usb_list(struct node **head)
{
   struct node *p=*head;

   while( p !=NULL){
     *head=(*head)->next;
     printf("%x->",p);
     free(p->FileName);
     free(p->realName);
     free(p);
     p=*head;
   }
   printf("\n %x \n",p);
}

int main(int argc,char *argv[])
{
  struct node *head=NULL;
  struct node *tail=(struct node*)malloc(sizeof(struct node));

  AddListFrontName(&head,"first","first",0);
  AddListFrontName(&head,"second","second",1);
  AddListFrontName(&head,"third","third",2);

  revNodes(&head);

  struct node *curr=head;

  while(curr->next!=NULL) curr=curr->next;
  tail=curr;
   //printf("+++%x \n",tail);


  free_usb_list(&head);
  printList(head);
  return 0;
}
