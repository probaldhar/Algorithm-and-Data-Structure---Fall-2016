/*
 * vector.h
 * @author T. Reichherzer
 */

#ifndef _VECTOR_LL_H
#define _VECTOR_LL_H

#include "nodeLL.h"

// ----------------------
// Definition of a Vector
// ----------------------
typedef struct VectorT
{
	NodeT *anchor;
} VectorT;

// ----------------------
// Interface to Vector ADT
// ----------------------

/**
 * Creates a new and empty vector with an initial capacity.
 */
VectorT* newVector();

/**
 * Inserts a new element at the beginning of the vector.
 *
 * @param vector the vector to be modified
 * @param item   the item to be inserted to the vector
 */
void vadd (VectorT *vector, NodeItemT item);


/**
 * Returns an element from the vector given a location.
 *
 * @param vector the vector to be accessed for an element
 * @param index  the location of the element to be returned
 *
 * @return the item in the vector at the location or NULL if the location is out of the valid range
 *         of the vector
 */
NodeItemT* vget (const VectorT *vector, int index);

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
int vset (VectorT *vector, NodeItemT item, int index);

/**
 * Removes an item in a vector at the specified location and shifts any subsequent elements to the left
 * by subtracting one from their indices.
 *
 * @param vector the vector to be modified
 * @param index  the location where the item needs to be removed
 */
void vremove (VectorT *vector, int index);

/**
 * Returns the number of elements in the vector.
 *
 * @param vector the vector whose size is to be determined
 *
 * @return the total number of elements stored in the vector
 */
int vsize(const VectorT *vector);

/**
 * Returns the capacity of the vector.
 *
 * @param vector the vector whose capacity is to be determined
 *
 * @return the total number of elements that the vector may be able to store
 */
int vcapacity(const VectorT *vector);

/**
 * Tests if the vector contains a specified element.
 *
 * @param vector the vector to be tested for containment of a specific element
 * @param item   the item to be tested
 *
 * @return 1 if the vector contains the element; 0 otherwise
 */
int vcontains(const VectorT *vector, NodeItemT item);

/**
 * Returns the index for a specified item in the vector.
 *
 * @param vector the vector to be checked for an element
 * @param item   the item whose location in the vector needs to be checked
 *
 * @return the index of the location of the item in the vector or -1 if the item cannot be found
 */
int vindexOf(const VectorT *vector, NodeItemT item);

/**
 * Deletes the entire vector. Memory for storing elements and vector's data structure will be deallocated.
 *
 * @param vector the vector to be deleted
 */
void vdelete(VectorT *vector);


#endif
