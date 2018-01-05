#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bruteForce.h"
#include "time.h"

/**
 * This program is the implementation of the TSP problem with brute force.
 * The program runs the vertices from a file.
 * 
 * @author probal chandra dhar
 * @date 12/1/2016
 * @info Course COP5990
 */

#define max 20

/**
 * Adjacency matrix
 */
int newAdjMat[max][max];

/**
 * Minimum value of the edges
 */
int minimumValuedEdge;

/**
 * Used to determine the minimum value of edges
 */
int count=0;

int main(int argc, char **argv){

	/**
 	 * Array that have the set of vertices
 	 */
	int arrElement[max]; 

	/**
 	 * Number of vertices in the graph
 	 */
	int n;

	/**
 	 * The minimum value of the edges.
 	 */
	int minimumNode = 0;

	// checking if the user put the correct value to run the program
	if ( argc < 3 ){
		printf("Argument missing\nusage: tspBruteForce <filename> <numCities>");
		exit(0);
	}

	// Number of cities is entered or not
	if (atoi(argv[2]) == 0){
		printf("Please enter valid number of cities.\n");
		exit(0);
	}

	// FIle pointer
	FILE *fp;
	fp = fopen(argv[1], "r+");
	const char s[2] = ",";
	char *token;
    int i, j;

    // int adj[16][16] = {0};
    int adj[16][16];
    int cost;

    // Stores the characters from the file
    char charOrigin, charDestination;

    if (fp){

    	// start the timer
    	startTimer();

    	char line[20];

        while (fgets(line, sizeof(line), fp) != NULL)
        {
            token = strtok(line, s);

    		charOrigin = token[0];
            // printf("%c\t",charOrigin);
            token = strtok(NULL,s);
            charDestination = token[0];
            // printf("%c\t",charDestination);
            token = strtok(NULL,s);

        	cost = atoi(token);
            // printf("%d\n",cost);

        	// converting the characters to numbers
            adj[charOrigin%65+1][charDestination%65+1] = cost;
            adj[charDestination%65+1][charOrigin%65+1] = cost;

        }
        fclose(fp);
    } else {
    	printf("File not found\n");
    	exit(0);
    }

    n = atoi(argv[2]);
	printf("Number of edges: %d\n", n);


	// assigining 0 to all elements
	for ( i = 0; i < n+1; i++)
    {
    	for ( j = 0; j < n+1; j++)
    	{
    		newAdjMat[i][j] = 0;
    	}
    }

    // assigning the values of the edges to global matrix
	for ( i = 1; i <= n; i++ )
	{
		for ( j = i+1; j <= n; j++ ){

			newAdjMat[i][j] = adj[i][j];
			newAdjMat[j][i] = adj[i][j];

		}
	}

	// creating the array of the vertices	
	createArrayOfVertices(n, arrElement);

	// Permuting the array
	permutation(arrElement,1,n, minimumNode, newAdjMat);
	
	printf("The minimum cost for the trip is %d\n",minimumValuedEdge);

	// stoping the timer
	float elapsedTime = stopTimer ();

	printf ("It took %f seconds to complete the job.\n", elapsedTime);
	
	return 0;
}

/**
 * Creates an array with all vertices taken for the graph
 *
 * @param n - number of vertices to be visited
 * @param array - the array where the value will store
 *
 */
void createArrayOfVertices(int n, int array[]){
	
	int i;
	for(i=1;i<=n;i++){
		array[i]=i;
	}
}

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
void permutation(int array[], int start, int end, int minNode, int adjMat[end][end]){

	int i;
	if (start==end) {
		calCost(array, end, minNode, adjMat);
		
	}
	
	else {
		
		for (i=start;i<=end;i++) {
			swap(&array[i],&array[start]);
			permutation(array, start+1, end, minNode, adjMat);
			swap(&array[i],&array[start]);
		}
	}
}

/**
 * Swap the value between two places
 *
 * @param a - pointer where the first element should point out
 * @param b - pointer where the second element should point out to swap
 *
 */
void swap(int* a,int* b){
	
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

/**
 * Calculate the minimum cost of the edges
 *
 * @param array - array where all vertices are stored
 * @param arrayLength - number of vertices for the graph 
 * @param minNode - Minimum cost of any edge
 * @param AdjMat - the adjacency matrix of the graph
 *
 */
void calCost(int array[], int arrayLength, int minNode, int adjMat[arrayLength][arrayLength]){
	
	int i;
	int sum=0;
	
	for(i=1;i<arrayLength;i++){
		sum+=findCost(array[i],array[i+1], arrayLength, adjMat);
	}
	// printf("%d\n", i);
	sum+=findCost(array[i],array[1], arrayLength, adjMat);

	// printf("%d\n", findCost(array[i],array[1]));

	// printf("%d\n", minNode);
	
	TripCost(sum, count, minNode);
	count++;
	//printf("The cost for this trip is %d\n",sum);
}

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
int findCost(int m,int n, int arrayLength, int adjMat[arrayLength][arrayLength]){
	
	return newAdjMat[m][n];
}

/**
 * Calculate the trip cost of a round trip around the graph
 *
 * @param cost - the cost for the trip
 * @param count - used to calculate minimum
 * @param minNode - minimum edge that have minimum cost
 *
 */
void TripCost(int cost,int count, int minNode){
	
	if(count==0){
		minimumValuedEdge=cost;
		// minNode=cost;
	}
	else{
		minimumValuedEdge=minCompare(cost, minNode);
		// minNode = minCompare(cost, minNode);
	}
	
	//printf("The minimum cost for the trip is %d \n",min);
}

/**
 * Determine if the cost is minimum or not
 *
 * @param cost - the cost for the trip
 * @param minNode - minimum edge that have minimum cost
 *
 */
int minCompare(int cost, int minNode){
	
	return((minimumValuedEdge>cost)?cost:minimumValuedEdge);
	// return((minNode>cost)?cost:minNode);
}
