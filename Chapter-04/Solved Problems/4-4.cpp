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

(a) Find the number of elements that must be moved if Brown, 
Johnson and Peters are inserted into NAME at three different times.

(b) How many elements are moved if the three names are inserted at the same time?

(c) How does the telephone company handle insertions in a telephone directory?
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