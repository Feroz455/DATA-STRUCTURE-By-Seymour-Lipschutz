/*
Algorithm 6.6: POLISH(Q, P)

Suppose Q is an arithmetic expression written in infix notation. 
This algorithm finds the equivalent postfix expression P.

1. Push “(” onto STACK, and add “)” to the end of Q.

2. Scan Q from left to right and repeat Steps 3 to 6 for each element of Q
until the STACK is empty:

3.      If an operand is encountered, add it to P.

4.      If a left parenthesis is encountered, push it onto STACK.

5.      If an operator ⊗ is encountered, then:

(a) Repeatedly pop from STACK and add to P each operator (on the top of STACK) 
which has the same precedence as or higher precedence than ⊗.

(b) Add ⊗ to STACK.

[End of If structure.]

6.      If a right parenthesis is encountered, then:

(a) Repeatedly pop from STACK and add to P each operator (on the top of STACK) 
until a left parenthesis is encountered.

(b) Remove the left parenthesis. [Do not add the left parenthesis to P.]

[End of If structure.]

[End of Step 2 loop.]

7. Exit.


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
    string exp = "A + ( B * C - ( D / E ^ F ) * G) * H";
    cout << infixToPostFix(exp) << endl;
    exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostFix(exp) << endl;
}
/*
ABC*DEF^/G*-H*+  
abcd^e-fgh*+^*+i-
*/