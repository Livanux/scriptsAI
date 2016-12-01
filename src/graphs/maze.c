/*
 * Author Luis Edmundo Espinoza Larios
 * Collaborators Jesús Iván Gastelum Romero
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 25

typedef struct {
    int x;
    int y;
} vertex;

void dfs(int[][SIZE], int[][SIZE], vertex);

int deadEnd(vertex[]);

void dfsVisit(int[][SIZE], int[][SIZE], vertex);

void getAdjacentVertices(int[][SIZE], vertex[], vertex);

int isOutOfBounds(int idx);

void initVertices(vertex[]);

void printMazeWithVertex(int[][SIZE], vertex);

void createMazeFromFile(int[][SIZE], char *);

void convertArrayToMatrix(int[], int[][SIZE]);

void printMatrix(int[][SIZE]);

int main(int argc, char * argv[])
{
    int maze[SIZE][SIZE];
    static int visited[SIZE][SIZE];
    vertex v = { .x = 1, .y = 0 };
    createMazeFromFile(maze, argv[1]);
    dfsVisit(maze, visited, v);
    return 0;
}

void printMatrix(int m[][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {
            printf("%d ", m[i][j]);
        }

        printf("\n");
    }
}

void initVertices(vertex vertices[])
{
    int i;

    for (i = 0; i < 4; i++) {
        vertices[i].x = -1;
        vertices[i].y = -1;
    }
}

void getAdjacentVertices(int maze[][SIZE], vertex vertices[], vertex v)
{
    int i, j, x, y;
    static int offsets[4][2] = {
        {-1, 0},
        {0,  1},
        {1,  0},
        {0, -1},
    };

    for (i = 0, j = 0; i < 4; i++) {
        x = v.x + offsets[i][0];
        y = v.y + offsets[i][1];
        if (!isOutOfBounds(x) && !isOutOfBounds(y) && maze[x][y] != 1) {
            vertices[j].x = x;
            vertices[j].y = y;
            j++;
        }
    }
}

int isOutOfBounds(int idx)
{
    return idx < 0 || idx >= SIZE;
}

void dfs(int maze[][SIZE], int visited[][SIZE], vertex v)
{
    int i;
    vertex vertices[4];
    initVertices(vertices);
    getAdjacentVertices(maze, vertices, v);
    printMazeWithVertex(maze, v);
    for (i = 0; i < 4 && vertices[i].x != -1 && vertices[i].y != -1; i++) {
        if (visited[vertices[i].x][vertices[i].y] == 0) {
            dfs(maze, visited, vertices[i]);
        }
    }
}

void printMazeWithVertex(int maze[][SIZE], vertex v)
{
    int i, j;

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {

            if (v.x == i && v.y == j) {
                printf("o ");
            } else {
                printf("%c ", maze[i][j] == 1 ? '.' : ' ');
            }
        }

        printf("\n");
    }

    printf("\n");
}

void createMazeFromFile(int maze[][SIZE], char * filename)
{
    FILE * file = fopen(filename, "r");
    int k = 0, c, array[SIZE * SIZE];

    while ((c = fgetc(file)) != EOF) {

        if (c == '1' || c == '0') {
            array[k++] = c - '0';
        }
    }

    convertArrayToMatrix(array, maze);

    fclose(file);
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

void dfsVisit(int maze[][SIZE], int visited[][SIZE], vertex v)
{
    int i;
    vertex vertices[4];
    visited[v.x][v.y] = 1;
    initVertices(vertices);
    getAdjacentVertices(maze, vertices, v);
    printMazeWithVertex(maze, v);
    for (i = 0; i < 4 && (vertices[i].x != -1 && vertices[i].y != -1); i++) {
        if (visited[vertices[i].x][vertices[i].y] == 0) {
            visited[vertices[i].x][vertices[i].y] = 1;
            dfsVisit(maze, visited, vertices[i]);
        }
    }
}

int deadEnd(vertex vertices[])
{
    int i, count = 0;

    for (i = 0; i < 4; i++) {
        if (vertices[i].x == -1 && vertices[i].x == -1) {
            count++;
        }
    }

    return count == 4;
}
