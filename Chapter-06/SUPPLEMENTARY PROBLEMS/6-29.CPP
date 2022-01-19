/*


6.3 Suppose the following stack of integers is in 
memory where STACK is allocated N = 6 memory cells:

TOP = 3 STACK: 5, 2, 3, ___, ___, ___

Find the output of the following program segment:

1. 
Call POP(STACK, ITEMA).
Call POP(STACK, ITEMB).
Call PUSH(STACK, ITEMB + 2).
Call PUSH(STACK, 8).
Call PUSH(STACK, ITEMA + ITEMB).

2. Repeat while TOP ≠ 0:
      Call POP(STACK, ITEM).
      Write: ITEM.
[End of loop.]
*/
#include<iostream>
#include<iomanip>
using namespace std;
class STACK
{
private:
 typedef struct _node
    {
        int DATA;
        _node *next;
    }STK;
    int MAXSTK;
    int AVAIL;
    STK *START;
   
public:
    STACK(int N);
    ~STACK();
    void PUSH(int DATA);
    int POP(int &ITEM);
    void DISPLAY();
};
STACK::STACK(int N)
{
    MAXSTK = 0;
    AVAIL = N;
    START = nullptr;
}
//INSERT DATA INTO THE STACK
void STACK::PUSH(int DATA)
{
    if(AVAIL <= 0)
    {
        cout << "\nOVERFLOW\n";
    }
    if(START == nullptr)
    {
        STK *PTR = new STK;
        PTR->DATA = DATA;
        PTR->next = nullptr;
        START = PTR;
        MAXSTK++;
        AVAIL--;
    }
    else
    {
         STK *PTR = new STK;
        PTR->DATA = DATA;
        PTR->next = START;
        START = PTR;
        MAXSTK++;
        AVAIL--;
    }
}
//POPPING DATA FROM STACK
int STACK::POP(int &ITEM)
{
    if(START== nullptr)
    {
        cout << "\nUNDER FLOW\n";
        return 0;
    }
    ITEM = START->DATA;
    START = START->next;
    AVAIL++;
    MAXSTK--;
    return 1;
}
void STACK::DISPLAY()
{
    int ITEM;
    while(1)
    {
        if(POP(ITEM))
        cout << ITEM<< " ";
        else 
        break;
    }
    

}
STACK::~STACK()
{
}
int main()
{
    int ITEM, ITEMA = 8, ITEMB = 10;
    STACK S(6);
    S.PUSH(5);
    S.PUSH(2);
    S.PUSH(3);
    if(S.POP(ITEM))
        cout << ITEM<< " ";
    if(S.POP(ITEM))
        cout << ITEM<< " ";
    S.PUSH(ITEMB+2);
    S.PUSH(8);
    S.PUSH(ITEMA+ITEMB);
    S.DISPLAY();
}
/*
OUTPUT
3 2 18 8 12 5 
UNDER FLOW
*/