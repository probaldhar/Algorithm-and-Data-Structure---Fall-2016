/**
* Implements the functions of backtracking.h
* 
* @author Probal Chandra Dhar
* @date 9/30/2016
* @info Course COP5990
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "maze.h"
#include "backtracking.h"

/**
 * a function to check if the cell has Top Wall, if the next cell is visited or not and if the next cell leads to a solution ot not.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	A integer to check the condition supplied by commandline argument.
 * @param reachEndFlag 		A integer to check if the current cell has already gone through Final point or not.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int hasTopWall(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps){

	// check if the present maze has top wall and if the next Top maze is visited or lead to a unsuccessful path
	if (!isTop(search->maze[search->yStart][search->xStart]) && 
		search->visits[search->yStart-1][search->xStart] != 'O' && 
		search->visits[search->yStart-1][search->xStart] != 'X' ) {

		// mark current cell as visited
		if ( search->visits[search->yStart][search->xStart] != 'S' && search->visits[search->yStart][search->xStart] != 'F' )
			search->visits[search->yStart][search->xStart] = 'O';

		// move to the top cell
		search->yStart = search->yStart - 1;

		// check if the next node is out of the maze
		if ( search->xStart > search->columns || search->yStart < 0 || search->xStart < 0 || search->yStart > search->rows )
			return 0;

		// push the next node to the stack
		spush(myStack, search->yStart, search->xStart);

		// check if the new node leads to a solution.
		if (step(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps)) 
			return 1;
		
		// backtrack.

		// mark current cell as visited
		if ( search->visits[search->yStart][search->xStart] != 'S' && search->visits[search->yStart][search->xStart] != 'F' && reachEndFlag != 1 )
			search->visits[search->yStart][search->xStart] = 'X';

		// go back
        search->yStart = search->yStart + 1;

        // pop the latest item from the stack
        if (!sempty(myStack))
        	spop(myStack);

	} 
	return 0;

}

/**
 * a function to check if the cell has Left Wall, if the next cell is visited or not and if the next cell leads to a solution ot not.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	A integer to check the condition supplied by commandline argument.
 * @param reachEndFlag 		A integer to check if the current cell has already gone through Final point or not.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int hasLeftWall(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps){

	// check if the present maze has Left wall and if the next Left maze is visited or lead to a unsuccessful path
	if( !isLeft(search->maze[search->yStart][search->xStart]) && 
		search->visits[search->yStart][search->xStart-1] != 'O' && 
		search->visits[search->yStart][search->xStart-1] != 'X' ){
		
		// mark current cell as visited
		if ( search->visits[search->yStart][search->xStart] != 'S' && search->visits[search->yStart][search->xStart] != 'F' && reachEndFlag != 1 )
			search->visits[search->yStart][search->xStart] = 'O';

		// move to the next cell
		search->xStart = search->xStart - 1;

		// check if the next node is out of the maze
		if ( search->xStart > search->columns || search->yStart < 0 || search->xStart < 0 || search->yStart > search->rows )
			return 0;

		// push the next node to the stack
		spush(myStack, search->yStart, search->xStart);

		// check if the new node leads to a solution.
		if(step(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps))
			return 1;

		// backtrack.

		// mark current cell as visited
		if ( search->visits[search->yStart][search->xStart] != 'S' && search->visits[search->yStart][search->xStart] != 'F' && reachEndFlag != 1 )
			search->visits[search->yStart][search->xStart] = 'X';

		// go back
		search->xStart = search->xStart + 1;

		// pop the latest item from the stack
		if (!sempty(myStack))
        	spop(myStack);

	}

	return 0;

}

/**
 * a function to check if the cell has Right Wall, if the next cell is visited or not and if the next cell leads to a solution ot not.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	A integer to check the condition supplied by commandline argument.
 * @param reachEndFlag 		A integer to check if the current cell has already gone through Final point or not.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int hasRightWall(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps){

	// check if the present maze has Right wall and if the next Right maze is visited or lead to a unsuccessful path
	if( !isRight(search->maze[search->yStart][search->xStart]) && 
		search->visits[search->yStart][search->xStart+1] != 'O' && 
		search->visits[search->yStart][search->xStart+1] != 'X' ){

		// mark current cell as visited but not if it's the starting point
		if ( search->visits[search->yStart][search->xStart] != 'S' && search->visits[search->yStart][search->xStart] != 'F' )
			search->visits[search->yStart][search->xStart] = 'O';

		//move to the next cell
		search->xStart = search->xStart + 1;

		// check if the next node is out of the maze
		if ( search->xStart > search->columns || search->yStart < 0 || search->xStart < 0 || search->yStart > search->rows )
			return 0;
	
		// push the next node to the stack
		spush(myStack, search->yStart, search->xStart);

		// check if the new node leads to a solution.
		if(step(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps))
			return 1;

		// backtrack.

		// mark current cell as visited
		if ( search->visits[search->yStart][search->xStart] != 'S' && search->visits[search->yStart][search->xStart] != 'F' && reachEndFlag != 1 )
			search->visits[search->yStart][search->xStart] = 'X';

		// go back
		search->xStart = search->xStart - 1;		

		// pop the latest item from the stack
		if (!sempty(myStack))
        	spop(myStack);

	}

	return 0;

}

/**
 * a function to check if the cell has Bottom Wall, if the next cell is visited or not and if the next cell leads to a solution ot not.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	A integer to check the condition supplied by commandline argument.
 * @param reachEndFlag 		A integer to check if the current cell has already gone through Final point or not.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int hasBottomWall(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps){

	// check if the present maze has Bottom wall and if the next Bottom maze is visited or lead to a unsuccessful path
	if ( !isBottom(search->maze[search->yStart][search->xStart]) && 
		search->visits[search->yStart+1][search->xStart] != 'O' && 
		search->visits[search->yStart+1][search->xStart] != 'X' ){

		// mark current cell as visited
		if ( search->visits[search->yStart][search->xStart] != 'S' && search->visits[search->yStart][search->xStart] != 'F' )
			search->visits[search->yStart][search->xStart] = 'O';

		//move to the next cell
		search->yStart = search->yStart + 1;

		// check if the next node is out of the maze
		if ( search->xStart > search->columns || search->yStart < 0 || search->xStart < 0 || search->yStart > search->rows )
			return 0;

		// push the next node to the stack
		spush(myStack, search->yStart, search->xStart);

		// check if the new node leads to a solution.
		if (step(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps)) 
			return 1;

		// backtrack.

		// mark current cell as visited
		if ( search->visits[search->yStart][search->xStart] != 'S' && search->visits[search->yStart][search->xStart] != 'F' && reachEndFlag != 1 )
			search->visits[search->yStart][search->xStart] = 'X';

		// go back
		search->yStart = search->yStart - 1;

		// pop the latest item from the stack
		if (!sempty(myStack))
        	spop(myStack);

	}

	return 0;

}

/**
 * a function to check if all the cells are already visited or not.
 *
 * @param search   	a description of the search problem
 */
