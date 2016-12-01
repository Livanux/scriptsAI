#include <stdio.h>

#define SIZE 5

typedef struct {
    int x;
    int y;
} vertex;

void printBoard(int[][SIZE], vertex);

int dfs(int[][SIZE], int[][SIZE], vertex);

void getAdjacentVertices(int[][SIZE], vertex[], vertex);

int isOutOfBounds(int);

void printVertices(vertex[]);

void initVertices(vertex[]);

int main()
{
    static int board[SIZE][SIZE] = {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    }, visited[SIZE][SIZE];
    vertex v = { .x = 1, .y = 0 };
    dfs(board, visited, v);
    return 0;
}

void initVertices(vertex vertices[])
{
    int i;

    for (i = 0; i < 4; i++) {
        vertices[i].x = -1;
        vertices[i].y = -1;
    }
}

void printBoard(int board[][SIZE], vertex v)
{
    int i, j;

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {

            if (v.x == i && v.y == j) {
                printf("* ");
            } else {
                printf("%c ", board[i][j] == 1 ? '#' : ' ');
            }
        }
        printf("\n");
    }
    printf("\n");
}

int dfs(int board[][SIZE], int visited[][SIZE], vertex v)
{
    int i, x, y;
    vertex vertices[4];
    visited[v.x][v.y] = 1;

    printBoard(board, v);

    if (v.x == 1 && v.y == 4) {
        return 1;
    }

    initVertices(vertices);
    getAdjacentVertices(board, vertices, v);
    for (i = 0; i < 4 && vertices[i].x != -1 && vertices[i].y != -1; i++) {
        x = vertices[i].x;
        y = vertices[i].y;
        if (visited[x][y] != 1) {
            if (dfs(board, visited, vertices[i])) return 1;
        }
    }

    return 0;
}

void getAdjacentVertices(int board[][SIZE], vertex vertices[], vertex v)
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
        if (!isOutOfBounds(x) && !isOutOfBounds(y) && board[x][y] != 1) {
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
