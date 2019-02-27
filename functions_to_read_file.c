#include "functions_to_read_file.h"
int getCounter()
{
    return count;
}

int getCol(FILE *file)
{
    int m=0;
    char character;
    while(character!=';')
    {
        character = getc(file);
        if(character==' ')
        {
            m++;
        }
    }
    return m;
}
int getRow(FILE *file)
{
    int n=0;
    char character;
    while(character!=']')
    {
        character = getc(file);
        if(character==';')
        {
            n++;
        }

    }
    ++n;
    return n;
}
void readTabs(FILE * file,  double **tab)
{

    char character;
    int end=1;
    int newLine=1;
    character = getc(file);
    ++count;
    if(character=='[')
    {
        int n=0;
        int m=0;
        int factor = 1;
        double tmp=0;
        double main_number=0;
        int ten =1;
        int comma=0;
        while(end!=0)
        {
            m=0;
            while(newLine!=0)
            {
                character = getc(file);
                if(character == '-' )
                {
                    factor = -1;
                }
                else if(character == ' ' || character == ';' || character == ']')
                {
                    factor = factor;
                }
                ++count;

                if(character==' ')
                {
                    if(comma==1)
                    {
                        tab[n][m]=(main_number+tmp/ten);
                        ten=1;
                        tmp=0;
                        comma=0;
                        main_number=0;
                    }
                    else
                    {
                        tab[n][m]=factor*tmp;
                        ten=1;
                        tmp=0;
                        factor = 1;
                    }

                    ++m;
                }

                else if(character==';')
                {

                    if(comma==1)
                    {
                        tab[n][m]=(main_number+tmp/ten);
                        ten=1;
                        tmp=0;
                        comma=0;
                        main_number=0;
                    }
                    else
                    {
                        tab[n][m]=factor*tmp;
                        ten=1;
                        tmp=0;
                        factor = 1;
                    }
                    newLine=0;

                }
                else if(character==']')
                {
                    if(comma==1)
                    {
                        tab[n][m]=(main_number+tmp/ten);
                        ten=1;
                        tmp=0;
                        comma=0;
                        main_number=0;
                    }
                    else
                    {
                        tab[n][m]=factor*tmp;
                        ten=1;
                        tmp=0;
                        factor = 1;
                    }
                    newLine=0;
                    end=0;
                }

                else if(((int)character>=48 &&(int)character<=57))
                {
                    tmp=tmp*10+((int)character-48);
                    ten*=10;
                    newLine =1;
                }
                else if((int)character==46 && comma==0)
                {
                    main_number=tmp;
                    ten=1;
                    tmp=0;
                    comma=1;
                }
                else if(character=='.' && comma==1)
                {
                    printf("\nMacierz zawiera niedozwolone wartości\n");
                    exit(0);
                }
                else if(character != '-')
                {
                    printf("\nMacierz jest zawiera niedozwolone wartości\n");
                    exit(0);

                }

            }
            ++n;
            newLine=1;

        }
    }


}
void readONP(FILE * file, struct Stack *s)
{
    struct Stack *helpStack=malloc(sizeof(struct Stack));
    if(helpStack==NULL)
    {
        printf("Błąd alokacji stosu");
        return;
    }
    helpStack->first = NULL;
    helpStack->size = 0;
    char character;
    char tmp;
    char add;
    character = getc(file);
    while(character!='_')
    {
        switch (character)
        {
        case '(':
            push(helpStack,character);
            break;
        case ')':
            tmp=showLastElement(helpStack);
            while(sizeOfStack(helpStack)!=0 && tmp!='(')
            {
                add=pop(helpStack);
                push(s,add);
                tmp=showLastElement(helpStack);

            }
            break;
        case '+':
        case '-':
            tmp=showLastElement(helpStack);
            while (sizeOfStack(helpStack)!=0  && tmp!='(')
            {

                add=pop(helpStack);
                push(s,add);
                tmp=add;

            }
            push(helpStack,character);

            break;
        case '*':
            tmp=showLastElement(helpStack);
            while (sizeOfStack(helpStack)!=0  && tmp!='+' && tmp!= '-')
            {
                if(tmp=='(')
                {
                    pop(helpStack);
                }
                else
                {
                    add=pop(helpStack);
                    push(s,add);
                }
                tmp=showLastElement(helpStack);
            }
            push(helpStack,character);
            break;
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
            push(s,character);
            break;
        default:
            printf("Błąd składni wyrażenia");
            exit(0);

        }
        character = getc(file);
    }
    tmp=showLastElement(helpStack);
    while (sizeOfStack(helpStack)!=0  && tmp!='(')
    {
        add=pop(helpStack);
        push(s,add);
        tmp=showLastElement(helpStack);
    }
    free(helpStack);
}

