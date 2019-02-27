#include "functions_to_calculate.h"
void multiplyArrays(double** tab1, double** tab2, double** K, int row1, int row2, int col1)
{
    double tmp=0;
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
        {
            K[i][j]=0;
            for(int k=0; k<row2; k++)
            {
                tmp +=tab1[i][k]*tab2[k][j];
            }
            K[i][j]=tmp;
            tmp=0;

        }
    }
}

void addArrays(double** tab1,double** tab2, double** K, int n, int m)
{

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            K[i][j]=tab1[i][j]+tab2[i][j];
        }
    }
}
void subtractArrays(double** tab1,double** tab2, double** K, int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            K[i][j]=tab1[i][j]-tab2[i][j];
        }
    }
}

int getValueOfCol(int colA, int colB, int colC, int colD, int colE, int colF, int colK, int colT, char character)
{
    int tmp;
    switch(character)
    {
    case 'A':
        tmp = colA;
        break;

    case 'B':
        tmp = colB;
        break;

    case 'C':
        tmp = colC;
        break;

    case 'D':
        tmp = colD;
        break;

    case 'E':
        tmp = colE;
        break;

    case 'F':
        tmp = colF;
        break;

    case 'R':
        tmp = colK;
        break;

    case 'T':
        tmp = colT;
        break;
    }
    return tmp;
}
int getValueOfRow(int rowA, int rowB, int rowC, int rowD, int rowE, int rowF, int rowK,int rowT, char character)
{
    int tmp;
    switch(character)
    {
    case 'A':
        tmp = rowA;
        break;

    case 'B':
        tmp = rowB;
        break;

    case 'C':
        tmp = rowC;
        break;

    case 'D':
        tmp = rowD;
        break;

    case 'E':
        tmp = rowE;
        break;

    case 'F':
        tmp = rowF;
        break;

    case 'R':
        tmp = rowK;
        break;

    case 'T':
        tmp = rowT;
        break;
    }
    return tmp;
}
void copyTable(struct tabStack *s, double** mainTab, int n, int m, char key)
{
    double** CopyTab;
    CopyTab=malloc(n*sizeof(double*));
    if(CopyTab==NULL)
    {
        printf("Błąd alokacji tablicy");
        return;
    }
    for(int i=0; i<n+1; ++i)
    {
        CopyTab[i] = malloc(m*sizeof(double));
        if(CopyTab[i]==NULL)
        {
            printf("Błąd alokacji tablicy");
            return;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            CopyTab[i][j]=mainTab[i][j];
        }
    }

    pushTab(s,key,CopyTab);
}
