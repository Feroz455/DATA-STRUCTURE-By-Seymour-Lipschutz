/*
5.1 Figure 5.48 is a list of five hospital patients and their room numbers. 
(a) Fill in values for NSTART and NLINK so that they form an alphabetical listing of the names. 
(b) Fill in values for RSTART and RLINK so that they form an ordering of the room numbers.
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
typedef struct _link
{
    int ROOM_NUMBER;
    string PATIENTS_NAME;
    _link *next;
    _link *prev;
}LINKED;
void INSERT_END(LINKED **START, int ROOM_NUMBER, string PATIENTS_NAME)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->ROOM_NUMBER = ROOM_NUMBER;
        NEW->PATIENTS_NAME = PATIENTS_NAME; 
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->ROOM_NUMBER = ROOM_NUMBER;
        NEW->PATIENTS_NAME = PATIENTS_NAME;

        NEW->next = (*START);
        NEW->prev = LAST;
        (*START)->prev = NEW;
        LAST->next = NEW;
    }   
}
void INSERT_BEGIN(LINKED **START, int ROOM_NUMBER, string PATIENTS_NAME)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->ROOM_NUMBER = ROOM_NUMBER;
        NEW->PATIENTS_NAME = PATIENTS_NAME;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;

        LINKED *NEW_LINK = new LINKED;
        NEW_LINK->ROOM_NUMBER = ROOM_NUMBER;
        NEW_LINK->PATIENTS_NAME = PATIENTS_NAME;

        NEW_LINK->next = *START;
        NEW_LINK->prev = LAST;

        LAST->next = (*START)->prev = NEW_LINK;
        *START = NEW_LINK;
    }
}
void INSERT_DATA_SORTED( LINKED **START, int ROOM_NUMBER, string PATIENTS_NAME)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->ROOM_NUMBER = ROOM_NUMBER;
        NEW->PATIENTS_NAME = PATIENTS_NAME;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else 
    if((*START)->ROOM_NUMBER >= ROOM_NUMBER)
    {
        INSERT_BEGIN(START, ROOM_NUMBER, PATIENTS_NAME);
    }
    else
    if((*START)->prev->ROOM_NUMBER <= ROOM_NUMBER)
    {
        INSERT_END(START, ROOM_NUMBER, PATIENTS_NAME);
    }
    else
    {
        LINKED *PTR = (*START);
        LINKED *NEW = new LINKED, *PP;
        NEW->ROOM_NUMBER = ROOM_NUMBER;
        NEW->PATIENTS_NAME = PATIENTS_NAME;

        while(PTR->ROOM_NUMBER < ROOM_NUMBER)
        {
            PP = PTR;
            PTR = PTR->next;
        }
        NEW->next = PTR;
        NEW->prev = PTR->prev;
        PTR->prev = NEW;
        PP->next = NEW;
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

    cout << PTR->PATIENTS_NAME << " "  << PTR->ROOM_NUMBER << " \n";
    PTR = PTR->next;
    }
    cout << PTR->PATIENTS_NAME << " "  << PTR->ROOM_NUMBER << " \n";
}
int main()
{
    LINKED *START = NULL;
    string PATIENTS_NAME;
    int ROOM_NUMBER;
    for(int i = 0; i < 5; i++)
    {
        cout << "PATIENTS_NAME?\n";
        cin >> PATIENTS_NAME;
        cout << "ROOM NUMBER?\n";
        cin >> ROOM_NUMBER;
        INSERT_DATA_SORTED(&START, ROOM_NUMBER, PATIENTS_NAME);
    }
    DISPLAY_FORWORD(&START);
}
/*
PATIENTS_NAME?
BROWN
ROOM NUMBER?
650
PATIENTS_NAME?
Smith
ROOM NUMBER?
422
PATIENTS_NAME?
Adams
ROOM NUMBER?
704
PATIENTS_NAME?
Jones
ROOM NUMBER?
462
PATIENTS_NAME?
Burns
ROOM NUMBER?
632


Smith 422 
Jones 462
Burns 632
BROWN 650
Adams 704
*/
