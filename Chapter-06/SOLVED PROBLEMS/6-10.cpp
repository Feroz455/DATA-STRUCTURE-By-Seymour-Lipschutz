/*
Page 199
6.11 Translate, by inspection and hand, each infix expression into its 
equivalent prefix expression:

(a) (A – B) * (D / E)

(b) (A + B ↑ D)/(E – F) + G

Is there any relationship between the prefix expressions and the equival
ent postfix expressions obtained in Solved Problem 6.7.

Using the order in which the operators are executed, translate each oper
ator from infix to prefix notation.

(a) (A – B)*(D/E) = [–AB]*[/DE] = * – A B / D E

(b) (A + B ↑ D)/(E – F) + G = (A + [↑ BD])/[–EF] + G

= [+ A ↑ BD]/[–EF] + G

= [/ + A ↑ BD – EF] + G

= + / + A ↑ B D – E F G

The prefix expression is not the reverse of the postfix expression. Howe
ver, the order of the operands—A, B, D and E in part (a) and A, B, D, E,
 F and G in part (b)—is the same for all three expressions, infix, postf
 ix and prefix.
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
    string exp = "(A - B) * (D / E)";
    cout << infixToPostFix(exp) << endl;
    exp = "(A + B ^ D)/(E - F) + G";
    cout << infixToPostFix(exp) << endl;
}
/*
AB-DE/*    
ABD^+EF-/G+
*/