/*
Page 109
Program
Consider the following multidimensional arrays:

X(−5 : 5, 3:33)    Y(3 : 10, 1 : 15, 10 : 20)

(a) Find the length of each dimension and the number of elements in X and Y.

(b) Suppose Base(Y) = 400 and there are w = 4 words per memory location. 
Find the effective indices E1, E2, E3 and the address of Y[5, 10, 15] 
assuming (i) Y is stored in row-major order and (ii) Y is stored in column-major order.
*/
#include<iostream>
#include<string>
using namespace std;
//Main from Here
int main()
{
    int J , K, X, Y, Z, N;
    J = -5;
    K = 5;
    X = 3;
    Y = 33;
    N = K - J;
    Z = Y - X;
    int Ar[N][X];
    J = 3;
    K = 10;
    X = 1;
    Y = 15;
    Z = 10; 
    N = 20;
    int YYY[K - J][Y - X][N-Z];
}

/*
Output

*/