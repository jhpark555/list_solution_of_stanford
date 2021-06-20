//Construct a height-balanced BST from an unbalanced BST


#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *left;
   struct node *right;
};

struct node *newNode(int data)
{
  struct node *root=(struct node*)malloc(sizeof(struct node));

  root->data=data;
  root->left=NULL;
  root->right=NULL;

  return root;
}

struct node *insert(struct node *root,int key)
{
   if(root ==NULL)
   {
     struct node *newnode=newNode(key);
     root=newnode;
   }
   else
   {
     if(key < root->data )
       root->left=insert(root->left,key);
     else
       root->right=insert(root->right,key);
   }

   return root;
}

void printpreorder(struct node *root,int arr[],int *count)
{
  if(root!=NULL)
  {
  //  printf("%d ->",root->data);
    arr[(*count)++]=root->data;
    printpreorder(root->left,arr,count);
    printpreorder(root->right,arr,count);;
  }
}


int main()
{
  int arr[100]={0};
  int count=0,i;

  struct node *root=newNode(20);
  root->left=newNode(15);
  root->left->left=newNode(10);
  root->left->left->left=newNode(5);
  root->left->left->left->left=newNode(2);
  root->left->left->left->right=newNode(8);


  printpreorder(root,arr,&count);

  //for(i=0;i<count;i++) printf("%d->",arr[i]);

  struct node *ans=NULL;

  for(i=0;i<count;i++) insert(ans,arr[i]);

  for(i=0;i<count;i++) printf("%d->",arr[i]);

return 0;
}
