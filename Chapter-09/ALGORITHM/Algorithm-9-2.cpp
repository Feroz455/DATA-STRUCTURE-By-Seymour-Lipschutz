#include <iostream>
using namespace std;
template <typename T>
void selection(T A[], int N)
{
    int min;
    T temp;
    for (int i = 0; i < N-1; i++)
    {
        min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}
int main()
{
    int A[] = {2,7,4,1,5,3};
    selection<int>(A, 6);
    for(int i:A)
    {
        cout << i << " ";
    }
}
/*
1 2 3 4 5 7 
*/