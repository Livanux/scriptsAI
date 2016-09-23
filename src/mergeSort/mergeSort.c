/*
 * An implementation of the mergesort algorithm
 * Author Luis Edmundo Espinoza Larios
 * Contributors Jesús Iván Gastelum Romero
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "util.h"

/*
 * Sorts the given array using the mergesort algorithm
 */
void sort(int[], int[], int);

/*
 * Merge two sub arrays
 */
void merge(int[], int, int, int[]);

/*
 * Used in merge
 */
void topDownMerge(int[], int, int, int, int[]);

/*
 * Copies from start to end the second array into the first
 */
void copyArray(int[], int, int, int[]);

int main()
{
    static int array[SIZE];
    static int workArray[SIZE];
    struct timeval start, end;

    srand(time(NULL));

    generateArray(array);

    gettimeofday(&start, NULL);

    sort(array, workArray, SIZE);

    gettimeofday(&end, NULL);

    printArray(array);

    printf("Execution time: %f us\n", (double) (end.tv_usec - start.tv_usec) / 1000000 + (double) (end.tv_sec - start.tv_sec));

    return 0;
}

void sort(int array[], int workArray[], int end)
{
    merge(array, 0, end, workArray);
}

void merge(int array[], int start, int end, int workArray[])
{
    int middle;

    if (end - start <  2) {
        return;
    }

    middle = (end + start) / 2;
    merge(array, start, middle, workArray);
    merge(array, middle, end, workArray);
    topDownMerge(array, start, middle, end, workArray);
    copyArray(array, start, end, workArray);
}

void topDownMerge(int array[], int start, int middle, int end, int workArray[])
{
    int i = start, j = middle, k;

    for (k = start; k < end; k++) {

        if (i < middle && (j >= end || array[i] <= array[j])) {
            workArray[k] = array[i++];
        } else {
            workArray[k] = array[j++];
        }
    }
}

void copyArray(int dst[], int start, int end, int src[])
{
    int i;

    for (i = start; i < end; i++) {
        dst[i] = src[i];
    }
}
