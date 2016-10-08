/*
 * A simple graph transversal algorithm
 * Author Luis Edmundo Espinoza Larios
 * Collaborators Jesús Iván Gastelum Romero
 */

#include <stdio.h>

#define SIZE 10

void goTo(int[][SIZE], int, int);

int dfs(int[][SIZE], int[], int, int);

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

    goTo(graph, 10, 8);

    return 0;
}

void goTo(int graph[][SIZE], int start, int end)
{
    int startIndex, visited[SIZE] = {0};

    startIndex = getIndex(graph, start);
    visited[startIndex] = 1;

    dfs(graph, visited, start, end);

    printf("\n");
}

int dfs(int graph[][SIZE], int visited[], int current, int end)
{
    int i, visitedIndex, currentIndex = getIndex(graph, current);

    printf("%d -> ", graph[currentIndex][0]);

    if (current == end) {
        return 1;
    }

    visited[currentIndex] = 1;

    for (i = 0; i < SIZE && graph[currentIndex][i] != 0; i++) {
        visitedIndex = getIndex(graph, graph[currentIndex][i]);
        if (!visited[visitedIndex]) {
            if (dfs(graph, visited, graph[currentIndex][i], end)) return 1;
        }
    }

    return 0;
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
