#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "time.h"

/**
 * This program tests the implementation of a btree on disk.
 * The program runs several test according to user input.
 * 
 * @author Thomas Reichherzer
 * @date 10/4/2016
 * @info Course COP5990
 */

int main ( int argc, char** argv )
{
    int   numOps, data, isSilent=0;
    char  ops;
    BTree btree;

    if (argc != 2 && argc != 3) {
        printf ("usage: btree <filename> [-silent]\n");
        exit (1);
    }

    if (argc == 3) {
        if (!strcmp (argv[2], "-silent")) {
            isSilent = 1;
        } else {
            printf ("usage: btree <filename> [-silent]\n");
            exit (1);
        }
    }


    // complete this

    init(&btree, argv[1]);

    // printAll(&btree);

    startTimer();

    // reading input data for adding characters to the vector
    if (!isSilent) {
        printf ("How many operations do you want to perform on the tree?");
    }
    scanf ("%d", &numOps);

    int i;
    for (i=0; i < numOps; i++) {

        printf ("Enter an operation ('s', 'i', 'd') and an integer value.\n");
        scanf (" %c %d", &ops, &data);

        // complete this
        switch (ops) {
            case 's': 
                // search
                printf("Search %d in BTree\n", data);
                int FileIndex = search (&btree, data);
                if ( FileIndex >= 0 ){
                    printf("Key Found in the BTree\n");
                } else {
                    printf("Search Key not found in the BTree.\n");
                }
                break;
            case 'i':
                // insert
                printf("Insert %d in BTree\n", data);
                if ( insert (&btree, data) == 0 ) {
                    printf("Key Inserted\n");
                }
                break;
            case 'd':
                // delete
                printf("Delete %d from BTree\n", data);
                if ( delete (&btree, data) == 0 )
                    printf("Key deleted\n");
                break;
            default:
                printf("Enter correct char\n");
                break;
        }
    }
	
    float elapsedTime = stopTimer ();
	
	printf ("It took %f seconds to complete the job.\n", elapsedTime);

    // closing the file
    if ( btree.btreeFP ){
        fclose(btree.btreeFP);
    }

    return 0;
}
