/**
 * Defines all data types and declares all function prototypes for modeling a maze.
 *
 * @author T. Reichherzer
 */


#ifndef MAZE_H
#define MAZE_H


// -------------------------------
// Definition of a search problem
// -------------------------------
typedef struct {
    int xStart;
    int yStart;

    int xEnd;
    int yEnd;
	
	int rows;
    int columns;

    int **maze;
	char **visits;
} SearchT;



/**
 * Tests if there is a top wall.
 * @param cell a maze cell
 * 
 * return 1 if there is a top wall, 0 otherwise
 */
 int isTop (int cell);
 
 /**
  * Tests if there is a left-side wall.
  * @param cell a maze cell
  * 
  * return 1 if there is a left-side wall, 0 otherwise
  */
 int isLeft (int cell);
 
 /**
  * Tests if there is a bottom wall.
  * @param cell a maze cell
  * 
  * return 1 if there is a bottom wall, 0 otherwise
  */
 int isBottom (int cell);
 
 /**
  * Tests if there is a right-side wall.
  * @param cell a maze cell
  * 
  * return 1 if there is a right-side wall, 0 otherwise
  */
 int isRight (int cell);

/**
 * Initializes the search problem by loading the maze data
 * and setting the initial path information.
 *
 * @param filename the name of the file storing maze data
 * @param search   a description of the search problem
 *
 * returns 0, if the search problem and path information was initialized and -1 if an error occured
 */
int init (char *filename, SearchT *search);

/**
 * Prints the maze, explored locations, and path information
 */
void print (SearchT *search);

/**
 * Frees up memory.
 *
 * @param search the search problem allocating memory for maze and search path
 */
void freeMemory (SearchT *search);

/**
 * Initializes the path information.
 *
 * @param search  the search problem
 */
void initPath (SearchT *search);

#endif
