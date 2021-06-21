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


void printpreorder(struct node *root)
{
  if(root!=NULL)
  {
    printf("%d ->",root->data);
    printpreorder(root->left);
    printpreorder(root->right);
  }
}

//// Function to insert a BST node at the front of a doubly linked list
void push(struct node *root,struct node **headref)
{
  root->right=*headref;
  if( (*headref) !=NULL) {
    (*headref)->left=root;
  }
  *headref= root;
}

/*
    Recursive function to construct a sorted doubly linked list from a BST
    root —> Pointer to the root node of the binary search tree
    headRef —> Reference to the head node of the doubly linked list
    n —> Stores the total number of nodes processed so far in the BST
*/
void convertBSTtoSortedDLL(struct node *root,struct node **headref,int *n)
{
  if(root ==NULL)  return;
  int *nn;

  *nn=*n;
   convertBSTtoSortedDLL(root,headref,nn);
   push(root,headref);
  *nn= ++(*n);
   convertBSTtoSortedDLL(root,headref,nn);
}

/*
    Recursive function to construct a height-balanced BST from a doubly linked list
    headRef —> Reference to the head node of the doubly linked list
    n —> Total number of nodes in the doubly linked list
*/
struct node *convertSortedDLLToBST(struct node **headref,int *n)
{
  int *nn;

  if( *n <0 )
  {
    return NULL;
  }
  *nn=*n/2;
  struct node *leftSubTree =convertSortedDLLToBST(headref,nn);

  // `headRef` now points to the middle node of the sorted DDL

 // make the middle node of the sorted DDL as the root node of the BST
  struct node *root=*headref;
// update left child of the root node
  root->left=leftSubTree;

// update left child of the root node
  *headref=(*headref)->right;

// recursively construct the right subtree with the remaining nodes
 *nn=*n-(*n/2+1);
  root->right=convertSortedDLLToBST(headref,nn);

return root;

}

void constructBalancedBST(struct node *root)
{
   struct node *head=NULL;
   int counter =0;

   convertBSTtoSortedDLL(root,&head,&counter);   //DLL

  root= convertSortedDLLToBST(&head,&counter);
}

int main()
{

  struct node *root=newNode(20);
  root->left=newNode(15);
  root->left->left=newNode(10);
  root->left->left->left=newNode(5);
  root->left->left->left->left=newNode(2);
  root->left->left->left->right=newNode(8);


  //for(i=0;i<count;i++) printf("%d->",arr[i]);

  constructBalancedBST(root);
  printpreorder(root);

return 0;
}
