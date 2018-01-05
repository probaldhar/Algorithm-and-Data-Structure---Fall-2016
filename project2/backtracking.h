/**
* Defines all functions needed for backtracking the maze.
* 
* @author Probal Chandra Dhar
* @date 9/30/2016
* @info Course COP5990
*/


#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "maze.h"
#include "stack.h"

/**
 * a recursive function which accomplishes the task of taking “one step” in the maze.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	integer to check the condition supplied by commandline argument.
 * @param reachEndFlag 		integer to check if the current cell has already gone through Final point or not.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int step(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps);

/**
 * a function to check if the cell has top Wall, if the next cell is visited or not and if the next cell leads to a solution ot not.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	integer to check the condition supplied by commandline argument.
 * @param reachEndFlag 		integer to check if the current cell has already gone through Final point or not.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int hasTopWall(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps);

/**
 * a function to check if the cell has Left Wall, if the next cell is visited or not and if the next cell leads to a solution ot not.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	integer to check the condition supplied by commandline argument.
 * @param reachEndFlag 		integer to check if the current cell has already gone through Final point or not.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int hasLeftWall(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps);

/**
 * a function to check if the cell has Right Wall, if the next cell is visited or not and if the next cell leads to a solution ot not.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	integer to check the condition supplied by commandline argument.
 * @param reachEndFlag 		integer to check if the current cell has already gone through Final point or not.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int hasRightWall(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps);

/**
 * a function to check if the cell has Bottom Wall, if the next cell is visited or not and if the next cell leads to a solution ot not.
 *
 * @param search   			a description of the search problem
 * @param myStack  			Stack that used to store the co-ordinates of the maze cell.
 * @param conditionFlag 	integer to check the condition supplied by commandline argument.
 * @param reachEndFlag 		integer to check if the current cell has already gone through Final point or not.
 * @param mazeStartX 		integer to store the x co-ordinate of starting point of the maze.
 * @param mazeStartY 		integer to store the y co-ordinate of starting point of the maze.
 * @param numOfSteps 		integer to store the number of steps required from start to end point.
 */
int hasBottomWall(SearchT *search, StackT *myStack, int conditionFlag, int reachEndFlag, int mazeStartX, int mazeStartY, int numOfSteps);

/**
 * a function to check if all the cells are already visited or not.
 *
 * @param search   	a description of the search problem
 */
int visitedNodes( SearchT *search );

#endif