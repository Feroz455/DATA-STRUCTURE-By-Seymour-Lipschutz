/*
6.16 Use Definition 6.3 (of the Ackermann function) to find A(2, 2).
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

    cout << ACKERMANN(2,2) <<endl;
}
/*
ACKERMANN( 1, ACKERMANN(2,1))
ACKERMANN( 1, ACKERMANN(2,0))
ACKERMANN(1,1)
ACKERMANN( 0, ACKERMANN(1,0))
ACKERMANN(0,1)
ACKERMANN( 0 , 1)
ACKERMANN( 0 , 2)
ACKERMANN( 0, ACKERMANN(1,2))
ACKERMANN( 0, ACKERMANN(1,1))
ACKERMANN( 0, ACKERMANN(1,0))
ACKERMANN(0,1)
ACKERMANN( 0 , 1)
ACKERMANN( 0 , 2) 
ACKERMANN( 0 , 3)
ACKERMANN( 0 , 4)
ACKERMANN( 0, ACKERMANN(1,4))
ACKERMANN( 0, ACKERMANN(1,3))
ACKERMANN( 0, ACKERMANN(1,2))
ACKERMANN( 0, ACKERMANN(1,1))
ACKERMANN( 0, ACKERMANN(1,0))
ACKERMANN(0,1)
ACKERMANN( 0 , 1)
ACKERMANN( 0 , 2)
ACKERMANN( 0 , 3) 
ACKERMANN( 0 , 4)
ACKERMANN( 0 , 5)
ACKERMANN( 0 , 6)
7
*/