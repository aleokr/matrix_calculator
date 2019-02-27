#ifndef functions_to_calculate
#define functions_to_calculate
#include <stdio.h>
#include "calculator_stack.h"
#include "tab_stack.h"
void multiplyArrays(double** tab1, double** tab2, double** K, int row1, int row2, int col1);
void addArrays(double** tab1,double** tab2, double** K, int n, int m);
void subtractArrays(double** tab1,double** tab2, double** K, int n, int m);
int getValueOfCol(int colA, int colB, int colC, int colD, int colE, int colF, int colK,int colT, char character);
int getValueOfRow(int rowA, int rowB, int rowC, int rowD, int rowE, int rowF, int rowK,int colT, char character);

void copyTable(struct tabStack *s, double** mainTab, int n, int m, char key);
#endif
