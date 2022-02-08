/*
9.5   Translate quicksort into a subprogram QUICKCOUNT(A, N, NUMB)
which sorts the array A with N elements and which also counts the
number NUMB of comparisons. (See Sec. 6.5.)
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void INTERCHANGE(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}
int QUICK(int A[], int N, int BEG, int END, int &NUMB)
{

    int LEFT = BEG, RIGHT = END;
    int LOC = BEG;
STEP2:
    while (A[LOC] <= A[RIGHT] && LOC != RIGHT)
    {
        RIGHT = RIGHT - 1;
        NUMB++;
    }
    if (LOC == RIGHT)
    {
        NUMB++;
        return LOC;
    }

    if (A[LOC] > A[RIGHT])
    {
        NUMB++;
        INTERCHANGE(&A[LOC], &A[RIGHT]);
        LOC = RIGHT;
    }
STEP3:
    while (A[LEFT] <= A[LOC] && LEFT != LOC)
    {
        NUMB++;
        LEFT = LEFT + 1;
    }
    if (LOC == LEFT)
    {
        NUMB++;
        return LOC;
    }
    if (A[LEFT] > A[LOC])
    {
        NUMB++;
        INTERCHANGE(&A[LOC], &A[LEFT]);
        LOC = LEFT;
        goto STEP2;
    }
    return 0;
}
int QUICK_SORT(int A[], int N)
{
    int NUMB = 0;
    int TOP = -1;
    int LOWER[N], UPPER[N], BEG, END, LOC;
    if (N > 1)
    {
        TOP = TOP + 1;
        LOWER[TOP] = 0;
        UPPER[TOP] = N - 1;
        NUMB++;
    }
    while (TOP >= 0)
    {

        BEG = LOWER[TOP];
        END = UPPER[TOP];
        TOP = TOP - 1;

        LOC = QUICK(A, N, BEG, END, NUMB);
        if (BEG < LOC - 1)
        {
            TOP = TOP + 1;
            LOWER[TOP] = BEG;
            UPPER[TOP] = LOC - 1;
        }
        if (LOC + 1 < END)
        {
            TOP = TOP + 1;
            LOWER[TOP] = LOC + 1;
            UPPER[TOP] = END;
        }
        NUMB++;
    }
    return NUMB;
}
void PRINT_ARRAY(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int ARRAY[] = {44, 33, 11, 55, 77, 90, 40, 60, 22, 88, 66};

    int sizeOf_ARRAY = sizeof(ARRAY) / sizeof(int);
    cout << "Number of comparison " << QUICK_SORT(ARRAY, sizeOf_ARRAY);
}

/*
output
Number of comparison 50
*/