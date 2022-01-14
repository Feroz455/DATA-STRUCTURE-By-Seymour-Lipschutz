/*
Algorithm P5.5: DELLST(INFO, LINK, START, AVAIL)

1. [List empty?] If START = NULL, then Write: UNDERFLOW, and Exit.

2. [List contains only one element?]

If LINK[START] = NULL, then:

(a) Set START := NULL. [Removes only node from list.]

(b) Set LINK[START] := AVAIL and AVAIL := START.

[Returns node to AVAIL list.]

(c) Exit.

[End of If structure.]

3. Set PTR := LINK[START] and SAVE := START. [Initializes pointers.]

4. Repeat while LINK[PTR] ≠ NULL. [Traverses list, seeking last node.]

Set SAVE := PTR and PTR := LINK[PTR]. [Updates SAVE and PTR.]

[End of loop.]

5. Set LINK[SAVE] := LINK[PTR]. [Removes last node.]

6. Set LINK[PTR] := AVAIL and AVAIL := PTR. [Returns node to AVAIL list.]

7. Exit.
*/
#include<iostream>
#include<string>
#include<iomanip>
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
int main()
{
    LINKED *START = NULL;
    for(int i = 1; i < 11; i++)
    {
        INSERT_BEGIN(&START, i*10);
    }
    DISPLAY_FORWORD(&START);
    DELETE_LAST_LINK(&START);
    cout << "\n";
    DISPLAY_FORWORD(&START);
    REPLACE(&START, 50, 55);
    cout << "\n";
    DISPLAY_FORWORD(&START);
    REPLACE(&START, 100, 101);
    cout << "\n";
    DISPLAY_FORWORD(&START);


}