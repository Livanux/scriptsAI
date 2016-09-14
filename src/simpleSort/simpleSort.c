/*
 * A simple sorting program using square matrices and vectors
 * Author Luis Edmundo Espinoza Larios
 * Contributors Jesús Iván Gastelum Romero
 */

#include <stdio.h>
#include <sys/time.h>

#define SIZE 4
#define ARRAY_SIZE SIZE * SIZE

/*
 * Sorts the given array in ascending order
 */
void sort(int[]);

/*
 * Convert a square matrix into an array
 */
void convertMatrixToArray(int[][SIZE], int[]);

/*
 * Convert an array into a matrix
 */
void convertArrayToMatrix(int[], int[][SIZE]);

/*
 * Prints matrix in snake-style
 * e.g.
 * Given:
 *       a, b
 *       c, d
 * printing using the snake style:
 *       a, b
 *       d, c
 */
void printMatrixSnakeStyle(int[][SIZE]);

int main()
{
    static int matrix[][SIZE] = {
        {5, 2, 12, 65},
        {404, 55, 291, -200},
        {6, -23, -1, 79},
        {1001, -9, 11, 98}
    };

    static int array[ARRAY_SIZE];
    struct timeval start, end;

    gettimeofday(&start, NULL);

    convertMatrixToArray(matrix, array);

    sort(array);

    convertArrayToMatrix(array, matrix);

    printMatrixSnakeStyle(matrix);

    gettimeofday(&end, NULL);

    printf ("Execution time: %f us\n", (double) (end.tv_usec - start.tv_usec) / 1000000 + (double) (end.tv_sec - start.tv_sec));

    return 0;
}

void sort(int array[])
{
    int i, j;
    int lowestNumber,
        swap,
        savedIndex,
        wasLowestNumberFound;

    for (i = 0; i < ARRAY_SIZE; i++) {
        lowestNumber = array[i];
        wasLowestNumberFound = 0;

        for (j = i + 1; j < ARRAY_SIZE; j++) {

            if (array[j] < lowestNumber) {
                lowestNumber = array[j];
                savedIndex = j;
                wasLowestNumberFound = 1;
            }
        }

        if (wasLowestNumberFound > 0) {
            swap = array[i];
            array[i] = lowestNumber;
            array[savedIndex] = swap;
        }
    }
}

void convertMatrixToArray(int matrix[][SIZE], int array[])
{
    int i, j, k = 0;

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {
            array[k++] = matrix[i][j];
        }
    }
}

void convertArrayToMatrix(int array[], int matrix[][SIZE])
{
    int i, j, k = 0;

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = array[k++];
        }
    }
}

void printMatrixSnakeStyle(int matrix[][SIZE])
{
    int i, j, delta, startIndex;

    for (i = 0; i < SIZE; i++) {
        delta = i % 2 != 0 ? -1 : 1;
        startIndex = i % 2 != 0 ? SIZE - 1 : 0;

        for (j = 0; j < SIZE; j++) {
            printf("% d\t", matrix[i][startIndex]);
            startIndex += delta;
        }

        printf("\n");
    }
}
