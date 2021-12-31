/*
Page 111
Program 
4.5 Write a program which reads the (last) NAME of a student and uses BINARY to find and print the 
student’s record. Test the program using 
(a) Rogers, 
(b) Johnson and 
(c) Bailey.
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct STUDENT
{
    string SSN;
    string LAST;
    string GIVEN;
    float CUM;
    int YEAR;
};
void INPUT(STUDENT DATA[], int N)
{
   for(int i = 0; i < N; i++)
    {
        cin >> DATA[i].SSN;
        cin >> DATA[i].LAST;
        cin >> DATA[i].GIVEN;
        cin >> DATA[i].CUM;
        cin >> DATA[i].YEAR;
    }

}

void OUTPUT(STUDENT DATA[], int N)
{
    for(int i = 0; i < N; i++)
    {
        cout << setw(3) << i+1 << ". " ;
        cout << setw(10) <<  DATA[i].SSN ;
        cout << setw(10) <<  DATA[i].LAST ;
        cout << setw(15) <<  DATA[i].GIVEN ;
        cout << setw(10) <<  DATA[i].CUM ;
        cout << setw(10) <<  DATA[i].YEAR << endl;
    }
}
void CUM_RANGE(STUDENT DATA[], int N, float K)
{
    cout << "\n\nListing all students in year L. (Test the program using L = 2, or sophomore.)\n\n";
    cout << "\n  ***********************************************************\n";
    for(int i = 0; i < N; i++)
    {
        if(DATA[i].CUM >= K)
        {
            cout << setw(3) << i+1 << ". " ;
            cout << setw(10) <<  DATA[i].SSN ;
            cout << setw(10) <<  DATA[i].LAST ;
            cout << setw(15) <<  DATA[i].GIVEN ;
            cout << setw(10) <<  DATA[i].CUM ;
            cout << setw(10) <<  DATA[i].YEAR << endl;
        }
        
    }
}

void YEAR_RANGE(STUDENT DATA[], int N, int K)
{
    cout << "\n\nListing all students whose CUM is K or higher. (Test the program using K = 3.00.)\n\n";
    cout << "\n  ***********************************************************\n";
    for(int i = 0; i < N; i++)
    {
        if(DATA[i].YEAR == K)
        {
            cout << setw(3) << i+1 << ". " ;
            cout << setw(10) <<  DATA[i].SSN ;
            cout << setw(10) <<  DATA[i].LAST ;
            cout << setw(15) <<  DATA[i].GIVEN ;
            cout << setw(10) <<  DATA[i].CUM ;
            cout << setw(10) <<  DATA[i].YEAR << endl;
        }
        
    }
}
/****************Linear Search*********************/
template<typename T>
int LINEAR(T DATA[],int LB, int UB, string ITEM)
{
    int K = LB;
    int LOC = -1;
    while(LOC == -1 && K <= UB)
    {
        if(ITEM == DATA[K].SSN)
            LOC = K ;
        K++;
    }
    return LOC+1;
}
/**********Binay Search*****************/
/*****************************************/
template<typename T>
int BINARY(STUDENT DATA[], int LB, int UB, string ITEM, int LOC)
{
    int BEG, END, MID;
    BEG = LB;
    END = UB;
    MID = (int)((LB+UB)/2);
    while(BEG <= END && DATA[MID].LAST != ITEM)
    {
        if(ITEM < DATA[MID].LAST)
        {
            END = MID - 1;
        }
        else 
        BEG = MID + 1;
        MID = (int)((BEG + END) / 2);        
    }
    if(DATA[MID].LAST == ITEM)
    LOC = MID;
    else
    LOC = -1;
    return LOC+1;
}


/*****************************************/
/**********Binay Search*****************/
void CHECK(STUDENT DATA[], int N, string ITEM)
{
    cout << "\n**************************************************\n";
    cout << ITEM << " Searching ...\n";
    int LOC = BINARY<STUDENT>(DATA, 0 , N, ITEM, 0);
    
    cout << "**************************************************\n";
    if( LOC != 0)
    {
            cout << setw(10) <<  DATA[LOC-1].SSN ;
            cout << setw(10) <<  DATA[LOC-1].LAST ;
            cout << setw(15) <<  DATA[LOC-1].GIVEN ;
            cout << setw(10) <<  DATA[LOC-1].CUM ;
            cout << setw(10) <<  DATA[LOC-1].YEAR << endl;
    }
    else 
    cout << "RESULT NOT FOUND\n";
}

