/**
* A test program to implement the functions decleared in the provided vectorLL.h file.
* 
* @author Probal Chandra Dhar
* @date 9/09/2016
* @info Course COP5990
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorLL.h"

/**
 * Creates a new and empty vector with an initial capacity.
 */
VectorT* newVector(){
	VectorT *vector;

	vector = (VectorT*) malloc(sizeof(VectorT));

	vector->anchor = (NodeT*)malloc(sizeof(NodeT)*1000);
	vector->anchor = NULL;


	return vector;

}

/**
 * Inserts a new element at the beginning of the vector.
 *
 * @param vector the vector to be modified
 * @param item   the item to be inserted to the vector
 */
void vadd (VectorT *vector, NodeItemT item){

	// create a new node and assign the memory to it and then save the item to it by calling the newNode function.
	NodeT *tempNode = newNode(item);

	// assign the next pointer the the anchor
	tempNode->next = vector->anchor;

	// assign the node to the anchor pointer 
	vector->anchor = tempNode;

}

/**
 * Returns an element from the vector given a location.
 *
 * @param vector the vector to be accessed for an element
 * @param index  the location of the element to be returned
 *
 * @return the item in the vector at the location or NULL if the location is out of the valid range
 *         of the vector
 */
NodeItemT* vget (const VectorT *vector, int index){

	// create a new node to check the value of the node
	NodeT* checkNode = vector->anchor;

	// check for the location and increase after if condition not matches
	int checkLocation = 1;

	// check till we get the NULL that means end of link list
	while( checkNode != NULL ){  
		// check if the location matches with the index
		if( checkLocation == index ){
			// return the value of the node
			return &(checkNode->info);
		}
		// assign the next to the current one
    	checkNode = checkNode->next;
    	checkLocation++;
	}
	return NULL;

}

/**
 * Sets an item in a vector.
 *
 * @param vector the vector to be modified
 * @param item   the item to be set
 * @param index  the location where the item needs to be set
 *
 * @return the location where the item was set or -1, if the item was not set because the location is
 *         out of the vector's range
 */
int vset (VectorT *vector, NodeItemT item, int index){

	// create a new node to check the value of the node
	NodeT* checkNode = vector->anchor;

	// check for the location and increase after if condition not matches
	int checkLocation = 1;

	// check till we get the NULL that means end of link list
	while( checkNode != NULL ){ 
		// check if the location matches with the index
		if( checkLocation == index ){
			// set the value to the node if the location matches with the index provided
			setInfo(checkNode, item);
			return checkLocation;
		}
		// assign the next to the current one
    	checkNode = checkNode->next;
    	checkLocation++;
	}
	return -1;

}

/**
 * Removes an item in a vector at the specified location and shifts any subsequent elements to the left
 * by subtracting one from their indices.
 *
 * @param vector the vector to be modified
 * @param index  the location where the item needs to be removed
 */
void vremove (VectorT *vector, int index){

	// checkNode is the present node and previousNode to save the previous node
	NodeT* checkNode, *previousNode;

	// create a new node to check the value of the node
	checkNode = vector->anchor;
	
	// check for the location and increase after if condition not matches
	int checkLocation = 1;

	// check till we get the NULL that means end of link list
	while( checkNode != NULL ){ 
		// check if the location matches with the index
		if( checkLocation == index ){
			// sets the next pointer of the previous node to the next node
			previousNode->next = checkNode->next;
			// delete the current node
			free(checkNode);
			break;
		}
		// saves the previous node
		previousNode = checkNode;
		// assign the next to the current one
    	checkNode = checkNode->next;
    	checkLocation++;
	}

}

/**
 * Returns the number of elements in the vector.
 *
 * @param vector the vector whose size is to be determined
 *
 * @return the total number of elements stored in the vector
 */
int vsize(const VectorT *vector){

	// create a new node to check the value of the node
	NodeT* checkNode = vector->anchor;

	// sizeOfList to calculate the size of the list 
	int sizeOfList = 1;

	// check till we get the NULL that means end of link list
	while( checkNode != NULL ){  
		// goes to the next node
    	checkNode = checkNode->next;
    	// add one to the previous sum of sizeOfList
    	sizeOfList++;
	}
	return sizeOfList;

}

/**
 * Returns the capacity of the vector.
 *
 * @param vector the vector whose capacity is to be determined
 *
 * @return the total number of elements that the vector may be able to store
 */
int vcapacity(const VectorT *vector){

	// create a new node to check the value of the node
	NodeT* checkNode = vector->anchor;

	// sizeOfList to calculate the size of the list 
	int sizeOfList = 1;

	// check till we get the NULL that means end of link list
	while( checkNode != NULL ){  
		// goes to the next node
    	checkNode = checkNode->next;
    	// add one to the previous sum of sizeOfList
    	sizeOfList++;
	}
	return sizeOfList;

}

/**
 * Tests if the vector contains a specified element.
 *
 * @param vector the vector to be tested for containment of a specific element
 * @param item   the item to be tested
 *
 * @return 1 if the vector contains the element; 0 otherwise
 */
int vcontains(const VectorT *vector, NodeItemT item){

	// create a new node to check the value of the node
	NodeT* checkNode = vector->anchor;

	// check till we get the NULL that means end of link list
	while( checkNode != NULL ){  
		// check if the value of the current node is the same with the item provided
		if( getInfo(checkNode) == item ){ 
    		return 1;
    	}
    	// go to the next node
    	checkNode = checkNode->next;
	}
	return 0;

}

/**
 * Returns the index for a specified item in the vector.
 *
 * @param vector the vector to be checked for an element
 * @param item   the item whose location in the vector needs to be checked
 *
 * @return the index of the location of the item in the vector or -1 if the item cannot be found
 */
int vindexOf(const VectorT *vector, NodeItemT item){

	// create a new node to check the value of the node
	NodeT* checkNode = vector->anchor;

	// check for the location and increase after if condition not matches	
	int checkLocation = 1;

	// check till we get the NULL that means end of link list	
	while( checkNode != NULL ){  
		// check if the value of the current node is the same with the item provided
		if( getInfo(checkNode) == item ){ 
    		return checkLocation;
    	}
    	// go to the next node
    	checkNode = checkNode->next;
    	checkLocation++;
	}
	return -1;

}

/**
 * Deletes the entire vector. Memory for storing elements and vector's data structure will be deallocated.
 *
 * @param vector the vector to be deleted
 */
void vdelete(VectorT *vector){

	// check if the vector exists of not
	if( vector ){
		// delete the vector
		free(vector);
	}

}

