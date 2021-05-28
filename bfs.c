/******************************************************************************


*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_Q_SIZE 500

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node **createQueue(int *front, int*rear)
{
    struct node **queue=(struct node**)malloc(sizeof(struct node*)*MAX_Q_SIZE);
    *front=*rear=0;
    return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)  // see why queue is double pointer
{
    queue[(*rear)++] = new_node;
}

struct node *deQueue(struct node **queue,int *front)
{
   // (*front)++;       // caution for (*ptr)++.   this is ptr value increase.
    return queue[(*front)++];
}

struct node *new_node(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

void printLevelOrder(struct node *root)
{
    int rear,front;
    struct node **queue=createQueue(&front,&rear);
    struct node *temp_node=root;

    while(temp_node)
    {
        printf("%d ",temp_node->data);
        // enqueue left child
        if(temp_node->left)
         enQueue(queue,&rear,temp_node->left);
        //enqueue right child
        if(temp_node->right)
         enQueue(queue,&rear,temp_node->right);

         //deQueue
         temp_node=deQueue(queue,&front);
    }
}

int main()
{

    struct node *root=NULL;

    root=new_node(1);

    root->left=new_node(2);
    root->right=new_node(3);
    root->left->left=new_node(4);
    root->right->right=new_node(6);

    printLevelOrder(root);

    return 0;
}
