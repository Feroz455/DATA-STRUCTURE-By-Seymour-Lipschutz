/*
page 161
5.20 Form two-way circular header lists from the one-way 
lists in Fig. 5.49 using, as in Supplementary Problem 5.13, 
CHAR[20], CHAR[19] and CHAR[18] as header nodes.
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
        INSERT_BEGIN(&START, rand()%10);
    }
    DISPLAY(START);
    DOUBLE_TO_SINGLE(START, &NEW);
    cout << "\nDUBBLE LIST TO SINGLE LIST \n";
    DISPLAY_S(NEW);


}
/*
OUTPUT 
4  2  8  8  4  9  0  4  7  1  
DUBBLE LIST TO SINGLE LIST
4  2  8  8  4  9  0  4  7  1
*/