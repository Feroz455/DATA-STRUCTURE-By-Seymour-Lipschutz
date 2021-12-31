/*
Page 104
Program
4.14 An n-square matrix array A is said to be symmetric 
if A[J, K] = A[K, J] for all J and K.

(a)Which of the following matrices are symmetric?

(b) Describe an efficient way of storing a symmetric matrix A in memory.

(c) Suppose A and B are two n-square symmetric matrices. 
Describe an efficient way of storing A and B in memory.
*/
#include<iostream>
#include<iomanip>
using namespace std;
void PRINT(int DATA[][3], int N)
{
    for(int i= 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << setw(5) << DATA[i][j] << " ";
        }
        cout << "\n";
    }
}
// Question A)
int symmetric(int DATA[][3], int N)
{

    for(int J = 0; J < N; J++)
    {
        for(int K = 0 ; K < N; K++)
        {
            if(DATA[J][K] != DATA[K][J])
            return 0;
        }
        
    }
    return 1;
}

// Question C)
void Lower_Triangular(int DATA[][3], int TRI[], int N)
{
     int k = 0;
    for(int i= 0; i < N; i++)
    {
        for(int j =  i+1 ; j < N; j++)
        {
            TRI[k++] = DATA[i][j] ;
        }
    }
}
void Upper_Triangular(int DATA[][3], int TRI[], int N)
{
     int k = 0;
    for(int i= 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            TRI[k++] = DATA[i][j] ;
        }
    }
}
void CHECK(int i)
{
    if(i != 0)
    {
        cout << "Matrix is symmetric \n"; 
    }
    else 
    cout << "Matrix is not symmetric \n"; 
}
//Main from Here
int main()
{
    int A[][3] = {1,3,-7,3,6,-1,-7,-1,2};
    int B[][3] ={2,-3,5,-3,-2,4,5,6,8}; 
    //A)
    PRINT(A, 3);
    CHECK(symmetric(A,3));
    PRINT(B, 3);
    CHECK(symmetric(A,3));

    int L[(3*(3+1)/ 2)];
    //B)
    Lower_Triangular(B, L, 3);
    for(int i = 0; i < (3*(3+1)/ 2);  i++)
    {
        cout << L[i] << " ";
    }

    // Question  C)
    //L = ((J(J-1))/2)+K;
    /*
    lets find B[J][K]
    J not gonna be greater then  K 
    */
   //Here is a BUG -_-
   int J = 2, K = 2 ;
   cout << "\nB[2][2] = " <<  L[((J*(J-1))/2)+K+1] << " " << endl;

}

/*
Output
    1     3    -7   
    3     6    -1   
   -7    -1     2   
Matrix is symmetric 
    2    -3     5   
   -3    -2     4   
    5     6     8
Matrix is symmetric
2 -3 -2 5 6 8 
B[2][2] = 6

*/