#include "tab_stack.h"

void pushTab(struct tabStack *s, char key, double** tab)
{

    if(s->size==0)
    {
        s->first = malloc(sizeof(struct tabElement));
        if(s->first==NULL)
        {
            printf("Błąd alokacji na stosie");
            exit(0);
        }
        s->first->key=key;
        s->first->tab=tab;
        s->first->next=NULL;
        s->size = s->size + 1;
        return;
    }

    struct tabElement *element=(s->first);
    while(element->next)
    {
        element=element->next;
    }

    struct tabElement *newEle = malloc(sizeof(struct tabElement));
    if(newEle==NULL)
    {
        printf("Błąd alokacji na stosie");
        exit(0);
    }

    newEle->key=key;
    newEle->tab=tab;
    newEle->next=NULL;
    element->next=newEle;

    s->size = s->size + 1;
}
double** getTab(struct tabStack *s, char key)
{

    if(s->first == NULL)
    {
        return NULL;

    }
    if(s->first->key==key)
    {
        return s->first->tab;
    }
    struct tabElement *element = s->first;
    while(element->next != NULL && element->key!=key)
    {
        element = element->next;
    }
    return element->tab;
}

void popTab(struct tabStack *s, char key)
{
    if(s->first == NULL)
    {
        return;

    }
    struct tabElement *curr = s->first;
    if(s->first->key==key)
    {
        s->first = s->first->next;
        free(curr);
        return;
    }


    while(curr->next)
    {
        if(curr->next->key == key)
        {
            {
                struct tabElement *newCurr = curr->next->next;

                free(curr->next);
                curr->next = newCurr;
                return;
            }
        }
        curr = curr->next;

    }
}

void clearTab(struct tabStack *s)
{

    struct tabElement *element = s->first->next;
    free(s->first);
    s->first=NULL;
    struct tabElement *last = s->first;
    struct tabElement *newLast = s->first;

    while(element->next)
    {
        newLast=element->next;
        free(element);
        element=NULL;
        element=newLast;
    }

}
