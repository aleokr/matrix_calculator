#ifndef _tab_stack_
#define _tab_stack_
#include <stdlib.h>
#include <stdio.h>
struct tabStack
{
    struct tabElement *first;
    int size;
};
struct tabElement
{
    char key;
    double** tab;
    struct tabElement *next;
};
void popTab(struct tabStack *s, char key);
void pushTab(struct tabStack *s, char key, double** tab);
double** getTab(struct tabStack *s, char key);
void clearTab(struct tabStack *s);

#endif
