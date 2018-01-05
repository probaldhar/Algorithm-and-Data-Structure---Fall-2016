/**
 * Defines the functrions needed for a Stack.
 *
 * @author T. Reichherzer
 */

#ifndef _NODE_H
#define _NODE_H

// -----------------------------------------
// Definition of an item stored with a Node.
// -----------------------------------------
typedef int NodeItemT;

// ----------------------
// Definition of a Node
// ----------------------
typedef struct NodeT
{
	NodeItemT info;
	// short int used;
} NodeT;

// ----------------------
// Interface to Node ADT
// ----------------------

/**
 * Creates a new node and stores the specified item in it.
 *
 * @param item the item to be stored in the node.
 */
NodeT *newNode(NodeItemT item);

/**
 * Returns the item of a node.
 *
 * @return the item stored in this node
 */
NodeItemT* getInfo(NodeT *);

/**
 * Sets the item in a node.
 *
 * @param node a node whose item must be set
 * @param item the item of the node
 */
void setInfo(NodeT* node, NodeItemT item);

/**
 * Frees up the item of a node.
 *
 * @param node the node to be deallocated from memory
 */
void freeNode(NodeT * node);

/**
 * Returns the item that indicates that the node is empty.
 *
 * @return an item indicating that the node is empty
 */
NodeItemT getEmtpyNodeItem();

#endif