/*
6.14
6.15 Let a and b denote positive integers. Suppose a function Q is defined recursively as follows:

            0           if( a < b)
Q(a,b) = 
            Q(a - b, b)+1 if(b<a)

(a) Find the value of Q(2, 3) and Q(14, 3).

(b) What does this function do? Find Q(5861, 7).
*/
#include<iostream>
using namespace std;

int Q(int a, int b)
{
    if(a < b)
    {
        return 0;
    }
    return (Q(a - b, b)+1);
}
int main()
{
    cout << Q(2,3) << endl;
    cout << Q(14,3) << endl;
    cout << Q(5861,7) << endl;
}
/*
output 
0
4  
837
*/