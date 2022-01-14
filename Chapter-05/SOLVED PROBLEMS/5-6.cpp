/*
Algorithm P5.6: COPY(INFO, LINK, NAMEl, NAME2, AVAIL)
This algorithm makes a copy of a list NAME1 using NAME2 as the list pointer variable of the new list.

1. Set NAME2 := NULL. [Forms empty list.]

2. [NAME1 empty?] If NAME1 = NULL, then: Exit.

3. [Insert first node of NAME1 into NAME2.]
Call INSLOC(INFO, LINK, NAME2, AVAIL, NULL, INFO[NAME1]) or:

(a) If AVAIL = NULL, then: Write: OVERFLOW, and Exit.

(b) Set NEW := AVAIL and AVAIL := LINK[AVAIL]. [Removes first node from AVAIL list.]

(c) Set INFO[NEW] := INFO[NAMEl]. [Copies data into new node.]

(d) [Insert new node as first node in NAME2.]
Set LINK[NEW] := NAME2 and NAME2 := NEW.

4. [Initializes pointers PTR and LOC.]
Set PTR := LINK[NAME1] and LOC := NAME2.

5. Repeat Steps 6 and 7 while PTR ≠ NULL:

6.       Call INSLOC(INFO, LINK, NAME2, AVAIL, LOC, INFO[PTR]) or:

(a) If AVAIL = NULL, then: Write: OVERFLOW, and Exit.

(b) Set NEW := AVAIL and AVAIL := LINK[AVAIL].

(c) Set INFO[NEW] := INFO[PTR]. [Copies data into new node.]

(d) [Insert new node into NAME2 after the node with location LOC.]
Set LINK [NEW] := LINK[LOC], and LINK[LOC] := NEW.

7.    Set PTR := LINK[PTR] and LOC := LINK[LOC]. [Updates PTR and LOC
[End of Step 5 loop.]

8. Exit.
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
    LINKED *COPY_LIST = START;
    cout << "\n";
    DISPLAY_FORWORD(&COPY_LIST);
}