#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "bfileio.h"

/**
* Definition of all the functions needed to implement BTree. some of them decleared in btree.h
* 
* @author Probal Chandra Dhar
* @date 10/10/2016
* @info Course COP5990
*/

#define NO_CHILD 0

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
int init (BTree *myBTree, char *name){

	// store the file name to the BTree structure 
	strcpy(myBTree->btreeFileName, name);

	// printf("%s\n", myBTree->btreeFileName);

	// Initialize the File pointer
	myBTree->btreeFP = fopen(name, "r+" );
    
    fseek(myBTree->btreeFP, 0, SEEK_END);

	// right now stream is in the end of the file
	int currentStream = ftell(myBTree->btreeFP);
	int newPosition = currentStream/sizeof(BTreeNode);

	printf("BTree size : %d\n", newPosition);

	// set the stream to the beginning of the file
	fseek(myBTree->btreeFP, 0, SEEK_SET);

	// check if the file has been created or not
	if ( myBTree->btreeFP ){
		// file created successfully
		printf("File opened\n");

		// initialize the size of the btree
		// check for the next file index available.
		myBTree->sizeBTree = newPosition;

		return 0;

	}

	return -1;

}

/**
 * Printing all the Node elements stored in the BTree
 *
 * @param myBTree - information about the btree to access the tree in a file
 *
 */
void printAll(BTree *myBTree){

	fseek(myBTree->btreeFP, 0, SEEK_END);

	// right now stream is in the end of the file
	int currentStream = ftell(myBTree->btreeFP);
	int newPosition = currentStream/sizeof(BTreeNode);

	BTreeNode testNode;

	printf("%d\n", newPosition);

	int i,j;
	for ( i = 0; i < newPosition; i++ )
	{
		readNode ( &testNode, i, myBTree->btreeFP );

		printf("Node %d\n numKeys : %d \n", i, testNode.numKeys);

		for ( j = 0; j < testNode.numKeys; j++ )
		{
			printf("%d \n", testNode.keys[j]);
		}
		printf("\nEnd of a node\n");	
	}

}

/**
 * Swap two positions in the array
 *
 * @param num - The array that needs to be sorted
 * @param i - position of a element
 * @param j - position of another element
 *
 */
void swap(int* num, int i, int j) {
	int help;
	help = num[i];
	num[i] = num[j];
	num[j] = help;
}

/**
 * sorting array using bubble sort.
 *
 * @param num - The array that needs to be sorted
 * @param b - The number of element in the array num
 *
 */
void bubbleSort(int* num, int n){
	int i,j;
	for (i=0; i<n-1; i++) {
		for (j=i+1; j < n; j++) {
			if (num[i] > num[j])
				swap(num, i, j);
		}
	}
}

/**
 * Split the Node and add them in the File.
 *
 * @param newNodeX - The node to split
 * @param index - The File index of the node newNodeX
 * @param myBTree - information about the btree to access the tree in a file
 *
 */
