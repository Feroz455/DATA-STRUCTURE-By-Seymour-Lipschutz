/*
Page 110
Program 
Write a program which reads the Name Of a Student and uses BAINARY too delete the student's
record from the list. Test the program using 
a) Parker
b) Fox

*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int  NumberOfItem = 18;
struct STUDENT
{
    string SSN;
    string LAST;
    string GIVEN;
    float CUM;
    int YEAR;
};
void INPUT(STUDENT DATA[])
{
   for(int i = 0; i < NumberOfItem; i++)
    {
        cin >> DATA[i].SSN;
        cin >> DATA[i].LAST;
        cin >> DATA[i].GIVEN;
        cin >> DATA[i].CUM;
        cin >> DATA[i].YEAR;
    }

}

void OUTPUT(STUDENT DATA[])
{
    cout <<"\n\n*************************************************************\n";
    for(int i = 0; i < NumberOfItem; i++)
    {
        cout << setw(3) << i+1 << ". " ;
        cout << setw(10) <<  DATA[i].SSN ;
        cout << setw(10) <<  DATA[i].LAST ;
        cout << setw(15) <<  DATA[i].GIVEN ;
        cout << setw(10) <<  DATA[i].CUM ;
        cout << setw(10) <<  DATA[i].YEAR << endl;
    }
}
void CUM_RANGE(STUDENT DATA[], float K)
{
    cout << "\n\nListing all students in year L. (Test the program using L = 2, or sophomore.)\n\n";
    cout << "\n  ***********************************************************\n";
    for(int i = 0; i < NumberOfItem; i++)
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

void YEAR_RANGE(STUDENT DATA[], int K)
{
    cout << "\n\nListing all students whose CUM is K or higher. (Test the program using K = 3.00.)\n\n";
    cout << "\n  ***********************************************************\n";
    for(int i = 0; i < NumberOfItem; i++)
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
void INSERT(STUDENT LA[], int K,STUDENT ITEM)
{
    int J = NumberOfItem;
    while(J >= K)
    {
        LA[J+1].LAST  = LA[J].LAST;
        LA[J+1].GIVEN = LA[J].GIVEN;
        LA[J+1].CUM   = LA[J].CUM;
        LA[J+1].SSN   = LA[J].SSN;
        LA[J+1].YEAR  = LA[J].YEAR;
        
        J--;
    }
        LA[K].LAST  = ITEM.LAST;
        LA[K].GIVEN = ITEM.GIVEN;
        LA[K].CUM   = ITEM.CUM;
        LA[K].SSN   = ITEM.SSN;
        LA[K].YEAR  = ITEM.YEAR;
    NumberOfItem++;

}
/**********Binary Search*************/
int BINARY(STUDENT DATA[], int LB, int UB, STUDENT ITEM, int LOC)
{
    int BEG, END, MID;
    BEG = LB;
    END = UB;
    MID = (int)((LB+UB)/2);
    while(BEG <= END && DATA[MID].SSN != ITEM.SSN)
    {
        if(ITEM.SSN < DATA[MID].SSN)
        {
            END = MID - 1;
        }
        else 
        BEG = MID + 1;
        MID = (int)((BEG + END) / 2);        
    }
    if(DATA[MID].SSN == ITEM.SSN)
    LOC = MID;
    else
    if(ITEM.SSN < DATA[MID].SSN)
    {
        LOC = MID;
        INSERT(DATA, LOC, ITEM);
    }
    else
    {
        LOC = MID + 1;
        INSERT(DATA, LOC, ITEM);
    }

    return LOC;
}
STUDENT DELETE(STUDENT DATA[], int K)
{
   // ITEM = DATA[K];
    STUDENT CHANGE;
    CHANGE.CUM   = DATA[K].CUM; 
    CHANGE.GIVEN = DATA[K].GIVEN; 
    CHANGE.LAST  = DATA[K].LAST; 
    CHANGE.SSN   = DATA[K].SSN; 
    CHANGE.YEAR  = DATA[K].YEAR;
    for(int j = K; j < NumberOfItem; j++)
    {
        //LA[j] = LA[j+1];
        DATA[j].CUM   = DATA[j+1].CUM;
        DATA[j].GIVEN = DATA[j+1].GIVEN;
        DATA[j].LAST  = DATA[j+1].LAST;
        DATA[j].SSN   = DATA[j+1].SSN;
        DATA[j].YEAR  = DATA[j+1].YEAR;
    }
    NumberOfItem--;
    return CHANGE;
}


STUDENT BINARY_DELETE(STUDENT DATA[], int LB, int UB, string ITEM, int LOC)
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
    STUDENT REMOVE =  DELETE(DATA, LOC);
    return REMOVE;
}
/**********************************/
void CHECK(STUDENT DATA[], STUDENT ITEM)
{
    cout << "\n**************************************************\n";
    cout << ITEM.SSN << " Searching ...\n";
    //int BINARY(STUDENT DATA[], int LB, int UB, STUDENT ITEM, int LOC)
    int LOC = BINARY(DATA, 0, NumberOfItem, ITEM,0);
    
    cout << "**************************************************\n";
    if( LOC != 0)
    {
            cout << setw(10) <<  DATA[LOC].SSN ;
            cout << setw(10) <<  DATA[LOC].LAST ;
            cout << setw(15) <<  DATA[LOC].GIVEN ;
            cout << setw(10) <<  DATA[LOC].CUM ;
            cout << setw(10) <<  DATA[LOC].YEAR << endl;
    }
    else 
    cout << "RESULT NOT FOUND\n";
}


