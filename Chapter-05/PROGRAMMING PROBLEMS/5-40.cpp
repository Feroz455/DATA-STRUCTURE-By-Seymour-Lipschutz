/*
Page 161
Programming Problems 5.1 to 5.6 refer to the data structure in
Fig. 5.52, which consists of four alphabetized lists of clients
and their respective lawyers.

5.4 Write a program which reads the NAME of a client and prints 
the client’s name, age and lawyer. Test the program using 
(a) Newman, (b) Ford, (c) Rivers and (d) Hall.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef struct _link
{
    string CLINT_NAME;
    int AGE;
    _link *next;
    _link *prev;
} LINKED;

typedef struct _lawyer
{
    string NAME;
    LINKED *CLINT;
} LAWYER;

/********************************/
void INSERT_END(LINKED **START, string NAME, int AGE)
{
    if ((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->CLINT_NAME = NAME;
        NEW->AGE = AGE;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->CLINT_NAME = NAME;
        NEW->AGE = AGE;

        NEW->next = (*START);
        NEW->prev = LAST;
        (*START)->prev = NEW;
        LAST->next = NEW;
    }
}
void DISPLAY_FORWORD(LINKED **START)
{
    if ((*START) == NULL)
    {
        cout << "LIST IS EMPTY\n";
        return;
    }
    LINKED *PTR = (*START);
    while (PTR->next != *START)
    {

        cout << setw(10) << PTR->CLINT_NAME << " " << setw(3) << PTR->AGE << "\n";
        PTR = PTR->next;
    }
    cout << setw(10) << PTR->CLINT_NAME << " " << setw(3) << PTR->AGE << "\n";
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
void DELETE_ITEM(LINKED **START, string NAME)
{
    LINKED *PTR = (*START);
    if(PTR->CLINT_NAME == NAME)
    {
        cout << "\n" << setw(10) << PTR->CLINT_NAME << " " << setw(3) << PTR->AGE << " DELETED\n";
        DELETE_FIRST_LINK(START);
        
    }
    else 
    if(PTR->prev->CLINT_NAME == NAME)
    {
        cout << "\n" << setw(10) << PTR->prev->CLINT_NAME  << " " << setw(3) << PTR->prev->AGE << " DELETED\n";
        DELETE_LAST_LINK(START);
        
    }
    else 
    {
        while(PTR->next != (*START) && PTR->CLINT_NAME != NAME)
        {
            PTR = PTR->next;
        }
        if(PTR->next == (*START))
        {
            return;
        }
        cout << "\n" << setw(10) << PTR->CLINT_NAME << " " << setw(3) << PTR->AGE << " DELETED\n";
        PTR->next->prev = PTR->prev;
        PTR->prev->next = PTR->next;
    }
}
int main()
{
    int k = 4, age;
    string name;
    LAWYER NAME[k];
    LINKED *START = NULL;
    for (int i = 0; i < k; i++)
    {
        cout << "Enter lowyer name\n";
        cin >> NAME[i].NAME;
        cout << "Enter clint NAME and AGE\n";
        cout << "TO STOP TYPE $$$$$\n";
        cin >> name;
        while (name != "$$$$$")
        {
            cin >> age;
            INSERT_END(&START, name, age);
            cin >> name;
        }
        NAME[i].CLINT = START;
        START = NULL;
        cout << "\nHELLO\n";
    }
    for (int i = 0; i < k; i++)
    {
        cout << "LOWYER NAME = " << NAME[i].NAME << endl;
        START = NAME[i].CLINT;
        DISPLAY_FORWORD(&START);
    }

    string CLINT_NAME, LOWYER_NAME;
    int check;
    for(int i = 0; i < 2; i++)
    {
        check = 0;
        cout << "Enter lowyer name\n";
        cin >> LOWYER_NAME;
        
        for(int j = 0; j < 4; j++)
        {
            if(LOWYER_NAME == NAME[j].NAME)
            {
                cout << "Enter clint name\n";
                cin >> CLINT_NAME;
                cout << "Enter clint age\n";
                cin >> age;
                START = NAME[j].CLINT;
                INSERT_END(&START, CLINT_NAME, age);
                check = 1;
                break;
            }

        }
        if(check == 0)
        {
            cout << "LOWYER DOES NOT EXIST\n";
        }
    }
    for (int i = 0; i < k ; i++)
    {
        cout << "LOWYER NAME = " << NAME[i].NAME << endl;
        START = NAME[i].CLINT;
        DISPLAY_FORWORD(&START);
    }

    

    return 0;
}

/*
OUTPUT
CLIENT
Davis


Hall
35

Moss
28

Ford
47

Brown
54

Ginn
38
$$$$$

Levine

Pride
42

Berk
38


White
45

Todd
25

Dixon
32

Newman
46
$$$$$

Nelson

Harris
42

Jackson
52

Roberts
40

Eisen
32

Adams
48

Cohen
36
$$$$$


Rogers
Fisher
32

Graves
42

Parker
50

Singer
45

Lewis
28
$$$$$





Enter lowyer name
Davis
Enter clint NAME and AGE
TO STOP TYPE $$$$$      


Hall
35

Moss
28

Ford
47

Brown
54

Ginn
38
$$$$$

HELLO
Enter lowyer name

Levine
Enter clint NAME and AGE
TO STOP TYPE $$$$$

Pride
42

Berk
38


White
45

Todd
25

Dixon
32

Newman
46
$$$$$

HELLO
Enter lowyer name

Nelson
Enter clint NAME and AGE
TO STOP TYPE $$$$$

Harris
42

Jackson
52

Roberts
40

Eisen
32

Adams
48

Cohen
36
$$$$$

HELLO
Enter lowyer name


Rogers
Enter clint NAME and AGE
TO STOP TYPE $$$$$
Fisher
32

Graves
42

Parker
50

Singer
45

Lewis
28
$$$$$

HELLO
LOWYER NAME = Davis
      Hall  35
      Moss  28
      Ford  47
     Brown  54
      Ginn  38
LOWYER NAME = Levine
     Pride  42
      Berk  38
     White  45
      Todd  25
     Dixon  32
    Newman  46
LOWYER NAME = Nelson
    Harris  42
   Jackson  52
   Roberts  40
     Eisen  32
     Adams  48
     Cohen  36
LOWYER NAME = Rogers
    Fisher  32
    Graves  42
    Parker  50
    Singer  45
     Lewis  28
Enter lowyer name
Levine
Enter clint name
Jones
Enter clint age
36
Enter lowyer name
Nelson
Enter clint name
Olsen
Enter clint age
44
LOWYER NAME = Davis
      Hall  35
      Moss  28
      Ford  47
     Brown  54
      Ginn  38
LOWYER NAME = Levine
     Pride  42
      Berk  38
     White  45
      Todd  25
     Dixon  32
    Newman  46
     Jones  36
LOWYER NAME = Nelson
    Harris  42
   Jackson  52
   Roberts  40
     Eisen  32
     Adams  48
     Cohen  36
     Olsen  44
LOWYER NAME = Rogers
    Fisher  32
    Graves  42
    Parker  50
    Singer  45
     Lewis  28
*/