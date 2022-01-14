/*
5.10 Suppose STRING is a character string in memory.

(a) Write a procedure which prints SUBSTRING(STRING, K, N), which is the substring of STRING beginning with the Kth character and of length N.

(b) Write a procedure which creates a new string SUBKN in memory where

SUBKN = SUBSTRING(STRING, K, N)
*/
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
    char CHAR;
    _link *next;
    _link *prev;
}LINKED;
void INSERT_END(LINKED **START, char CHAR)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->CHAR = CHAR;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->CHAR = CHAR;

        NEW->next = (*START);
        NEW->prev = LAST;
        (*START)->prev = NEW;
        LAST->next = NEW;
    }   
}
void DISPLAY_FORWORD( LINKED **START)
{
    if((*START) == NULL)
    {
        cout << "LIST IS EMPTY\n";
        return;
    }
    LINKED *PTR = (*START);
    while (PTR->next != *START)
    {
        cout << PTR->CHAR << " -> ";
        PTR = PTR->next;
    }
    cout << PTR->CHAR << "\n"; 

}
LINKED * PRINT_SUB_STR(LINKED **START , int K, int N)
{
    LINKED *PTR = (*START), *TEMP = NULL;
    while (K--)
    {
        PTR = PTR->next;
    }
    while (N--)
    {
        //cout << PTR->CHAR << " ";
        INSERT_END(&TEMP, PTR->CHAR);
        PTR = PTR->next;
    }
    return TEMP;

}
int main()
{
    srand(time(0));
    LINKED *START = NULL;
    for(char i = 0 ; i < 26;  i++)
    {
        INSERT_END(&START,i+65);
    }
    DISPLAY_FORWORD(&START);
    LINKED *SUBKN = PRINT_SUB_STR(&START, 10, 5);
    DISPLAY_FORWORD(&SUBKN);
}
/*
OUTPUT 
A -> B -> C -> D -> E -> F -> G -> H -> I -> J -> K -> L -> M -> N -> O -> P -> Q -> R -> S -> T -> U -> V -> W -> X -> Y -> Z
K L M N O
A -> B -> C -> D -> E -> F -> G -> H -> I -> J -> K -> L -> M -> N -> O -> P -> Q -> R -> S -> T -> U -> V -> W -> X -> Y -> Z
K -> L -> M -> N -> O
*/