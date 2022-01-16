/*

*/
#include<iostream>
#include<iomanip>
using namespace std;
class STACK
{
    private:
    typedef struct _node
        {
            string  DATA;
            _node *next;
        }STK;
        int MAXSTK;
        int AVAIL;
        STK *START;
    
    public:
        STACK(int N);
        ~STACK();
        void PUSH(string DATA);
        string POP();
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
        cout << "OVERFLOW\n";
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
string STACK::POP()
{
    if(START== nullptr)
    {
        cout << "UNDER FLOW\n";
        return "NULL";
    }
    string temp = START->DATA;
    START = START->next;
    AVAIL++;
    MAXSTK--;
    return temp;
}
void STACK::DISPLAY()
{
    string ITEM = POP();
    int CK = 1;
    while(ITEM != "NULL")
    {
        cout <<CK++ <<  " " << ITEM<< " \n";
        ITEM = POP();
    }
    

}
STACK::~STACK()
{
}
int main()
{
    string temp;
    STACK S(10);
    for(int  i  = 0 ; i < 4; i++)
    {   
        cin >> temp;
        S.PUSH(temp);
        
    };
    S.DISPLAY();
}
