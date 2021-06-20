#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *left;
   struct node *right;
};

struct node *insert(struct node *root,int key)
{
   if(root ==NULL)
   {
     struct node *newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=key;
     newnode->left=NULL;
     newnode->right=NULL;
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

void printpostorder(struct node *root)
{
  if(root!=NULL)
  {
    printpostorder(root->left);
    printpostorder(root->right);
    printf("%d ->",root->data);
  }
}

int findSubtree(struct node *root,int low,int high, int *count)
{
   if(root ==NULL) return 1;

   if(findSubtree(root->left,low,high,count) && findSubtree(root->right,low,high,count) &&
    (root->data >low && root->data <high))
    {
      (*count)++;
      printf("## data=%d count=%d \n",root->data,*count);
      return 1;
    }
  return 1;
}

int main()
{
  struct node *root=NULL;

  int arr[]={ 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int i;
  int count=0;

  for(i=1;i<n;i++)
  {
    root=insert(root,arr[i]);
  }

 printpostorder(root);
 findSubtree(root,5,20,&count);
 printf("**count= %d \n",count);

return 0;
}
