/*
Page 65
Program 3-27
In Supplementary Problems 3.5 to 3.10, let S and T be character variables such that

S = 'WE THE PEOPLE'    and    T = 'OF THE UNITED STATES'

3.5 Find the length of S and T

3.6 Find (a) SUBSTRING(S, 4, 8) and (b) SUBSTRING(T, 10, 5).
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
  string S("WE THE PEOPLE"), T("OF THE UNITED STATES");
  cout << S.length() << " " << T.length() << endl;
  cout << S.substr(4,8)  <<  endl;
  cout << " " << T.substr(10,5) << endl;
 
  return 0;
}
/*
Output

*/