all : btree

btree : time.o bfileio.o btree.o btreeMain.o
	gcc -o btree time.o bfileio.o btree.o btreeMain.o

time.o : time.h time.c
	gcc -g -c time.c -Wall

bfileio.o : bfileio.h bfileio.c
	gcc -g -c bfileio.c -Wall

btree.o : btree.h btree.c
	gcc -g -std=c99 -c btree.c -Wall

btreeMain.o : btree.h btreeMain.c
	gcc -g -c btreeMain.c -Wall

clean :
	rm time.o bfileio.o btree.o btreeMain.o btree
