/* 
Page  65
Program 3.33
 Suppose U is the text 'MARC STUDIES MATHEMATICS'. 
 Use INSERT to change U so that it reads: 
 (a) MARC STUDIES ONLY MATHEMATICS. 
 (b) MARC STUDIES MATHEMATICS AND PHYSICS. 
 (c) MARC STUDIES APPLIED MATHEMATICS.
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
    string U("MARC STUDIES MATHEMATICS.");
    cout << INSERT(U, U.find("MATHEMATICS."), "ONLY ") <<  endl;
    cout << INSERT(U, U.length()-1, " AND PHYSICS") <<  endl;
    cout << INSERT(U, U.find("MATHEMATICS"), "APPLY ") <<  endl;

 
  return 0;
}
/*
Output
MARC STUDIES ONLY MATHEMATICS.
MARC STUDIES MATHEMATICS AND PHYSICS.
MARC STUDIES APPLY MATHEMATICS.
*/