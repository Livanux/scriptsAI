/*
 * arrayUtil.c
 * Utils implementations
 */

#include <stdio.h>
#include "arrayUtil.h"

void printArray(int array[])
{
    int i;

    for (i = 0; i < SIZE; i++) {
        printf("% d ", array[i]);
    }

    printf("\n");
}
