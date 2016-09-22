/*
 * An implementation of the mergesort algorithm
 * Author Luis Edmundo Espinoza Larios
 * Contributors Jesús Iván Gastelum Romero
 */

#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include "arrayUtil.h"

/*
 * Sorts the given array using the mergesort algorithm
 */
void sort(int[], int[], int);

void merge(int[], int, int, int[]);

void topDownMerge(int[], int, int, int, int[]);

void copyArray(int[], int, int, int[]);

int main()
{
    static int array[SIZE] = {7, -5 , 0, 2, 16, -9, 21, -874, 0, 8, 16, -210};
    static int workArray[SIZE];
    struct timeval start, end;

    gettimeofday(&start, NULL);

    sort(array, workArray, SIZE);
    printArray(array);

    gettimeofday(&end, NULL);

    printf ("Execution time: %f us\n", (double) (end.tv_usec - start.tv_usec) / 1000000 + (double) (end.tv_sec - start.tv_sec));

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
            workArray[k] = array[i];
            i++;
        } else {
            workArray[k] = array[j];
            j++;
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
