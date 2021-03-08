
#include <limits.h> 
  
#include <stdbool.h> 
  
#include <stdio.h> 
  
#define V 6
  
 
int
minKey (int key[], bool m[]) 
 
{
  
 
 
int min = INT_MAX, min_index;
  
 
for (int v = 0; v < V; v++)
    
 
if (m[v] == false && key[v] < min)
      
 
min = key[v], min_index = v;
  
 
return min_index;

 
}


 
 
 
int
printMST (int p[], int graph[V][V]) 
 
{
  
 
printf ("Edge \tCost\n");
  
 
for (int i = 1; i < V; i++)
    
 
printf ("%d to %d -> %d \n", p[i], i, graph[i][p[i]]);

 
} 
 
 
 
void

prim (int graph[V][V]) 
 
{
  
 
 
 
int p[V];
  
 
 
 
int key[V];
  
 
 
 
bool m[V];
  
 
 
 
for (int i = 0; i < V; i++)
    
 
key[i] = INT_MAX, m[i] = false;
  
 
 
 
key[0] = 0;
  
 
p[0] = -1;
  
 
 
 
for (int count = 0; count < V - 1; count++)
    {
      
 
 
 
int u = minKey (key, m);
      
 
 
 
m[u] = true;
      
 
 
 
for (int v = 0; v < V; v++)
	
 
if (graph[u][v] && m[v] == false && graph[u][v] < key[v])
	  
 
p[v] = u, key[v] = graph[u][v];
    
 
}
  
 
printMST (p, graph);

 
}


 
void
main () 
 
{
  
 
int graph[V][V] = { {0, 1, 0, 0, 5, 0}, 
    {1, 0, 4, 3, 0, 0}, 
    {0, 4, 0, 0, 0, 8}, 
    {0, 3, 0, 0, 1, 2}, 
{5, 0, 0, 1, 0, 6}, 
{0, 0, 8, 2, 6, 0}
  };
  
 
 
prim (graph);

 
}

