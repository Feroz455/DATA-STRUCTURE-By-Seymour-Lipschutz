/*
6.18 Use the definition of the Ackermann function (Definition 6.3) to find A(l, 3).

We have the following 15 steps:



The forward indention indicates that we are postponing 
an evaluation and are recalling the definition, and the 
backward indention indicates that we are backtracking.

Observe that the first formula in Definition 6.3 is used 
in Steps 5, 8, 11 and 14, the second formula in Step 4 and 
the third formula in Steps 1, 2 and 3. In the other Steps 
we are backtracking with substitutions.
*/
#include<iomanip>
#include<iostream>
using namespace std;
int ACKERMANN(int m, int n)
{
    if(m == 0)
    {
        cout << "ACKERMANN( " << m << " , " << n << ") " << endl;
        return(n+1);
    }
    else 
    if( (m > 0) && (n == 0))
    {
        cout << "ACKERMANN(" << m-1 << "," << 1 << ")\n";
        return ACKERMANN(m-1,1);
    }
    else 
    if ((m > 0) && (n > 0))
    {
        cout << "ACKERMANN( "<<  m - 1 <<  ", ACKERMANN(" <<  m  << "," << n - 1 << "))\n";
        return ACKERMANN(m - 1 ,ACKERMANN( m , n - 1));
    }

    return 0;
}
int main()
{

    cout << ACKERMANN(1,3) <<endl;
}
/*
ACKERMANN( 0, ACKERMANN(1,2))
ACKERMANN( 0, ACKERMANN(1,1))
ACKERMANN( 0, ACKERMANN(1,0))
ACKERMANN(0,1)
ACKERMANN( 0 , 1)
ACKERMANN( 0 , 2) 
ACKERMANN( 0 , 3)
ACKERMANN( 0 , 4)
5
*/