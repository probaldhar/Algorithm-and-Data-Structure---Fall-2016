/**
* Implements the functions of StackT.
* 
* @author T. Reichherzer
*/

#include <stdlib.h>
#include "stack.h"
#include "node.h"

#define TRUE 1
#define FALSE 0

/**
 * Initializes the stack.
 *
 * @param thisStack the stack to be initialized
 */
void sinit(StackT *thisStack)
{
	thisStack->size = 0;
}

/**
 * Pushes an element onto the stack.
 *
 * @param thisStack the stack to be modified
 * @param xElement the x-coordinate of the current cell to be pushed onto the stack
 * @param yElement the y-coordinate of the current cell to be pushed onto the stack
 */
void spush(StackT *thisStack, NodeItemT xElement, NodeItemT yElement)
{
	// test if stack is full before adding a new element
	if (sfull(thisStack)) {
		fprintf (stderr, "stack overflow; unable to add more elements to the stack");
		return; // can't add more elements
	}
	
	// create a new node
	// NodeT* aNode = newNode(newElement);
	
	// new node to save the x co-ordinate
	NodeT* xNode = newNode(xElement);
	// new node to save the y co-ordinate
	NodeT* yNode = newNode(yElement);
	
	// insert node into the stack
	// thisStack->items[thisStack->size] = aNode;
	
	// push the nodes to the stack
	thisStack->xCoordinate[thisStack->size] = xNode;
	thisStack->yCoordinate[thisStack->size] = yNode;
	
	// increase stack pointer by 1 so that the pointer points to the next new
	// space and reflects the correct number of items on the stack
	thisStack->size++;
}

/**
 * Pops an element from the stack.
 *
 * @param thisStack the stack to be modified
 */
void spop(StackT *thisStack)
{
	// test if stack is empty before popping the top element
	if (sempty(thisStack)) {
		fprintf (stderr, "stack is empty; unable to pop an element from the stack");
		// can't pop because there are no elements on the stack
		return; 
	}
	
	// release memory of NodeT referenced by stack position
	// size-1 points 
	freeNode (thisStack->xCoordinate[thisStack->size-1]);
	freeNode (thisStack->yCoordinate[thisStack->size-1]);
	
	// reduce stack pointer by 1 so that the pointer points to the next new
	// space and reflects the correct number of items on the stack
	thisStack->size--;
}

/**
 * Looks at the top element of the stack.
 *
 * @param thisStack the stack to be looked at
 *
 * @return the top element on the stack
 */
NodeItemT* speek(const StackT *thisStack)
{
	// test if stack is empty before peeking at the top element
	if (sempty(thisStack)) {
		fprintf (stderr, "stack is empty; unable to peek at an element on the stack");
		// can't peek because there are no elements on the stack; return NULL as indicator
		return NULL;
	}
	
	return getInfo (thisStack->xCoordinate[thisStack->size-1]);
}

/**
 * Tests if the stack is empty.
 *
 * @param thisStack the stack to be tested
 *
 * @return 1 if the stack is empty; otherwise 0
 */
int sempty(const StackT *thisStack)
{
	return thisStack->size == 0;
}

/**
 * Tests if the stack is full.
 *
 * @param thisStack the stack to be tested
 *
 * @return 1 if the stack is full; otherwise 0
 */
int sfull(const StackT *thisStack)
{
	return thisStack->size == MAX_SIZE;
}

/**
 * Removes all elements from the stack.
 *
 * @param thisStack the stack to be modified
 */
void sclear(StackT *thisStack)
{
	while ( !sempty (thisStack) )
		spop (thisStack);
}


/**
 * Display all the elements of a stack.
 *
 * @param myStack the stack to be showed
 */
void displayAll(StackT *myStack){

	int i;
	for ( i = 0; i < myStack->size; i++ )
	{
		NodeT *xNode = myStack->xCoordinate[i];
		NodeT *yNode = myStack->yCoordinate[i];

		printf("%d %d\n", xNode->info, yNode->info);
	}
	printf("%d\n", myStack->size);
	printf("\n");

}




