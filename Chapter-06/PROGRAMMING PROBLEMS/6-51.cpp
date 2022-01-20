/*
page 213
6.1  Translate Quicksort into a subprogram QUICK(A, N) 
which sorts the array A with N elements. Test the program using

(a) 44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66
(b) D, A, T, A, S, T, R, U, C, T, U, R, E, S
'D', 'A', 'T', 'A', 'S', 'T', 'R', 'U', 'C', 'T', 'U', 'R', 'E', 'S'

*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
template<typename T>
void INTERCHANGE(T *A, T *B)
{
    T temp = *A;
    *A = *B;
    *B = temp;
}
template<typename T>
int  QUICK(T A[], int N, int BEG, int END)
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
        INTERCHANGE<T>(&A[LOC], &A[RIGHT]);
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
        INTERCHANGE<T>(&A[LOC], &A[LEFT]);
        LOC = LEFT;
        goto STEP2;
    }
    return 0;
}
template<typename T>
void QUICK_SORT(T A[], int N)
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


        LOC = QUICK<T>(A, N, BEG, END);
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
template<class T>
void PRINT_ARRAY(T A[], int N)
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
    PRINT_ARRAY<int>(ARRAY, sizeOf_ARRAY);
    QUICK_SORT(ARRAY, sizeOf_ARRAY);
    PRINT_ARRAY<int>(ARRAY, sizeOf_ARRAY);


    char CHAR_ARRAY[] = {'D', 'A', 'T', 'A', 'S', 'T', 'R', 'U', 'C', 'T', 'U', 'R', 'E', 'S'};
    sizeOf_ARRAY = sizeof(CHAR_ARRAY);
    PRINT_ARRAY<char>(CHAR_ARRAY, sizeOf_ARRAY);
    QUICK_SORT(CHAR_ARRAY,sizeOf_ARRAY);
    PRINT_ARRAY<char>(CHAR_ARRAY, sizeOf_ARRAY);
}
/*
output
44 33 11 55 77 90 40 60 22 88 66 
11 22 33 40 44 55 60 66 77 88 90 
D A T A S T R U C T U R E S      
A A C D E R R S S T T T U U
*/