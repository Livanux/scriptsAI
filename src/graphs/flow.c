#include <stdio.h>

#define SIZE 5

typedef struct {
    int x;
    int y;
} vertex;

void printBoard(int[][SIZE], vertex);

int dfs(int[][SIZE], int[][SIZE], vertex, vertex);

void getAdjacentVertices(int[][SIZE], vertex[], vertex, vertex);

int isOutOfBounds(int);

void initVertices(vertex[]);

void printMatrix(int[][SIZE]);

int isAdjacentPair(vertex[], vertex, vertex *);

int main()
{
    static int board[SIZE][SIZE] = {
        {1, 2, 0, 0, 0},
        {0, 0, 3, 4, 0},
        {1, 0, 2, 0, 0},
        {0, 0, 0, 0, 0},
        {4, 3, 0, 0, 0}
    }, visited[SIZE][SIZE];
    int result;
    vertex v = { .x = 0, .y = 1 }, y = { .x = 2, .y = 2 };
    result = dfs(board, visited, v, y);
    printMatrix(visited);
    printf("Result: %d\n", result);
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
                printf("%c ", board[i][j] == 0 ? ' ' : board[i][j] + '0');
            }
        }
        printf("\n");
    }
    printf("\n");
}

int dfs(int board[][SIZE], int visited[][SIZE], vertex from, vertex to)
{
    int i, x, y;
    vertex vertices[4];
    vertex pair;

    visited[from.x][from.y] = 1;

    printBoard(board, from);

    if (from.x == to.x && from.y == to.y) {
        return 1;
    }

    initVertices(vertices);
    getAdjacentVertices(board, vertices, from, to);

    if (isAdjacentPair(vertices, to, &pair)) {
        return dfs(board, visited, pair, to);
    }

    for (i = 0; i < 4 && vertices[i].x != -1 && vertices[i].y != -1; i++) {
        x = vertices[i].x;
        y = vertices[i].y;
        if (visited[x][y] != 1) {
            if (dfs(board, visited, vertices[i], to)) return 1;
        }
    }

    return 0;
}

void getAdjacentVertices(int board[][SIZE], vertex vertices[], vertex v, vertex to)
{
    int i, j, x, y;
    static int offsets[4][2] = {
        {-1, 0}, // ^
        {0,  1}, // >
        {1,  0}, // v
        {0, -1}, // <
    };

    for (i = 0, j = 0; i < 4; i++) {
        x = v.x + offsets[i][0];
        y = v.y + offsets[i][1];
        if (!isOutOfBounds(x) && !isOutOfBounds(y) && (board[x][y] == 0 || (to.x == x && to.y == y))) {
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

void printMatrix(int matrix[][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int isAdjacentPair(vertex vertices[], vertex v, vertex * pair)
{
    int i;

    for (i = 0; i < 4 && vertices[i].x != -1 && vertices[i].y != -1; i++) {

        if (vertices[i].x == v.x && vertices[i].y == v.y) {
            pair->x = vertices[i].x;
            pair->y = vertices[i].y;
            return 1;
        }
    }

    return 0;
}
