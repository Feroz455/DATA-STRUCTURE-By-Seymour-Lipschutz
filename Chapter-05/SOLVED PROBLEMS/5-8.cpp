/*
page 155
5.8 Find the polynomials POLY1 and POLY2 stored in Fig. 5.44
Beginning with POLY1, traverse the list by following the pointers to obtain the polynomial
p1(x) = 3x5 ∠ 4x3 + 6x − 5
Beginning with POLY2, traverse the list by following the pointers to obtain the polynomial
p2(x) = 2x8 + 7x5 + 3x2
Here COEF[K] and EXP[K] contain, respectively, the coefficient and exponent of a term of t
he polynomial. Observe that the header nodes are assigned −1 in the EXP field.
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
typedef struct _link
{
    int COEF;
    int EXP;
    _link *next;
}LINKED;
/****************************/
void ADD_TILE(LINKED **HEAD, int COEF, int EXP)
{
    LINKED *PTR  = *HEAD , *NEW;
    if(*HEAD == NULL)
    {
        *HEAD = new LINKED;
        (*HEAD)->COEF = COEF;
        (*HEAD)->EXP = EXP;

        (*HEAD)->next = *HEAD;
    }
    else 
    {
        while(PTR->next != *HEAD)
        {
            PTR = PTR->next;
        }
        NEW = new LINKED;
        NEW->COEF = COEF;
        NEW->EXP = EXP;
        NEW->next = *HEAD;
        PTR->next = NEW;
    }
    return;
}
void DISPLAY(LINKED *HEAD)
{
    LINKED *PTR = HEAD;
    while(PTR->next != HEAD)
    {
        cout << PTR->COEF << "  ";
        cout << PTR->EXP << " \n";
        PTR = PTR->next;
    }
    cout << PTR->COEF << "  ";
    cout << PTR->EXP << " \n";
}
void SRCHHL(LINKED *HEAD, int ITEM)
{
    int LOC = 1;
    LINKED *PTR = HEAD;
    while(PTR->next != HEAD && PTR->COEF != ITEM)
    {
        LOC++;
        PTR = PTR->next;
    }
    if(PTR->COEF == ITEM)
    {
        cout << "ITEM FOUND AT " << LOC << " \n"; 
    }
    else
    cout << "ITEM NOT FOUND\n";
    
}
int main()
{
    int COEF;
    LINKED *HEAD;
    HEAD = NULL;
    for(int i = 1; i < 11; i++)
    {
        ADD_TILE(&HEAD, i*10, i);
        //cout << "I = " << i*10 << endl;
     }
    DISPLAY(HEAD);
    SRCHHL(HEAD, 10);
}