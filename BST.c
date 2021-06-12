#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *newnode(int data)
{
  struct node *node=(struct node*)malloc(sizeof(struct node));
  node->data=data;

  node->left=NULL;
  node->right=NULL;
  return(node);

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

  return node;
}
void inorder(struct node *temp)
{
  if(temp==NULL) return;
  inorder(temp->left);
  printf("%d->",temp->data);
  inorder(temp->right);
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
struct node *deleteNode(struct node*root,int data)
{
  if(root ==NULL){
    return root;
  }

  if(root->data > data){
    root->left=deleteNode(root->left,data); }
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
//printf("**\n");
    struct node *temp=minValueNode(root->right);
//printf("***temp=%d root=%d\n",temp->data,root->data);
    // Copy the inorder
    // successor's content to this node
      root->data=temp->data;
     // Delete the inorder successor
     root->right= deleteNode(root->right,temp->data);

  }
  return root;
}

int main()
{
  struct node *root=NULL;
  root=insert(root,50);
  insert(root,30);
  insert(root,20);
  insert(root,40);
  insert(root,70);
  insert(root,60);
  insert(root,80);
  printf("Inorder traversal of the given tree \n");
  inorder(root);
  printf("\nDelete 30\n");
  deleteNode(root,30);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);
//  printf("\n");
//  deleteNode(root,70); inorder(root);
//  root=insert(root,12);


  return 0;
}
