/*
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