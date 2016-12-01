
#include "stack.h"

void push(stack * stk, int x, int y)
{
    stack new;
    new = (stack) malloc(sizeof(STACK));
    new->x = x;
    new->y = y;
    new->next = *stk;
    *stk = new;
}

int pop(stack * stk)
{
    stack temp = *stk;
    int number;

    number = (*stk)->number;
    *stk = (*stk)->next;
    free(temp);

    return number;
}

void printStack(stack * stk)
{
    stack curr = *stk;

    while (curr != NULL) {
        printf("@%p [number: %d| next: %p] -> ", curr, curr->number, curr->next);
        curr = curr->next;
    }

    printf("\n");
}

void removeAll(stack * stk)
{
    stack temp;
    while (*stk != NULL) {
        temp = *stk;
        *stk = (*stk)->next;
        free(temp);
    }
}

int isEmpty(stack * stk)
{
    return *stk == NULL;
}
