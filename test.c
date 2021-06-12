#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a>b)? a:b )

struct node{
  int data;
  struct node *left;
  struct node *right;
  int height;
};

int height(struct node *N)
{
  if(N==NULL) return 0;
  return N->height;
}

int getBalance(struct node *N)
{
  if(N==NULL) return 0;
  return height(N->left)-height(N->right);
}

struct node *newnode(int data)
{
  struct node *node=(struct node*)malloc(sizeof(struct node));
  node->data=data;

  node->left=NULL;
  node->right=NULL;
  node->height=1;
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
T1, T2, T3 and T4 are subtrees.
                                               x
                                                \
       y         Right Rotate (y)                y
      /           - - - - - - - - ->             /
     x                                         T2
      \
       T2
  */
struct node *rightRotate(struct node *y)
{
  struct node *x=y->left;
  struct node *T2=x->right;

  x->right=y;
  y->left=T2;

  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;

  return x;
}

/*
                                  y
                                /
    x     Left Rotate(x)       x
     \   - - - - - - - ->       \
      y                          T2
     /
   T2
   */

struct node *leftRotate(struct node *x)
{
  struct node *y=x->right;
  struct node *T2=y->left;

  x->right=T2;
  y->left=x;

  x->height=max(height(x->left),height(x->right))+1;
  y->height=max(height(y->left),height(y->right))+1;

  return y;
}



struct node *insert(struct node *node,int data)
{
  if(node==NULL) {
    return newnode(data);
  }

  if(node->data>data)
     node->left=insert(node->left,data);
  else if(node->data < data)
     node->right=insert(node->right,data);
  else   return node;

  node->height=1 +max(height(node->left),height(node->right));

  /* Get the balance factor of this ancestor
    node to check whether this node became
    unbalanced */
  int balance =getBalance(node);
  // If this node becomes unbalanced, then
  // there are 4 cases
  if(balance > 1 && data < node->left->data)
    return rightRotate(node);
  if(balance <-1 && data > node->right->data)
    return leftRotate(node);
  if(balance >1 && data > node->left->data)
  {
    node->left=leftRotate(node->left);
    return rightRotate(node);
  }
  if(balance <-1 &&data < node->right->data)
  {
    node->right=rightRotate(node->right);
    return leftRotate(node);
  }
    return node;
}


struct node *deleteNode(struct node  *root,int data)
{
   if(root ==NULL) return root;

   if(data < root->data)
     root->left=deleteNode(root->left,data);
   else if( data > root->data)
     root->right=deleteNode(root->right,data);

     // if key is same as root's key, then This is
     // the node to be deleted
   else
   {
     //node with only one child or no child
     if(root->left ==NULL || root->right==NULL)
     {
       struct node *temp=root->left ? root->left:root->right;

       //no chile case
       if(temp==NULL)
       {
         temp=root;
         root=NULL;
       }
      else  //one child
       {
        *root=*temp;   //copy the non-empty child
        free(temp);
       }
    }
    else
    {
      //node with two child: get inorder successor
      struct node *temp=minValueNode(root->right);
      // Copy the inorder successor's data to this node
      root->data=temp->data;
      // Delete the inorder successor
      root->right = deleteNode(root->right,temp->data);
     }
  }

  //if the tree had only one node then return
  if(root==NULL) return root;
//update height of the current nodes
 root->height =1+max(height(root->left),height(root->right));

 int balance = getBalance(root);
 //if node is unstale , 4 cases to Rotate
 if( balance >1 && getBalance(root->left) >=0)
   return rightRotate(root);
 if( balance >1 && getBalance(root->left) <0)
 {
   root->left=leftRotate(root->left);
   return rightRotate(root);
 }
 if(balance < -1 && getBalance(root->right) <=0)
   return leftRotate(root);
 if( balance <-1 && getBalance(root->right)> 0)
 {
   root->right=rightRotate(root->right);
   return leftRotate(root);
 }

  return root;

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

/*
1) Node to be deleted is the leaf: Simply remove from the tree.

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70
         /  \    /  \                     \    /  \
       20   40  60   80                   40  60   80
2) Node to be deleted has only one child: Copy the child to the node and delete the child

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70
            \    /  \                          /  \
            40  60   80                       60   80
3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used.


              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70
                 /  \                            \
                60   80                           80
*/
#if 0
struct node *deleteNode(struct node*root,int data)
{
  if(root ==NULL){
    return root;
  }

  if(root->data > data)
    root->left=deleteNode(root->left,data);
  else if(root->data < data)
    root->right=deleteNode(root->right,data);
    // if key is same as root's key,
        // then This is the node
        // to be deleted
  else {
     if(root->left==NULL){
       struct node *temp=root->right;
       free(root);
       return temp;
     }
     else if(root->right==NULL){
       struct node *temp=root->left;
       free(root);
       return temp;
     }

     // node with two children:
    // Get the inorder successor
    // (smallest in the right subtree)

    struct node *temp=minValueNode(root->right);

    // Copy the inorder
    // successor's content to this node
      root->data=temp->data;
     // Delete the inorder successor
     root->right= deleteNode(root->right,temp->data);

  }
  return root;
}
#endif
int main()
{
  struct node *root=NULL;
  root=insert(root,9);
  root=insert(root,5);
  root=insert(root,10);
  root=insert(root,0);
  root=insert(root,6);
  root=insert(root,11);
  root=insert(root,-1);
  root=insert(root,1);
  root=insert(root,2);

  root=deleteNode(root,10);

  printf("Preorder traverse of the constructed AVL \n");
  preorder(root);

  return 0;
}
