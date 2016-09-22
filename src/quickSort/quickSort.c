/*
 * An implementation of the quicksort algorithm
 * Author Luis Edmundo Espinoza Larios
 * Contributors Jesús Iván Gastelum Romero
 */

#include <stdio.h>
#include <sys/time.h>
#include "arrayUtil.h"

/*
 * Sorts the given array using the quicksort algorithm
 */
void sort(int[], int, int);

/*
 * Partition helper function for quicksort
 */
int partition(int[], int, int);

/*
 * Swap utility
 */
void swap(int *, int *);

int main()
{
    static int array[SIZE] = {7, -5 , 0, 2, 16, -9, 21, -874, 0, 8, 16, -210};
    struct timeval start, end;

    gettimeofday(&start, NULL);

    sort(array, 0, SIZE - 1);
    printArray(array);

    gettimeofday(&end, NULL);

    printf ("Execution time: %f us\n", (double) (end.tv_usec - start.tv_usec) / 1000000 + (double) (end.tv_sec - start.tv_sec));

    return 0;
}

void sort(int array[], int left, int right)
{
    int pivot;

    if (left < right) {
        pivot = partition(array, left, right);
        sort(array, left, pivot - 1);
        sort(array, pivot + 1, right);
    }
}

int partition(int array[], int left, int right)
{
    int pivot = array[right], i = left, j;

    for (j = left; j < right; j++) {

        if (array[j] <= pivot) {
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[right]);

    return i;
}

void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
