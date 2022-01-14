/*
Page 160
5.15 Consider the following polynomial:

p(x, y, z) = 2xy2z3 + 3x2yz2 + 4xy3z + 5x2y2 + 6y3z + 7x3z + 8xy2z5 + 9

(a) Rewrite the polynomial so that the terms are ordered lexicographically.

(b) Suppose the terms are stored in the order shown here in parallel arrays 
COEF, XEXP, YEXP and ZEXP with the header node first. 
(Thus COEF[K] = K for K = 2,3, …, 9.) Assign values to an array LINK so that 
the linked list contains the ordered sequence of terms. (See Solved Problem 5.9.)
*/
/*
5.9 Consider a polynomial p(x, y, z) in variables x, y and z. 
Unless otherwise stated, the terms in p(x, y, z) will be ordered 
lexicographically. That is, first we order the terms according 
to decreasing degrees in x; those with the same degree in x we 
order according to decreasing degrees in y; those with the same 
degrees in x and y we order according to decreasing degrees in z. 
Supposep(x, y, z) = 8x2y2z − 6yz8 + 3x3yz + 2xy7z − 5x2y3 − 4xy7z3

(a) Rewrite the polynomial so that the terms are ordered.

(b) Suppose the terms are stored in the order shown in the 
problem statement in the linear arrays COEF, XEXP, YEXP and 
ZEXP, with the HEAD node first. Assign values to LINK so that 
the linked list contains the ordered sequence of terms.
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
using namespace std;
typedef struct _link
{
    int COEF;
    int XEXP;
    int YEXP;
    int ZEXP;
    _link *next;
    _link *prev;
}LINKED;
void INSERT_END(LINKED **START, LINKED PP)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->COEF = PP.COEF;
        NEW->XEXP = PP.XEXP;
        NEW->YEXP = PP.YEXP;
        NEW->ZEXP = PP.ZEXP;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->COEF = PP.COEF;
        NEW->XEXP = PP.XEXP;
        NEW->YEXP = PP.YEXP;
        NEW->ZEXP = PP.ZEXP;

        NEW->next = (*START);
        NEW->prev = LAST;
        (*START)->prev = NEW;
        LAST->next = NEW;
    }   
}
void INSERT_BEGIN(LINKED **START, LINKED PP)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->COEF = PP.COEF;
        NEW->XEXP = PP.XEXP;
        NEW->YEXP = PP.YEXP;
        NEW->ZEXP = PP.ZEXP;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;

        LINKED *NEW = new LINKED;
        NEW->COEF = PP.COEF;
        NEW->XEXP = PP.XEXP;
        NEW->YEXP = PP.YEXP;
        NEW->ZEXP = PP.ZEXP;

        NEW->next = *START;
        NEW->prev = LAST;

        LAST->next = (*START)->prev = NEW;
        *START = NEW;
    }
}
void INSERT_DATA_SORTED( LINKED **START, LINKED PP)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->COEF = PP.COEF;
        NEW->XEXP = PP.XEXP;
        NEW->YEXP = PP.YEXP;
        NEW->ZEXP = PP.ZEXP;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else 
    if((*START)->XEXP >= PP.XEXP)
    {
        INSERT_BEGIN(START, PP);
    }
    else
    if((*START)->prev->XEXP <= PP.XEXP)
    {
        INSERT_END(START, PP);
    }
    else
    {
        LINKED *PTR = (*START);
        LINKED *NEW = new LINKED, *PPP;
        NEW->COEF = PP.COEF;
        NEW->XEXP = PP.XEXP;
        NEW->YEXP = PP.YEXP;
        NEW->ZEXP = PP.ZEXP;

        while(PTR->XEXP < PP.XEXP)
        {
            PPP = PTR;
            PTR = PTR->next;
        }
        NEW->next = PTR;
        NEW->prev = PTR->prev;
        PTR->prev = NEW;
        PPP->next = NEW;
    }
}
void DISPLAY(LINKED *HEAD)
{
    LINKED *PTR = HEAD;
    while(PTR->next != HEAD)
    {
        cout << PTR->COEF << "  ";
        cout << PTR->XEXP << "  ";
        cout << PTR->YEXP << "  ";
        cout << PTR->ZEXP << "  \n";
        PTR = PTR->next;
    }
        cout << PTR->COEF << "  ";
        cout << PTR->XEXP << "  ";
        cout << PTR->YEXP << "  ";
        cout << PTR->ZEXP << "  ";
}
void DISPLAY_REVERSE(LINKED *HEAD)
{
    LINKED *PTR = HEAD->prev;
    while(PTR != HEAD)
    {
        cout << PTR->COEF << "  ";
        cout << PTR->XEXP << "  ";
        cout << PTR->YEXP << "  ";
        cout << PTR->ZEXP << "  \n";
        PTR = PTR->prev;
    }
        cout << PTR->COEF << "  ";
        cout << PTR->XEXP << "  ";
        cout << PTR->YEXP << "  ";
        cout << PTR->ZEXP << "  ";
}
int main()
{
    srand(time(0));
    LINKED *START = NULL, PP;
    for(int i = 1; i < 5; i++)
    {
        PP.COEF = i*10;
        PP.XEXP = rand()%10;
        PP.YEXP = rand()%10;
        PP.ZEXP = rand()%10;
        INSERT_DATA_SORTED(&START,PP);
    }
    DISPLAY_REVERSE(START);
}
/*
OUTPUT
30  7  9  7
40  4  8  4
10  3  4  1
20  0  1  4
*/