/*
6.15 Let N be an integer and suppose H(N) is recursively defined by
        3 * N               if N < 5
H(N) = 
        2 * H (N - 5) + 7   otherwise 

(a) Find the base criteria of H and

(b) find H(2), H(8) and H(24).
*/
#include<iostream>
using namespace std;
int H(int N)
{
    if(N < 5)
    {
        return (3 * N);
    }
    return (2*H(N-5))+7;
}
int main()
{
    cout << H(2) << endl;
    cout << H(8) << endl;
    cout << H(24) << endl;
}
/*
6
25 
297
*/