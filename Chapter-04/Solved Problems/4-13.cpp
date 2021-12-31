/*
Page 104 
Program
4.13 Consider an n-square tridiagonal array A as shown in Fig. 4.24. 
Note that A has n elements on the diagonal and n − 1 elements above 
and n − 1 elements below the diagonal. Hence A contains at most 3n − 2 
nonzero elements. Suppose we want to store A in a linear array B as 
indicated by the arrows in Fig. 4.24; i.e.,

B[1] = a11,   B[2] = a12,   B[3] = a21,   B[4] = a22, …
Find the formula that will give us L in terms of J and K such that
B[L] = A[J, K]
(so that one can access the value of A[J, K] from the array B).

Note that there are 3(J − 2) + 2 elements above A[J, K] 
and K − J + 1 elements to the left of A[J, K].
Hence
L = [3(J − 2) + 2] + [K − J + 1] + 1 = 2J + K − 2
*/
#include<iostream>
#include<iomanip>
using namespace std;
void PRINT(int DATA[][4], int N)
{
    for(int i= 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << DATA[i][j] << " ";
        }
        cout << "\n";
    }
}
int TRIDIAGONAL(int DATA[][4], int TRI[],int N)
{
    int k = 0;
    for(int i= 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == j)
            {
                
                if(i != 0 && j  != 0 ) 
                TRI[k++] = DATA[i][j-1];
                TRI[k++] = DATA[i][j];
                if(j != N-1)
                TRI[k++] = DATA[i][j+1];
                 
            }

           
        }
        cout <<  "\n";
    }
    return k;
}

//Main from Here
int main()
{
    int N = 4;
    int A[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    PRINT(A,4);
    int L[20];
   
    int k =  TRIDIAGONAL(A,L,4);
    for(int i = 0;  i < (3*N-2); i++)
    {
        cout << L[i] << " ";
    }

   // L = [3(J − 2) + 2] + [K − J + 1] + 1 = 2J + K − 2
   cout<< "\nA[2][3] = " <<L[2*3 + 2 - 2] << " ";
     
}

/*
Output
1 2 3 4 
5 6 7 8
9 10 11 12
13 14 15 16

1 2 5 6 7 10 11 12 15 16
A[2][3] = 11
*/