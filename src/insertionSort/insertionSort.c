/*
 * An implementation of the insertion sort algorithm
 * Author Luis Edmundo Espinoza Larios
 * Contributors Jesús Iván Gastelum Romero
 */

#include <stdio.h>
#include <sys/time.h>
#include "arrayUtil.h"

/*
 * Sorts a given array using insertion sort algorithm
 */
void sort(int[]);

int main()
{
    static int array[SIZE] = {7, -5, 0, 2, 16, -9, 21, -874, 0, 8, 16, -210};
    struct timeval start, end;

    gettimeofday(&start, NULL);

    sort(array);
    printArray(array);

    gettimeofday(&end, NULL);

    printf ("Execution time: %f us\n", (double) (end.tv_usec - start.tv_usec) / 1000000 + (double) (end.tv_sec - start.tv_sec));

    return 0;
}

void sort(int array[])
{
    int i, j, aux;

    for (i = 1; i < SIZE; i++) {
        j = i;

        while (j > 0 && array[j - 1] > array[j]) {
            aux = array[j];
            array[j] = array[j - 1];
            array[j - 1] = aux;
            j -= 1;
        }
    }
}