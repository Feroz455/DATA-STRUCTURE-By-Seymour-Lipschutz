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
    int POP();
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
    
    if(START == nullptr)
    {
        STK *PTR = new STK;
        PTR->DATA = DATA;
        PTR->next = nullptr;
        START = PTR;
        MAXSTK++;
        AVAIL--;
    }
    if(AVAIL <= 0)
    {
        cout << "OVERFLOW\n";
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
int STACK::POP()
{
    if(START== nullptr)
    {
        cout << "UNDER FLOW\n";
        return 0;
    }
    int temp = START->DATA;
    START = START->next;
    AVAIL++;
    MAXSTK--;
    return temp;
}
void STACK::DISPLAY()
{
    int ITEM = POP();
    while(ITEM)
    {
        cout << ITEM<< " ";
        ITEM = POP();
    }
    

}
STACK::~STACK()
{
}
int main()
{
    STACK S(10);
    for(int  i  = 1 ; i < 7; i++)
    {
        S.PUSH(i);
    };
    S.DISPLAY();
}
/*
OUTPUT
6 5 4 3 2 1 1 UNDER FLOW
*/
