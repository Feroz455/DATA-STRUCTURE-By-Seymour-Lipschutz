/*
Page 167
Procedure 6.2: POP(STACK, TOP, ITEM)

This procedure deletes the top element of STACK and assigns it to the variable

ITEM.

1. [Stack has an item to be removed?]
If TOP = 0, then: Print: UNDERFLOW, and Return.

2. Set ITEM := STACK[TOP]. [Assigns TOP element to ITEM.]

3. Set TOP := TOP – 1. [Decreases TOP by 1.]

4. Return.
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
    int ITEM;
    STACK S(10);
    for(int  i  = 1 ; i < 7; i++)
    {
        S.PUSH(i);
    };
    S.DISPLAY();
    if(S.POP(ITEM))
        cout << ITEM<< " ";
}
/*
OUTPUT
6 5 4 3 2 1 1 UNDER FLOW
*/