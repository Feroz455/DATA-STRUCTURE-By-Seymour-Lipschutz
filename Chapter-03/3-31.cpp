/*
Page 65
Program
Find 
(a) REPLACE('ABABAB', 'B', 'BAB'), 
(b) REPLACE(S, 'WE', 'ALL') and 
(c) REPLACE(T, 'THE', 'THESE').

*/
#include<iostream>
#include<string>
using namespace std;
string REPLACE(string S, string Q, string Z)
{
    int i = S.find(Q);
    S.replace(S.find(Q),Q.length(),Z);
    return S;

}
int main()
{
    string R;
    string S("WE THE PEOPLE");
    string T("OF THE UNITED STATES");
    R = REPLACE("ABABAB", "B", "BAB");
    cout <<  R  << endl;
    R = REPLACE(S, "WE", "ALL");
    cout << R << endl;
    R = REPLACE(T, "THE", "THESE");
    cout << R << endl;
  
 
  return 0;
}
/*
Output
ABABABAB
ALL THE PEOPLE
OF THESE UNITED STATES

*/