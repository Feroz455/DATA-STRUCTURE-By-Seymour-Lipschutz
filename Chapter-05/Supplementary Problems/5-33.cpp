/*
page 161
 Given an integer K, write a procedure

DELK(INFO, FORW, BACK, START, AVAIL, K)

which deletes the Kth element from a two-way circular header list.
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include<cmath>
using namespace std;
typedef struct _link
{
    int DATA;
    _link *next;
    _link *prev;
}LINKED;
void INSERT_BEGIN(LINKED **START, int DATA)
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

        LINKED *NEW_LINK = new LINKED;
        NEW_LINK->DATA = DATA;

        NEW_LINK->next = *START;
        NEW_LINK->prev = LAST;

        LAST->next = (*START)->prev = NEW_LINK;
        *START = NEW_LINK;
    }
}
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
void DISPLAY(LINKED *HEAD)
{
    LINKED *PTR = HEAD;
    while(PTR->next != HEAD)
    {
        cout << PTR->DATA << "  ";
        PTR = PTR->next;
    }
        cout << PTR->DATA << "  ";
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

int main()
{
    LINKED *START = NULL, *NEW = NULL;
    for(int i =  0 ; i < 10; i++)
    {
        INSERT_BEGIN(&START, rand()%10);
    }
    DISPLAY(START);
    DELETE_ON_LOCATION(&START, 5);
    cout <<"\nAFTER DELETE  5th element\n";
    DISPLAY(START);
}
/*
OUTPUT 
4  2  8  8  4  9  0  4  7  1  
AFTER DELETE  5th element
4  2  8  8  9  0  4  7  1
*/