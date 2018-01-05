/**
 * Defines all data functions of TSP brute force
 *
 * @author Probal chandra dhar
 */

#ifndef _BRUTEFORCE_H
#define _BRUTEFORCE_H

/**
 * Creates an array with all vertices taken for the graph
 *
 * @param n - number of vertices to be visited
 * @param array - the array where the value will store
 *
 */
void createArrayOfVertices(int n, int array[]);

/**
 * Do all possible permutation for the number of vertices taken from file.
 *
 * @param array - array where all the vertices are stored
 * @param start - Starting node of the graph
 * @param start - Number of vertices in the graph
 * @param minNode - Minimum cost of any edge
 * @param AdjMat - the adjacency matrix of the graph
 *
 */
void permutation(int array[], int start, int end, int minNode, int adjMat[end][end]);


/**
 * crossover the vertices to apply a geentic algorithm in the vertices
 *
 * @param n - number of vertices to be visited
 * @param array - the array where the value will store
 *
 */
void genetic(int arrayLength, int array[]);

/**
 * Swap the value between two places
 *
 * @param a - pointer where the first element should point out
 * @param b - pointer where the second element should point out to swap
 *
 */
void swap(int* a,int* b);

/**
 * Calculate the minimum cost of the edges
 *
 * @param array - array where all vertices are stored
 * @param arrayLength - number of vertices for the graph 
 * @param minNode - Minimum cost of any edge
 * @param AdjMat - the adjacency matrix of the graph
 *
 */
void calCost(int array[], int arrayLength, int minNode, int adjMat[arrayLength][arrayLength]);

/**
 * Find out the value of a particular edge from adjacency matrix
 *
 * @param m - integer that represent first vertex
 * @param n - integer that represent second vertex
 * @param arrayLength - number of vertices for the graph 
 * @param AdjMat - the adjacency matrix of the graph
 *
 * @return the value of a particular edge between two vertices
 *
 */
int findCost(int m,int n, int arrayLength, int adjMat[arrayLength][arrayLength]);

/**
 * Calculate the trip cost of a round trip around the graph
 *
 * @param cost - the cost for the trip
 * @param count - used to calculate minimum
 * @param minNode - minimum edge that have minimum cost
 *
 */
void TripCost(int cost,int count, int minNode);

/**
 * Determine if the cost is minimum or not
 *
 * @param cost - the cost for the trip
 * @param minNode - minimum edge that have minimum cost
 *
 */
int minCompare(int cost, int minNode);

#endif