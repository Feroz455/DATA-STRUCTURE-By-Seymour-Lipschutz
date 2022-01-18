/*
Page 196
6.1 Consider the following stack of characters, where STACK is allocated N = 8 memory cells:

STACK: A, C, D, F, K, ___, ___, ___,

(For notational convenience, we use “___” to denote an empty memory cell.) Describe the stack as the following operations take place:

(a) POP(STACK, ITEM)

(b) POP(STACK, ITEM)

(c) PUSH(STACK, L)

(d) PUSH(STACK, P)

(e) POP(STACK, ITEM)

(f) PUSH(STACK, R)

(g) PUSH(STACK, S)

(h) POP(STACK, ITEM)

The POP procedure always deletes the top element from the stack, and the PUSH procedure always adds the new element to the top of the stack. Accordingly:

(a) STACK: A, C, D, F, ___, ___, ___, ___

(b) STACK: A, C, D, ___, ___, ___, ___, ___

(c) STACK: A, C, D, L, ___, ___, ___, ___

(d) STACK: A, C, D, L, P, ___, ___, ___

(e) STACK: A, C, D, L, ___, ___, ___, ___

(f) STACK: A, C, D, L, R, ___, ___, ___

(g) STACK: A, C, D, L, R, S, ___, ___

(h) STACK: A, C, D, L, R, ___, ___, ___
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
    STACK S(8);
        S.PUSH('A');
        S.PUSH('C');
        S.PUSH('D');
        S.PUSH('F');
        S.PUSH('K');
    if(S.POP(ITEM))
    {
        cout << (char)ITEM  << endl;
    }
    if(S.POP(ITEM))
    {
        cout << (char)ITEM  << endl;
    }
    S.PUSH('L');
    S.PUSH('P');
    if(S.POP(ITEM))
    {
        cout << (char)ITEM  << endl;
    }
    S.PUSH('R');
    S.PUSH('S');
    if(S.POP(ITEM))
    {
        cout << (char)ITEM  << endl;
    }


}
/*
OUTPUT
K
F
P
S
*/