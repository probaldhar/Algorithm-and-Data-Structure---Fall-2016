all : backtracking

backtracking : node.o stack.o maze.o backtracking.o main.o
	gcc -o backtracking node.o stack.o maze.o backtracking.o main.o

node.o : node.h node.c
	gcc -c node.c

stack.o : stack.h stack.c
	gcc -c stack.c

maze.o : maze.h maze.c
	gcc -c maze.c

backtracking.o : backtracking.h backtracking.c
	gcc -g -c backtracking.c

main.o : main.c
	gcc -g -c main.c

clean :
	rm node.o stack.o maze.o backtracking.o main.o backtracking