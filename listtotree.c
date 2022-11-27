#include <stdio.h>
#include <stdlib.h>

struct LNode
{
  int data;
  struct LNode* next;
};

struct TNode
{
  int data;
  struct TNode* left;
  struct TNode* right;
};

struct TNode* newNode(int data);
int countLNodes(struct LNode* head);
struct TNode *sortedListToBSTRecur(struct LNode **head_ref, int n);

/* This function counts the number of nodes in Linked List and then calls
   sortedListToBSTRecur() to construct BST */
struct TNode *sortedListToBST(struct LNode *head)
{
  int n= countLNodes(head);

  return sortedListToBSTRecur(&head,n);
}

/* The main function that constructs balanced BST and returns root of it.
       head_ref -->  Pointer to pointer to head node of linked list
       n  --> No. of nodes in Linked List */
struct TNode *sortedListToBSTRecur(struct LNode **head_ref, int n)
{
  if (n<=0) return NULL;     // <= is important to recursive

  struct TNode *left = sortedListToBSTRecur(head_ref,n/2);

  struct TNode *root = newNode((*head_ref)->data);
  root -> left = left;

  *head_ref= (*head_ref)->next;
/* Recursively construct the right subtree and link it with root
      The number of nodes in right subtree  is total nodes - nodes in
      left subtree - 1 (for root) which is n-n/2-1*/
   root->right =sortedListToBSTRecur(head_ref,n-n/2-1);

   return root;
}

int countLNodes(struct LNode *head)
{
  int count =0;

  struct LNode *temp=head;
  while(temp)
  {
    temp=temp->next;
    count++;
  }
  return count;
}

void push(struct LNode **head_ref, int new_data)
{
  struct LNode *new_node = (struct LNode*)malloc(sizeof(struct LNode));
  new_node->data=new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void printList(struct LNode *node)
{
  struct LNode *curr=node;
  while(curr!=NULL)
  {
    printf("%d->",curr->data);
    curr = curr->next;
  }

}


struct TNode *newNode(int data)
{
  struct TNode *node=(struct TNode*)malloc(sizeof(struct TNode));
  node->data=data;
  node->left=NULL;
  node->right=NULL;

  return node;
}

void preOrder(struct TNode *node)
{
  if(node == NULL) return ;
  printf("%d->",node->data);
  preOrder(node->left);
  preOrder(node->right);
}

int main()
{
 struct LNode *head=NULL;

 push(&head,7);
 push(&head,6);
 push(&head,5);
 push(&head,4);
 push(&head,3);
 push(&head,2);
 push(&head,1);
 printf("\n Gievn Linked List ");
 printList(head);
 struct TNode *root=sortedListToBST(head);
 printf("\n Preorder Traverseal of constructed BST ");
 preOrder(root);

return 0;
}