int visitedNodes( SearchT *search ){

	for (int i=0; i < search->rows; i++) {
		for (int j=0; j < search->columns; j++) {
			if ( search->visits[i][j] ==  ' ' ) {
				return 0;
			}
		}
	}

	return 1;
}


/**
 * a recursive function which accomplishes the task of taking “one step” in the maze.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	A integer to check the condition supplied by commandline argument.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int step(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps) {

	// Number of steps adding 1.
	numOfSteps++;

	// start the normal step by step process for no all & short.
	if ( conditionFlag == 1 ){

		// print the maze
		print (search);

		// wait for the keyboard input
		char key = getchar();

		// base case: if the final destination is reached or not.
		if( (search->yStart == search->yEnd) && (search->xStart == search->xEnd) ){
			return 1;
		}

		// check for four walls of a single maze cell
		if ( hasTopWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;
		
		if ( hasLeftWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;
		
		if ( hasRightWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;
		
		if ( hasBottomWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;

	}else if ( conditionFlag == 2 ){
		// condition for -all

		// base case: if the final destination is reached or not.
		if( (search->yStart == search->yEnd) && (search->xStart == search->xEnd) ){

			// Find another path from start to finish, so number of steps is again set to 0.
			numOfSteps = 0;
			reachEndFlag = 1;

			if ( visitedNodes( search ) != 0 ){
				return 1;
			}else{
				// again start from starting point to explore unexplored points.
				search->xStart = mazeStartX;
				search->yStart = mazeStartY;
			}

		}

		// check for four walls of a single maze cell
		if ( hasTopWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;
		
		if ( hasLeftWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;
		
		if ( hasRightWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;
		
		if ( hasBottomWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;

	}else if ( conditionFlag == 3 ){
		// condition for -short

		// base case: if the final destination is reached or not.
		if( (search->yStart == search->yEnd) && (search->xStart == search->xEnd) ){

			// Find another path from start to finish, so number of steps is again set to 0.
			numOfSteps = 0;
			reachEndFlag = 1;

			if ( visitedNodes( search ) != 0 ){

				// Put spaces into all maze cells
				int i, j;
				for (i=0; i < search->rows; i++) {
					for (j=0; j < search->columns; j++) {
						search->visits[i][j] = ' ';
					}
				}
				// set start and end location
				search->visits[mazeStartY][mazeStartX] = 'S';
				search->visits[search->yEnd][search->xEnd] = 'F';

				// put O for shortest path
				for ( i = 0; i < myStack->size; i++ )
				{
					NodeT *xNode = myStack->xCoordinate[i];
					NodeT *yNode = myStack->yCoordinate[i];

					int xPoint = xNode->info;
					int yPoint = yNode->info;

					// check if the cell is start or end point
					if ( search->visits[xPoint][yPoint] != 'S' && search->visits[xPoint][yPoint] != 'F' )
						search->visits[xPoint][yPoint] = 'O';
				}

				return 1;
			}else{
				// again start from starting point to explore unexplored points.
				search->xStart = mazeStartX;
				search->yStart = mazeStartY;

				// clear the stack
				sclear(myStack);

			}

		}

		// check for four walls of a single maze cell
		if ( hasTopWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;
		
		if ( hasLeftWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;
		
		if ( hasRightWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;
		
		if ( hasBottomWall(search, myStack, conditionFlag, reachEndFlag, mazeStartX, mazeStartY, numOfSteps) ) return 1;

	}

	return 0;

}



