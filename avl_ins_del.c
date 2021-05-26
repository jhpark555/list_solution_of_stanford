/******************************************************************************
AVL insert / delete node in c
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int height(struct node *N)
{
    if (N==NULL) return 0;
    return (N->height);
}

int max(int a,int b)
{
    return (a>b)? a:b;
}

struct node *newnode(int key)
{
    struct node *node=(struct node*)malloc(sizeof(struct node));
    
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return(node);
}


//     y                               x
//    / \     Right Rotation          /  \
//   x   T3   - - - - - - - >        T1   y 
//  / \       < - - - - - - -            / \
// T1  T2     Left Rotation            T2  T3

struct node *rightrotate(struct node *y)
{
    struct node *x=y->left;
    struct node *T2=x->right;
    
    x->right=y;
    y->left=T2;
    
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    
    return(x);
}

struct node *leftrotate(struct node *x)
{
    struct node *y=x->right;
    struct node *T2=y->left;
    
    y->left=x;
    x->right=T2;
    
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    
    return(y);
}

int getbalance(struct node *n)
{
    if(n==NULL)
    return 0;
    
    return( height(n->left) - height(n->right) );
}

struct node *insert(struct node *node,int key)
{
   if(node ==NULL) return(newnode(key));
   
   /* 1.  Perform the normal BST insertion */
   if(key< node->key)
     node->left= insert(node->left,key);
   else if(key >node->key)
     node->right= insert(node->right,key);
   else 
     return (node);
     
    /* 2. Update height of this ancestor node */
    node->height= max(height(node->left) , height(node->right)) +1;
    
     /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
          
    int balance = getbalance(node);
    // If this node becomes unbalanced, then
    // there are 4 cases
    
    //left left case 
//  T1, T2, T3 and T4 are subtrees.
//         z                                      y 
//        / \                                   /   \
//       y   T4      Right Rotate (z)          x      z
//      / \          - - - - - - - - ->      /  \    /  \ 
//     x   T3                               T1  T2  T3  T4
//   / \
//  T1   T2  
    
    if(balance >1 && key < node->left->key)
      return rightrotate(node);
  
  // Right Right Case
//  z                                y
// /  \                            /   \ 
//T1   y     Left Rotate(z)       z      x
//    /  \   - - - - - - - ->    / \    / \
//   T2   x                     T1  T2 T3  T4
//       / \
//     T3  T4 
    if(balance <-1 && key> node->right->key)
     return leftrotate(node);
     
     
   // Left Right Case  
    
 //    z                               z                           x
 //   / \                            /   \                        /  \ 
 //  y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
 // / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
//T1   x                          y    T3                    T1  T2 T3  T4
//    / \                        / \
//  T2   T3                    T1   T2   

    if(balance>1 && key> node->left->key)
    {
        node->left=leftrotate(node->left);
        return rightrotate(node);
    }
    
    // Right Left Case
//   z                            z                            x
//  / \                          / \                          /  \ 
//T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
//    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
//   x   T4                      T2   y                  T1  T2  T3  T4
//  / \                              /  \
//T2   T3                           T3   T4   
   if( balance <-1 && key < node->right->key)
   {
       node->right=rightrotate(node->right);
       return leftrotate(node);
   }
    
    return (node);
    
}

struct node *minvaluenode(struct node *node)
{
    struct node *current=node;
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
struct node *deletenode(struct node *root,int key)
{
    if(root==NULL) return root;
    
    if(key<root->key) 
      root->left=deletenode(root->left,key);
    else if(key>root->key)
      root->right=deletenode(root->right,key);
    else
    {
        if((root->left==NULL) ||(root->right==NULL))
        {
            struct node *temp=root->left? root->left:root->right;
            
            if(temp ==NULL)
            {
                temp=root;
                root=NULL;
            }
            else
               *root=*temp;
               free(temp);
        }
        else
        {
           // node with two children: Get the inorder
            // successor (smallest in the right subtree)
           struct node *temp=minvaluenode(root->right);
           // Copy the inorder successor's data to this node
           root->key=temp->key;
           // Delete the inorder successor
           root->right=deletenode(root->right,temp->key);
        }
    }
    
    if(root==NULL)  return root;
    
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height=max(height(root->left),height(root->right))+1;
    
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance =getbalance(root);
    // If this node becomes unbalanced, then there are 4 cases
  
    // Left Left Case
    
    if( balance >1 && getbalance(root->left) >=0)
      return  rightrotate(root);
    // Left Right Case
    if( balance >1 && getbalance(root->left) <0 )
    {
        root->left =leftrotate(root->left);
        return rightrotate(root);
    }
    
    // Right Right Case
    if(balance <-1 && getbalance(root->right) <=0)
      return leftrotate(root);
    // Right Left Case
    if(balance <-1 && getbalance(root->right)>0)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    
    return root;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node *root=NULL;
    
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);
    
    root=deletenode(root,25);
    
    preorder(root);  printf("\n");
    return 0;
}

