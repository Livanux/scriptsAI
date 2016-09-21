# makefile

# C compiler
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -ansi

# Base directory
BASEDIR = src

# Modules
MODULES = $(BASEDIR)/simpleSort/simpleSort.c \
		   $(BASEDIR)/insertionSort/insertionSort.c \
		   $(BASEDIR)/selectionSort/selectionSort.c \
		   $(BASEDIR)/bubbleSort/bubbleSort.c

all: $(MODULES)
	$(CC) $(CFLAGS) -o bin/simpleSort $(BASEDIR)/simpleSort/simpleSort.c src/util/arrayUtil.c -I src/util/
	$(CC) $(CFLAGS) -o bin/bubbleSort $(BASEDIR)/bubbleSort/bubbleSort.c src/util/arrayUtil.c -I src/util/
	$(CC) $(CFLAGS) -o bin/insertionSort $(BASEDIR)/insertionSort/insertionSort.c src/util/arrayUtil.c -I src/util/
	$(CC) $(CFLAGS) -o bin/selectionSort $(BASEDIR)/selectionSort/selectionSort.c src/util/arrayUtil.c -I src/util/
