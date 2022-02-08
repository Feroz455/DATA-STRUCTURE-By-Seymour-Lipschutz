/*
page 338
9.6   Write a program TESTQUICKSORT(N, AVE) which repeats QUICKCOUNT(A, N, NUMB)
500 times and which finds the average AVE of the 500 values of NUMB.
(Theoretically, AVE ≈ N log2 N.) Use RANDOM(A, N, 5*N) from Problem 9.1 as each input.
Test the program using N = 100 (so, theoretically, AVE ≈ 700).
*/
#include <iostream>
#include <time.h>
using namespace std;
void RANDOM(int ARRAY[], int N, int K)
{
    srand(time(0));
    for (int i = 0; i < K; i++)
    {
        ARRAY[i] = rand() % N;
    }
    return;
}
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
int QUICK_SORT_COUNT(int A[], int N)
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
void TEST_QUICK_SORT(int N, int &AVE)
{
    int ARRAY[N * 5];
    int SUM = 0;
    for (int i = 0; i < 500; i++)
    {
        RANDOM(ARRAY, N, N * 5);
        SUM += QUICK_SORT_COUNT(ARRAY, N * 5);
    }
    AVE = SUM / 500;
    cout << "AVE = " << AVE << "\n";
}
int main()
{
    int N = 100, AVE = 0;
    TEST_QUICK_SORT(N, AVE);
}