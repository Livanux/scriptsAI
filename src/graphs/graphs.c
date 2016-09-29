/*
 * A simple graph transversal algorithm
 * Author Luis Edmundo Espinoza Larios
 * Collaborators Jesús Iván Gastelum Romero
 */

#include <stdio.h>

#define SIZE 6

void goTo(int[][SIZE], const int, const int);

int next(int[][SIZE], int[], int);

int wasVisited(int[], int);

int main()
{
    int matrix[SIZE][SIZE] = {
        {1, 2, 4},
        {2, 1, 3},
        {3, 2, 4, 5},
        {4, 1, 3, 5},
        {5, 3, 4, 6},
        {6, 5}
    };

    goTo(matrix, 4, 6);

    return 0;
}

void goTo(int matrix[][SIZE], const int from, const int to)
{
    int current = from, k = 0;
    static int array[SIZE];

    while (current != to) {
        printf("%d -> ", current);
        array[k++] = current;
        current = next(matrix, array, current);
    }

    printf("%d\n", current);
}

int next(int matrix[][SIZE], int array[], int node)
{
    int i;

    for (i = 0; i < SIZE; i++) {

        if (matrix[node - 1][i] != node) {

            if (!wasVisited(array, matrix[node - 1][i])) {
                return matrix[node - 1][i];
            }
        }
    }

    return 0;
}

int wasVisited(int array[], int number)
{
    int i;


    for (i = 0; i < SIZE; i++) {

        if (array[i] == number) {
            return 1;
        }
    }

    return 0;
}
