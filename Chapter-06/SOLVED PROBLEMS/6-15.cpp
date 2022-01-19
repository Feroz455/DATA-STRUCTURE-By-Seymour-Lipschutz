/*
6.16 Let n denote a positive integer. Suppose a function L is defined. recursively as follows:

        0               if(n = 1)
L(n) = 
        L(floor(n/2))+1 if(n > 1)

(Here [k] denotes the “floor” of k, that is, the greatest integer which does not exceed k. See Sec. 2.2.)

(a) Find L(25).

(b) What does this function do?
*/
#include<iostream>
#include<cmath>
using namespace std;
int L(int N)
{
    if( N == 1)
    {
        return 1;
    }
    return (L(floor(N/2))+1);
}
int main()
{
    cout << L(12) << endl;
}
/*
3
*/