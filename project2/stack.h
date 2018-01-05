/**
* A Stack Abstract Data Type
* 
* @author T. Reichherzer
*/

#ifndef _STACK_h
#define _STACK_h

#include <stdio.h>
#include "node.h"

// ----------------------
// Fixed size of the stack
// ----------------------
#define MAX_SIZE 100

// --------------------------------------
// Type definition for boolean variables.
// --------------------------------------
typedef int bool;

// ----------------------
// Definition of boolean values
// ----------------------
#define TRUE 1
#define FALSE 0

// ----------------------
// Definition of queue data structure
// ----------------------
typedef struct
{
	NodeT *xCoordinate[MAX_SIZE];  // store the x-Coordinate of the path of a maze
	NodeT *yCoordinate[MAX_SIZE];  // store the y-Coordinate of the path of a maze
	int size;              		   // the current size of the stack
} StackT;


// ----------------------
// Interface to Stack ADT
// ----------------------

/**
 * Initializes the stack.
 *
 * @param thisStack the stack to be initialized
 */
void sinit(StackT *thisStack);

/**
 * Pushes an element onto the stack.
 *
 * @param thisStack the stack to be modified
 * @param xElement the x-coordinate of the current cell to be pushed onto the stack
 * @param yElement the y-coordinate of the current cell to be pushed onto the stack
 */
// void spush(StackT *thisStack, NodeItemT newElement);
void spush(StackT *thisStack, NodeItemT xElement, NodeItemT yElement);

/**
 * Pops an element from the stack.
 *
 * @param thisStack the stack to be modified
 */
void spop(StackT *thisStack);

/**
 * Looks at the top element of the stack.
 *
 * @param thisStack the stack to be looked at
 *
 * @return the top element on the stack
 */
NodeItemT* speek(const StackT *thisStack);

/**
 * Tests if the stack is empty.
 *
 * @param thisStack the stack to be tested
 *
 * @return 1 if the stack is empty; otherwise 0
 */
int sempty(const StackT *thisStack);

/**
 * Tests if the stack is full.
 *
 * @param thisStack the stack to be tested
 *
 * @return 1 if the stack is full; otherwise 0
 */
int sfull(const StackT *thisStack);

/**
 * Removes all elements from the stack.
 *
 * @param thisStack the stack to be modified
 */
void sclear(StackT *thisStack);

/**
 * Display all the elements of a stack.
 *
 * @param myStack the stack to be showed
 */
void displayAll(StackT *myStack);


#endif