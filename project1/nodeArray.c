/**
 * Implements the functions of NodeT.
 *
 * @author T. Reichherzer
 */

#include "nodeArray.h"
#include <stdlib.h>

NodeT* newNode(NodeItemT item)
{
	NodeT* node;

	node = (NodeT*) malloc (sizeof(NodeT));
	node->info = item;

	return node;
}

NodeItemT getInfo(NodeT *node)
{
	return node->info;
}

void setInfo(NodeT *node, NodeItemT item)
{
	node->info = item;
}

void freeNode(NodeT *node)
{
	if (node != NULL)
		free(node);
}


