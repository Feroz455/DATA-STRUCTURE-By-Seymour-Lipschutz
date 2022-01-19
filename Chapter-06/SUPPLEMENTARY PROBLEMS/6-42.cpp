/*
6.17 Let M and N be integers and suppose F(M, N) is recursively defined by

        1                               if(M == 0 || (M >= N && N >= 1))
F(M, N) = 
        F(M -1 , N) + F (M - 1, N - 1); otherwise

(a) Find F(4, 2), F(1, 5) and F(2, 4).

(b) When is F(M, N) undefined?
*/
#include<iostream>
using namespace std;
int F(int M,int N)
{
    if(M == 0 || (M >= N && N >= 1))
    {
        return 1;
    }
    return (F(M -1 , N) + F (M - 1, N - 1));
}
int main()
{
    cout <<  F(4, 2) << endl;
    cout <<  F(1, 5) << endl;
    cout <<  F(2, 4) << endl;
}
/*
1
2
4
*/