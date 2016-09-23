/*
 * An implementation of the selection sort algorithm
 * Author Luis Edmundo Espinoza Larios
 * Contributors Jesús Iván Gastelum Romero
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "util.h"

/*
 * Sorts the given array using the selection sort algorithm
 */
void sort(int[]);

int main()
{
    static int array[SIZE];
    struct timeval start, end;

    srand(time(NULL));

    generateArray(array);

    gettimeofday(&start, NULL);

    sort(array);

    gettimeofday(&end, NULL);

    printArray(array);

    printf ("Execution time: %f us\n", (double) (end.tv_usec - start.tv_usec) / 1000000 + (double) (end.tv_sec - start.tv_sec));

    return 0;
}

void sort(int array[])
{
    int i, j, lowestNumberIndex;

    for (i = 0; i < SIZE - 1; i++) {
        lowestNumberIndex = i;

        for (j = i + 1; j < SIZE; j++) {

            if (array[j] < array[lowestNumberIndex]) {
                lowestNumberIndex = j;
            }
        }

        swap(&array[i], &array[lowestNumberIndex]);
    }
}
