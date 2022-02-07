#include <iostream>
using namespace std;
template <typename T>
void insertion_sort(T A[], int N)
{
    T temp;
    int hole;
    for (int i = 1; i < N - 1; i++)
    {
        temp = A[i];
        hole = i;
        while(hole>0 && A[hole-1] > temp)
        {
            A[hole] = A[hole-1];
            hole = hole -1;
        }
        A[hole] = temp;
    }
}
int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    insertion_sort<int>(A, 6);
    for (int i : A)
    {
        cout << i << " ";
    }
}
/*
1 2 3 4 5 7
*/