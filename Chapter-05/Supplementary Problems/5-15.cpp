/*
PAGE 158
5.3 Suppose LIST is a linked list in memory consisting 
of numerical values. Write a procedure for each of the following:

(a) Finding the maximum MAX of the values in LIST

(b) Finding the average MEAN of the values in LIST

(c) Finding the product PROD of the elements in LIST
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
using namespace std;
typedef struct _link
{
    int DATA;
    _link *next;
    _link *prev;
}LINKED;
void INSERT_END(LINKED **START, int DATA)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->DATA = DATA;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->DATA = DATA;

        NEW->next = (*START);
        NEW->prev = LAST;
        (*START)->prev = NEW;
        LAST->next = NEW;
    }   
}
void DISPLAY_FORWORD( LINKED **START)
{
    int MAX, MEAN = 0 , PROD = 1, CHECK = 1, SUM = 0;
    if((*START) == NULL)
    {
        cout << "LIST IS EMPTY\n";
        return;
    }
    MAX =(*START)->DATA;
    LINKED *PTR = (*START);
    while (PTR->next != *START)
    {
        SUM += PTR->DATA;
        PROD *= PTR->DATA;
        if(MAX < PTR->DATA)
        {
            MAX = PTR->DATA;
        }
        cout << PTR->DATA << " -> ";
        PTR = PTR->next;
        CHECK++;
    }
    cout << PTR->DATA << "\n"; 
    SUM += PTR->DATA;
    PROD *= PTR->DATA;
    if(MAX < PTR->DATA)
        {
            MAX = PTR->DATA;
        }
    cout << "MAX VALUE IS = " << MAX << endl;
    cout << "NUMBER OF ELEMENT = " << CHECK << endl;
    cout << "AVEREGE MEAN = " << SUM / CHECK << endl;
    cout << "PRODUCT OF ALL NUMBER = " << PROD << endl;

}
int main()
{
    srand(time(0));
    LINKED *START = NULL;
    
    for(int i = 0 ; i < 5;  i++)
    {
        INSERT_END(&START,(rand()%10)+1);
    }
    DISPLAY_FORWORD(&START);
}
/*
OUTPUT 
10 -> 10 -> 8 -> 6 -> 4      
MAX VALUE IS = 10
NUMBER OF ELEMENT = 5        
AVEREGE MEAN = 7
PRODUCT OF ALL NUMBER = 19200
*/