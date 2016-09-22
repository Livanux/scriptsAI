# makefile

# C compiler
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -ansi

# Base directory
BASEDIR = src

# Util dir
UTILDIR = $(BASEDIR)/util

# Modules
MODULES = $(BASEDIR)/simpleSort/simpleSort.c \
		  $(BASEDIR)/insertionSort/insertionSort.c \
		  $(BASEDIR)/selectionSort/selectionSort.c \
		  $(BASEDIR)/bubbleSort/bubbleSort.c \
		  $(BASEDIR)/quickSort/quickSort.c \
		  $(BASEDIR)/heapSort/heapSort.c \
		  $(BASEDIR)/mergeSort/mergeSort.c

all: clean $(MODULES)
	mkdir ./bin
	$(CC) $(CFLAGS) -o bin/simpleSort $(BASEDIR)/simpleSort/simpleSort.c $(UTILDIR)/util.c -I $(UTILDIR)
	$(CC) $(CFLAGS) -o bin/bubbleSort $(BASEDIR)/bubbleSort/bubbleSort.c $(UTILDIR)/util.c -I $(UTILDIR)
	$(CC) $(CFLAGS) -o bin/insertionSort $(BASEDIR)/insertionSort/insertionSort.c $(UTILDIR)/util.c -I $(UTILDIR)
	$(CC) $(CFLAGS) -o bin/selectionSort $(BASEDIR)/selectionSort/selectionSort.c $(UTILDIR)/util.c -I $(UTILDIR)
	$(CC) $(CFLAGS) -o bin/quickSort $(BASEDIR)/quickSort/quickSort.c $(UTILDIR)/util.c -I $(UTILDIR)
	$(CC) $(CFLAGS) -o bin/heapSort $(BASEDIR)/heapSort/heapSort.c $(UTILDIR)/util.c -I $(UTILDIR)
	$(CC) $(CFLAGS) -o bin/mergeSort $(BASEDIR)/mergeSort/mergeSort.c $(UTILDIR)/util.c -I $(UTILDIR)

clean:
	rm -r ./bin
