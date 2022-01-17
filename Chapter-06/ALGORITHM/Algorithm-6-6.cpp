
/*
Page 175
Algorithm 6.8: (Quicksort) This algorithm sorts an array A with N elements.

1. [Initialize.] TOP := NULL.

2. [Push boundary values of A onto stacks when A has 2 or more elements.]
If N > 1, then: TOP := TOP + 1, LOWER[1] := 1, UPPER[1] := N.

3. Repeat Steps 4 to 7 while TOP ≠ NULL.

4.      [Pop sublist from stacks.]

Set BEG := LOWER[TOP], END := UPPER[TOP],
TOP := TOP – 1.

5.      Call QUICK(A, N, BEG, END, LOC). [Procedure 6.5.]

6.      [Push left sublist onto stacks when it has 2 or more elements.]

If BEG < LOC – 1, then:

TOP := TOP + 1, LOWER[TOP] := BEG,
UPPER[TOP] = LOC – 1.

[End of If structure.]

7.      [Push right sublist onto stacks when it has 2 or more elements.]

If LOC + 1 < END, then:

TOP := TOP + 1, LOWER[TOP] := LOC + 1,
UPPER[TOP] := END.

[End of If structure.]

[End of Step 3 loop.]

8. Exit.
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