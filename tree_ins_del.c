/******************************************************************************


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insertElement(struct node *tree,int val)
{
    struct node *ptr,*nodeptr,*parentptr;
    ptr=(struct node *)malloc(sizeof(struct node ));
    
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
    
    if(tree==NULL)
    {
        tree=ptr;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        parentptr=NULL;
        nodeptr=tree;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(val<nodeptr->data) nodeptr=nodeptr->left;
            else nodeptr=nodeptr->right;
        }
        if(val<parentptr->data) parentptr->left=ptr;
        else parentptr->right=ptr;
        
    }
    return tree;
}

void preorderTraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t",tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
    
}
void inorderTraversal(struct node *tree)
{
      if( tree!=NULL)
      {
          inorderTraversal(tree->left);
          printf("%d\t",tree->data);
          inorderTraversal(tree->right);
      }
}
void postorderTraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t",tree->data);
    }
}

struct node *findsmallestElement(struct node *tree)
{
    if(tree==NULL || tree->left ==NULL) return tree;
    else  return findsmallestElement(tree->left);
}

struct node *findlargestElement(struct node *tree)
{
      if(tree==NULL || tree->right==NULL) return tree;
      else return findlargestElement(tree->right);
}

struct node *minvalueNode(struct node *tree)
{
    struct node *current=tree;
    while(current!=NULL && current->left !=NULL)
      current=current->left;
      return (current);
}
#if 0
struct node *deleteElement(struct node *tree,int val)
{
    struct node *current,*parent,*suc,*psuc,*ptr;
    
    if(tree->left==NULL)
    {
        printf("\n The tree is empty ");
        return(tree);
    }
    parent=tree;
    current=tree->left;
    while(current!=NULL && val!=current->data)
    {
        parent=current;
         printf("# %d  %d \n",current->data,val);
        current=(val<current->data)? current->left:current->right;
    }
    if(current==NULL)
    {
        printf("\n The value to be deleted is not present in the tree\n");
        return (tree);
    }
    if(current->left ==NULL) ptr=current->right;
    else if(current->right==NULL) ptr=current->left;
    else
    {
        psuc=current;
        current=current->left;
        while(suc->left!=NULL)
        {
            psuc=suc;
            suc=suc->left;
        }
        if(current==psuc)
        {
            suc->left=current->right;
        }
        else
        {
            suc->left=current->left;
            psuc->left=suc->right;
            suc->right=current->right;
        }
        ptr=suc;
    }
    if(parent->left==current)
        parent->left=ptr;
    else 
        parent->right=ptr;
    free(current);
    return (tree);
}
#else
struct node *deleteElement(struct node *tree, int val)
{
    if(tree ==NULL) return tree;
    
    if(val<tree->data) 
       tree->left=deleteElement(tree->left,val);
    else if(val > tree->data) 
       tree->right=deleteElement(tree->right,val);
    else
    {
        // node with only one child or no child
        if(tree->left ==NULL) {
            struct node *temp=tree->right;
            free(tree);
            return(temp);
        }
        else if(tree->right==NULL){
            struct node *temp=tree->left;
            free(tree);
            return (temp);
        }
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        
        struct node *temp=minvalueNode(tree->right);
         // Copy the inorder
        // successor's content to this node
        tree->data=temp->data;
        
        // Delete the inorder successor
        tree->right=deleteElement(tree->right,temp->data);
    }
    return (tree);
}

#endif

int totalNodes(struct node *tree)
{
    if(tree ==NULL) return 0;
    else
     return( totalNodes(tree->left)+totalNodes(tree->right)+1);
}
int totalExternalNodes(struct node *tree)
{
    if(tree==NULL) return 0;
    else if( (tree->left==NULL)&&(tree->right==NULL)) return 1;
    else
     return( totalExternalNodes(tree->left)+totalExternalNodes(tree->right));
}

int totalInterNodes(struct node *tree)
{
    if(tree==NULL) return 0;
    else
     return( totalInterNodes(tree->left)+totalInterNodes(tree->right)+1);
}

int Height(struct node *tree)
{
    int leftheight,rightheight;
    
    if(tree==NULL) return 0;
    else{
    leftheight=Height(tree->left);
    rightheight=Height(tree->right);
    
    if(leftheight > rightheight) return(leftheight +1);
    else return(rightheight+1);
    }
}
struct node *deletetree(struct node *tree)
{
    if(tree!=NULL)
    {
        deletetree(tree->left);
        deletetree(tree->right);
        free(tree);
    }
}


int main()
{
    struct node *tree=NULL;
    struct node *ret=NULL;
    
    tree=insertElement(tree,50);
      tree=insertElement(tree,30);
        tree=insertElement(tree,20);
          tree=insertElement(tree,40);
           tree=insertElement(tree,70);
            tree=insertElement(tree,60);
             tree=insertElement(tree,80);
          
          
          
    preorderTraversal(tree);
    printf("\n****************\n");
    inorderTraversal(tree);
    printf("\n****************\n");
    postorderTraversal(tree);
    
    ret=findsmallestElement(tree);
    printf("\n****************\n");
    printf("SmallestElement=%d \n",ret->data);
    
    ret=findlargestElement(tree);
    printf("\n****************\n");
    printf("LargestElement=%d \n",ret->data);
    
    ret=deleteElement(tree,80);
     inorderTraversal(ret);
     
    int nodes= totalNodes(tree);
    int totalExt=totalExternalNodes(tree);
    int intnodes=totalInterNodes(tree);
    int height=Height(tree);
    printf("\n Nodes=%d ext nodes=%d internal node=%d height=%d",nodes,totalExt,intnodes,height);
    return 0;
}

