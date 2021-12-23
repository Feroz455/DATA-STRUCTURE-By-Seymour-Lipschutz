/*
Page 65
Program
Using S1//S2 to stand for the concatenation of S1 and S2, find 
(a) 'NO'//'EXIT', 
(b) 'NO'// '' // 'EXIT' and 
(c) SUBSTRING(S, 4, 10)//'ARE' //SUBSTRING(T, 8, 6).
*/
#include<iostream>
#include<string>
using namespace std;
string STRINGCAT(string S, string O)
{
    string X = S + O;
    return X;
}
string STRINGCAT(string S, string O, string T)
{
    string X = S + O + T;
    return X;
}
int main()
{
  string S("WE THE PEOPLE");
  string T("OF THE UNITED STATES");
  string S1("NO"), S2("EXIT");
  cout << STRINGCAT(S1, S2) <<  endl;
  cout << STRINGCAT(S1, " ", S2) << endl;
  cout << STRINGCAT(S.substr(4-1,10), " ARE ", T.substr(8-1,6));
  return 0;
}
/*
Output

NOEXIT
NO EXIT
THE PEOPLE ARE UNITED
*/