//Main from Here
int main()
{
    int N = 18;
    STUDENT student[N];
    INPUT(student, N);

    cout << "\n***********\n";
    OUTPUT(student, N);
    CUM_RANGE(student, N, 3.0);
    YEAR_RANGE(student, N, 2);
    CHECK(student, N, "ROgers");
    CHECK(student, N, "Johnson");
    CHECK(student, N, "Bailey");

}

/*
Output
    211-58-1329     Adams          Bruce      2.55         2
    169-38-4248    Bailey       Irene_L.      3.25         4
    166-48-5842     Cheng            Kim       3.4         1
    187-52-4076     Davis        John_C.      2.85         1
    126-63-6382   Edwards         Steven      1.75         2
    135-58-9565       Fox        Kenneth       2.8         3
    172-48-1849     Green      Gerald_S.      2.35         2
    192-60-3157   Hopkins           Gary       2.7         2
    160-60-1826     Klein     Deborah_M.      3.05         2
    166-52-4147       Lee           John       2.6         3
    186-58-0430    Murphy        William       2.3         2
    187-58-1123    Newman      Ronald_P.       3.9         4
    174-58-0732    Osborn           Paul      2.05         3
    183-52-3865    Parker          David      1.55         2
    135-48-1397    Rogers        Mary_J.      1.85         1
    182-52-6712    Schwab         Joanna      2.95         2
    184-48-8539  Thompson       David_E.      3.15         3
    187-48-2377     White           Adam       2.5         2

***********
  1. 211-58-1329     Adams          Bruce      2.55         2
  2. 169-38-4248    Bailey       Irene_L.      3.25         4
  3. 166-48-5842     Cheng            Kim       3.4         1
  4. 187-52-4076     Davis        John_C.      2.85         1
  5. 126-63-6382   Edwards         Steven      1.75         2
  6. 135-58-9565       Fox        Kenneth       2.8         3
  7. 172-48-1849     Green      Gerald_S.      2.35         2
  8. 192-60-3157   Hopkins           Gary       2.7         2
  9. 160-60-1826     Klein     Deborah_M.      3.05         2
 10. 166-52-4147       Lee           John       2.6         3
 11. 186-58-0430    Murphy        William       2.3         2
 12. 187-58-1123    Newman      Ronald_P.       3.9         4
 13. 174-58-0732    Osborn           Paul      2.05         3
 14. 183-52-3865    Parker          David      1.55         2
 15. 135-48-1397    Rogers        Mary_J.      1.85         1
 16. 182-52-6712    Schwab         Joanna      2.95         2
 17. 184-48-8539  Thompson       David_E.      3.15         3
 18. 187-48-2377     White           Adam       2.5         2


Listing all students in year L. (Test the program using L = 2, or sophomore.)


  ***********************************************************
  2. 169-38-4248    Bailey       Irene_L.      3.25         4
  3. 166-48-5842     Cheng            Kim       3.4         1
  9. 160-60-1826     Klein     Deborah_M.      3.05         2
 12. 187-58-1123    Newman      Ronald_P.       3.9         4
 17. 184-48-8539  Thompson       David_E.      3.15         3


Listing all students whose CUM is K or higher. (Test the program using K = 3.00.)


  ***********************************************************
  1. 211-58-1329     Adams          Bruce      2.55         2
  5. 126-63-6382   Edwards         Steven      1.75         2
  7. 172-48-1849     Green      Gerald_S.      2.35         2
  8. 192-60-3157   Hopkins           Gary       2.7         2
  9. 160-60-1826     Klein     Deborah_M.      3.05         2
 11. 186-58-0430    Murphy        William       2.3         2
 14. 183-52-3865    Parker          David      1.55         2
 16. 182-52-6712    Schwab         Joanna      2.95         2
 18. 187-48-2377     White           Adam       2.5         2

    **************************************************
    ROgers Searching ...
    **************************************************
    RESULT NOT FOUND

    **************************************************
    Johnson Searching ...
    **************************************************
    RESULT NOT FOUND

    **************************************************
    Bailey Searching ...
    **************************************************
    169-38-4248    Bailey       Irene_L.      3.25         4
*/