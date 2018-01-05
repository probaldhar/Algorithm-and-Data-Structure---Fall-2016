/**
* A test program to implement the functions decleared in the provided vectorArray.h file.
* 
* @author Probal Chandra Dhar
* @date 9/09/2016
* @info Course COP5990
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorArray.h"

/**
 * Creates a new and empty vector with an initial capacity.
 *
 * @param capacity the initial capacity of the Vector.
 */
VectorT* newVector(int capacity)
{
	VectorT* vector;

	vector = (VectorT*) malloc(sizeof(VectorT));

	if( vector == NULL ){
		return NULL;
	}

	vector->list = (NodeT**) malloc (sizeof(NodeT*)*capacity);
	vector->capacity = capacity;
	vector->size = 0;

	// NodeT* aNode = (NodeT*)malloc(sizeof(NodeT));

	return vector;
}

/**
 * Resize the whole array when there's no space for new element.
 *
 * @param vector the vector to be modified
 *
 */
void resize(VectorT* vector){

	// defining a new list of elements
	NodeT** Newlist = (NodeT**) malloc(sizeof(NodeT*)*(vector->capacity + GROWTH_RATE)); 

	int i;
	for ( i=0; i < vector->capacity; ++i)
	{
		Newlist[i] = vector->list[i]; //confusion
		// *(Newlist[i]) = *(vector->list[i]); 
	}

	// delete the full list and copy all the elements to the vector->list that is newly created
	free(vector->list);
	vector->list = Newlist;
	vector->capacity = vector->capacity + GROWTH_RATE;

}

/**
 * Appends a new element to the end of the vector. If the capacity of the vector is reached, the vector
 * dynamically grows by a fixed size.
 *
 * @param vector the vector to be modified
 * @param item   the item to be appended to the vector
 */
void vadd(VectorT *vector, NodeItemT item)
{
	if( (vector->size+1) > vector->capacity ) //vector->size+1 > vector->capacity
	{
		if( vector->list ){
			resize(vector);
		}
	}else{
		// add a new node
		NodeT* aNode = newNode(item);
		// assign to the node to the list
		vector->list[vector->size] = aNode;
		// increase the vector size
		vector->size++;
	}
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
NodeItemT* vget(const VectorT *vector, int index)
{
	// check if the index is within the range of the vector size
	if( index >= 0 || index < vector->size ){
		// create a new node to find the value
		NodeT *node = vector->list[index];
		return &(node->info);
	}else{
		return NULL;
	}
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
int vset(VectorT *vector, NodeItemT item, int index)
{
	// check if the index is within the range of the vector size
	if( index >= 0 || index < vector->size ){
		NodeT* tempNode = vector->list[index];
		// set the new value to the node that is in the position provided(index)
		setInfo(tempNode, item); 
		// return the value of the index if condition matched otherwise -1
		return index;
	}else{
		return -1;
	}

}

/**
 * Removes an item in a vector at the specified location and shifts any subsequent elements to the left
 * by subtracting one from their indices.
 *
 * @param vector the vector to be modified
 * @param index  the location where the item needs to be removed
 */
void vremove(VectorT *vector, int index)
{
	if( index >= 0 || index < vector->size ){
		// remove the node that is in the position provided (index)
		free( vector->list[index] );

		int i, j;
		//shifts any subsequent elements to the left by subtracting one from their indices.
		for ( i = index + 1, j = index; i < vector->size; i++) {
        	vector->list[j] = vector->list[i];
        	j++;
    	}

    	// reduce the vector size
    	vector->size--;
    }


}

/**
 * Returns the number of elements in the vector.
 *
 * @param vector the vector whose size is to be determined
 *
 * @return the total number of elements stored in the vector
 */
int vsize(const VectorT *vector)
{
	// return the vector size
	return vector->size;

}

/**
 * Returns the capacity of the vector.
 *
 * @param vector the vector whose capacity is to be determined
 *
 * @return the total number of elements that the vector may be able to store
 */
int vcapacity(const VectorT *vector)
{
	// return the vector capacity
	return vector->capacity;
}

/**
 * Tests if the vector contains a specified element.
 *
 * @param vector the vector to be tested for containment of a specific element
 * @param item   the item to be tested
 *
 * @return 1 if the vector contains the element; 0 otherwise
 */
int vcontains(const VectorT *vector, NodeItemT item)
{
	int i;
	for ( i = 0; i < vector->size; i++) {
		// create a new node to check the value of a position
		NodeT* checkNode = vector->list[i];
		// check the value of the node if it's the same with the item provided
    	if( getInfo(checkNode) == item ){ 
    		return 1;
    	}
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
int vindexOf(const VectorT *vector, NodeItemT item)
{
	int i;
	for ( i = 0; i < vector->size; i++ ) {
		// create a new node to check the value of a position
		NodeT* checkNode = vector->list[i];
    	if( getInfo(checkNode) == item ){ 
    		return i;
    	}
    }
    return -1;
}

/**
 * Removes all elements from the specified vector. The capacity remains unchanged but the size changes to 0.
 *
 * @param vector the vector to be cleared
 */
void vclear(VectorT *vector)
{
	// not sure
	int i;
	// clear all the values of all nodes
	for ( i = 0; i < vector->size; i++ ) {
    	free(vector->list[i]);
    }
    vector->size = 0;
}

/**
 * Deletes the vector. Memory for storing elements will be deallocated.
 *
 * @param vector the vector to be deleted
 */
void vdelete(VectorT *vector)
{
	// deletes the vector list and then the vector itself
	if( vector ){
    	free(vector->list);
    	free(vector);
	}
}