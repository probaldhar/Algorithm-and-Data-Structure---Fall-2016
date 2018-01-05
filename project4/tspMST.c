#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"

/**
 * This program is the implementation of the TSP problem with minimal spanning tree.
 * The program runs the vertices from a file.
 *
 * This program is not finished
 *
 * @author probal chandra dhar
 * @date 12/1/2016
 * @info Course COP5990
 */
 
// Number of vertices in the graph
#define V 20
#define INT_MAX 9999
typedef int bool;
#define true 1
#define false 0
 
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
/**
 * Print the minimal edges of the minimal spinning tree
 *
 * @param parent - the array of the parents
 * @param n - number of vertices
 * @param adjMat - Adjacency matrix
 *
 */
void printMST(int parent[], int n, int adjMat[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, adjMat[i][parent[i]]);
}
 
/**
 * Calculate the minimal spinning tree from a graph
 *
 * @param adjMat - Adjacency matrix
 *
 */
void primMST(int graph[V][V])
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < V-1; count++)
     {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     // print the constructed MST
     printMST(parent, V, graph);
}
 
 
int main()
{
   
   int graph[V][V] ;

   // start the timer
    startTimer();
 
    // Print the solution
    primMST(graph);

    // stoping the timer
	float elapsedTime = stopTimer ();

	printf ("It took %f seconds to complete the job.\n", elapsedTime);
 
    return 0;
}