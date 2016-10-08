
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

struct stack {
    int number;
    struct stack * next;
};

typedef struct stack STACK;
typedef STACK * stack;

void push(stack *, int);

int pop(stack *);

void printStack(stack *);

void removeAll(stack *);

int isEmpty(stack *);

#endif /* STACK_H */
