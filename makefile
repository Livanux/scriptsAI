# makefile

# C compiler
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -ansi

# Base directory
BASEDIR = src

# Util dir
UTILDIR = $(BASEDIR)/util

all: clean makedir simpleSort bubbleSort insertionSort selectionSort quickSort heapSort mergeSort graphs

simpleSort: $(BASEDIR)/simpleSort/simpleSort.c
	$(CC) $(CFLAGS) -o bin/simpleSort $(BASEDIR)/simpleSort/simpleSort.c $(UTILDIR)/util.c -I $(UTILDIR)

bubbleSort: $(BASEDIR)/bubbleSort/bubbleSort.c
	$(CC) $(CFLAGS) -o bin/bubbleSort $(BASEDIR)/bubbleSort/bubbleSort.c $(UTILDIR)/util.c -I $(UTILDIR)

insertionSort: $(BASEDIR)/insertionSort/insertionSort.c
	$(CC) $(CFLAGS) -o bin/insertionSort $(BASEDIR)/insertionSort/insertionSort.c $(UTILDIR)/util.c -I $(UTILDIR)

selectionSort: $(BASEDIR)/selectionSort/selectionSort.c
	$(CC) $(CFLAGS) -o bin/selectionSort $(BASEDIR)/selectionSort/selectionSort.c $(UTILDIR)/util.c -I $(UTILDIR)

quickSort: $(BASEDIR)/quickSort/quickSort.c
	$(CC) $(CFLAGS) -o bin/quickSort $(BASEDIR)/quickSort/quickSort.c $(UTILDIR)/util.c -I $(UTILDIR)

heapSort: $(BASEDIR)/heapSort/heapSort.c
	$(CC) $(CFLAGS) -o bin/heapSort $(BASEDIR)/heapSort/heapSort.c $(UTILDIR)/util.c -I $(UTILDIR)

mergeSort: $(BASEDIR)/mergeSort/mergeSort.c
	$(CC) $(CFLAGS) -o bin/mergeSort $(BASEDIR)/mergeSort/mergeSort.c $(UTILDIR)/util.c -I $(UTILDIR)

graphs: $(BASEDIR)/graphs/graphs.c
	$(CC) $(CFLAGS) -o bin/graphs $(BASEDIR)/graphs/graphs.c 

makedir:
	mkdir ./bin

clean:
	rm -rf ./bin
