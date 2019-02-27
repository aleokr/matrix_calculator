#include "calculator_stack.h"

void push(struct Stack *s, char character)
{

    if(s->size==0)
    {
        s->first = malloc(sizeof(struct Element));
        if(s->first==NULL)
        {
            printf("Błąd alokacji na stosie");
            return;
        }
        s->first->character=character;
        s->first->next=NULL;
        s->size = s->size + 1;
        return;
    }

    struct Element *element=(s->first);
    while(element->next)
    {
        element=element->next;
    }

    struct Element *newEle = malloc(sizeof(struct Element));
    if(newEle==NULL)
    {
        printf("Błąd alokacji na stosie");
        return;
    }

    newEle->character=character;
    newEle->next=NULL;
    element->next=newEle;

    s->size = s->size + 1;
}

char pop(struct Stack *s)
{
    char tmp='q';
    if(s->size==0)
    {
        printf("Lista jest pusta!!!");
        return tmp;
    }

    if(s->size == 1)
    {
        free(s->first->next);
        tmp = s->first->character;
        s->first = NULL;
        s->size = s->size - 1;
        return tmp;

    }
    struct Element *last = s->first;
    while(last->next != NULL)
    {
        last = last->next;
    }
    struct Element *newLast = s->first;
    while(newLast->next != last)
    {
        newLast = newLast->next;
    }
    tmp = last->character;
    free(last->next);
    last = NULL;
    newLast->next = last;
    s->size = s->size - 1;

    return tmp;

}
int sizeOfStack(struct Stack *s )
{
    int tmp=0;
    struct Element *element=s->first;
    while(element->next!=NULL)
    {
        element=element->next;
        ++tmp;
    }
    return tmp;
}
char showLastElement(struct Stack *s )
{
    char tmp;
    struct Element *element=s->first;
    while(element->next!=NULL)
    {
        element=element->next;

    }
    tmp=element->character;
    return tmp;
}
void showStackInFile(struct Stack *s, FILE *file)
{
    if(s->first == NULL)
        return;
    struct Element *element=s->first;
    while(element->next!=NULL)
    {
        fprintf(file, "%c",element->character);
        element=element->next;
    }
    fprintf(file, "%c",element->character);
}
void showStack(struct Stack *s)
{
    if(s->first == NULL)
        return;
    struct Element *element=s->first;
    while(element->next!=NULL)
    {
        printf("%c",element->character);
        element=element->next;
    }
    printf("%c",element->character);
}
