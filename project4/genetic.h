/**
 * Defines all data functions of TSP genetic algorithm
 *
 * @author Probal chandra dhar
 */

#ifndef _GENETIC_H
#define _GENETIC_H

/**
 * Creates an array with all vertices taken for the graph
 *
 * @param n - number of vertices to be visited
 * @param array - the array where the value will store
 *
 */
void createArrayOfVertices(int, int array[]);

/**
 * crossover the vertices to apply a geentic algorithm in the vertices
 *
 * @param n - number of vertices to be visited
 * @param array - the array where the value will store
 *
 */
void genetic(int arrayLength, int array[]);

/**
 * Calculate the minimum cost of the edges
 *
 * @param array - array where all vertices are stored
 * @param arrayLength - number of vertices for the graph 
 *
 */
void calCost(int array[], int arrayLength);

/**
 * Find out the value of a particular edge from adjacency matrix
 *
 * @param m - integer that represent first vertex
 * @param n - integer that represent second vertex
 * @param arrayLength - number of vertices for the graph 
 *
 * @return the value of a particular edge between two vertices
 *
 */
int findCost(int m,int n, int arrayLength);

/**
 * Calculate the trip cost of a round trip around the graph
 *
 * @param cost - the cost for the trip
 * @param count - used to calculate minimum
 *
 */
void TripCost(int cost,int count);

/**
 * Determine if the cost is minimum or not
 *
 * @param cost - the cost for the trip
 *
 */
int minCost(int cost);



#endif