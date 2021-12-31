/*
Page 103
Program
4.12 Let A be an n × n square matrix array. Write a module which

(a) Finds the number NUM of nonzero elements in A

(b) Finds the SUM of the elements above the diagonal, i.e., elements A[I, J] where I < J

(c) Finds the product PROD of the diagonal elements (a11, a22, …, ann)

(a) 
    1. Set NUM := 0.
    2. Repeat for I = 1 to N:
    3.       Repeat for J = 1 to N:
    If A[I, J] ≠ 0, then: Set NUM := NUM + 1.
    [End of inner loop.]
    [End of outer loop.]
    4. Return.
(b)
    1. Set SUM := 0.
    2. Repeat for J = 2 to N:
    3.       Repeat for I = 1 to J – 1:
    Set SUM := SUM + A[I, J].
    [End of inner Step 3 loop.]
    4. Return.
(c) 
    1. Set PROD := 1. [This is analogous to setting SUM = 0.]
    2. Repeat for K = 1 to N:
    Set PROD := PROD*A[K, K].
    [End of loop.]
    3. Return.
*/
#include<iostream>
#include<iomanip>
using namespace std;
int NONZero(int Matrix[][4], int N)
{
    int NONZERO = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0 ; j < N; j++)
        {
            if(Matrix[i][j] != 0)
            {
                NONZERO++;
            }
        }
    }
    return NONZERO;
}
/***************************/
void INPUT(int DATA[][4], int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0 ; j < N; j++)
        {
           cin >>  DATA[i][j];
        
        }
    }
}

/************************/
int sumOfArray(int DATA[][4], int N)
{
    int sum = 0, J, I;
    for(J = 1; J < N ; J++)
    {
        for(I = 0;  I < J  ; I++)
        {
            sum += DATA[I][J];
           // cout <<  DATA[I][J] << " ";
        }
        cout << "\n";
    }
    return sum;
}
int PRODUCTofARRAY(int DATA[][4], int N)
{
    int PROD = 1;
    for(int K = 0; K < N; K++)
    {
        PROD = PROD * DATA[K][K];
    }
    return PROD;
}
//Main from Here
int main()
{
    int const N = 4;
    int MAtrix[N][N];
    INPUT(MAtrix,N);
    cout << "Nonzero number in Array A = " << NONZero(MAtrix,N) << endl;  
    cout << "Sum of the elements above the deiagonal = " << sumOfArray(MAtrix,N) << endl; 
    cout << "PRODUCT OF THE DIAGONAL ELEMENTS " << PRODUCTofARRAY(MAtrix, N) << endl;
    return 0; 
}

/*
Output
9 0 4 6
6 7 3 8
2 8 4 5
5 5 7 7
Nonzero number in Array A = 15
Sum of the elements above the deiagonal =  26
PRODUCT OF THE DIAGONAL ELEMENTS 1764
*/