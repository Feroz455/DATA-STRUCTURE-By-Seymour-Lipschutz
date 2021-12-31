/*
Page 79
Algorithm 4.6: (Binary Search) BINARY(DATA, LB, UB, ITEM, LOC)
Here DATA is a sorted array with lower bound LB and upper bound UB, 
and ITEM is a given item of information. The variables BEG, END and 
MID denote, respectively, the beginning, end and middle locations of 
a segment of elements of DATA. This algorithm finds the location LOC 
of ITEM in DATA or sets LOC = NULL.

1. [Initialize segment variables.]
Set BEG := LB, END := UB and MID = INT((BEG + END)/2).
2. Repeat Steps 3 and 4 while BEG ≤ END and DATA[MID] ≠ ITEM.
3.         If ITEM < DATA[MID], then:
Set END := MID – 1.
Else:
Set BEG := MID + 1.
[End of If structure.]
4.         Set MID := INT((BEG + END)/2).
[End of Step 2 loop.]
5. If DATA[MID] = ITEM, then:
Set LOC := MID.
Else:
Set LOC := NULL.
[End of If structure.]
6. Exit
*/
#include<iostream>
#include<string>
using namespace std;
template<typename T>

/******************************************/
void INPUT(T DATA[], int N)
{
    for(int i = 0; i < N ; i++)
    {
        cin >> DATA[i];
    }
    return;
}

/******************************************/
template<typename T>
void PRINT(T A[], int j)
{
    cout << "\n**************************\n";
    for(int i = 1; i <= j; i++)
    {
        cout << A[i-1] << " ";
        if(i % 4 == 0)
        cout << "\n";
    }
}


/******************************************/
/************Bubble Sort******************/
template<typename T>
void Bubble_Sort(T DATA[], int N)
{
    int K, PTR;
    T CHANGE;
    for(K = 0; K < N; K++)
    {
        PTR = 0;
        while(PTR < (N - K))
        {
            if(DATA[PTR] > DATA[PTR+1])
            {
                CHANGE = DATA[PTR];
                DATA[PTR] = DATA[PTR+1];
                DATA[PTR+1] = CHANGE;
            }
            
            PTR++;
        }
    }
    return;
}

/******************************************/
template<typename T>
void Bubble(T DATA[], int N)
{
    int CHANGE;
    N = N - 1;
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
    LOC = -1;
    return LOC;
}
/*****************************************/
int main()
{
    int N = 52,  LOC = 0, key;
    int DATA[N];
    INPUT<int>(DATA,N);
    PRINT<int>(DATA,N);
    Bubble<int>(DATA,N);
    PRINT<int>(DATA,N);
    cout << "Enter your Search key\n";
    cin >> key;
    LOC = BINARY<int>(DATA, 0, N,key,LOC);
    if(LOC != -1)
    {
        cout << "Item Found at " << LOC + 1 << " " << endl;
    }
    else
    cout << "Item not Found "<< endl;


    return 0;
}
/*
output
763 573 466 895
200 228 70 389 
497 726 514 180
577 272 856 135
717 545 993 216
833 930 290 3  
847 672 903 59 
153 808 311 867
129 482 840 848
262 601 589 725
762 946 549 831
891 403 790 922
231 518 809 495

**************************
763 573 466 895
200 228 70 389
497 726 514 180
577 272 856 135
717 545 993 216
833 930 290 3
847 672 903 59
153 808 311 867
129 482 840 848
262 601 589 725
762 946 549 831
891 403 790 922
231 518 809 495

**************************
3 59 70 129
135 153 180 200
216 228 231 262
272 290 311 389
403 466 482 495
497 514 518 545
549 573 577 589
601 672 717 725
726 762 763 790
808 809 831 833
840 847 848 856
867 891 895 903
922 930 946 993
Enter your Search key
466
Item Found at 18
*/