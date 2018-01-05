/**
 * Defines all data types and declares all function prototypes for creating and updating
 * a btree.
 *
 * @author T. Reichherzer
 */

#ifndef _BTREE_H
#define _BTREE_H

#define D 2

typedef struct {
    char btreeFileName[100];       // stores the name of the btree file
    FILE* btreeFP;				   // stores the file pointer of the btree file
    int  sizeBTree;                // stores the total number of nodes in the tree
} BTree;

typedef struct {
	// int isLeaf;     			   // is this a leaf node?  {{{ can I add a integer in here???  }}}
    int keys[2*D];                 // stores the search keys
    unsigned int children[2*D+1];  // stores links to other nodes
    int numKeys;                   // stores the number of search keys in this node
} BTreeNode;




void printAll(BTree *myBTree);


/**
 * Initializes the Btree by opening or creating the btree file and initializing the
 * the size of the btree.
 * 
 * @param myBTree - information about the BTree file
 * @param name - the file name of the BTree file
 *
 * @retun a value of 0, if the was successfully opened or created or value of non-zero
          if an error occurred
 */
int init (BTree *myBTree, char *name);

/**
 * Inserts a search key into btree.
 *
 * @param myBTree - information about the BTree file
 * @param searchKey - the search key to be inserted
 *
 * @return a value of 0, if the key was successfully inserted or a value of none-zero
 *         if an error occurred 
 */
int insert (BTree *myBTree, int searchKey);


/**
 * Deletes a search key from a btree.
 *
 * @param myBTree - information about the btree to access the tree in a file
 * @param searchKey - the search key to be deleted
 *
 * @return a value of 0, if the key was successfully deleted or a value of none-zero
 *         if an error occurred (-1 indicates that the node is not in the tree)
 */
int delete (BTree *myBTree, int searchKey);

/**
 * Searches a key in a btree.
 *
 * @param myBTree - information about the btree to access the tree in a file
 * @param searchKey - the key to be searched 
 *
 * @return a value of 0, if the key was found or a value of none-zero
 *         if an error occurred  (-1 indicates that the key is not in the tree)
 */
int search (BTree *myBTree, int searchKey);

#endif
