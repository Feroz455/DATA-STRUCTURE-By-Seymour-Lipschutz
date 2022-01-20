/*
6.3  Translate Algorithm 6.6 into a subprogram POLISH(Q, P) 
which transforms an infix expression Q into its equivalent 
postfix expression P. Assume each operand is a single alphabetic 
character, and use the usual symbols for addition (+), subtraction (–), 
multiplication (*) and division (/), but use the symbol ↑ or $ for exponentiation. 
(Some programming languages do not accept ↑.) Test the program using

(a) ( ( A + B ) * D ) $ (E – F)

(b) A + ( B * C – ( D / E $ F ) * G ) * H
*/
#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

// Function to return perecendece of operators
int PRECENDCE(char c)
{
    if (c == '$')
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
    stack<char> STK;
    STK.push('(');
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
         STK.push('(');

         else 
         if(c == ')')
         {
             while(STK.top() != '(')
             {
                 P.push_back(STK.top());
                 STK.pop();
             }
             STK.pop();
         }
         else 
         {
             while (!STK.empty() && PRECENDCE(s[i]) <= PRECENDCE(STK.top()))
             {
                 P.push_back(STK.top());
                 STK.pop();
             }
             STK.push(c);    
         }
    }
    return P;
}
int main()
{
    string exp = "( ( A + B ) * D ) $ (E - F)";
    cout << infixToPostFix(exp) << endl;
    exp = "A + ( B * C - ( D / E $ F ) * G ) * H";
    cout << infixToPostFix(exp) << endl;
}
/*
AB+D*EF-$      
ABC*DEF$/G*-H*+
*/