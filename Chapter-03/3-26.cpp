/*
Page 65
Program 3-26
In Supplementary Problems 3.5 to 3.10, let S and T be character variables such that

S = 'WE THE PEOPLE'    and    T = 'OF THE UNITED STATES'

3.5 Find the length of S and T
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
  string S("WE THE PEOPLE"), T("OF THE UNITED STATES");
  cout << S.length() << " " << T.length();
 
  return 0;
}
/*
Output

*/