/*
5.13 Character strings are stored in the three linked lists in Fig. 5.50.
(a) Find the three strings. 
(b) Form circular header lists from the one-way lists using CHAR[20], CHAR[19] and CHAR[18] as header nodes.
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

int main()
{
    srand(time(0));
    char c;
    LINKED *START[3] ={ NULL,NULL,NULL};
    for(int i = 0 ; i < 3; i++)
    {
        cout << "Enter your string\n";
        cin >> c;
        while (c != '$')
        {
            INSERT_END(&START[i], c);
            cin >> c;
        }
        
    }
    for(int i = 0 ; i < 3; i++)
    {
        DISPLAY_FORWORD(&START[i]);   
    }
}
/*
OUTPUT 
Enter your string
o
h
i
o
$
Enter your string
M
A
I
N
E
X
A
 
$
Enter your string
T
E
X
A
 
$
o -> h -> i -> o
M -> A -> I -> N -> E -> X -> A
T -> E -> X -> A
*/