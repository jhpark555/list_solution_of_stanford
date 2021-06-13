#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a>b)? a:b )

struct node{
  int data;
  struct node *left;
  struct node *right;
  struct node *parent;
};


struct node *newNode(int data)
{
  struct node *node=(struct node*)malloc(sizeof(struct node));
  node->data=data;

  node->left=NULL;
  node->right=NULL;
  node->parent=NULL;
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
/*
If right subtree of node is not NULL, then succ lies in right subtree. Do the following.
Go to right subtree and return the node with minimum key value in the right subtree.
If right sbtree of node is NULL, then succ is one of the ancestors. Do the following.
Travel up using the parent pointer until you see a node which is left child of its parent. The parent of such a node is the succ.
*/
#if 0
struct node *inOrderSuccessor(struct node *node,struct node *n)
{
  //case 1.
  if(n->right !=NULL) return minValueNode(n->right);
  //case 2.
  struct node *p=n->parent;
  while(p!=NULL && n==p->right)
  {
    n=p;
    p=p->parent;
  }
  return p;
}
#else    //below method is more feasible
struct node *inOrderSuccessor(struct node *root,struct node *n)
{
   if(n->right!=NULL)
     return minValueNode(n->right);
   struct node *succ=NULL;

   while(root!=NULL)
   {
     if(n->data < root->data)
     {
       succ=root;
       root=root->left;
     }
     else if(n->data> root->data)
     {
       root=root->right;
     }
     else
      break;
   }
  return succ;
}
#endif
struct node* insert(struct node* node,
                    int data)
{
    /* 1. If the tree is empty, return a new,
      single node */
    if (node == NULL)
        return (newNode(data));
    else {
        struct node* temp;

        /* 2. Otherwise, recur down the tree */
        if (data <= node->data) {
            temp = insert(node->left, data);
            node->left = temp;
            temp->parent = node;
        }
        else {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }

        /* return the (unchanged) node pointer */
        return node;
    }
}

void inorder(struct node *temp)
{
  if(temp==NULL) return;
  inorder(temp->left);
  printf("%d->",temp->data);
  inorder(temp->right);
}

void preorder(struct node *temp)
{
  if(temp!=NULL)
  {
    printf("%d->",temp->data);
    preorder(temp->left);
    preorder(temp->right);
  }


}


int main()
{
  struct node *root=NULL,*temp,*succ;
  root=insert(root,20);
  root=insert(root,8);
  root=insert(root,22);
  root=insert(root,4);
  root=insert(root,12);
  root=insert(root,10);
  root=insert(root,14);
  temp=root->left->right->right;

  succ=inOrderSuccessor(root,temp);

  if(succ!=NULL)
   printf("\n Inorder Succssor of %d is %d ",temp->data,succ->data);
  else
    printf("\n Inorder Succeessor doesn't exist ");

  return 0;
}
