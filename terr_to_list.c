
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*
TreeList.c
C code version of the great Tree-List recursion problem.
See http://cslibrary.stanford.edu/109/ for the full
discussion and the Java solution.
This code is free for any purpose.
Feb 22, 2000
Nick Parlante nick.parlante@cs.stanford.edu
*/

struct node{
    int data;
    struct node* small;
    struct node* large;
};

typedef struct node* Node;

static void join(Node a, Node b)
{
    a->large=b;
    b->small=a;
}

static Node append(Node a, Node b)
{
    Node aLast, bLast;

    if(a==NULL) return(b);
    if(b==NULL) return(a);

    aLast=a->small;
    bLast=b->small;

    join(aLast,b);
    join(bLast,a);

    return(a);

}

static Node treeTolist(Node root)
{
    Node aList,bList;

    if(root==NULL) return(NULL);

    aList=treeTolist(root->small);
    bList=treeTolist(root->large);

    root->small=root;
    root->large=root;

    aList=append(aList,root);
    aList=append(aList,bList);

    return(aList);

}

static Node newNode(int data)
{
    Node node=(Node)malloc(sizeof(struct node));
    node->data=data;
    node->small=NULL;
    node->large=NULL;

    return(node);
}

static void treeInsert(Node* rootref,int data)
{
    Node root =*rootref;
    if(root==NULL) *rootref=newNode(data);
    else{
        if(data<=root->data) treeInsert(&(root->small),data);
        else treeInsert(&(root->large),data);
    }
}

static void printList(Node head)
{
    Node current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->large;
        if(current==head) break;

    }
    printf("\n");
}

int main()
{
    Node root=NULL;
    Node head;

    treeInsert(&root,4);
    treeInsert(&root,2);
    treeInsert(&root,1);
    treeInsert(&root,3);
    treeInsert(&root,5);

    head=treeTolist(root);

    printList(head);

    return 0;
}
