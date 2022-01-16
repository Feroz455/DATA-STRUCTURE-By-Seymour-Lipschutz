/*
page 170
Algorithm 6.3: This algorithm finds the VALUE of an arithmetic expression P written in postfix notation.

1. Add a right parenthesis “)” at the end of P. [This acts as a sentinel.]

2. Scan P from left to right and repeat Steps 3 and 4 for each element of P until
the sentinel “)” is encountered.

3.      If an operand is encountered, put it on STACK.

4.      If an operator ⊗ is encountered, then:

(a) Remove the two top elements of STACK, where A is the top element and B is the next-to-top element.

(b) Evaluate B ⊗ A.

(c) Place the result of (b) back on STACK.

[End of If structure.]

[End of Step 2 loop.]

5. Set VALUE equal to the top element on STACK.

6. Exit.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include<cstring>
using namespace std;
class STACK
{
private:
    int top;
    unsigned capasity;
    int *array;

public:
    STACK(unsigned capasity);
    void PUSH(int op);
    int POP();
    bool isEmpty();
    int PEEK();
    int EVALUATE_POSTFIX(char *exp);
    ~STACK();
};
bool STACK::isEmpty()
{
    return (top == -1);
}
void STACK::PUSH(int op)
{
    array[++top] = op;
}
int STACK::POP()
{
    if (!isEmpty())
    {
        return array[top--];
    }
    return '$';
}
int STACK::PEEK()
{
    return array[top];
}
STACK::STACK(unsigned capasity)
{
    top = -1;
    this->capasity = capasity;
    array = new int[(capasity * sizeof(int))];
}

STACK::~STACK()
{
}
int STACK::EVALUATE_POSTFIX(char *exp)
{
    int i, num, val1, val2;
    for (i = 0; exp[i]; i++)
    {
       // cout << "exp[" << i << "] " << exp[i] << endl;
        if (exp[i] == ' ')
            continue;
        else if (isdigit(exp[i]))
        {
            num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            //cout << "NUM " << num << endl;
            PUSH(num);
        }
        else
        {
            val1 = POP();
            val2 = POP();
            switch (exp[i])
            {
            case '+':
                PUSH(val2 + val1);
               // cout << PEEK() << endl;
                break;
            case '-':
                PUSH(val2 - val1);
              //  cout << PEEK() << endl;
                break;
            case '*':
                PUSH(val2 * val1);
               // cout << PEEK() << endl;
                break;
            case '/':
                PUSH(val2 / val1);
               // cout << PEEK() << endl;
                break;
            case '^':
                PUSH(pow(val2, val1));
              //  cout << PEEK() << endl;
                break;
            }
        }
    }
    return POP();
}
int main()
{
    char exp[] = "5 6 2 + * 12 4 / -";;
    STACK N(strlen(exp));
    cout << N.EVALUATE_POSTFIX(exp);
}