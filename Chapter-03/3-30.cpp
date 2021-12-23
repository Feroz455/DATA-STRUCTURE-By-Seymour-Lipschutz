/*
Page 
Program
Find 
(a) DELETE('AAABBB', 3, 3), 
(b) DELETE('AAABBB', 1, 4), 
(c) DELETE(S, 1, 3) and 
(d) DELETE(T, 1, 7).
*/
#include<iostream>
#include<string>
using namespace std;
string DELETE(string S, int i, int j)
{
    string Q;
    S.erase(i,j);
    return S;
}
int main()
{
  
    string R;
    string S("WE THE PEOPLE");
    string T("OF THE UNITED STATES");
    R = DELETE("AAABBB", 2,3);
    cout << R << endl;
    R = DELETE("AAABBB", 0,4);
    cout << R << endl;
    R = DELETE(S, 0, 3);
    cout << R << endl;
    R = DELETE(T, 0, 7);
    cout << R << endl;
  return 0;
}
/*
Output
AAB
BB
THE PEOPLE   
UNITED STATES
*/