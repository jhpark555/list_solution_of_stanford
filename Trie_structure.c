#include <stdio.h>
#include <stdlib.h>

#define CHAR_SIZE 26

struct Trie
{
  int isLeaf;
  struct Trie *character[CHAR_SIZE];
};

struct Trie *getNewTrieNode()
{
  int i;
  struct Trie *node=(struct Trie*)malloc(sizeof(struct Trie));
  node->isLeaf =0;

  for(i=0; i <CHAR_SIZE ; i++ ){
    node ->character[i]=NULL;
  }

  return node;
}

void insert(struct Trie *head,char *str)
{
  struct Trie *curr=head;
  while(*str)
  {
    // create a new node if the path doesn't exist
    if(curr->character[*str-'a']==NULL ){
      curr->character[*str-'a']=getNewTrieNode();
    }
    // go to the next node
    curr=curr->character[*str-'a'];
    // move to the next character
    str++;
  }
  // mark the current node as a leaf
  curr->isLeaf =1;
}

int search(struct Trie *head,char *str)
{
  struct Trie *curr=head;

  if(head ==NULL) return 0;

  while(*str)
  {
    curr=curr->character[*str-'a'];

    // if the string is invalid (reached end of a path in the Trie)
    if(curr==NULL) return 0;
    str++;
  }
  // return 1 if the current node is a leaf and the
  // end of the string is reached
  return curr->isLeaf;
}

int hasChildren(struct Trie *curr)
{
  int i;
  for(i=0 ;i <CHAR_SIZE ; i++)
  {
    if( curr->character[i]) return 1;
  }
  return 0;
}

int deletion(struct Trie **curr, char *str)
{
  if(*curr == NULL) return 0;

  if(*str)
  {
    // recur for the node corresponding to the next character in
    // the string and if it returns 1, delete the current node
    // (if it is non-leaf)
    if(*curr !=NULL && (*curr)->character[*str-'a'] !=NULL &&
       deletion(&((*curr)->character[*str-'a']),str+1) && (*curr)->isLeaf ==0)
       {
         if(hasChildren(*curr))
         {
           free(*curr);
           (*curr) = NULL;
           return 1;
         }
         else
         {
           return 0;
         }
       }
  }
  // if the end of the string is reached
  if(*str=='\0' && (*curr)->isLeaf)
  {
    // if the current node is a leaf node and doesn't have any children
    if(!hasChildren(*curr))
    {
      free(*curr);
      (*curr) = NULL;
      return 1;
    }
   // if the current node is a leaf node and has children
   else
   {
      // mark the current node as a non-leaf node (DON'T DELETE IT)
     (*curr)->isLeaf =0;
     return 0;
   }
  }
 return 0;
}

// Trie implementation in C – Insertion, Searching, and Deletion
int main()
{
    struct Trie* head = getNewTrieNode();

    insert(head, "hello");
    printf("%d ", search(head, "hello"));       // print 1

    insert(head, "helloworld");
    printf("%d ", search(head, "helloworld"));  // print 1

    printf("%d ", search(head, "helll"));       // print 0 (Not present)

    insert(head, "hell");
    printf("%d ", search(head, "hell"));        // print 1

    insert(head, "h");
    printf("%d \n", search(head, "h"));         // print 1 + newline

    deletion(&head, "hello");
    printf("%d ", search(head, "hello"));       // print 0 (hello deleted)
    printf("%d ", search(head, "helloworld"));  // print 1
    printf("%d \n", search(head, "hell"));      // print 1 + newline

    deletion(&head, "h");
    printf("%d ", search(head, "h"));           // print 0 (h deleted)
    printf("%d ", search(head, "hell"));        // print 1
    printf("%d\n", search(head, "helloworld")); // print 1 + newline

    deletion(&head, "helloworld");
    printf("%d ", search(head, "helloworld"));  // print 0
    printf("%d ", search(head, "hell"));        // print 1

    deletion(&head, "hell");
    printf("%d\n", search(head, "hell"));       // print 0 + newline

    if (head == NULL) {
        printf("Trie empty!!\n");               // Trie is empty now
    }

    printf("%d ", search(head, "hell"));        // print 0

    return 0;
}
