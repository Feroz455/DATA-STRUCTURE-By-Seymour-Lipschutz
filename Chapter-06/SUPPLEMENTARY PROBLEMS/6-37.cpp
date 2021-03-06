/*
page 211
6.12 Use Algorithm 6.6 to translate each infix expression into its equivalent postfix expression:

(a) (A – B)/((D + E) * F) 

(b) ((A + B)/D) ↑ ((E – F) * G)

(Compare with Supplementary Problem 6.31)
*/
#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

// Function to return perecendece of operators
int PRECENDCE(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostFix(string s)
{
    stack<char> STACK;
    STACK.push('(');
    s.push_back(')');
    string P;
    for(int i = 0 ; i < s.length(); i++)
    {
        char c = s[i];
        if(c == ' ')continue;
         if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
         P.push_back(c);

         else 
         if(c == '(')
         STACK.push('(');

         else 
         if(c == ')')
         {
             while(STACK.top() != '(')
             {
                 P.push_back(STACK.top());
                 STACK.pop();
             }
             STACK.pop();
         }
         else 
         {
             while (!STACK.empty() && PRECENDCE(s[i]) <= PRECENDCE(STACK.top()))
             {
                 P.push_back(STACK.top());
                 STACK.pop();
             }
             STACK.push(c);    
         }
    }
    return P;
}
int main()
{
    string exp = "(A - B)/((D + E) * F)";
    cout << infixToPostFix(exp) << endl;
    exp = "((A + B)/D) ^ ((E - F) * G)";
    cout << infixToPostFix(exp) << endl;
}
/*
AB-DE+F* /
AB+D/EF-G*^
*/