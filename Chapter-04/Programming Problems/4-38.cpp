/*
Page 110
Program 
4.6 Write a program which reads the record of a student
SSNST,   LASTST,   GVNST,   CUMST,   YEARST
and uses BINARY to insert the record into the list. Test the program using:
(a) 168-48-2255, Quinn, Michael, 2.15, 3
(b) 177-58-0772, Jones, Amy, 2.75, 2
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
struct TRACK
{
    string NUMBER;
    STUDENT *PTR;
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
/**********Binary Search*************/
int BINARY(TRACK DATA[], int LB, int UB, string ITEM, int LOC)
{
    int BEG, END, MID;
    BEG = LB;
    END = UB;
    MID = (int)((LB+UB)/2);
    while(BEG <= END && DATA[MID].NUMBER != ITEM)
    {
        if(ITEM < DATA[MID].NUMBER)
        {
            END = MID - 1;
        }
        else 
        BEG = MID + 1;
        MID = (int)((BEG + END) / 2);        
    }
    if(DATA[MID].NUMBER == ITEM)
    LOC = MID;
    else
    LOC = -1;

    return LOC+1;
}
/**********************************/
void CHECK(TRACK DATA[], string ITEM)
{
    cout << "\n**************************************************\n";
    cout << ITEM << " Searching ...\n";
    //int BINARY(STUDENT DATA[], int LB, int UB, STUDENT ITEM, int LOC)
    int LOC = BINARY(DATA, 0, NumberOfItem, ITEM,0);
    cout << "LOC = " << LOC << "\n";
    
    cout << "**************************************************\n";
    if( LOC != 0)
    {
            cout << setw(10) <<  DATA[LOC-1].PTR->SSN ;
            cout << setw(10) <<  DATA[LOC-1].PTR->LAST ;
            cout << setw(15) <<  DATA[LOC-1].PTR->GIVEN ;
            cout << setw(10) <<  DATA[LOC-1].PTR->CUM ;
            cout << setw(10) <<  DATA[LOC-1].PTR->YEAR << endl;
    }
    else 
    cout << "RESULT NOT FOUND\n";
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
            if(DATA[PTR].SSN > DATA[PTR+1].SSN)
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
void copySSN(STUDENT DATA[], TRACK TT[])
{
    for(int i = 0; i < NumberOfItem; i++)
    {
        TT[i].NUMBER = DATA[i].SSN;
        cout << "NUMBER " << TT[i].NUMBER << "\n";
        TT[i].PTR = &DATA[i];
        cout << "TT[i].PTR =  " << TT[i].PTR << "\n"; 
    }
}
//Main from Here
int main()
{
    STUDENT student[30];
    TRACK track[30];
    INPUT(student);
    Bubble_Sort(student, NumberOfItem);
    OUTPUT(student);
    //Bubble_Sort(student, NumberOfItem);
    copySSN(student,track);

    string NUMBER;
    cout << "Enter SSN \n";
    cin >> NUMBER;
    while(NUMBER != "$$$$$")
    {
        cout << "NUMBER =  " << NUMBER << "\n";
        CHECK(track,NUMBER);
        cout << "Enter SSN \n";
        cin >> NUMBER;
    }

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


*************************************************************
  1. 126-63-6382   Edwards         Steven      1.75         2
  2. 135-48-1397    Rogers        Mary_J.      1.85         1
  3. 135-58-9565       Fox        Kenneth       2.8         3
  4. 160-60-1826     Klein     Deborah_M.      3.05         2
  5. 166-48-5842     Cheng            Kim       3.4         1
  6. 166-52-4147       Lee           John       2.6         3
  7. 169-38-4248    Bailey       Irene_L.      3.25         4
  8. 172-48-1849     Green      Gerald_S.      2.35         2
  9. 174-58-0732    Osborn           Paul      2.05         3
 10. 182-52-6712    Schwab         Joanna      2.95         2
 11. 183-52-3865    Parker          David      1.55         2
 12. 184-48-8539  Thompson       David_E.      3.15         3
 13. 186-58-0430    Murphy        William       2.3         2
 14. 187-48-2377     White           Adam       2.5         2
 15. 187-52-4076     Davis        John_C.      2.85         1
 16. 187-58-1123    Newman      Ronald_P.       3.9         4
 17. 192-60-3157   Hopkins           Gary       2.7         2
 18. 211-58-1329     Adams          Bruce      2.55         2
NUMBER 126-63-6382
TT[i].PTR =  0x61f1c0
NUMBER 135-48-1397
TT[i].PTR =  0x61f228
NUMBER 135-58-9565
TT[i].PTR =  0x61f290
NUMBER 160-60-1826
TT[i].PTR =  0x61f2f8
NUMBER 166-48-5842
TT[i].PTR =  0x61f360
NUMBER 166-52-4147
TT[i].PTR =  0x61f3c8
NUMBER 169-38-4248
TT[i].PTR =  0x61f430
NUMBER 172-48-1849
TT[i].PTR =  0x61f498
NUMBER 174-58-0732
TT[i].PTR =  0x61f500
NUMBER 182-52-6712
TT[i].PTR =  0x61f568
NUMBER 183-52-3865
TT[i].PTR =  0x61f5d0
NUMBER 184-48-8539
TT[i].PTR =  0x61f638
NUMBER 186-58-0430
TT[i].PTR =  0x61f6a0
NUMBER 187-48-2377
TT[i].PTR =  0x61f708
NUMBER 187-52-4076
TT[i].PTR =  0x61f770
NUMBER 187-58-1123
TT[i].PTR =  0x61f7d8
NUMBER 192-60-3157
TT[i].PTR =  0x61f840
NUMBER 211-58-1329
TT[i].PTR =  0x61f8a8
Enter SSN
211-58-1329
NUMBER =  211-58-1329

**************************************************
211-58-1329 Searching ...
LOC = 18
**************************************************
211-58-1329     Adams          Bruce      2.55         2
Enter SSN
187-48-2377
NUMBER =  187-48-2377

**************************************************
187-48-2377 Searching ...
LOC = 14
**************************************************
187-48-2377     White           Adam       2.5         2
Enter SSN
174-58-0732
NUMBER =  174-58-0732

**************************************************
174-58-0732 Searching ...
LOC = 9
**************************************************
174-58-0732    Osborn           Paul      2.05         3
Enter SSN
172-55-5554
NUMBER =  172-55-5554

**************************************************
172-55-5554 Searching ...
LOC = 0
**************************************************
RESULT NOT FOUND
Enter SSN
126-63-6382
NUMBER =  126-63-6382

**************************************************
126-63-6382 Searching ...
LOC = 1
**************************************************
126-63-6382   Edwards         Steven      1.75         2
*/