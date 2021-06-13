#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a>b)? a:b )

struct node{
  int key;
  struct node *left;
  struct node *right;
};


struct node *newNode(int data)
{
  struct node *node=(struct node*)malloc(sizeof(struct node));
  node->key=data;

  node->left=NULL;
  node->right=NULL;
  return(node);

}
struct node *minValueNode(struct node *node)
{
  struct node *current=node;
/* loop down to find the leftmost leaf */
  while(current && current->left!=NULL)
    current=current->left;

  return current;

}
struct node* insert(struct node* node,
                    int data)
{
    /* 1. If the tree is empty, return a new,
      single node */
    if (node == NULL)
        return (newNode(data));
    if(data <node->key)
       node->left = insert(node->left,data);
    else
       node->right = insert(node->right,data);

    return node;
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(struct node *root, struct node **pre,struct node **suc,int key)
{
  if(root ==NULL) return;

  if(root->key==key)
  {
    //maximum value in left subtree is predecessor
    if(root->left !=NULL)
    {
      struct node *temp=root->left;
      while(temp->right)
        temp=temp->right;
      *pre=temp;
    }
    //maximum value in right subtree is Succeessor
    if(root->right!=NULL)
    {
      struct node *temp=root->right;
      while(temp->left)
        temp=temp->left;
      *suc=temp;
    }
    return;
  }
 // If key is smaller than root's key, go to left subtree
 if(root->key>key)
 {
   *suc=root;
   findPreSuc(root->left,pre,suc,key);
 }
 else
 {
   *pre =root;
   findPreSuc(root->right,pre,suc,key);
 }
}

int main()
{
  struct node *root=NULL,*pre,*suc;
  int key=55;

  root=insert(root,50);
  root=insert(root,30);
  root=insert(root,20);
  root=insert(root,40);
  root=insert(root,70);
  root=insert(root,60);
  root=insert(root,80);

  findPreSuc(root,&pre,&suc,key);

 if(pre!=NULL)   printf("Pre is %d \n",pre->key);
 else printf("No pre \n");

 if(suc!=NULL) printf("Suc is %d \n",suc->key);
 else printf("No Suc \n");

  return 0;
}
