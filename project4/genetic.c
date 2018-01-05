#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genetic.h"
#include "time.h"

/**
 * This program is the implementation of the TSP problem with genetic algorithm.
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

	// checking if the user put the correct value to run the program
	if ( argc < 4 ){
		printf("Argument missing\nusage: tspBruteForce <filename> <numCities> <numGen>");
		exit(0);
	}

	// Number of cities is entered valid or not
	if (atoi(argv[2]) == 0){
		printf("Please enter valid number of cities.\n");
		exit(0);
	}

	// number of generations is entered valid or not
	if (atoi(argv[3]) == 0){
		printf("Please enter valid number of generations.\n");
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
    int cost, generations;

    // assigining number of generations from argument
    generations = atoi(argv[3]);

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

	// displayArray(arrElement, n);

	for ( i = 0; i < generations; i++){
		// printf("%d ", i);
		genetic(n, arrElement);
	}
	
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
 * crossover the vertices to apply a geentic algorithm in the vertices
 *
 * @param n - number of vertices to be visited
 * @param array - the array where the value will store
 *
 */
void genetic(int arrayLength, int array[]){

	int i, j, firstHalf, secondHalf, breakArray;

	breakArray = arrayLength/2;

	firstHalf = breakArray;
	secondHalf = arrayLength - firstHalf;

	int firstHalfArray[firstHalf], secondHalfArray[secondHalf];

	for ( i = 1; i <= breakArray; i++)
	{
		firstHalfArray[i] = array[i];
		// printf("%d ", firstHalfArray[i]);
	}
	// printf("\n");
	for ( i = breakArray+1, j = 1; i <= arrayLength; i++, j++)
	{
		secondHalfArray[j] = array[i];
		// printf("%d ", secondHalfArray[j]);
	}

	// printf("\n");printf("\n");
	int firstCounter = 1, secondCounter = 1;

	for ( i = 1; i <= arrayLength; i=i+2)
	{

		array[i] 	= firstHalfArray[firstCounter];
		firstCounter++;
		array[i+1] 	= secondHalfArray[secondCounter];
		secondCounter++;

		if ( i >= arrayLength ){
			array[i] = secondHalfArray[secondHalf];
		}

	}
	// printf("\n");
	calCost(array, arrayLength);


}

/**
 * Calculate the minimum cost of the edges
 *
 * @param array - array where all vertices are stored
 * @param arrayLength - number of vertices for the graph 
 *
 */
void calCost(int array[], int arrayLength){
	
	int i;
	int sum=0;
	
	for(i=1;i<arrayLength;i++){
		sum+=findCost(array[i],array[i+1], arrayLength);
	}
	// printf("%d\n", i);
	sum+=findCost(array[i],array[1], arrayLength);

	TripCost(sum, count);
	count++;
	//printf("The cost for this trip is %d\n",sum);
}

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
int findCost(int m,int n, int arrayLength){
	
	return newAdjMat[m][n];
}

/**
 * Calculate the trip cost of a round trip around the graph
 *
 * @param cost - the cost for the trip
 * @param count - used to calculate minimum
 *
 */
void TripCost(int cost,int count){
	
	if(count==0){
		minimumValuedEdge=cost;
		// minNode=cost;
	}
	else{
		minimumValuedEdge=minCost(cost);
		// minNode = minCost(cost, minNode);
	}
	
	//printf("The minimum cost for the trip is %d \n",min);
}

/**
 * Determine if the cost is minimum or not
 *
 * @param cost - the cost for the trip
 *
 */
int minCost(int cost){
	
	return((minimumValuedEdge>cost)?cost:minimumValuedEdge);
	// return((minNode>cost)?cost:minNode);
}


