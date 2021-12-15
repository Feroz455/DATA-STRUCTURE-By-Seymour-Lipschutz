/*
Page 33
Program 
2.1 Find (a) 7.5, −7.5, −18, , , π; and (b) 7.5, −7.5, −18, , , π.

*/
#include<iostream>
#include<cmath>
using namespace std;

//main begin
int main()
{
    cout <<"floor(7.5)   " <<floor(7.5) << endl;
    cout <<"floor(-7.5)  "<<  floor(-7.5) << endl;
    cout <<"floor(-18)   "<< floor(-18) << endl;
    cout <<"floor(sqrt(30)) "<< floor(sqrt(30)) << endl;
    cout <<"floor(cbrt(30)) "<< floor(cbrt(30)) << endl;
    cout <<"floor(3.1416)   "<< floor(3.1416) << endl;
        cout <<"***********************\n";
    cout <<"ceil(7.5)     "<< ceil(7.5) << endl;
    cout <<"ceil(-7.5)    "<< ceil(-7.5) << endl;
    cout <<"ceil(-18)     "<< ceil(-18) << endl;
    cout <<"ceil(sqrt(30))"<< ceil(sqrt(30)) << endl;
    cout <<"ceil(cbrt(30))"<< ceil(cbrt(30)) << endl;
    cout <<"ceil(3.1416)  "<< ceil(3.1416) << endl;

    return 0;
}
//main end
///Program end

/*
output
floor(7.5)   7
floor(-7.5)  -8
floor(-18)   -18
floor(sqrt(30)) 5
floor(cbrt(30)) 3
floor(3.1416)   3
***********************
ceil(7.5)     8
ceil(-7.5)    -7
ceil(-18)     -18
ceil(sqrt(30))6
ceil(cbrt(30))4
ceil(3.1416)  4
*/