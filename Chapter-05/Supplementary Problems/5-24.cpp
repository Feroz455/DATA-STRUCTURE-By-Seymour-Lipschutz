/*
5.11 Suppose STR1 and STR2 are character strings in memory. 
Write a procedure which creates a new string STR3 which is the concatenation of STR1 and STR2.
*/
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
    char CHAR;
    _link *next;
    _link *prev;
}LINKED;
void INSERT_END(LINKED **START, char CHAR)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->CHAR = CHAR;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->CHAR = CHAR;

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
        cout << PTR->CHAR << " -> ";
        PTR = PTR->next;
    }
    cout << PTR->CHAR << "\n"; 

}
void SWAP(LINKED *FIRST, LINKED *SECOND)
{
    char TEMP = FIRST->CHAR;
    FIRST->CHAR = SECOND->CHAR;
    SECOND->CHAR = TEMP;
}
void BUBBLE_SORT(LINKED *START)
{
    char SWAPPED, i;
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
            if(PTR->CHAR > PTR->next->CHAR)
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
        INSERT_END(&TEMP, SPTR->CHAR);
        SPTR = SPTR->next;
    } while (SPTR->next != START);
    INSERT_END(&TEMP, SPTR->CHAR);
    SPTR = SPTR->next;
    do
    {
        INSERT_END(&TEMP, LPTR->CHAR);
        LPTR = LPTR->next;
    } while (LPTR->next != LAST);
    INSERT_END(&TEMP, LPTR->CHAR);
    LPTR = LPTR->next;
    return TEMP;
}
int INDEX(LINKED *NEXT, LINKED *PATTERN)
{
    int CHECK = 0, RCHECK = 0;
    LINKED *PTR = NEXT, *PPTR = PATTERN;
    while (PTR->next != NEXT)
    {
        CHECK++;
        if(PTR->CHAR == PPTR->CHAR)
        {
            cout << PPTR->CHAR << " ";
            PPTR = PPTR->next;
            if(RCHECK == 0)
            {
                RCHECK = CHECK;
            }
            if(PPTR == PATTERN)
            {
                return RCHECK;
            }
            
        }
        else
        {
            PPTR = PATTERN;
            RCHECK = 0;
        }

        PTR = PTR->next;
    }
    return 0;
    
}
int main()
{
    srand(time(0));
    LINKED *START = NULL;
    LINKED *LAST = NULL;
    for(char i = 0 ; i < 20;  i++)
    {
        INSERT_END(&START,i+65);
    }
    cout << "\n";
    for(char i = 9 ; i < 15;  i++)
    {
        INSERT_END(&LAST,i+65);
    }
    
    BUBBLE_SORT(LAST);
    BUBBLE_SORT(START);
    DISPLAY_FORWORD(&START);
    DISPLAY_FORWORD(&LAST);
    //LINKED * NEW = COMBINE(START, LAST);
    int CK  = INDEX(START,LAST);
    if(CK == 0)
    cout << "\nPATTERN NOT FOUND\n";
    else 
    cout << "\nPATTERN FOUND AT " << CK << endl;
    //DISPLAY_FORWORD(&NEW);
}
/*
OUTPUT 
A -> B -> C -> D -> E -> F -> G -> H -> I -> J -> K -> L -> M -> N -> O -> P -> Q -> R -> S -> T
J -> K -> L -> M -> N -> O
J K L M N O 
PATTERN FOUND AT 10
*/