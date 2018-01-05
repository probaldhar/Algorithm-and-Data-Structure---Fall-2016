#include <stdio.h>
#include <stdlib.h>
#include "bfileio.h"

/**
 * Defines all file IO operations on a BTree.
 *
 * @author T. Reichherzer
 */


/**
 * Reads a BTree node from the specified file.
 *
 * @param node - the node read from the file
 * @param index - the index of the node in the file
 * @param fp - the file pointer for reading the node
 *
 * @return a value of 0, if the node was successfully read; otherwise, a non-zero value, if
 *         if an error occurred 
 */
int readNode (BTreeNode *myBTreeNode, unsigned int index, FILE* fp){

	fseek(fp, index*sizeof(BTreeNode), SEEK_SET);
	
	if( fread(myBTreeNode, sizeof(BTreeNode), 1, fp) ){

		return 0;

	}

	return -1;

}


/**
 * Writes a BTree node to the specified file.
 *
 * @param node - the node to be written into the file
 * @param index - the index of the node determining the position in the file
 * @param fp - the file pointer for reading the node
 *
 * @return a value of 0, if the node was successfully written to the file; otherwise, a non-zero value, if
 *         if an error occurred 
 */
int writeNode (BTreeNode *myBTreeNode, unsigned int index, FILE* fp){

	fseek(fp, index*sizeof(BTreeNode), SEEK_SET);

	// printf("write Node Index: %d\n", index);
	
	if( fwrite(myBTreeNode, sizeof(BTreeNode), 1, fp) ){

		return 0;

	}
	
	return -1;
}


