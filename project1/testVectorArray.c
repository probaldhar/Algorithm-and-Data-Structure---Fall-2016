/**
* A test program for testing the Vector Abstract Data Type using Array.
* 
* @author Probal Chandra Dhar
* @date 9/09/2016
* @info Course COP5990
*/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "vectorArray.h"

int main(void)
{
	// starts the clock to calculate the elapsed time
	startTimer();

	// character to get the values from standard input
	char nextChar;

	// defining a new vector with a defined capacity
    VectorT *vector;
    vector = newVector(100000); 

    printf("Inserting 500,000 elements into vector.\n");
    // a interger to track the loop index
    int i;
    for( i=0; i<500000; i++ ){
    	// input the character from standard input
    	scanf ("%c ", &nextChar);

    	// add the value to the vector that is found from standard input
    	vadd(vector, nextChar);
    }

    // for ( i = 0; i < vector->size; ++i )
    // {
  //   	NodeT *node;
  //   	node = (NodeT*) malloc (sizeof(NodeT));
  //   	node = vector->list[i];
		// printf("i = %d %hhd\n",i ,node->info);
		// printf("%hhd\n", getInfo(node) );
		// printf("%s", vget(vector, i) );
    //}
  //   printf("\n%d\n", vector->size);

    printf("Check for the location of 100 elements of the vector.\n");
    for( i=0; i<100; i++){

    	// input the character from standard input
    	scanf ("%c ", &nextChar);

    	// check if the item present on the vector or not
    	vcontains(vector, nextChar);
    	// printf("%s", vget(vector, i) );
    }

    printf("Removing 300,000 elements from vector.\n");
    for ( i = 0; i < 300000; ++i){

    	// position where the item is present
    	int position;

    	// input the character from standard input
    	scanf("%c ", &nextChar);

    	// find the position of the item to the vector
    	position = vindexOf(vector, nextChar);

    	// remove the item from the vector
    	vremove(vector, position);

    }

    printf("Check for the location of 100 elements of the vector.\n");
    for( i=0; i<100; i++){

    	// input the character from standard input
    	scanf ("%c ", &nextChar);

    	// check if the item present on the vector or not
    	vcontains(vector, nextChar);
    }

    // Clear the Vector.
    vclear(vector);

    // Delete the Vector.
    vdelete(vector);

    // stop the clock that starts in the start of the program
    float elapsed = stopTimer();

    // prints the elapsed time
	printf ("It took %f seconds", elapsed);

    return 0;
}