/*
Page 199
6.10 Consider the following infix expression Q:

Q: ((A + B) * D) ↑ (E – F)

Use Algorithm 6.6 to translate Q into its equivalent postfix expression P.

First push a left parenthesis onto STACK, and then add a right parenthesis to the end of Q to obtain

Q: ( ( A + B ) * D ) ↑ ( E – F ) )

(Note that Q now contains 16 elements.) Scan Q from left to right. Recall that (1) if a constant is encountered, it is added to P; (2) if a left parenthesis is encountered, it is put on the stack; (3) if an operator is encountered, it “sinks” to its own level; and (4) if a right parenthesis is encountered, it “sinks” to the first left parenthesis. Figure 6.33 shows pictures of STACK and the string P as each element of Q is scanned. When STACK is empty, the final right parenthesis has been scanned and the result is

P: A B + D * E F – ↑

which is the required postfix equivalent of Q.
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
    string exp = "((A + B) * D) ^ (E - F)";
    cout << infixToPostFix(exp) << endl;
}
/*
AB+D*EF-^
*/