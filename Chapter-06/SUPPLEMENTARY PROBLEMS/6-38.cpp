/*
6.13 Let J and K be integers and suppose Q(J, K) is recursively defined by

            5                 if j < k
GCD(A,B) =  
            Q(j-k, k+2) + j   if j >= k 
Find Q(2, 7), Q(5, 3) and Q(15, 2)
*/
#include<iostream>
using namespace std;
int Q(int J, int K)
{
    if(J < K)
    {
        return 5;
    }
    return (Q(J - K, K+2)+J);
}
int main()
{
    cout << Q(2,7) << endl;
    cout << Q(5,3) << endl;
    cout << Q(15,2) << endl;

}
/*
5
10
42
*/