all : vectorADTArray

vectorADTArray : nodeArray.o vectorArray.o time.o testVectorArray.o
	gcc -o vectorADTArray nodeArray.o vectorArray.o time.o testVectorArray.o

vectorADTLL : nodeLL.o vectorLL.o time.o testVectorLL.o
	gcc -o vectorADTLL nodeLL.o vectorLL.o time.o testVectorLL.o

nodeArray.o : nodeArray.h nodeArray.c
	gcc -c nodeArray.c

vectorArray.o : vectorArray.h vectorArray.c
	gcc -g -c vectorArray.c

time.o : time.h time.c
	gcc -g -c time.c

testVectorArray.o : vectorArray.h testVectorArray.c
	gcc -g -c testVectorArray.c

nodeLL.o : nodeLL.h nodeLL.c
	gcc -c nodeLL.c

vectorLL.o : vectorLL.h vectorLL.c
	gcc -g -c vectorLL.c

testVectorLL.o : vectorLL.h testVectorLL.c
	gcc -g -c testVectorLL.c

clean :
	rm time.o nodeArray.o vectorArray.o testVectorArray.o vectorADTArray nodeLL.o vectorLL.o testVectorLL.o vectorADTLL
