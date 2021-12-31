/*
Page 99
Program
4.3 Suppose a 10-element array A contains the values a1, a2 , …, a10. 
Find the values in A after each loop.

(a) Repeat for K = 1 to 9:

Set A[K + 1] := A[K].

[End of loop.]

(b) Repeat for K = 9 to 1 by −1:

Set A[K + 1] := A[9].

[End of loop.]

Note that the index K runs from 1 to 9 in part 
(a) but in reverse order from 9 back to 1 in part (b)

*/
#include<iostream>
#include<iomanip>
using namespace std;
//Main from Here
int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0;  i < 10; i++)
    {
        cout << A[i] << " ";
    }

    for(int K = 0; K < 10; K++)
    {
        A[K+1] = A[K];
    }

    cout << "\n\n\n";
    for(int i = 0;  i < 10; i++)
    {
        cout << A[i] << " ";
    }
     for(int K = 10; K > 0; K--)
    {
        A[K+1] = A[K];
    }


    cout << "\n\n\n";
    for(int i = 0;  i < 10; i++)
    {
        cout << A[i] << " ";
    }
}

/*
Output
1 2 3 4 5 6 7 8 9 10 


1 1 1 1 1 1 1 1 1 1  


1 1 1 1 1 1 1 1 1 1  
*/