int treeSplitChild(BTreeNode *newNodeX, unsigned int index, int searchKey, BTree *myBTree){

	BTreeNode newNodeZ, newNodeY;

	// check for the next file index available.
	// set the stream to the end of the file
	fseek(myBTree->btreeFP, 0, SEEK_END);
	int currentStream = ftell(myBTree->btreeFP);
	int newPosition = currentStream/sizeof(BTreeNode);

	int childNodeIndex = newNodeX->children[index];

	// check if we only have root node
	if ( childNodeIndex == 0 ){

		// special case because don't have to read child this time

		int i;

		// temp array to store the keys
		int tempArray[2*D+1];

		// adding the root elements into a tempArray
		for ( i = 0; i < 2*D; i++ )
		{
			tempArray[i] = newNodeX->keys[i];
		}
		// adding the searchKey to the tempArray
		tempArray[2*D] = searchKey;

		// sorting the array
		bubbleSort( tempArray, 2*D+1 );

		// calculating the middle element of the array
		// this will be the key of the new root node after split the rootNode
		int middleElement = tempArray[(2*D+1)/2];

		newNodeZ.numKeys = D;

		for ( i = 0; i < D; i++ ) 
		{
			newNodeZ.keys[i] = tempArray[i+D+1];
		}

		newNodeY.numKeys = D;

		for ( i = 0; i < D; i++ )
		{
			newNodeY.keys[i] = newNodeX->keys[i];
		}

		// Y & Z both leaf node
		for ( i = 0; i < 2*D+1; i++ )
		{
			newNodeY.children[i] = 0;
			newNodeZ.children[i] = 0;
		}

		// getting the medien element
		newNodeX->keys[0] = middleElement;
		newNodeX->numKeys = 1;

		// assigning the children to the Node
		for ( i = 0; i < 2*D+1; i++ )
		{
			if ( i == 0 || i == 1 ){
				//printf("0,1 %d\n", i);
				newNodeX->children[i] = i+1;
			}
			else
				newNodeX->children[i] = 0;
		}

		// root node
		writeNode (newNodeX, 0, myBTree->btreeFP);

		// Y - new child
		writeNode (&newNodeY, 1, myBTree->btreeFP);

		// Y is the new node
		myBTree->sizeBTree++;
		// Z - new child
		writeNode (&newNodeZ, 2, myBTree->btreeFP);

		// Z is the new node
		myBTree->sizeBTree++;

		return -1; // special case


	}

	// read the child node to split
	readNode ( &newNodeY, childNodeIndex, myBTree->btreeFP );

	int i, j, flag = 0;
	for ( i = 0; i < 2*D+1; ++i)
	{
		newNodeZ.children[i] = newNodeY.children[i];
	}

	newNodeZ.numKeys = D;

	for ( j = 1; j < D; j++ ) // is the conditional statement correct????
	{
		newNodeZ.keys[j] = newNodeY.keys[j+D+1];
	}

	// checking if Y node is the leaf node
	for ( i = 0; i < 2*D+1; i++ )
	{
		if ( newNodeY.children[i] != NO_CHILD )
			flag++;
	}

	// if y is not a leaf node
	if ( flag != 0 )
		for ( j = 1; j < D+1; j++ )
		{
			newNodeZ.children[j] = newNodeY.children[j+D+1];
		}

	newNodeY.numKeys = D;

	for ( j = newNodeX->numKeys + 1; j > index + 1; j-- )
	{
		newNodeX->children[j+1] = newNodeX->children[j];
	}

	// positioning the Z node to the X's children
	newNodeX->children[index+1] = newPosition;

	for ( j = newNodeX->numKeys; j > index; j-- )
	{
		newNodeX->keys[j+1] = newNodeX->keys[j];
	}

	newNodeX->keys[index] = newNodeY.keys[D+1];

	newNodeX->numKeys = newNodeX->numKeys + 1;

	// write these nodes
	// Y - old but splitted child of root
	writeNode (&newNodeY, childNodeIndex, myBTree->btreeFP);
	// Z - new child
	writeNode (&newNodeZ, newPosition, myBTree->btreeFP);

	// Z is the new node
	myBTree->sizeBTree++;

	// X - root node
	writeNode (newNodeX, index, myBTree->btreeFP);

	return 0;


}

/**
 * Insert a search key in the BTree if the node is not full.
 *
 * @param rootNodeX - Node to be searched for the position of searchKey
 * @param searchKey - the key to be inserted 
 * @param index 	- File Index of the node where it's stored in the file
 * @param myBTree - information about the btree to access the tree in a file
 *
 * @return a value of 0, if the key was found or a value of none-zero
 *         if an error occurred  (-1 indicates that the key is not in the tree)
 */
