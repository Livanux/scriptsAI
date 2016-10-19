
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 9
#define WIN_ROWS 8
#define WIN_COLUMNS 3
#define COULD_ROWS 18
#define COULD_COLUMNS 2
#define O 1
#define X 2
#define E 0

#define token(T) T - 1

static const int winPattern[WIN_ROWS][WIN_COLUMNS] = {
    {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7},
    {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}
};

static const int couldPattern[COULD_ROWS][COULD_COLUMNS + 1] = {
    {1, 2, 3}, {1, 5, 9}, {1, 4, 7}, {1, 3, 2}, {1, 9, 5}, {1, 7, 4},
    {2, 3, 1}, {2, 5, 8}, {2, 8, 5}, {3, 6, 9}, {3, 9, 6}, {4, 7, 1},
    {4, 5, 6}, {4, 6, 5}, {7, 8, 9}, {7, 9, 8}, {5, 6, 4}, {8, 9, 7},
};

void printBoard(int[]);

void putToken(int[], int, int);

int isSlotEmpty(int[], int);

int isBoardFilled(int[]);

int isWinner(int[], int);

int isGameOver(int[]);

void computeSlot(int[], int *);

int couldWin(int[], int, int[]);

int main()
{
    int board[BOARD_SIZE] = {
        E, E, E,
        E, E, E,
        E, E, E
    }, slot;

    srand(time(NULL));

    while (1) {

        if (isGameOver(board)) {
            break;
        }

        do {
            printf("Player O turn: \n");
            scanf("%d", &slot);
        } while (!isSlotEmpty(board, slot));
        putToken(board, slot, O);
        printBoard(board);

        if (isGameOver(board)) {
            break;
        }

        do {
            printf("Player X turn: \n");
            computeSlot(board, &slot);
            printf("%d\n", slot);
        } while (!isSlotEmpty(board, slot));
        putToken(board, slot, X);
        printBoard(board);
    }

    return 0;
}

void printBoard(int board[])
{
    int i, j;

    for (i = 0, j = 2; i < BOARD_SIZE; i++) {
        printf("%c ", (board[i] == O) ? 'o' : ((board[i] == X) ? 'x' : '-'));
        if (i == j) {
            printf("\n");
            j += 3;
        }
    }
}

void putToken(int board[], int pos, int token)
{
    board[token(pos)] = token;
}

int isSlotEmpty(int board[], int pos)
{
    return board[token(pos)] == E;
}

int isBoardFilled(int board[])
{
    int i;

    for (i = 0; i < BOARD_SIZE; i++) {

        if (board[i] == E) {
            return 0;
        }
    }

    return 1;
}

int isWinner(int board[], int token)
{
    int i, j, matchCount;

    for (i = 0; i < WIN_ROWS; i++) {

        for (j = 0, matchCount = 0; j < WIN_COLUMNS; j++) {

            if (board[token(winPattern[i][j])] == token) {
                matchCount++;
            } else {
                break;
            }
        }

        if (matchCount == 3) {
            return 1;
        }
    }

    return 0;
}

int isGameOver(int board[])
{
    return isBoardFilled(board) || (isWinner(board, O) || isWinner(board, X));
}

void computeSlot(int board[], int * slot)
{
    int corners[4] = {1, 3, 7, 9}, matchedPattern[COULD_COLUMNS + 1];

    if (isSlotEmpty(board, 5)) {
        *slot = 5;
    } else if (couldWin(board, X, matchedPattern)) {
        *slot = matchedPattern[2];
    } else if (couldWin(board, O, matchedPattern)) {
        *slot = matchedPattern[2];
    } else {
        *slot = corners[rand() % 4];
    }
}

int couldWin(int board[], int token, int matchedPattern[])
{
    int i, j, matchCount;

    for (i = 0; i < COULD_ROWS; i++) {

        for (j = 0, matchCount = 0; j < COULD_COLUMNS; j++) {

            if (board[token(couldPattern[i][j])] == token) {
                matchCount++;
            } else {
                break;
            }
        }

        if (matchCount == 2) {
            memcpy(matchedPattern, couldPattern[i], (COULD_COLUMNS + 1) * sizeof(int));
            if (isSlotEmpty(board, matchedPattern[2])) {
                return 1;
            }
        }
    }

    return 0;
}
