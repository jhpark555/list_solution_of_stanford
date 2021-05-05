/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int lookup(struct node* node,int target)
{
   if(node==NULL) return 0;
   else
   {
       if(target == node->data)    return(1);
       else{
       if(target <node->data) return( lookup(node->left,target));
       else return ( lookup(node->right,target));
       }
   }
}

struct node* NewNode(int data)
{
    struct node* node=malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    
    return(node);
}

struct node* insert(struct node* node,int data)
{
    if(node ==NULL) return(NewNode(data));
    else{
        if(data <= node->data) node->left=insert(node->left,data);
        else node->right=insert(node->right,data);
        
        return(node);
    }
    
}

struct node* build123a()
{
    struct node* root=NewNode(2);
    struct node* lChild= NewNode(1);
    struct node* rChild=NewNode(3);
    
    root->left=lChild;
    root->right=rChild;
    
}

struct node* build123b()
{
    struct node* root=NewNode(2);
    root->left= NewNode(1);
    root->right=NewNode(3);
    
    return(root);
    
}

struct node* build123c()
{
    struct node* root=NULL;
    root=insert(root,2);
    root= insert(root,1);
    root= insert(root,3);
    
    return(root);
    
}
struct node* build12345()
{
    struct node* root= NULL;
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root,5);
    
    return(root);
}

int size(struct node* node)
{
    
    if( node ==NULL) return(0);
    else{
       // printf("node->data=%d  \n",node->data);
        return( size(node->left) + size(node->right) +1);
    }
    
}

int  maxDepth(struct node* node)
{
   
    if(node==NULL) return 0;
    else{
       printf("## node->data=%d \n ",node->data);
      int lDepth= maxDepth(node->left);
      int rDepth= maxDepth(node->right);
      printf("data=%d  %x %x \n",node->data,lDepth,rDepth);
      if(lDepth>rDepth){
         // printf("l**%d \n",lDepth+1);
          return(lDepth+1);
      } 
      else {
         //  printf("r**%d \n",rDepth+1);
          return(rDepth+1);
      }
    }
  
}

int minValue(struct node* node)
{
    struct node* current= node;
    
    while(current->left !=NULL){
        current=current->left;
    }
    
    return(current->data);
    
}

int maxValue(struct node* node)
{
    struct node* current=node;
    
    while(current->right !=NULL){
        current=current->right;
    }
    return(current->data);
}

void printTree(struct node* node)
{
    if(node==NULL) return;
    
    printTree(node->left);
    printf(" %d ",node->data);
    printTree(node->right);
}

void printPostorder(struct node* node)
{
    if(node==NULL) return;
    
    printPostorder(node->left);
    printPostorder(node->right);
    
    printf("%d ",node->data);
}

int hasPathSum(struct node* node,int sum)
{
    if(node==NULL) return(sum==0);
    else
    {
        int subSum=sum-node->data;
        //printf(" Sum=%d sum=%d data=%d \n ",subSum,sum,node->data);
        return(hasPathSum(node->left,subSum) || hasPathSum(node->right,subSum));
    }
}

void printArray(int *path,int pathLen)
{
    for(int i=0;i<pathLen;i++)
     printf("%d ",path[i]);
     
     printf("\n");
}

void printPathsRecur(struct node* node,int *path,int pathLen)
{
    if(node==NULL) return;
    
    path[pathLen]=node->data;
    pathLen++;
    if(node->left==NULL && node->right==NULL) printArray(path,pathLen);
    else
    {
        printPathsRecur(node->left,path,pathLen);
        printPathsRecur(node->right,path,pathLen);
    }
}

void printPaths(struct node* node)
{
    int path[1000];
    
    printPathsRecur(node,path,0);
    
}


struct node* mirror(struct node* node)
{
    struct node* current;
    if(node==NULL) return;
    else{
        mirror(node->left);
        mirror(node->right);
        
        current=node->left;
        node->left=node->right;
        node->right=current;
        
    }
    return node;
}

struct node* doubleTree(struct node* node)
{
    struct node* oldLeft;
    
    if(node==NULL) return;
   
    doubleTree(node->left);
    doubleTree(node->right);
    
    oldLeft=node->left;
    
    node->left=NewNode(node->data);
    node->left->left=oldLeft;
    
    return(node);
}

int sameTree(struct node* a,struct node* b)
{
    if(a==NULL && b==NULL ) return(1);
    else if(a!=NULL && b!=NULL){
       // printf(" ==%d %d \n",a->data,b->data);
        return(
       ( a->data == b->data) &&
        sameTree(a->left,b->left) &&
        sameTree(a->right,b->right));
    }
    else return(0);
}

int countTrees(int numKeys)
{
    if(numKeys <=1) return (1);
    else{
        int sum=0;
        int left,right,root;
        
        for(root=1;root<=numKeys;root++){
            left=countTrees(root-1);
            right=countTrees(numKeys-root);
            
            sum +=left*right;
        }
        return(sum);
    }
}

int isBST(struct node* node)
{
    if(node==NULL) return (true);
    
    if( node->left!=NULL && minValue(node->left) > node->data) return (false);
    if(node->right!=NULL && maxValue(node->right)<= node->data) return (false);
    
    if( !isBST(node->left) || !isBST(node->right) ) return (true);
    
    return (true);
}

int isBSTRecur(struct node* node,int min,int max)
{
    if(node==NULL) return (true);
    
    if(node->data < min || node->data> max ) return ( false);
    
    return( 
        isBSTRecur(node->left,min,node->data) &&
        isBSTRecur(node->right,node->data+1,max)
        );
}
int isBST2(struct node* node)
{
    return(isBSTRecur(node,INT_MAX,INT_MAX));
    
}


int main()
{
    struct node* head, *head2;
    
    head=build12345();//build123c();
    head2=build123c();
   // int ret=maxValue(head);//maxDepth(head);//size(head);
   // printf("%d \n",ret);
    
     //printTree(head);
    // printPostorder(head);
    // ret=hasPathSum(head,9);
    //printf("ret=%d \n",ret);
    
   // printPaths(head);
  // printPaths(head);
  // struct node* temp= mirror(head);
   //printPaths(temp);
   //struct node* temp=doubleTree(head);
  // printPaths(temp);
 // int ret= sameTree(head,temp);
  //printf("%d \n",ret);
  
 // int sum=countTrees(2);
  //printf("%d \n",sum);
  int ret = isBST2(head);
   printf("%d \n",ret);
    return 0;
}




