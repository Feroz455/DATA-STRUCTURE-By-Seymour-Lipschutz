/*
Redo Supplementary Problems 5.16–5.20 using a header circular list 
rather than an ordinary one-way list. (Observe that the algorithms are now much simpler.)
*/
#include<iomanip>
#include<iostream>
#include<time.h>
using namespace std;
typedef struct _link
{
    int DATA;
    _link *next;
    _link *prev;
}LINKED;
void INSERT_END(LINKED **START, int DATA)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->DATA = DATA;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->DATA = DATA;

        NEW->next = (*START);
        NEW->prev = LAST;
        (*START)->prev = NEW;
        LAST->next = NEW;
    }   
}
void DISPLAY_FORWORD( LINKED **START)
{
    if((*START) == NULL)
    {
        cout << "LIST IS EMPTY\n";
        return;
    }
    LINKED *PTR = (*START);
    while (PTR->next != *START)
    {
        cout << PTR->DATA << " -> ";
        PTR = PTR->next;
    }
    cout << PTR->DATA << "\n"; 
}
void DELETE_ALL(LINKED **START)
{
    LINKED *PTR = (*START)->prev, *PP;
    while (PTR->prev != (*START))
    {
        PP = PTR;
        PTR = PTR->prev;
        delete PP;
    }
     *START = NULL;
}
void DELETE_FIRST_LINK(LINKED **START)
{
    if((*START) == NULL)
    {
        return;
    }
    if((*START)->next == (*START))
    {
        delete (*START);
        (*START) = NULL;
        return;
    }
    LINKED *PTR = (*START);
    (*START)->prev->next = (*START)->next;
    (*START)= (*START)->next;
    (*START)->prev = PTR->prev;
    delete PTR;
}
void DELETE_LAST_LINK(LINKED **START)
{
    if((*START) == NULL)
    {
        return;
    }
    if((*START)->next == (*START))
    {
        delete (*START);
        (*START) = NULL;
        return;
    }
    LINKED *PTR = (*START)->prev, *PP;
    PP = (*START)->prev->prev;
    PP->next = (*START);
    (*START)->prev = PP;
    delete PTR;
}
void DELETE_ITEM(LINKED **START, int DATA)
{
    LINKED *PTR = (*START);
    if(PTR->DATA == DATA)
    {
        DELETE_FIRST_LINK(START);
    }
    else 
    if(PTR->prev->DATA == DATA)
    {
        DELETE_LAST_LINK(START);
    }
    else 
    {
        while(PTR->next != (*START) && PTR->DATA != DATA)
        {
            PTR = PTR->next;
        }
        if(PTR->next == (*START))
        {
            return;
        }
        PTR->next->prev = PTR->prev;
        PTR->prev->next = PTR->next;
    }
}
void DELETE_ON_LOCATION(LINKED **START, int DATA)
{
    DATA = DATA - 1;
    LINKED *PTR = (*START);
    if(DATA == 0)
    {
        DELETE_FIRST_LINK(START);
    }
    else 
    {
        while(DATA-- != 0 && PTR->next != *START)
        {
            PTR = PTR->next;
        }
        if(PTR->next == (*START))
        {
            if(DATA == 1)
            DELETE_LAST_LINK(START);
            else
            cout << "\nLOCATION DAES NOT EXISTED\n";
            return;
        }
        PTR->next->prev = PTR->prev;
        PTR->prev->next = PTR->next;
    }
}
void SWAP(LINKED *FIRST, LINKED *SECOND)
{
    int TEMP = FIRST->DATA;
    FIRST->DATA = SECOND->DATA;
    SECOND->DATA = TEMP;
}
void BUBBLE_SORT(LINKED *START)
{
    int SWAPPED, i;
    LINKED *PTR, *LAST = START;
    if(START == NULL)
    {
        return;
    }
    do
    {
        SWAPPED = 0;
        PTR = START;
        while(PTR->next != LAST)
        {
            if(PTR->DATA > PTR->next->DATA)
            {
                SWAP(PTR, PTR->next);
                SWAPPED = 1;
            }
            PTR = PTR->next;
        }
        LAST = PTR;
    }while (SWAPPED);

}
int main()
{
    LINKED *START = NULL;
    
}