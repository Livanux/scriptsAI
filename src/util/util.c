/*
 * arrayUtil.c
 * Utils implementations
 */

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void printArray(int array[])
{
    int i;

    for (i = 0; i < SIZE; i++) {
        printf("% d ", array[i]);
    }

    printf("\n");
}

void generateArray(int array[])
{
    int i;

    for (i = 0; i < SIZE; i++) {
        array[i] = 1 + (rand() % 10000);
    }
}

void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

