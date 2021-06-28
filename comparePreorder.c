// compare arr[] is same order with preorder  arr이 tree의 preorder 순서와 같은지
//확인하는 코 드

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

void printpreorder(struct node *root,int pre[])
{
  static int i=0;
  if(root!=NULL)
  {
    printf("%d ->",root->data);
    pre[i++]=root->data;
    printpreorder(root->left,pre);
    printpreorder(root->right,pre);
  }
}


int main()
{
  struct node *root=NULL;

  int arr[]={ 15, 10, 8, 12, 20, 16, 25 };
  int n=sizeof(arr)/sizeof(arr[0]);
  int i;
  int count=0;
  int pre[n];

  for(i=0;i<n;i++)
  {
    root=insert(root,arr[i]);
  }

 printpreorder(root,pre);
 printf("\n");
for(i=0;i<n;i++)
{
  if(arr[i]!=pre[i])  break;
  printf("%d %d :\n",pre[i],arr[i]);
}

if(i!=n) printf("\nNot preorder\n");
else printf("\nIt's preorder\n");
return 0;
}
