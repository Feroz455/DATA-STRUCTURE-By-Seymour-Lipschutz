/*
page 158
Write a procedure SORT(INFO, LINK, START) which 
sorts a list without changing any values in INFO. 
(Hint: Use the procedure SWAP in Supplementary 
Problem 5.14 together with a bubble sort.)

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
    srand(time(0));
    LINKED *START = NULL;
    for(int i = 0; i < 10; i++)
    {
        INSERT_END(&START,rand()%10);
    }
    DISPLAY_FORWORD(&START);
    BUBBLE_SORT(START);
    DISPLAY_FORWORD(&START);
}