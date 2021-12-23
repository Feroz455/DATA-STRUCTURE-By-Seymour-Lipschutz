/*
Page 65
Program
Find 
(a) INSERT('AAA', 2, 'BBB'), 
(b) INSERT('ABCDE', 3, 'XYZ') and 
(c) INSERT ('THE BOY', 5, 'BIG').
*/
#include<iostream>
#include<string>
using namespace std;
string INSERT(string T, int i , string R)
{
     T.insert(i,R);
     return T;
}
int main()
{   
    string R;
    string S("WE THE PEOPLE");
    string T("OF THE UNITED STATES");
    cout << INSERT("AAA", 1, "BBB") <<  endl;
    cout << INSERT("ABCDE", 2, "XYZ") << endl;
    cout << INSERT("THE BOY", 4, "BIG ") << endl;

 
  return 0;
}
/*
Output
ABBBAA
ABXYZCDE
THE BIG BOY
*/