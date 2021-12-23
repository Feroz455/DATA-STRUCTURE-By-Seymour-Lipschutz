/*
page 60
Pagogram 
3.12 Recall that we use INSERT(text, position, string) to denote inserting a 
string S in a given text T beginning in position K.

(a) Find 
(i) INSERT('AAAAA', 1, 'BBB'), 
(ii) INSERT('AAAAA', 3, 'BBB') and 
(iii) INSERT('AAAAA', 6, 'BBB').

(b) Suppose T is the text 'THE STUDENT IS ILL. ' 
Use INSERT to change T so that it reads: 
(i) The student is very ill. 
(ii) The student is ill today. 
(iii) The student is very ill today.
*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string INSERT(string T, int i , string R)
{
     T.insert(i,R);
     return T;
}
int main()
{
    string test("The STUDENT IS ILL");
    cout << test <<  endl;
    test.insert(test.find("ILL"), "VERY ");
    cout << test <<  endl;
    test.insert(test.length(), " TODAY");
    cout << test <<  endl;
    cout << INSERT("AAAAA", 1-0, "BBB") <<  endl;
    cout << INSERT("AAAAA", 3-1, "BBB") <<  endl;
    cout << INSERT("AAAAA", 6-1, "BBB") << endl;
    
    
}
/*
The STUDENT IS ILL
The STUDENT IS VERY ILL
The STUDENT IS VERY ILL TODAY
ABBBAAAA
AABBBAAA
AAAAABBB
*/