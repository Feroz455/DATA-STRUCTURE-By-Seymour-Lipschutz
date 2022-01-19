/*
page 211
6.10 Consider each of the following postfix expressions:

P1: 5, 3, +, 2, *, 6, 9, 7, –, /, –

P2: 3, 5, +, 6, 4, –, *, 4, 1, –, 2, ↑, +

P3: 3, 1, +, 2, ↑, 7, 4, –, 2, *, +, 5, –

Translate, by inspection and hand, each expression into infix notation and then evaluate.
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
    /*
    char exp[] = "5, 3, +, 2, *, 6, 9, 7, -, /, -";
    STACK N(strlen(exp));
    cout << N.EVALUATE_POSTFIX(exp);
    
    char exp[] = "3, 5, +, 6, 4, -, *, 4, 1, -, 2, ↑, +";
    STACK N(strlen(exp));
    cout << N.EVALUATE_POSTFIX(exp);
    */
    char exp[] = "3, 1, +, 2, ↑, 7, 4, -, 2, *, +, 5, -";
    STACK N(strlen(exp));
    cout << N.EVALUATE_POSTFIX(exp);
}
/*
13
72
37
*/