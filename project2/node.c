/**
 * Implements the functions of NodeT.
 *
 * @author T. Reichherzer
 */

#include "node.h"
#include <stdlib.h>

// -----------------------------------------
// Definition of an empty item.
// -----------------------------------------
const NodeItemT EmptyNodeItem = '\0';

/**
 * Creates a new node and stores the specified item in it.
 *
 * @param item the item to be stored in the node.
 */
NodeT *newNode(NodeItemT item)
{
	NodeT* node;
	
	// allocate memory for new node
	node = (NodeT*) malloc (sizeof(NodeT));

	// set item in new node
	node->info = item;
	
	return node;
}

/**
 * Returns the item of a node.
 *
 * @return the item stored in this node
 */
NodeItemT* getInfo(NodeT* node)
{
	if (node == NULL)
		return NULL;
	return &(node->info);
}

/**
 * Sets the item in a node.
 *
 * @param node a node whose item must be set
 * @param item the item of the node
 */
void setInfo(NodeT* node, NodeItemT item)
{
	node->info = item;
}

/**
 * Frees up the item of a node.
 *
 * @param node the node to be deallocated from memory
 */
void freeNode(NodeT * node)
{
	free (node);
}

/**
 * Returns the item that indicates that the node is empty.
 *
 * @return an item indicating that the node is empty
 */
NodeItemT getEmtpyNodeItem()
{
	return EmptyNodeItem;
}
