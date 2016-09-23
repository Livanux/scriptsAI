/*
 * An implementation of the heapsort algorithm
 * Author Luis Edmundo Espinoza Larios
 * Contributors Jesús Iván Gastelum Romero
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "util.h"

/*
 * Sorts the given array using the heapsort algorithm
 */
void sort(int[], int);

/*
 * Put elements of array in heap order
 */
void heapify(int[], int);

/*
 * Repair or satify the heap
 */
void siftDown(int[], int, int);

int main()
{
    static int array[SIZE];
    struct timeval start, end;

    srand(time(NULL));

    generateArray(array);

    gettimeofday(&start, NULL);

    sort(array, SIZE);

    gettimeofday(&end, NULL);

    printArray(array);

    printf("Execution time: %f us\n", (double) (end.tv_usec - start.tv_usec) / 1000000 + (double) (end.tv_sec - start.tv_sec));

    return 0;
}

void sort(int array[], int count)
{
    int end;

    heapify(array, count);

    end = count - 1;

    while (end > 0) {
        swap(&array[end], &array[0]);
        end -= 1;
        siftDown(array, 0, end);
    }
}

void heapify(int array[], int count)
{
    int start = count - 1;

    while (start >= 0) {
        siftDown(array, start, count - 1);
        start -= 1;
    }
}

void siftDown(int array[], int start, int end)
{
    int left, right, largest;
    left = 2 * start;
    right = 2 * start + 1;

    if (left <= end && array[left] > array[start]) {
        largest = left;
    } else {
        largest = start;
    }

    if (right  <= end && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != start) {
        swap(&array[start], &array[largest]);
        siftDown(array, largest, end);
    }
}
