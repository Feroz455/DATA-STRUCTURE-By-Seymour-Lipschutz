/*
PAGE 160
5.14  Find the polynomials stored in the three header lists in Fig. 5.50.
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
        cout << PTR->XEXP << "  \n";
        PTR = PTR->next;
    }
        cout << PTR->COEF << "  ";
        cout << PTR->XEXP << "  \n";
}

int main()
{
    srand(time(0));
    LINKED *START[3] ={ NULL,NULL,NULL};
    LINKED PP;
    cout << "ENTER COEF AND EXP\nENTER -99 to STOP\n";
    cin >> PP.COEF >> PP.XEXP;
    for(int i = 0; i < 3; i++)
    while (PP.COEF != -99)
    {
        INSERT_END(&START[i],PP);
        cout << "ENTER COEF AND EXP\nENTER -99 to STOP\n";
        cin >> PP.COEF >> PP.XEXP;
    }
    
    for(int i = 0 ; i < 3; i++)
    {
        DISPLAY(START[i]);   
    }
}
/*
OUTPUT 

*/