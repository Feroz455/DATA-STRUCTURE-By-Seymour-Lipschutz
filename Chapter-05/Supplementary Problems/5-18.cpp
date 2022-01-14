/*
PAGE 158
5.3 Suppose LIST is a linked list in memory consisting 
of numerical values. Write a procedure for each of the following:

(a) Finding the maximum MAX of the values in LIST

(b) Finding the average MEAN of the values in LIST

(c) Finding the product PROD of the elements in LIST
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
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
void REPLACE(LINKED **START, int DATA, int RDATA)
{
    LINKED *PTR = (*START);
    if(PTR->DATA == DATA)
    {
        PTR->DATA = RDATA;
    }
    else 
    if(PTR->prev->DATA == DATA)
    {
        PTR->prev->DATA = RDATA;
    }
    else 
    {
        while(PTR->next != (*START) && PTR->DATA != DATA)
        {
            PTR = PTR->next;
        }
        if(PTR->next == (*START))
        {
            cout << DATA << " NOT FOUND\n";
            return;
        }
        PTR->DATA = RDATA;
    }
}
void MAKE_FIRST_ELEMENT_LAST_ELEMENT(LINKED **START)
{
    (*START) = (*START)->next;
}
void INTERCHANGE(LINKED **START, int lOC)
{
    LINKED *PTR = (*START);
    if(lOC == 0)
    {
        MAKE_FIRST_ELEMENT_LAST_ELEMENT(START);
        return;
    }
    while (lOC-- != 1)
    {
        PTR = PTR->next;
    }
    int TEMP = PTR->DATA;
    PTR->DATA = PTR->next->DATA;
    PTR->next->DATA = TEMP;
}
int main()
{
    srand(time(0));
    LINKED *START = NULL;
    for(int i = 0 ; i < 5;  i++)
    {
        INSERT_END(&START,i*10);
    }
    DISPLAY_FORWORD(&START);
    INTERCHANGE(&START, 8);
    DISPLAY_FORWORD(&START);
}
/*
OUTPUT 
0 -> 10 -> 20 -> 30 -> 40
0 -> 10 -> 30 -> 20 -> 40
*/