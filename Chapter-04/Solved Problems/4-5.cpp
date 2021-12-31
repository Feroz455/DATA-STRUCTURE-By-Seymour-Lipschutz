/*
Page 99
Program

Fig. 4.23
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
4.5 Consider the alphabetized linear array NAME in Fig. 4.23.

(a) Using the linear search algorithm, Algorithm 4.5, how many 
comparisons C are used to locate Hobbs, Morgan and Fisher?

(b) Indicate how the algorithm may be changed for such a sorted 
array to make an unsuccessful search more efficient. How does this affect part (a)
*/
#include<iostream>
#include<iomanip>
using namespace std;
int NumberOfName;
/*****/
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
    return LOC+1;
}
/*******/
void CHECK(int ck)
{
    if(ck != 0)
    {
        cout << "\nItem Found at " << ck  << endl;
    }
    else 
    cout << "\nItem not found \n";
}
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
    INSERT(Name,2,"Brown");
    PRINT(Name);
    INSERT(Name,8,"Johnson");
    PRINT(Name);
    INSERT(Name,11,"Peters");
    PRINT(Name);
    Bubble<string>(Name, NumberOfName);
    PRINT(Name);
    CHECK(LINEAR<string>(Name, NumberOfName, "Hobbs"));
    CHECK(LINEAR<string>(Name, NumberOfName, "Morgan"));
    CHECK(LINEAR<string>(Name, NumberOfName, "FIsher"));

}

/*
Output
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
1. Allen
2. Clark
3. Brown
4. Dickens
5. Edwards
6. Goodman
7. Hobbs
8. Irwin
9. Klein
10. Lewis
11. Morgan
12. Richards
13. Scott
14. Tucker
15. Walton
*********Printing Name ************
1. Allen
2. Clark
3. Brown
4. Dickens
5. Edwards
6. Goodman
7. Hobbs
8. Irwin
9. Johnson
10. Klein
11. Lewis
12. Morgan
13. Richards
14. Scott
15. Tucker
16. Walton
*********Printing Name ************
1. Allen
2. Clark
3. Brown
4. Dickens
5. Edwards
6. Goodman
7. Hobbs
8. Irwin
9. Johnson
10. Klein
11. Lewis
12. Peters
13. Morgan
14. Richards
15. Scott
16. Tucker
17. Walton
*/