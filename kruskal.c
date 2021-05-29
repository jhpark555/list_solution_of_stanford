// kruskal's minimum spanning tree algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge{
  int src, dest,weight;
};

struct Graph{
  int V,E;    //vertices, edges
  struct Edge *edge;
};

struct Graph *createGraph(int V,int E)
{
  struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
  graph->V=V;
  graph->E=E;

  graph->edge=(struct Edge*)malloc(sizeof(struct Edge));

  return graph;
}

// A structure to represent a subset for union-find
struct subset
{
  int parent;
  int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[],int i)
{
  // find root and make root as parent of i
  // (path compression)
  if(subsets[i].parent !=i)
   subsets[i].parent = find(subsets,subsets[i].parent);
   return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[],int x,int y)
{
  int xroot= find(subsets,x);
  int yroot= find(subsets,y);

  // Attach smaller rank tree under root of high
  // rank tree (Union by Rank)
  if(subsets[xroot].rank < subsets[yroot].rank)
     subsets[xroot].parent =yroot;
  else if ( subsets[xroot].rank > subsets[yroot].rank)
     subsets[yroot].parent =xroot;
  else
  {
     subsets[yroot].parent=xroot;
     subsets[xroot].rank++;
  }
}

int myComp(const void *a,const void *b)
{
  struct Edge *a1=(struct Edge*)a;
  struct Edge *b1=(struct Edge*)b;

  return a1->weight - b1->weight;
}

// The main function to construct MST using Kruskal's
// algorithm
void KruskalMST(struct Graph *graph)
{
  int V =graph->V;
  struct Edge result[V];
  struct subset *subsets;

  int e=0;
  int i=0;
  int v;


  // Step 1: Sort all the edges in non-decreasing
  // order of their weight. If we are not allowed to
  // change the given graph, we can create a copy of
  // array of edges
  qsort(graph->edge,graph->E,sizeof(graph->edge[0]),myComp);

  struct subset *subsets=(struct subset*)malloc(V*sizeof(struct subset));

  for(v=0; v< V;++v )
  {
    subsets[v].parent =v;
    subsets[v].rank =0;
  }

  while(e <V-1 && i <graph->E)
  {
    // Step 2: Pick the smallest edge. And increment
    // the index for next iteration
   struct Edge next_edge= graph->edge[i++];
   int x=find(subsets,next_edge.src);
   int y=find(subsets,next_edge.dest);

  // If including this edge does't cause cycle,
  // include it in result and increment the index
  // of result for next edge

  if(x!=y){
    result[e++] = next_edge;
    Union(subsets,x,y);
  }
  }
  printf("\nFollowing are the edges in the constructed MST\n");
  int minimumCost =0;

  for(i=0;i< e; ++i)
  {
    printf("%d--%d ==%d\n",result[i].src,result[i].dest, result[i].weight);
    minimumCost += result[i].weight;
  }
  printf("\nMinimum Cost Spanning tree : %d \n", minimumCost);
  return;
}

int main()
{
  /* Let us create following weighted graph
         10
     0--------1
     | \     |
    6|  5\   |15
     |     \ |
     2--------3
         4     */
  int V=4;   // Number of vertices in graph
  int E=5;   // Number of edges in graph

  struct Graph *graph= createGraph(V,E);

  // add edge 0-1
   graph->edge[0].src=0;
   graph->edge[0].dest=1;
   graph->edge[0].weight=10;
  //add edge 0 -2
   graph->edge[1].src=0;
   graph->edge[1].dest=2;
   graph->edge[1].weight=6;

   //add edge 0 -3
   graph->edge[2].src=0;
   graph->edge[2].dest=3;
   graph->edge[2].weight=5;

   //add edge 1 -3
   graph->edge[2].src=1;
   graph->edge[2].dest=3;
   graph->edge[2].weight=15;

   //add edge 2 -3
   graph->edge[2].src=2;
   graph->edge[2].dest=3;
   graph->edge[2].weight=4;

   KruskalMST(graph);

   return 0;

}
