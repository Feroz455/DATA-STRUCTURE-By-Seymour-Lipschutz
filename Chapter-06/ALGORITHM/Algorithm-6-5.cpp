
/*
page 176
Procedure 6.7: QUICK(A, N, BEG, END, LOC)

Here A is an array with N elements. Parameters BEG and END contain the boundary values of the sublist of A to which this procedure applies. LOC keeps track of the position of the first element A[BEG] of the sublist during the procedure. The local variables LEFT and RIGHT will contain the boundary values of the list of elements that have not been scanned.

1. [Initialize.] Set LEFT := BEG, RIGHT := END and LOC := BEG.

2. [Scan from right to left.]

(a) Repeat while A[LOC) ≤ A[RIGHT] and LOC ≠ RIGHT:

RIGHT := RIGHT – 1.

[End of loop.]

(b) If LOC = RIGHT, then: Return.

(c) If A[LOC] > A[RIGHT], then:

(i) [Interchange A[LOC) and A[RIGHT].]

TEMP := A[LOC), A[LOC] := A[RIGHT),

A[RIGHT] := TEMP.

(ii) Set LOC := RIGHT.

(iii) Go to Step 3.

[End of If structure.]

3. [Scan from left to right.]

(a) Repeat while A[LEFT] ≤ A[LOC) and LEFT ≠ LOC:

LEFT := LEFT + 1.

[End of loop.]

(b) If LOC = LEFT, then: Return.

(c) If A[LEFT] > A[LOC], then

(i) [Interchange A[LEFT] and A[LOC].]

TEMP := A[LOC], A[LOC] := A[LEFT],

A[LEFT] := TEMP.

(ii) Set LOC := LEFT.

(iii) Go to Step 2.

[End of If structure.]
*/// An iterative implementation of quick sort#include<iostream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void INTERCHANGE(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}
int  QUICK(int A[], int N, int BEG, int END)
{
    
    int LEFT = BEG, RIGHT = END ;
    int LOC = BEG;
    STEP2:
    while(A[LOC] <= A[RIGHT] && LOC != RIGHT)
    {
        RIGHT = RIGHT - 1;  
    }
    if(LOC == RIGHT)
    {
        return LOC;
    }

    if(A[LOC] > A[RIGHT])
    {
        INTERCHANGE(&A[LOC], &A[RIGHT]);
        LOC = RIGHT;
    }
    STEP3:
    while(A[LEFT] <= A[LOC] && LEFT != LOC)
    {
        LEFT = LEFT + 1;
    }
    if(LOC == LEFT)
    {
        return LOC;
    }
    if(A[LEFT] > A[LOC])
    {
        INTERCHANGE(&A[LOC], &A[LEFT]);
        LOC = LEFT;
        goto STEP2;
    }
    return 0;
}
void QUICK_SORT(int A[], int N)
{
    int TOP = -1;
    int LOWER[N] , UPPER[N], BEG, END, LOC;
    if(N > 1)
    {
        TOP = TOP + 1;
        LOWER[TOP] = 0;
        UPPER[TOP] = N-1;
    }
    while(TOP >= 0)
    {
        BEG = LOWER[TOP];
        END = UPPER[TOP];
        TOP = TOP - 1;


        LOC = QUICK(A, N, BEG, END);
         if(BEG < LOC - 1)
         {
             TOP = TOP + 1;
             LOWER[TOP] = BEG;
             UPPER[TOP] = LOC - 1;
         }
         if(LOC + 1 < END)
         {
             TOP = TOP + 1;
             LOWER[TOP] = LOC + 1;
             UPPER[TOP] = END;
         }
    }
}
void PRINT_ARRAY(int A[], int N)
{
    for(int i  = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
     cout << "\n";
}
int main()
{
    int ARRAY[] = {44,33,11,55,77,90,40,60,22,88,66};
    
    int sizeOf_ARRAY = sizeof(ARRAY) / sizeof(int);
    PRINT_ARRAY(ARRAY, sizeOf_ARRAY);
    QUICK_SORT(ARRAY, sizeOf_ARRAY);
    PRINT_ARRAY(ARRAY, sizeOf_ARRAY);
}
/*
output
44 33 11 55 77 90 40 60 22 88 66 
11 22 33 40 44 55 60 66 77 88 90 
*/