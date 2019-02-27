#include "functions_to_calculate.h"
#include "calculator_stack.h"
#include "tab_stack.h"
#include "functions_to_read_file.h"



int main(int argc, char* argv1[], char* argv2[])
{
    if(argc!=3)
    {
        fputs("Proszę podać 2 argumenty wywołania\n",stderr);
        return 1;
        
        
    }
    FILE* fileToRead = fopen(argv1[1], "r");
    if(!fileToRead)
    {
        fputs("Błąd otwarcia pliku do odczytu\n", stderr);
        return 1;
    }
    FILE* fileToWrite = fopen(argv1[2], "w");
    if(!fileToWrite)
    {
        fputs("Błąd w pliku do zapisu\n", stderr);
        return 1;
    }

    struct Stack *stack=malloc(sizeof(struct Stack));
    if(stack==NULL)
    {
        printf("Błąd alokacji stosu");
        return 1;
    }
    stack->first = NULL;
    stack->size = 0;
    struct tabStack *stackTab=malloc(sizeof(struct tabStack));
    if(stackTab==NULL)
    {
        printf("Błąd alokacji stosu");
        return 1;
    }
    stackTab->first=NULL;
    stackTab->size=0;
    double** A;
    int n_a=0;
    int m_a=0;

    double** B;
    int n_b=0;
    int m_b=0;

    double** C;
    int n_c=0;
    int m_c=0;

    double** D;
    int n_d=0;
    int m_d=0;

    double** E;
    int n_e=0;
    int m_e=0;

    double** F;
    int n_f=0;
    int m_f=0;

    char whichTab1=' ';
    char whichTab2=' ';
    char whichTab3=' ';
    char operator;
    int n_k=0;
    int m_k=0;
    int n_t=0;
    int m_t=0;
    int tmp_m1=0;
    int tmp_n1=0;
    int tmp_m2=0;
    int tmp_n2=0;

    int pos = 0;
    char character = getc(fileToRead);
    if(character=='[')
    {
        fseek(fileToRead, 0, SEEK_SET);
        n_a=getRow(fileToRead);
        fseek(fileToRead, 0, SEEK_SET);
        m_a=getCol(fileToRead);
        A = malloc((n_a+1)* sizeof( double* ) );
        if(A==NULL)
        {
            printf("Błąd alokacji tablicy");
            return 1;
        }
        for(int i=0; i<n_a+1; i++)
        {
            A[i] = malloc(m_a*sizeof(double));
            if(A[i]==NULL)
            {
                printf("Błąd alokacji tablicy");
                return 1;
            }
        }
        fseek(fileToRead, 0, SEEK_SET);
        readTabs(fileToRead, A);
        pushTab(stackTab, 'A', A);
    }

    pos=getCounter()+1;
    fseek(fileToRead,pos-1, SEEK_SET);
    character = getc(fileToRead);
    if(character=='[')
    {
        n_b = 0;
        m_b = 0;
        fseek(fileToRead,pos, SEEK_SET);
        n_b=getRow(fileToRead);
        fseek(fileToRead, pos, SEEK_SET);
        m_b=getCol(fileToRead);
        B=malloc((n_b+1)*sizeof(double*));
        if(B==NULL)
        {
            printf("Błąd alokacji tablicy");
            return 1;
        }
        for(int i=0; i<n_b+1; ++i)
        {
            B[i] = malloc(m_b*sizeof(double));
            if(B[i]==NULL)
            {
                printf("Błąd alokacji tablicy");
                return 1;
            }
        }
        fseek(fileToRead, pos-1, SEEK_SET);
        readTabs(fileToRead, B);
        pushTab(stackTab, 'B', B);
    }
    pos=getCounter()+1;
    fseek(fileToRead,pos-1, SEEK_SET);
    character = getc(fileToRead);
    if(character=='[')
    {
        n_c = 0;
        m_c = 0;
        fseek(fileToRead,pos, SEEK_SET);
        n_c=getRow(fileToRead);
        fseek(fileToRead, pos, SEEK_SET);
        m_c=getCol(fileToRead);
        C = malloc( (n_c+1) * sizeof( double* ) );
        if(C==NULL)
        {
            printf("Błąd alokacji tablicy");
            return 1;
        }
        for(int i=0; i<n_c+1; i++)
        {
            C[i] =malloc(m_c*sizeof(double));
            if(C[i]==NULL)
            {
                printf("Błąd alokacji tablicy");
                return 1;
            }
        }
        fseek(fileToRead, pos-1, SEEK_SET);
        readTabs(fileToRead, C);
        pushTab(stackTab, 'C', C);
    }
    pos=getCounter()+1;
    fseek(fileToRead,pos-1, SEEK_SET);
    character = getc(fileToRead);

    if(character=='[')
    {
        n_d = 0;
        m_d = 0;
        fseek(fileToRead,pos, SEEK_SET);
        n_d=getRow(fileToRead);
        fseek(fileToRead, pos, SEEK_SET);
        m_d=getCol(fileToRead);
        D=malloc((n_d+1)*sizeof(double*));
        if(D==NULL)
        {
            printf("Błąd alokacji tablicy");
            return 1;
        }

        for(int i=0; i<n_d+1; ++i)
        {
            D[i] = malloc(m_d*sizeof(double));
            if(D[i]==NULL)
            {
                printf("Błąd alokacji tablicy");
                return 1;
            }
        }
        fseek(fileToRead, pos-1, SEEK_SET);
        readTabs(fileToRead, D);
        pushTab(stackTab, 'D', D);
    }
    pos=getCounter()+1;
    fseek(fileToRead,pos-1, SEEK_SET);
    character = getc(fileToRead);

    if(character=='[')
    {
        n_e = 0;
        m_e = 0;
        fseek(fileToRead,pos, SEEK_SET);
        n_e=getRow(fileToRead);
        fseek(fileToRead, pos, SEEK_SET);
        m_e=getCol(fileToRead);
        E=malloc((n_e+1)*sizeof(double*));
        if(E==NULL)
        {
            printf("Błąd alokacji tablicy");
            return 1;
        }
        for(int i=0; i<n_e+1; ++i)
        {
            E[i] = malloc(m_e*sizeof(double));
            if(E[i]==NULL)
            {
                printf("Błąd alokacji tablicy");
                return 1;
            }
        }
        fseek(fileToRead, pos-1, SEEK_SET);
        readTabs(fileToRead, E);
        pushTab(stackTab, 'E', E);
    }
    pos=getCounter()+1;
    fseek(fileToRead,pos-1, SEEK_SET);
    character = getc(fileToRead);

    if(character=='[')
    {
        n_f = 0;
        m_f = 0;
        fseek(fileToRead,pos, SEEK_SET);
        n_f=getRow(fileToRead);
        fseek(fileToRead, pos, SEEK_SET);
        m_f=getCol(fileToRead);
        F = malloc( (n_f+1) * sizeof( double* ) );
        if(F==NULL)
        {
            printf("Błąd alokacji tablicy");
            return 1;
        }
        for(int i=0; i<n_f+1; i++)
        {
            F[i] = malloc(m_f*sizeof(double*));
            if(F[i]==NULL)
            {
                printf("Błąd alokacji tablicy");
                return 1;
            }
        }
        fseek(fileToRead, pos-1, SEEK_SET);
        readTabs(fileToRead, F);
        pushTab(stackTab, 'F', F);
    }
    pos=getCounter()+1;
    fseek(fileToRead,pos-1, SEEK_SET);
    character = getc(fileToRead);
    if(character==';')
    {
        readONP(fileToRead, stack);
        character = ' ';
    }
    // Obliczanie wartości wyrażenia

    //zapis do pliku
    fprintf(fileToWrite, "Wyrażenie zapisane za pomocą Odwrotnej Notacji Polskiej:\n");
    showStackInFile(stack,fileToWrite);
    struct Stack *stackToCalculate=malloc(sizeof(struct Stack));
    if(stackToCalculate==NULL)
    {
        printf("Błąd alokacji stosu");
        return 1;
    }
    stackToCalculate->first = NULL;
    stackToCalculate->size = 0;
    char tmp;
    while(stack->size!=0)
    {
        tmp=pop(stack);
        push(stackToCalculate,tmp);
    }
    while(stackToCalculate->size>2)
    {
        whichTab1=pop(stackToCalculate);
        whichTab2=pop(stackToCalculate);

        whichTab3=pop(stackToCalculate);

        if(whichTab3=='+' || whichTab3=='-' || whichTab3=='*')
        {
            operator=whichTab3;
            whichTab3 =' ';
        }
        else
        {

            operator=pop(stackToCalculate);
            char tmp=whichTab1;
            whichTab1=whichTab2;
            whichTab2=whichTab3;
            whichTab3=tmp;
            printf("\nT: %c\n",whichTab3);
            n_t=getValueOfRow(n_a, n_b,n_c,n_d,n_e,n_f,n_k,n_t,whichTab3);
            m_t=getValueOfCol(m_a, m_b,m_c,m_d,m_e,m_f,m_k,m_t,whichTab3);

            popTab(stackTab, 'T');
            pushTab(stackTab,'T',getTab(stackTab,whichTab3));


        }
        double** tmpResult;

        if(operator=='+')
        {
            tmp_n1=getValueOfRow(n_a, n_b,n_c,n_d,n_e,n_f,n_k,n_t,whichTab1);
            tmp_n2=getValueOfRow(n_a, n_b,n_c,n_d,n_e,n_f,n_k,n_t,whichTab2);
            tmp_m1=getValueOfCol(m_a, m_b,m_c,m_d,m_e,m_f,m_k,m_t,whichTab1);
            tmp_m2=getValueOfCol(m_a, m_b,m_c,m_d,m_e,m_f,m_k,m_t,whichTab2);

            if(tmp_n1==tmp_n2 && tmp_m1==tmp_m2)
            {
                tmpResult = malloc( (tmp_n1+1) * sizeof( double* ) );
                if(tmpResult==NULL)
                {
                    printf("Błąd alokacji tablicy");
                    return 1;
                }
                for(int i=0; i<tmp_n1+1; i++)
                {
                    tmpResult[i] =malloc(tmp_m1*sizeof(double));
                    if(tmpResult[i]==NULL)
                    {
                        printf("Błąd alokacji tablicy");
                        return 1;
                    }
                }
                addArrays(getTab(stackTab,whichTab1), getTab(stackTab,whichTab2), tmpResult, tmp_n1, tmp_m1);
                push(stackToCalculate, 'R');
                if(whichTab3!=' ')
                {
                    push(stackToCalculate, 'T');
                    popTab(stackTab, 'T');
                    pushTab(stackTab,'T',getTab(stackTab,whichTab3));
                }
                popTab(stackTab, 'R');
                copyTable(stackTab,tmpResult, tmp_n1, tmp_m1, 'R');
                n_k=tmp_n1;
                m_k=tmp_m1;
            }
            else
            {
                printf("Nie można dodać macierzy");
                return 1;
            }
        }
        else if(operator=='-')
        {
            tmp_n1=getValueOfRow(n_a, n_b,n_c,n_d,n_e,n_f,n_k,n_t,whichTab1);
            tmp_n2=getValueOfRow(n_a, n_b,n_c,n_d,n_e,n_f,n_k,n_t,whichTab2);
            tmp_m1=getValueOfCol(m_a, m_b,m_c,m_d,m_e,m_f,m_k,m_t,whichTab1);
            tmp_m2=getValueOfCol(m_a, m_b,m_c,m_d,m_e,m_f,m_k,m_t,whichTab2);

            if(tmp_n1==tmp_n2 && tmp_m1==tmp_m2)
            {
                tmpResult = malloc( (tmp_n1 +1)* sizeof( double* ) );
                if(tmpResult==NULL)
                {
                    printf("Błąd alokacji tablicy");
                    return 1;
                }
                for(int i=0; i<tmp_n1+1; i++)
                {
                    tmpResult[i] =malloc(tmp_m1*sizeof(double));
                    if(tmpResult[i]==NULL)
                    {
                        printf("Błąd alokacji tablicy");
                        return 1;
                    }
                }
                subtractArrays(getTab(stackTab,whichTab1), getTab(stackTab,whichTab2), tmpResult, tmp_n1, tmp_m1);
                push(stackToCalculate, 'R');
                if(whichTab3!=' ')
                {
                    push(stackToCalculate, 'T');
                    popTab(stackTab, 'T');
                    pushTab(stackTab,'T',getTab(stackTab,whichTab3));
                }
                popTab(stackTab, 'R');
                copyTable(stackTab,tmpResult, tmp_n1, tmp_m1, 'R');
                n_k=tmp_n1;
                m_k=tmp_m1;
            }
            else
            {
                printf("Nie można odjąć macierzy");
                return 1;
            }
        }
        else if(operator=='*')
        {
            tmp_n1=getValueOfRow(n_a, n_b,n_c,n_d,n_e,n_f,n_k,n_t,whichTab1);
            tmp_n2=getValueOfRow(n_a, n_b,n_c,n_d,n_e,n_f,n_k,n_t,whichTab2);
            tmp_m1=getValueOfCol(m_a, m_b,m_c,m_d,m_e,m_f,m_k,m_t,whichTab1);
            tmp_m2=getValueOfCol(m_a, m_b,m_c,m_d,m_e,m_f,m_k,m_t,whichTab2);

            if(tmp_m1==tmp_n2)
            {
                tmpResult = malloc( (tmp_n1+1) * sizeof( double* ) );
                if(tmpResult==NULL)
                {
                    printf("Błąd alokacji tablicy");
                    return 1;
                }
                for(int i=0; i<tmp_n1+1; i++)
                {
                    tmpResult[i] =malloc(tmp_m2*sizeof(double));

                    if(tmpResult[i]==NULL)
                    {
                        printf("Błąd alokacji tablicy");
                        return 1;
                    }
                }
                multiplyArrays(getTab(stackTab,whichTab1), getTab(stackTab,whichTab2), tmpResult, tmp_n1, tmp_n2, tmp_m2);
                push(stackToCalculate, 'R');
                if(whichTab3!=' ')
                {
                    push(stackToCalculate, 'T');
                    popTab(stackTab, 'T');
                    pushTab(stackTab,'T',getTab(stackTab,whichTab3));
                }
                popTab(stackTab, 'R');
                copyTable(stackTab,tmpResult, tmp_n1, tmp_m2, 'R');
                n_k=tmp_n1;
                m_k=tmp_m2;
            }
            else
            {
                printf("Nie można pomnożyć macierzy");
                return 1;
            }
            free(tmpResult);
            tmpResult=NULL;
        }
        fprintf(fileToWrite, "\n");
        fprintf(fileToWrite, "Obliczona tablica:\n");
        tmpResult=getTab(stackTab,'K');
        for(int i=0; i<n_k; i++)
        {
            for(int j=0; j<m_k; j++)
            {
                fprintf(fileToWrite, "%lf", tmpResult[i][j]);
            }
            fprintf(fileToWrite, "\n");
        }

        whichTab1=' ';
        whichTab2=' ';
        whichTab3=' ';
        operator=' ';

    }
 /*   if(A!=NULL)
    {
        free(A);
        A=NULL;
    }


    if(B!=NULL)
    {
        free(B);
        B=NULL;
    }
    if(C!=NULL)
    {
        free(C);
        C=NULL;
    }
    if(D!=NULL)
    {
        free(D);
        D=NULL;
    }
    if(E!=NULL)
    {
        free(E);
        E=NULL;
    }
    if(F!=NULL)
    {
        free(F);
        F=NULL;
    }
    if(stackTab!=NULL)
    {
        clearTab(stackTab);
        stackTab=NULL;
    }
    if(stackToCalculate!=NULL)
    {
        pop(stackToCalculate);
        free(stackToCalculate);
        stackToCalculate=NULL;
    }
    if(stackTab!=NULL)
    {
        free(stackTab);
        stackTab=NULL;
    }
    if(stack!=NULL)
    {
        free(stack);
        stack=NULL;
    }


*/

    fclose(fileToRead);
    fclose(fileToWrite);
    return 0;
}
