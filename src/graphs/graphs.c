/*
 * A simple graph transversal algorithm
 * Author Luis Edmundo Espinoza Larios
 * Collaborators Jesús Iván Gastelum Romero
 */

#include <stdio.h>

#define SIZE 10

void explore(int[][SIZE], int);

void DFS(int[][SIZE], int[], int);

int getIndex(int[][SIZE], int);

int main()
{
    int graph[SIZE][SIZE] = {
        {1, 2, 4, 8},
        {2, 1, 3, 4},
        {3, 2, 6, 7},
        {4, 1, 2},
        {5, 6, 9},
        {6, 3, 5, 7},
        {7, 3, 6},
        {8, 1},
        {9, 5},
        {10},
    };

    printf("With 1: "); explore(graph, 1);
    printf("With 2: "); explore(graph, 2);
    printf("With 3: "); explore(graph, 3);
    printf("With 4: "); explore(graph, 4);
    printf("With 5: "); explore(graph, 5);
    printf("With 6: "); explore(graph, 6);
    printf("With 7: "); explore(graph, 7);
    printf("With 8: "); explore(graph, 8);
    printf("With 9: "); explore(graph, 9);
    printf("With 10: "); explore(graph, 10);

    return 0;
}

void explore(int graph[][SIZE], int start)
{
    int startIndex, visited[SIZE] = {0};

    startIndex = getIndex(graph, start);
    visited[startIndex] = 1;

    DFS(graph, visited, start);

    printf("\n");
}

void DFS(int graph[][SIZE], int visited[], int current)
{
    int j, visitedIndex, currentIndex = getIndex(graph, current);

    printf("%d -> ", graph[currentIndex][0]);

    visited[currentIndex] = 1;

    for (j = 0; j < SIZE && graph[currentIndex][j] != 0; j++) {
        visitedIndex = getIndex(graph, graph[currentIndex][j]);
        if (!visited[visitedIndex]) {
            DFS(graph, visited, graph[currentIndex][j]);
        }
    }
}

int getIndex(int graph[][SIZE], int number)
{
    int i;

    for (i = 0; i < SIZE; i++) {

        if (graph[i][0] == number) {
            return i;
        }
    }

    return -1;
}
