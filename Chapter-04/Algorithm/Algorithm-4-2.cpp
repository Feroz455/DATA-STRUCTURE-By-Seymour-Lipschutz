/*
page 73
Algorithm 4.2: (Inserting into a Linear Array) INSERT (LA, N, K, ITEM)
Here LA is a linear array with N elements and K is a positive integer 
such that K≤ N. This algorithm inserts an element ITEM into the Kth position in LA.
1. [Initialize counter.] Set J : = N.
2. Repeat Steps 3 and 4 while J ≥ K.
3.         [Move Jth element downward.] Set LA[J + 1] := LA[J].
4.         [Decrease counter.] Set J := J – 1.
[End of Step 2 loop.]
5. [Insert element.] Set LA[K] := ITEM.
6. [Reset N.] Set N := N + 1.
7. Exit.
*/
#include<iostream>
#include<string>
using namespace std;


int NumberOfName;
void INSERT(string LA[],int N, int K, string ITEM)
{
    int J = N;
    while(J >= K)
    {
        LA[J+1] = LA[J];
        J--;
    }
    LA[K] = ITEM;
    NumberOfName++;

}
void DELETE(string LA[],int N, int K, string ITEM)
{
    ITEM = LA[K];
    for(int j = K; j <= N-1; j++)
    {
        LA[j] = LA[j+1];
    }
    NumberOfName--;
}
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

int main()
{
    string Name[100];
    NumberOfName = INPUTNAME(Name);
    PRINT(Name);
    INSERT(Name,NumberOfName, 3-1, "Ford");
    PRINT(Name);
    INSERT(Name,NumberOfName, 6-1, "Taylor");
    PRINT(Name);
    INSERT(Name,NumberOfName, 6-1, "Taylor");
    PRINT(Name);
    INSERT(Name,NumberOfName,NumberOfName, "ZAFAR");
    PRINT(Name);
    DELETE(Name,NumberOfName, 2-1, "Davis");
    PRINT(Name);
    return 0;
}
/*
Enter names
To end input Enter '$$$$$'
Brown 
Davis  
Johnson
Smith  
Wagner 
$$$$$  
*********Printing Name ************
1. Brown
2. Davis
3. Johnson
4. Smith
5. Wagner
*********Printing Name ************
1. Brown
2. Davis
3. Ford
4. Johnson
5. Smith
6. Wagner
*********Printing Name ************
1. Brown
2. Davis
3. Ford
4. Johnson
5. Smith
6. Taylor
7. Wagner
*********Printing Name ************
1. Brown
2. Davis
3. Ford
4. Johnson
5. Smith
6. Taylor
7. Taylor
8. Wagner
*********Printing Name ************
1. Brown
2. Ford
3. Johnson
4. Smith
5. Taylor
6. Taylor
7. Wagner
*/