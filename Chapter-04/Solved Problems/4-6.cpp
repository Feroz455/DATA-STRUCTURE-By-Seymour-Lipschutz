/*
Page 99
Program
4.6 Suppose the binary search algorithm, Algorithm 4.6, 
is applied to the array NAME in Fig. 4.23 to find the 
location of Goodman. Find the ends BEG and END and the 
middle MID for the test segment in each step of the algorithm
*/
#include<iostream>
#include<iomanip>
using namespace std;
int NumberOfName;
/***************************************************/
template<typename T>
int BINARY(T DATA[], int UB, T ITEM)
{
    int BEG, END, MID, LOC = 0, LB = 0;
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
    LOC = -1;
    return LOC;
}
/********************************************/
void INSERT(string LA[], int K, string ITEM)
{
    int J = NumberOfName;
    while(J >= K)
    {
        LA[J+1] = LA[J];
        J--;
    }
    LA[K] = ITEM;
    NumberOfName++;
}

/**********/
void DELETE(string LA[],int N, int K, string ITEM)
{
    ITEM = LA[K];
    for(int j = K; j <= N-1; j++)
    {
        LA[j] = LA[j+1];
    }
    NumberOfName--;
}
/********/
void PRINT(string Name[])
{
    cout << "*********Printing Name ************\n";
  for(int i = 0; i < 100; i++)
    {
        if(Name[i] == "$$$$$")
            return;
        cout << i+1 << ". " << Name[i] <<   endl;
        
        
    }
}
/***********/
int  INPUTNAME(string Name[])
{
    cout << "Enter names \n";
    cout <<  "To end input Enter '$$$$$'\n";
    for(int i = 0; i < 100; i++)
    {
        cin >> Name[i];
        if(Name[i] == "$$$$$")
            return i;
    }
    return 0;
}
/****************Linear Search*********************/
template<typename T>
int LINEAR(T DATA[], int N, T ITEM)
{
    int K = 0;
    int LOC = -1;
    while(LOC == -1 && K <= N)
    {
        if(ITEM == DATA[K])
            LOC = K ;
    //B..
        if(ITEM < DATA[K])
        break;
        K++;
    }
    return LOC;
}
/*******/
void CHECK(int ck)
{
    if(ck != -1)
    {
        cout << "\nItem Found at " << ck  << endl;
    }
    else 
    cout << "\nItem not found \n";
}
/*****************************/
template<typename T>
void Bubble(T DATA[], int N)
{
    T CHANGE;
    for(int K = 0; K < N; K++)
    {
        for(int PTR = 0; PTR < N - K; PTR++)
        {
            if(DATA[PTR]> DATA[PTR+1])
            {
                CHANGE = DATA[PTR];
                DATA[PTR] = DATA[PTR+1];
                DATA[PTR+1] = CHANGE;
            }
        }
    }
    return;
}
//Main from Here
int main()
{
    string Name[100];
    NumberOfName = INPUTNAME(Name);
    PRINT(Name);
    Bubble<string>(Name, NumberOfName);
    PRINT(Name);
    CHECK(LINEAR<string>(Name, NumberOfName, "Hobbs"));
    CHECK(LINEAR<string>(Name, NumberOfName, "Morgan"));
    CHECK(BINARY<string>(Name,NumberOfName,"Goodman"));

}

/*
Output
Enter names
To end input Enter '$$$$$'
Allen
Clark
Dickens
Edwards
Goodman
Hobbs
Irwin
Klein
Lewis
Morgan
Richards
Scott
Tucker
Walton
$$$$$
*********Printing Name ************
1. Allen
2. Clark
3. Dickens
4. Edwards
5. Goodman
6. Hobbs
7. Irwin
8. Klein
9. Lewis
10. Morgan
11. Richards
12. Scott
13. Tucker
14. Walton
*********Printing Name ************

Item Found at 6

Item Found at 10

Item Found at 5
*/