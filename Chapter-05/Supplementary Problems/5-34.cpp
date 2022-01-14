/*
page 161
5.22 Suppose LIST(INFO, LINK, START, AVAIL) is a one-way circular header list in memory. Write a procedure
TWOWAY(INFO, LINK, BACK, START)
which assigns values to a linear array BACK to form a two-way list from the one-way list.
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

        cout << PTR->DATA << "-> " ;
        PTR = PTR->next;
    }
    cout << PTR->DATA ; 
}
void INSERT_SIGLE(LINKED **START, int DATA)
{
    LINKED *PTR = new LINKED;
    PTR->DATA = DATA;
    PTR->next = *START;
    PTR->prev = NULL;
    *START = PTR;
}
void DOUBLE_TO_SINGLE(LINKED *START, LINKED **NEW)
{
   
    LINKED *PTR = START->prev;
    while(PTR != START)
    {
        INSERT_SIGLE(NEW,PTR->DATA);
        PTR = PTR->prev;
    }
    INSERT_SIGLE(NEW,PTR->DATA);
    return;  
}
void SINGLE_TO_DOUBLE(LINKED *START, LINKED **NEW)
{
   
    LINKED *PTR = START;
    while (PTR->next != NULL)
    {
        INSERT_END(NEW, PTR->DATA);
        //cout << "\nPTR->DATA = " << PTR->DATA << "\n";
        PTR = PTR->next;
    }
    INSERT_BEGIN(NEW, PTR->DATA);
    return;  
}
void DISPLAY_S(LINKED *HEAD)
{
    LINKED *PTR = HEAD;
    while(PTR->next != NULL)
    {
        cout << PTR->DATA << "  ";
        PTR = PTR->next;
    }
        cout << PTR->DATA << "  ";
}
int main()
{
    LINKED *START = NULL, *NEW = NULL;
    for(int i =  0 ; i < 10; i++)
    {
        INSERT_SIGLE(&START, rand()%10);
    }
    DISPLAY_S(START);
    SINGLE_TO_DOUBLE(START, &NEW);
    cout << "\n SINGLE LIST TO DUBBLE LIST\n";
    DISPLAY_FORWORD(&NEW);


}
/*
OUTPUT 
4  2  8  8  4  9  0  4  7  1  
 SINGLE LIST TO DUBBLE LIST   
1-> 4-> 2-> 8-> 8-> 4-> 9-> 0-> 4-> 7
*/