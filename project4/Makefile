all : tspBruteForce tspGenetic tspMST

tspBruteForce : time.o bruteForce.o 
	gcc -o tspBruteForce time.o bruteForce.o 

tspGenetic : time.o genetic.o
	gcc -o tspGenetic time.o genetic.o

tspMST : time.o tspMST.o
	gcc -o tspMST time.o tspMST.o

time.o : time.h time.c
	gcc -g -c time.c -Wall

bruteForce.o : bruteForce.h bruteForce.c
	gcc -g -c bruteForce.c -Wall

genetic.o : genetic.c
	gcc -g -c genetic.c -Wall

tspMST.o : tspMST.c
	gcc -g -std=c99 -c tspMST.c -Wall

clean :
	rm time.o bruteForce.o genetic.o tspMST.o tspBruteForce tspGenetic tspMST
