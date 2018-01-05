/**
 * Implements the functions of NodeT.
 *
 * @author T. Reichherzer
 */

#include "nodeLL.h"
#include <stdlib.h>

NodeT *newNode(NodeItemT item)
{
	NodeT* node;

	node = (NodeT*) malloc (sizeof(NodeT));
	node->info = item;
    node->next = NULL;

	return node;
}

NodeItemT getInfo(NodeT *node)
{
    if ( node != NULL ) {
        return node->info;
    }

    return EMPTY_ITEM;
}

void setInfo(NodeT* node, NodeItemT item)
{
    if ( node != NULL ) {
	    node->info = item;
    }
}

void freeNode(NodeT *node)
{
	free(node);
}
