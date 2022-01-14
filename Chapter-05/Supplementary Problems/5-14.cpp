/*
(a) Find the sequence of characters in the list.

(b) Suppose F and then C are deleted from the list and then G 
is inserted at the beginning of the list. Find the final structure.

(c) Suppose C and then F are deleted from the list and then G 
is inserted at the beginning of the list. Find the final structure.

(d) Suppose G is inserted at the beginning of the list and then
F and then C are deleted from the structure. Find the final structure.
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

typedef struct _link
{
    char DATA;
    _link *next;
    _link *prev;
}LINKED;
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
    cout << PTR->DATA << "\n" ; 
}
void INSERT_END(LINKED **START, char DATA)
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
void INSERT_BEGIN(LINKED **START, char DATA)
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
void DELETE_ITEM(LINKED **START, char DATA)
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
int main()
{
    LINKED *STAR = NULL;
    //(a) Find the sequence of characters in the list.
    INSERT_END(&STAR, 'C');
    INSERT_END(&STAR, 'E');
    INSERT_END(&STAR, 'A');
    INSERT_END(&STAR, 'B');
    INSERT_END(&STAR, 'F');
    INSERT_END(&STAR, 'D');

/*
(b) Suppose F and then C are deleted from the list and then G is 
inserted at the beginning of the list. Find the final structure.
    DISPLAY_FORWORD(&STAR);
    DELETE_ITEM(&STAR, 'F');
    DELETE_ITEM(&STAR, 'C');
    INSERT_BEGIN(&STAR, 'G');
    DISPLAY_FORWORD(&STAR);
*/
/*
(c) Suppose C and then F are deleted from the list and then G is 
inserted at the beginning of the list. Find the final structure.
    DISPLAY_FORWORD(&STAR);
    DELETE_ITEM(&STAR, 'C');
    DELETE_ITEM(&STAR, 'F');
    INSERT_BEGIN(&STAR, 'G');
    DISPLAY_FORWORD(&STAR);
*/
//(d) Suppose G is inserted at the beginning of the list and then 
//F and then C are deleted from the structure. Find the final structure.
   
    DISPLAY_FORWORD(&STAR);
    INSERT_BEGIN(&STAR, 'G');
    DELETE_ITEM(&STAR, 'F');
    DELETE_ITEM(&STAR, 'C');
    DISPLAY_FORWORD(&STAR);

}
/*
OUTPUT 
C-> E-> A-> B-> F-> D

C-> E-> A-> B-> F-> D
E-> A-> B-> D

C-> E-> A-> B-> F-> D
G-> E-> A-> B-> D

C-> E-> A-> B-> F-> D
G-> E-> A-> B-> D

C-> E-> A-> B-> F-> D
G-> E-> A-> B-> D
*/