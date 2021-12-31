/*
Page 110
Program 
4.3 Translate the binary search and insertion algorithm into a subprogram 
BINARY(ARRAY, LB, UB, ITEM, LOC) which finds either the location LOC where 
ITEM appears in ARRAY or the location LOC where ITEM should be inserted into ARRAY.
*/
#include<iostream>
#include<string>
using namespace std;
/*****************************************/
template<typename T>
int BINARY(T DATA[], int LB, int UB, T ITEM, int LOC)
{
    int BEG, END, MID;
    BEG = LB;
    END = UB;
    MID = (int)((LB+UB)/2);
    while(BEG <= END && DATA[MID] != ITEM)
    {
        if(ITEM < DATA[MID])
        {
            END = MID - 1;
        }
        else 
        BEG = MID + 1;
        MID = (int)((BEG + END) / 2);        
    }
    if(DATA[MID] == ITEM)
    LOC = MID;
    else
    if(ITEM < DATD[MID])
    LOC = MID;
    else
    LOC = MID + 1;
    INSERT<string>(DATA, LOC, ITEM);
    return LOC;
}

/****************************/
template<typename T>
void INSERT(T LA[],int N, int K, T ITEM)
{
    int J = N;
    while(J >= K)
    {
        LA[J+1] = LA[J];
        J--;
    }
    LA[K] = ITEM;
    Global_J++;
}
//Main from Here
int main()
{

}

/*
Output

*/