int treeInsertNonFull(BTreeNode newNodeX, int searchKey, unsigned int index, BTree *myBTree){

	int i = newNodeX.numKeys, flag = 0, j=0;

	// checking if X node is the leaf node
	for ( j = 0; j < 2*D+1; j++ )
	{
		if ( newNodeX.children[j] != NO_CHILD )
			flag++;
	}

	// X is the leaf node
	if ( flag == 0)
	{
		while ( i >= 1 && searchKey < newNodeX.keys[i] ){

			newNodeX.keys[i+1] = newNodeX.keys[i];
			i--;
		}

		// getting the value of the rootNode
		BTreeNode storeRootNode;
		readNode( &storeRootNode, 0, myBTree->btreeFP);

		if ( searchKey < storeRootNode.keys[0] )
			newNodeX.keys[i+1] = searchKey;
		else if ( searchKey > storeRootNode.keys[storeRootNode.numKeys] )
			newNodeX.keys[i] = searchKey;

		newNodeX.numKeys++;

		// inserted
		writeNode (&newNodeX, index, myBTree->btreeFP);

		return 0;

	} else {

		int k = 0;
		while ( i >= 1 && searchKey < newNodeX.keys[k] ){ // problem in condition
			i--;
			k++;
		}

		//i++;

		// disk - read children
		int childIndex = newNodeX.children[i];

		// now newNodeX is the i'th children of newNodeX
		readNode( &newNodeX, childIndex, myBTree->btreeFP);

		if ( newNodeX.numKeys == 2*D ){

			treeSplitChild(&newNodeX, i, searchKey, myBTree); // i = i'th children

			if ( searchKey > newNodeX.keys[i] )
				i++;

		}

		// recursion with the i'th children of newNodeX
		if ( treeInsertNonFull ( newNodeX, searchKey, childIndex, myBTree ) == -1 )
			return -1;
	}

	return -1;

}



/**
 * Inserts a search key into btree.
 *
 * @param myBTree - information about the BTree file
 * @param searchKey - the search key to be inserted
 *
 * @return a value of 0, if the key was successfully inserted or a value of none-zero
 *         if an error occurred 
 */
int insert (BTree *myBTree, int searchKey){

	int i,j;

	// no file for BTree
	if ( strlen(myBTree->btreeFileName) == 0 ){
		// create new file
		printf("There's no File\n");
	}

	// if tree size is 0
	if ( myBTree->sizeBTree == 0 ) {

		// create new node 
		BTreeNode newNode;

		// assign the search key to the first element of the newly created node
		newNode.keys[0] = searchKey;
		newNode.numKeys = 1;

		// Assigning all children to 0 because there's no children right now

		for ( i = 0; i < (2*D+1); i++ )
		{
			newNode.children[i] = NO_CHILD;
		}

		// write the node to the file
		writeNode (&newNode, 0, myBTree->btreeFP);

		myBTree->sizeBTree++;

		return 0;
	}

	// if only root node is there in the tree
	if ( myBTree->sizeBTree == 1 ) {

		BTreeNode newNode;

		// read the root Node from file
		readNode ( &newNode, 0, myBTree->btreeFP );

		// if element is less than maximum then push the element to the root node
		if ( newNode.numKeys < (2*D) ){

			i = 0;
			// checking the root if it's full and the key is less then the keys
			while ( i < newNode.numKeys && searchKey > newNode.keys[i] )
				i++;

			//shifts any subsequent elements to the right by adding one from their indices.
			for ( j = newNode.numKeys; j > i; j--)
			{
				newNode.keys[j] = newNode.keys[j-1];
			}

			// if the search element is greater or equal to the current key
			newNode.keys[i] = searchKey;
			newNode.numKeys++;

			// write this node to the file
			writeNode (&newNode, 0, myBTree->btreeFP);

			// insert the node successfully in the file
			return 0;
		
		} // ends if Node keys < 2*D

	} // ends if BTreesize 1



	// general case
	BTreeNode rootNode, newRootNode, storeRootNode;

	// Root node
	readNode ( &rootNode, 0, myBTree->btreeFP );	

	// storing root node
	storeRootNode = rootNode;

	// if the root is full
	if ( rootNode.numKeys == 2*D ){

		// rootNode = newRootNode;
		newRootNode = rootNode;
		newRootNode.numKeys = 0;

		// split the root
		if ( treeSplitChild (&newRootNode, 0, searchKey, myBTree) == -1 ) { // special case

			return 0; // only root is been splited
		}
		// insert if the new node is not full
		treeInsertNonFull (newRootNode, searchKey, 0, myBTree);

	} else {

		// insert if the root is not full
		treeInsertNonFull (storeRootNode, searchKey, 0, myBTree);		
	}

	return 0;

}


