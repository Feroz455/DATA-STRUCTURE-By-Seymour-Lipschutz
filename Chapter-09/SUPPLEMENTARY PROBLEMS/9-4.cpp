/*
9.4   Write a program TESTINSERT(N, AVE) which repeats 500 times the procedure INSERTCOUNT(A, N, NUMB)
and which finds the average AVE of the 500 values of NUMB. (Theoretically, AVE ≈ N2/4.)
Use RANDOM(A, N, 5*N) from Problem 9.1 as each input. Test the program using N = 100
(so, theoretically, AVE ≈ N2/4 = 2500).
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
int insert_count(int A[], int N)
{
    int count = 0;
    int temp;
    int hole;
    for (int i = 1; i < N - 1; i++)
    {
        temp = A[i];
        hole = i;
        while (hole > 0 && A[hole - 1] > temp)
        {
            A[hole] = A[hole - 1];
            hole = hole - 1;
            count++;
        }
        A[hole] = temp;
    }
    return count;
}
void TESTINSERT(int N, int &AVE)
{
    int ARRAY[N * 5];
    int SUM = 0;
    for (int i = 0; i < 500; i++)
    {
        RANDOM(ARRAY, N, N * 5);
        SUM += insert_count(ARRAY, N * 5);
    }
    AVE = SUM / 500;
    cout << "AVE = " << AVE << "\n";
}
int main()
{
    int N = 100, AVE = 0;
    TESTINSERT(N, AVE);
}