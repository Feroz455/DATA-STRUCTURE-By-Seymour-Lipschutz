/*
page 170
6.9 Consider the postfix expression P in Problem 6.8. Evaluate P using Algorithm 6.5.

First add a sentinel right parenthesis at the end of P to obtain:

P: 12, 7, 3, –, /, 2, 1, 5, +, *, +, )
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
    string result;

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
        if (exp[i] == ' ' || exp[i] == ',')
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
                PUSH(pow(val2, val1));;
              //  cout << PEEK() << endl;
                break;
            }
        }
    }
    return POP();
}
int main()
{
    char exp[] = "12, 7, 3, -, /, 2, 1, 5, +, *, +";;
    STACK N(strlen(exp));
    cout << N.EVALUATE_POSTFIX(exp); 
}
/*
15
*/