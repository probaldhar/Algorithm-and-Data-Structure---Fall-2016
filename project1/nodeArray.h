#ifndef _NODE_ARRAY_H
#define _NODE_ARRAY_H

// -----------------------------------------
// Definition of an item stored with a Node.
// -----------------------------------------
typedef char NodeItemT;

// ----------------------
// Definition of a Node
// ----------------------
typedef struct NodeT
{
	NodeItemT info;
} NodeT;

// ----------------------
// Interface to Node ADT
// ----------------------

/**
 * Creates a new node and stores the specified item in it.
 *
 * @param item the item to be stored in the node.
 */
NodeT* newNode(NodeItemT item);

/**
 * Returns the item of a node.
 *
 * @return a new node.
 */
NodeItemT getInfo(NodeT* node);

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

#endif