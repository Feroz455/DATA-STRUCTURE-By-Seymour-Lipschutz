/*
Page 197
6.2 Consider the data in Problem 6.1. 
(a) When will overflow occur? 
(b) When will C be deleted before D?

(a) Since STACK has been allocated N = 8 memory cells, 
overflow will occur when STACK contains 8 elements and 
there is a PUSH operation to add another element to STACK.

(b) Since STACK is implemented as a stack, C will never be deleted before D.
*/
#include<iostream>
#include<iomanip>
using namespace std;
class STACK
{
private:
 typedef struct _node
    {
        string DATA;
        _node *next;
    }STK;
    int MAXSTK;
    int AVAIL;
    STK *START;
   
public:
    STACK(int N);
    ~STACK();
    void PUSH(string DATA);
    int POP(string &ITEM);
    void DISPLAY();
};
STACK::STACK(int N)
{
    MAXSTK = 0;
    AVAIL = N;
    START = nullptr;
}
//INSERT DATA INTO THE STACK
void STACK::PUSH(string DATA)
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
int STACK::POP(string &ITEM)
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
    string ITEM;
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
    string  ITEM;
    STACK S(6);
    
    S.PUSH("AAA");
    S.PUSH("DDD");
    S.PUSH("EEE");
    S.PUSH("FFF");
    S.PUSH("GGG");

    S.PUSH("KKK");
    if(S.POP(ITEM))
        cout << ITEM<< " ";
    S.PUSH("LLL");
    S.PUSH("SSS");
    if(S.POP(ITEM))
        cout << ITEM<< " ";
    S.PUSH("TTT");
}
/*
OVERFLOW
KKK
OVERFLOW
SSS
OVERFLOW
*/