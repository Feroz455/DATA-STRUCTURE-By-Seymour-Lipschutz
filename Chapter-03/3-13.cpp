/*
Page 59
Program 
(a) DELETE('AAABBB', 2, 2) and DELETE('JOHN PAUL JONES', 6, 5)

(b) REPLACE('AAABBB', 'AA', 'BB') and REPLACE('JOHN PAUL JONES', 'PAUL', 'DAVID')
*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string DELETE(string S, int i, int j)
{
    string Q;
    S.erase(i-1,j);
    return S;
}

string REPLACE(string S, string Q, string Z)
{
    int i = S.find(Q);
    S.replace(S.find(Q),Q.length(),Z);
    return S;

}
int main()
{
    string R;
    R = DELETE("AAABBB", 2,2);
    cout << R << endl;
    R = DELETE("JOHN PAUL JONES", 6, 5);
    cout << R << endl;
    R = REPLACE("AAABBB", "AA", "BB");
    cout <<  R  << endl;
    R = REPLACE("JOHN PAUL JONES", "PAUL", "DEVID");
    cout << R << endl;

    return 0;
}
/*
ABBB
JOHN JONES
BBABBB
JOHN DEVID JONES
*/