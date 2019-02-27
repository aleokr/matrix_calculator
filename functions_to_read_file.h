#ifndef functions_to_read_file
#define functions_to_read_file
#include <stdio.h>
#include "calculator_stack.h"
#include <stdlib.h>
#include <string.h>
static int count=0;
int getCounter();
int getRow(FILE *file);
int getCol(FILE *file);
void readTabs(FILE * file, double **tab);
void readONP(FILE * file, struct Stack *s);
#endif
