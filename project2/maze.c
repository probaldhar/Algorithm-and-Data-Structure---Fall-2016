/**
* Implements the functions of maze.h.
* 
* @author Probal Chandra Dhar
* @date 9/30/2016
* @info Course COP5990
*/

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

/**
 * Tests if there is a top wall.
 * @param cell a maze cell
 * 
 * return 1 if there is a top wall, 0 otherwise
 */
int isTop (int cell)
{
	return cell & 1; 
} 
 
/**
  * Tests if there is a left-side wall.
  * @param cell a maze cell
  * 
  * return 1 if there is a left-side wall, 0 otherwise
  */

int isLeft (int cell)
{
	// finish this
	if( (cell&8) == 8 ){
		return 1;
	}else{
		return 0;
	}
}

 /**
  * Tests if there is a bottom wall.
  * @param cell a maze cell
  * 
  * return 1 if there is a bottom wall, 0 otherwise
  */
int isBottom (int cell)
{
	// finish this
	if( (cell&4) == 4 ){
		return 1;
	}else{
		return 0;
	}
}

/**
  * Tests if there is a right-side wall.
  * @param cell a maze cell
  * 
  * return 1 if there is a right-side wall, 0 otherwise
  */
int isRight (int cell)
{
	// finish this
	if( (cell&2) == 2 ){
		return 1;
	}else{
		return 0;
	}
}

/**
 * Frees up the memory allocated for the search problem
 *
 * @param maze the maze to be freed up
 */
void freeMemory (SearchT *search)
{
	// finish this
	int i;
	for ( i = 0; i < search->rows; i++ )
	{
		if( search->maze[i] != NULL ){
			free( search->maze[i] );
		}

		if( search->visits[i] != NULL ){
			free( search->visits[i] );
		}
	}
	free(search->maze);
	free(search->visits);
}

 
/**
 * Allocates memory for the search problem.
 *
 * @param search the search problem
 *
 * returns 0, if no error, or a negative value if an error occurs
 */
int allocateMemory (SearchT *search)
{	
	int i;
	
	// allocate row pointers for the maze and visits matrix
	search->maze = (int **) malloc (sizeof(int*) * search->rows);
	if (search->maze == NULL) {
		return -1;
	}
	
	search->visits = (char **) malloc (sizeof(char*) * search->rows);
	if (search->visits == NULL) {
		free (search->maze);
		return -1;
	}
	
	for (i=0; i < search->rows; i++) {
		search->maze[i] = (int *) malloc (sizeof(int) * search->columns);
		
		// finish this
		search->visits[i] = (char *) malloc(sizeof(char) * search->columns);
		if( search->maze[i] == NULL || search->visits[i] == NULL ){
			freeMemory( search );
			return -1;
		}

	}
	
	// allocated the correct amount of space for two matrices
	return 0;
}

/**
 * Initializes the path information.
 *
 * @param search  the search problem
 */
void initPath (SearchT *search)
{
	int i, j;
	
	for (i=0; i < search->rows; i++) {
		for (j=0; j < search->columns; j++) {
			search->visits[i][j] = ' ';
		}
	}
	// set start and end location
	search->visits[search->yStart][search->xStart] = 'S';
	search->visits[search->yEnd][search->xEnd] = 'F';
}


/**
 * Reads a row of wall information from the text file.
 *
 * @param fp       the file pointer to read the file
 * @param maze     the maze
 * @param rowIndex the index of the row that has to be populated with data from the file
 * @param columns  the number of columns to read from the file
 */
int readRow (FILE *fp, int **maze, int rowIndex, int columns)
{
	int i;
	for (i=0; i < columns; i++) {
		if (fscanf (fp, "%d", &(maze[rowIndex][i])) == EOF ) {
			return -1;
		}
	}
	return 0;
}
 
/**
 * Reads maze data from a file and allocates memory for the maze data.
 *
 * filename the name of the file where data will be read
 * search   the search problem to be read from the file
 */
int readData (FILE *fp, SearchT *search)
{
	// read size of matrix
	if (fscanf (fp, "%d %d", &(search->rows), &(search->columns)) == EOF)
		return -1;
	
	// read start position
	if (fscanf (fp, "%d %d", &(search->xStart), &(search->yStart)) == EOF)
		return -1;
		
	// read end position
	if (fscanf (fp, "%d %d", &(search->xEnd), &(search->yEnd)) == EOF)
		return -1;
	
	// allocating memory for the maze
	if (allocateMemory (search))
		return -1;
	
	// finish this code
	int i;
	for ( i = 0; i < search->rows; i++ )
	{
		if( readRow(fp, search->maze, i, search->columns) < 0 ){
			freeMemory( search );
			return -1;
		}
	}
	
	// initialize path
	initPath (search);
	
	return 0;
}
 
/**
 * Initializes the search problem by loading the maze data
 * and setting the initial path information.
 *
 * @param filename the name of the file storing maze data
 * @param search   a description of the search problem
 *
 * returns 0, if the search problem and path information was initialized and -1 if an error occured
 */
int init (char *filename, SearchT *search)
{
	FILE *fp;
	
	fp = fopen(filename, "r");
	if (fp == NULL) {
		return -1;
	}
	
	int result = readData (fp, search);
	
	// close file
	fclose (fp);

	return result;
}

/**
 * Prints top/bottom wall or spaces depending on the value of wall.
 * @param wall if 1, prints a wall, otherwise, prints space
 */
void printTopWallOrSpace (int wall)
{
	if (wall) {
		printf ("---");
	}
	else {
		printf ("   ");
	}
}

/**
 * Prints side wall or spaces depending on the value of wall.
 * @param wall if 1, prints a wall, otherwise, prints space
 */
void printSideWallOrSpace (int wall)
{
	// finish this
	if(wall){
		printf("|");
	}else{
		printf(" ");
	}
}

/**
 * Prints the top of a row of the maze.
 * @param row     a row in the maze
 * @param columns the number of columns
 */
void printTop (int *row, int columns)
{
	// finish this
	int i;
	for ( i = 0; i < columns; i++ )
	{
		printf("+");
		printTopWallOrSpace( isTop( row[i] ) );
	}
	printf("+\n");
}

/**
 * Prints the side of a row of the maze.
 * @param row     a row in the maze
 * @param visits  information about the start and end point and visited spaces
 * @param columns the number of columns
 */
void printSide (int *row, char *visits, int columns)
{
	int i;
	
	printSideWallOrSpace (isLeft(row[0]));
	for (i=0; i < columns; i++) {
		// finish this
		printf(" %c ", visits[i]);
		printSideWallOrSpace( isRight( row[i]) );
	}
	printf ("\n");
}

/**
 * Prints the bottom of a row of the maze.
 * @param row     a row in the maze
 * @param columns the number of columns
 */
void printBottom (int *row, int columns)
{
	int i;
	// finish this
	for ( i = 0; i < columns; i++ )
	{
		printf("+");
		printTopWallOrSpace( isBottom( row[i] ) );
	}
	printf("+");
}

/*
 * Prints the maze, explored locations, and path information
 * @param search   a description of the search problem
 */
void print (SearchT *search)
{
	int i;
	
	// print wall
	for (i=0; i < search->rows; i++) {
		printTop (search->maze[i], search->columns);
		printSide (search->maze[i], search->visits[i], search->columns);
	}
	printBottom (search->maze[search->rows-1], search->columns);
	printf("\n");
}






