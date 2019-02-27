#ifndef _stack_
#define _stack_
#include <stdlib.h>
#include <stdio.h>
struct Stack
{
    struct Element *first;
    int size;
};
struct Element
{
    char character;
    struct Element *next;
};
void push(struct Stack *s, char character);
char pop(struct Stack *s);
int sizeOfStack(struct Stack *s);
char showLastElement(struct Stack *s);
void showStackInFile(struct Stack *s, FILE *file);
void showStack(struct Stack *s);

#endif
