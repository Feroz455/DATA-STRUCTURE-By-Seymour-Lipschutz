/*
5.18 Suppose POLY1 and POLY2 are polynomials (in one variable) 
which are stored as header circular lists using the same paral
lel arrays COEF, EXP and LINK. Write a procedure

ADD(COEF, EXP, LINK, POLY1, POLY2, AVAIL, SUMPOLY)

which finds the sum SUMPOLY of POLY1 and POLY2 (and which is 
also stored in memory using COEF, EXP and LINK).
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include<cmath>
using namespace std;
typedef struct _link
{
    int COEF;
    int XEXP;
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

        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->COEF = PP.COEF;
        NEW->XEXP = PP.XEXP;

        NEW->next = (*START);
        NEW->prev = LAST;
        (*START)->prev = NEW;
        LAST->next = NEW;
    }   
}
void DISPLAY(LINKED *HEAD)
{
    LINKED *PTR = HEAD;
    while(PTR->next != HEAD)
    {
        cout << PTR->COEF << "  ";
        cout << PTR->XEXP << "\n";
        PTR = PTR->next;
    }
        cout << PTR->COEF << "  ";
        cout << PTR->XEXP << "  \n";
}
long SUM(LINKED *START)
{
    long SUM = 0;
    LINKED *PTR = (START);
    while (PTR->next != (START))
    {
        SUM += pow(PTR->COEF,PTR->XEXP);
        //cout<< "\n" << PTR->COEF << " " << PTR->XEXP <<  " " << pow( PTR->COEF,PTR->XEXP) << endl;
        //cout << "\nSUM = " << SUM;
        PTR = PTR->next;
    }
    SUM += pow( PTR->COEF,PTR->XEXP);
     //cout<< "\n" << PTR->COEF << " " << PTR->XEXP <<  " " << pow( PTR->COEF,PTR->XEXP) << endl;
     //cout << "\nSUM = " << SUM;
    return SUM;
}
long ADD(LINKED *FIRST, LINKED *SECOND)
{
    return ( SUM(FIRST) +  SUM(SECOND));
}
long MUL(LINKED *FIRST, LINKED *SECOND)
{
    return ( SUM(FIRST) *  SUM(SECOND));
}
int main()
{
    srand(time(0));
    LINKED *POLY1 = NULL, *POLY2= NULL, PP;
    for(int i = 0; i < 3; i++)
    {

        PP.COEF = rand()%5;
        PP.XEXP = rand()%5;
        INSERT_END(&POLY1, PP);
        PP.COEF = rand()%5;
        PP.XEXP = rand()%5;
        INSERT_END(&POLY2, PP);

    }
    DISPLAY(POLY1);
    cout << "\n";
    DISPLAY(POLY2);
    long RESULT = ADD(POLY2, POLY1);
    cout << "POLY1 + POLY2 = " << RESULT;
    RESULT = MUL(POLY2, POLY1);
    cout << "\nPOLY1 * POLY2 = " << RESULT;
}
/*
OUTPUT 
1  4
1  1
4  0

1  3
0  0
2  3
POLY1 + POLY2 = 13
POLY1 * POLY2 = 30
*/