void CHECK_DELETE(STUDENT DATA[], string Name)
{
    STUDENT REMOVE = BINARY_DELETE(DATA,0,NumberOfItem,Name,0);
    cout << "Removed item is \n";
    cout << setw(10) <<  REMOVE.SSN ;
    cout << setw(10) <<  REMOVE.LAST ;
    cout << setw(15) <<  REMOVE.GIVEN ;
    cout << setw(10) <<  REMOVE.CUM ;
    cout << setw(10) <<  REMOVE.YEAR << endl;
}
void Bubble_Sort(STUDENT DATA[], int N)
{
    int K, PTR;
    STUDENT CHANGE;
    N = N - 1;
    for(K = 0; K < N; K++)
    {
        PTR = 0;
        while(PTR < (N - K))
        {
            if(DATA[PTR].LAST > DATA[PTR+1].LAST)
            {
                CHANGE.CUM = DATA[PTR].CUM; 
                CHANGE.GIVEN = DATA[PTR].GIVEN; 
                CHANGE.LAST = DATA[PTR].LAST; 
                CHANGE.SSN = DATA[PTR].SSN; 
                CHANGE.YEAR=DATA[PTR].YEAR;
                /*******************************/
                DATA[PTR].CUM   = DATA[PTR+1].CUM;
                DATA[PTR].GIVEN = DATA[PTR+1].GIVEN;
                DATA[PTR].LAST  = DATA[PTR+1].LAST;
                DATA[PTR].SSN   = DATA[PTR+1].SSN;
                DATA[PTR].YEAR  = DATA[PTR+1].YEAR;
                /*********************************/
                DATA[PTR+1].CUM = CHANGE.CUM;
                DATA[PTR+1].GIVEN = CHANGE.GIVEN;
                DATA[PTR+1].LAST = CHANGE.LAST;
                DATA[PTR+1].SSN = CHANGE.SSN;
                DATA[PTR+1].YEAR = CHANGE.YEAR;
            }
            
            PTR++;
        }
    }
    return;
}
//Main from Here
int main()
{
    STUDENT student[30];
    INPUT(student);

    cout << "\n***********\n";
    OUTPUT(student);
    Bubble_Sort(student,NumberOfItem);
    OUTPUT(student);
    /*
    (a) 168-48-2255, Quinn, Michael, 2.15, 3
    (b) 177-58-0772, Jones, Amy, 2.75, 2
    */
    STUDENT ST;
    ST.SSN = "168-48-2255";
    ST.LAST = "Quinn";
    ST.GIVEN = "Michael";
    ST.CUM = 2.15;
    ST.YEAR = 3;
    CHECK(student,ST);

    OUTPUT(student);
    STUDENT STT;
    STT.SSN = "177-58-0772";
    STT.LAST = "Jones";
    STT.GIVEN = "Amy";
    STT.CUM = 2.75;
    STT.YEAR = 2;
    CHECK(student,STT);
    OUTPUT(student);
    CHECK_DELETE(student, "Parker");
    OUTPUT(student);
    CHECK_DELETE(student, "Fox");
    OUTPUT(student);


}
/*
OUTPUT
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


*************************************************************
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


*************************************************************
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

**************************************************
168-48-2255 Searching ...
**************************************************
168-48-2255     Quinn        Michael      2.15         3


*************************************************************
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
 16. 168-48-2255     Quinn        Michael      2.15         3
 17. 182-52-6712    Schwab         Joanna      2.95         2
 18. 184-48-8539  Thompson       David_E.      3.15         3
 19. 187-48-2377     White           Adam       2.5         2

**************************************************
177-58-0772 Searching ...
**************************************************
177-58-0772     Jones            Amy      2.75         2


*************************************************************
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
 16. 168-48-2255     Quinn        Michael      2.15         3
 17. 177-58-0772     Jones            Amy      2.75         2
 18. 182-52-6712    Schwab         Joanna      2.95         2
 19. 184-48-8539  Thompson       David_E.      3.15         3
 20. 187-48-2377     White           Adam       2.5         2
Removed item is
183-52-3865    Parker          David      1.55         2


*************************************************************
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
 14. 135-48-1397    Rogers        Mary_J.      1.85         1
 15. 168-48-2255     Quinn        Michael      2.15         3
 16. 177-58-0772     Jones            Amy      2.75         2
 17. 182-52-6712    Schwab         Joanna      2.95         2
 18. 184-48-8539  Thompson       David_E.      3.15         3
 19. 187-48-2377     White           Adam       2.5         2
Removed item is
135-58-9565       Fox        Kenneth       2.8         3


*************************************************************
  1. 211-58-1329     Adams          Bruce      2.55         2
  2. 169-38-4248    Bailey       Irene_L.      3.25         4
  3. 166-48-5842     Cheng            Kim       3.4         1
  4. 187-52-4076     Davis        John_C.      2.85         1
  5. 126-63-6382   Edwards         Steven      1.75         2
  6. 172-48-1849     Green      Gerald_S.      2.35         2
  7. 192-60-3157   Hopkins           Gary       2.7         2
  8. 160-60-1826     Klein     Deborah_M.      3.05         2
  9. 166-52-4147       Lee           John       2.6         3
 10. 186-58-0430    Murphy        William       2.3         2
 11. 187-58-1123    Newman      Ronald_P.       3.9         4
 12. 174-58-0732    Osborn           Paul      2.05         3
 13. 135-48-1397    Rogers        Mary_J.      1.85         1
 14. 168-48-2255     Quinn        Michael      2.15         3
 15. 177-58-0772     Jones            Amy      2.75         2
 16. 182-52-6712    Schwab         Joanna      2.95         2
 17. 184-48-8539  Thompson       David_E.      3.15         3
 18. 187-48-2377     White           Adam       2.5         2
*/