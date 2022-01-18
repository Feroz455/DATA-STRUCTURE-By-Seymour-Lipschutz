/*

6.7 Translate, by inspection and hand, each infix expression into its equivalent 
postfix expression:

(a) (A – B) * (D/E) (b) (A + B ↑ D)/(E – F) + G

(c) A * (B + D)/E – F * (G + H/K)

Using the order in which the operators are executed, translate each operator from 
infix to postfix notation, (We use brackets [ ] to denote a partial translation.)

(a) (A – B)*(D/E) = [AB–]*[DE/] = AB – DE/*

(b) (A + B ↑ D)/(E – F) + G = (A + [BD↑])/[EF –] + G = [ABD↑+]/[EF–] + G

= [ABD↑ +EF – /] + G = ABD↑+EF–/G +

(c) A*(B + D) /E – F*(G + H/K) = A*[BD +]/E – F*(G + [HK/])

= [ABD + *]/E – F*[GHK/ +]

= [ABD + *E/] – [FGHK/ + *]

= ABD + *E/FGHK / + * –

Observe that we did translate more than one operator in a single step when the 
operands did not overlap.
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
    string exp = "(A - B) * (D/E)";
    cout << infixToPostFix(exp) << endl;
    exp = "(A + B ^ D)/(E - F) + G";
    cout << infixToPostFix(exp) << endl;
     exp = "A * (B + D)/E - F * (G + H/K)";
    cout << infixToPostFix(exp) << endl;
}

/*
output
AB-DE/*        
ABD^+EF-/G+    
ABD+*E/FGHK/+*-
*/
