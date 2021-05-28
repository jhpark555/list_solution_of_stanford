/******************************************************************************

Depth first search
*******************************************************************************/
#include <stdio.h>
#define MAX 9

void depth_first_search(int adj[][MAX],int visited[],int start)    // use stack
{
    int stack[MAX],top=-1,i;

    printf("%c->",start+65);
    stack[++top]= start;
    visited[start]=1;

    while(top!=-1)
    {
        start=stack[top];

        for(i=0;i <MAX;i++)
        {
            if(adj[start][i] ==1 && visited[i]==0)
            {
                stack[++top]=i;
                printf("%c->",i+65);
                visited[i]=1;
                break;
            }
        }
       if(i==MAX){
        top--;
       }
    }
}

/*

   a -> b <- C
   / /   /
   d ->e

*/

int main()
{
    int visited[MAX]={0};
    int adj[MAX][MAX]={
        0,1,1,1,0,0,0,0,0,
        0,0,0,0,1,0,0,0,0,
        0,1,0,0,0,0,1,0,0,
        0,0,1,0,0,0,1,0,0,
        0,0,1,0,0,1,0,0,0,
        0,0,1,0,0,0,0,1,0,
        0,0,0,0,0,1,0,1,1,
        0,0,0,0,1,0,0,0,1,
        0,0,0,0,0,1,0,0,0,
    };
    int i,j;
    printf("DFS Traversal: \n");
    depth_first_search(adj,visited,0);



    return 0;
}
