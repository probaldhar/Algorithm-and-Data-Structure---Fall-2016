/**
* Main file to call all the functions for checking the maze and to receive inputs from commandline argument.
* 
* @author Probal Chandra Dhar
* @date 9/30/2016
* @info Course COP5990
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include "backtracking.h"

int main(int argc, char **argv){

	// Stack structure
	StackT myStack;

	// initialize stack
	sinit(&myStack);

	// Maze structure
	SearchT *search;

	// allocate memory.
	search = ( SearchT* ) malloc( sizeof( SearchT ) );

	// init function calling from maze.c
	int result = init(argv[1], search);

	// check if the input file is formatted properly.
	if(result < 0){
		printf("Write the input file properly.\n");
		exit(1);
	}

	// store the initial starting point.
	int mazeStartX = search->xStart;
	int mazeStartY = search->yStart;

	// Check the number of steps needed for the current path.
	int numOfSteps = 0;

	// Flag to send the argument through solve function. 1 for no all & short, 2 for all, 3 for short.
	int conditionFlag = 1;

	// Check if the current position already reached the final position of maze.
	int reachEndFlag = 0;

	// check if there's any third argument of not. Like -all or -short
	if ( argv[2] ) {

		// compare the argument with all and short
		int findAll = strcmp(argv[2], "-all");
		int findShort = strcmp(argv[2], "-short");

		// check if the third commandline argument is -all
		if ( findAll == 0 ){

			// set the flag 2 for all.
			conditionFlag = 2;
			// printf("all\n");

			// Step to the next position in maze.
			step( search, &myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps );

			// print the final maze.
			print(search);

		// check if the third commandline argument is -short
		} else if ( findShort == 0 ){

			// set the flag 3 for short.
			conditionFlag = 3;
			// printf("short\n");

			// Step to the next position in maze.
			step( search, &myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps );

			// print the final maze.
			print(search);

		// Given third commandline argument is wrong
		} else {

			// in argument 2 condition written is wrong. No -all or -short.
			printf("Give the condition properly in the argument 2.\n");

		}

	// No third commandline argument given.
	} else {

		// Step to the next position in maze.
		if ( step( search, &myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps ) ) {
			printf("Solution found.\n");
		} else {
			printf("No Solution found.\n");
		}

	}

	// clear the stack 
	sclear(&myStack);


	// free the memory used for search data structure.
	freeMemory( search );

	return 0;
}