/**
 * Deletes a search key from a btree.
 *
 * @param myBTree - information about the btree to access the tree in a file
 * @param searchKey - the search key to be deleted
 *
 * @return a value of 0, if the key was successfully deleted or a value of none-zero
 *         if an error occurred (-1 indicates that the node is not in the tree)
 */
int delete (BTree *myBTree, int searchKey){

	// if tree size is 0
	if ( myBTree->sizeBTree == 0 ) {
		printf("There's no node in the BTree\n");
		return -1;
	}

	BTreeNode rootNode;

	// getting the file index of the node
	int FileIndex = search (myBTree, searchKey);

	// read the root Node
	readNode ( &rootNode, FileIndex, myBTree->btreeFP );

	int i,j;
	for ( i = 0; i < rootNode.numKeys; i++ )
	{
		if ( rootNode.keys[i] == searchKey ){

			rootNode.keys[i] = 0;

			// move the subsequent values
			for ( j = i; j < rootNode.numKeys; j++)
			{
				rootNode.keys[j] = rootNode.keys[j+1];
			}

			// decreasing the numKeys
			rootNode.numKeys--;

			// writing the root node to file
			writeNode ( &rootNode, FileIndex, myBTree->btreeFP );

			return 0;

		}
	}

	return -1;
}


/**
 * Searches the key position recursively.
 *
 * @param rootNode - Node to be searched for the searchKey
 * @param FileIndex - index of the Node where it is stored in the file
 * @param searchKey - the key to be searched 
 * @param myBTree - information about the btree to access the tree in a file
 *
 * @return the value of FileIndex where the node is stored in the file, if the key was found 
 *         if an error occurred  (-1 indicates that the key is not in the tree)
 */
int searchMiddle( BTreeNode rootNode, int searchKey, int FileIndex, BTree *myBTree ){

	// checking for the children - if this node is the leaf node
	int i, flag = 0, index = 0;

	for ( i = 0; i < 2*D+1; i++ )
	{
		if ( rootNode.children[i] != NO_CHILD ){
			flag++;
		}
	}

	// checking the root if it's full and the key is less then the keys
	while ( index < rootNode.numKeys && searchKey > rootNode.keys[index] )
		index++;

	// getting the file index of the child node
	int childIndex = rootNode.children[index];

	// check if the i'th value is the searchKey or not
	if ( index <= (2*D) && searchKey == rootNode.keys[index] ){
		// return 0;
		return FileIndex;
	} else if ( flag == 0){
		// node is leaf node
		return -1;
	} else {

		// read the child node
		readNode ( &rootNode, childIndex, myBTree->btreeFP);

		// call again search with the new node and returning it
		return searchMiddle( rootNode, searchKey, childIndex, myBTree );

	}

	// returning the File Index of the element
	return FileIndex;

}



/**
 * Searches a key in a btree.
 *
 * @param myBTree - information about the btree to access the tree in a file
 * @param searchKey - the key to be searched 
 *
 * @return the value of FileIndex where the node is stored in the file, if the key was found 
 *         if an error occurred  (-1 indicates that the key is not in the tree)
 */
int search (BTree *myBTree, int searchKey){

	int index = 0;

	// Just creating a Node
	BTreeNode rootNode;

	// no node in the BTree
	if ( myBTree->sizeBTree == 0 ){
		printf("There's no Node in the tree \n");
		return -1;
	}

	// read first node
	readNode ( &rootNode, index, myBTree->btreeFP);

	// getting the search result from recursive function searchMiddle
	int result = searchMiddle( rootNode, searchKey, 0, myBTree );

	return result;

}





