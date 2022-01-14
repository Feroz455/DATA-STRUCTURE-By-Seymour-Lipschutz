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
void ADD_TWO_LIST(LINKED **START, LINKED *LAST)
{
    LINKED *SFIRST, *SLAST, *LFIRT, *LLAST;
    SFIRST = (*START);
    SLAST = (*START)->prev;
    LFIRT = (LAST);
    LLAST = (LAST->prev);

    (*START)->prev->next = LAST;
    LAST->prev = (*START)->prev;
    LLAST->next = (*START);
    (*START)->prev = LLAST;
}
LINKED * COMBINE(LINKED *START, LINKED *LAST)
{
    LINKED *TEMP = NULL;
    LINKED *SPTR = START, *LPTR = LAST;

    do
    {
        INSERT_END(&TEMP, SPTR->DATA);
        SPTR = SPTR->next;
    } while (SPTR->next != START);
    INSERT_END(&TEMP, SPTR->DATA);
    SPTR = SPTR->next;
    do
    {
        INSERT_END(&TEMP, LPTR->DATA);
        LPTR = LPTR->next;
    } while (LPTR->next != LAST);
    INSERT_END(&TEMP, LPTR->DATA);
    LPTR = LPTR->next;
    return TEMP;
}
int main()
{
    srand(time(0));
    LINKED *START = NULL;
    LINKED *LAST = NULL;
    for(int i = 0 ; i < 5;  i++)
    {
        INSERT_END(&START,rand()%10);
    }
    cout << "\n";
    for(int i = 0 ; i < 5;  i++)
    {
        INSERT_END(&LAST,rand()%10);
    }
    
    BUBBLE_SORT(LAST);
    BUBBLE_SORT(START);
    DISPLAY_FORWORD(&START);
    DISPLAY_FORWORD(&LAST);
    LINKED * NEW = COMBINE(START, LAST);
    DISPLAY_FORWORD(&NEW);
}
/*
OUTPUT 
0 -> 0 -> 2 -> 3 -> 6
1 -> 2 -> 4 -> 6 -> 8
0 -> 0 -> 2 -> 3 -> 6 -> 1 -> 2 -> 4 -> 6 -> 8
*/