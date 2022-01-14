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

int main()
{
    srand(time(0));
    LINKED *START = NULL;
    for(int i = 0 ; i < 5;  i++)
    {
        INSERT_END(&START,(rand()%10)+1);
    }
    DISPLAY_FORWORD(&START);
    DELETE_ON_LOCATION(&START, 4);
    DISPLAY_FORWORD(&START);
    INSERT_END(&START,(rand()%10)+1);
    DISPLAY_FORWORD(&START);
}
/*
OUTPUT 
9 -> 6 -> 9 -> 5 -> 7
9 -> 6 -> 9 -> 7     
9 -> 6 -> 9 -> 7 -> 1
*/