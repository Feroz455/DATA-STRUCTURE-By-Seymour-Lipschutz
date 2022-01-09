/*
Page 120
Program 
Algorithm 5.1: (Traversing a Linked List) Let LIST be a linked list in memory. 
This algorithm traverses LIST, applying an operation PROCESS to each element 
of LIST. The variable PTR points to the node currently being processed.
1. Set PTR := START. [Initializes pointer PTR.]

2. Repeat Steps 3 and 4 while PTR ≠ NULL.

3.       Apply PROCESS to INFO[PTR].

4.       Set PTR := LINK[PTR]. [PTR now points to the next node.]
[End of Step 2 loop.]

5. Exit.
*/
#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>
using namespace std;
typedef struct _node
{
    string Name;
    string SSN;
    string SEX;
    int SALARY;
    _node *next;
}NODE;
/********************************************/
void START(NODE *HEAD);
void PRINTLINE(int N = 50, string c = "**");
void OPTION();
void PROCESS(NODE *HEAD);
//void INSERT(NODE *HEAD);
void INPUT(NODE *HEAD);
//void DELETEINFO(NODE *HEAD);

/********************************************/


void PROCESS_LINKED_LIST(NODE *head)
{
    return;
}
void START(NODE *HEAD)
{
    char c;
    int check;

    while(1)
    {
        PRINTLINE();
        PRINTLINE();
        OPTION();
        PRINTLINE();
        cout << "-> \t";
        cin >> c;
        switch (c)
        {
        case '0':
            INPUT(HEAD);

            break;
        case '1':
            cout << "CUMMING SOON\n";
           // INSERT(HEAD);
            break;
        case '2':
            PROCESS(HEAD);
            break;
        case '3':
            cout << "CUMMING SOON\n";
          //  DELETEINFO(HEAD);
            break;
        case '4':
            exit(0);
            break;
        default:
            cout << "INVALID INPUT\n";
            cout << "TRY AGAIN\n";
            break;
        }

    }
}


//Main from Here
int main()
{
    NODE *HEAD;
    HEAD = new NODE;
    START(HEAD);
    return 0;

}
void INPUT(NODE *HEAD)
{
    string name, ssn;
    string sex;
    int salary;
    cout << "Enter Info \n";
    cout << "Name ? -> ";
    cin >> name;
    while (name != "$$$$$")
    {
        cout << "SSN ? -> \n";
        cin >> ssn;
        cout << "sex? Male -> M & Female -> F\n";
        cin >> sex;
        cout << "Salary? -> ";
        cin >> salary;
        HEAD->Name = name;
        HEAD->SSN = ssn;
        HEAD->SEX = sex;
        HEAD->SALARY = salary;


        HEAD->next = new NODE;
        HEAD = HEAD->next;


        cout << "Name ? -> ";
        cin >> name;
    }
    HEAD->next = NULL;
    return;
}
void PROCESS(NODE *START)
{
    NODE *HEAD = START;
        PRINTLINE(50, "_");
        cout << "\n" << setw(14) << "NAME" ;
        cout << setw(15) << "SSN" ;
        cout << setw(8) << "SEX" ;
        cout << setw(10) << "SALARY";
        PRINTLINE(50, "_");
    while (HEAD->next != NULL)
    {
        cout << setw(14) << HEAD->Name ;
        cout << setw(15) << HEAD->SSN ;
        cout << setw(8) << HEAD->SEX ;
        cout << setw(10) << HEAD->SALARY << "\n";
        HEAD = HEAD->next;
    }
    return;
    
}
void PRINTLINE(int N, string c)
{
    cout << "\n";
    while(N-- != 0)
    {
        cout << c;
    }
    cout << "\n";
    return;
}
void OPTION()
{
    cout << "**ENTER YOUR CHOISE**\n";
    cout << setw(3) << "0. " << "INPUT INFO0\n"; 
    cout << setw(3) << "1. " << "INSERT INFO\n"; 
    cout << setw(3) << "2. " << "SHOW INFO\n";
    cout << setw(3) << "3. " << "DELETE INFO\n";
    cout << setw(3) << "4. " << "EXIT";
    return;
}
/*
Output
NAME
SSN
SEX
SALARY


Davis
192-38-7282
Female
22800
Kelly
165-64-3351
Male
19000
Green
175-56-2251
Male
27200
Brown
178-52-1065
Female
14700
Lewis
181-58-9939
Female
16400
Cohen
177-44-4557
Male
19000
Rubin
135-46-6262
Female
15500
Evans
168-56-8113
Male
34200
Harris
208-56-1654
Female
22800





****************************************************************************************************

****************************************************************************************************
**ENTER YOUR CHOISE**
0. INPUT INFO0
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. EXIT
****************************************************************************************************
->      0
Enter Info 
Name ? -> Davis
SSN ? -> 
192-38-7282
sex? Male -> M & Female -> F
Female
Salary? -> 22800
Name ? -> Kelly
SSN ? ->
165-64-3351
sex? Male -> M & Female -> F
Male
Salary? -> 19000
Name ? -> Green
SSN ? ->
175-56-2251
sex? Male -> M & Female -> F
Male
Salary? -> 27200
Name ? -> Brown
SSN ? ->
178-52-1065
sex? Male -> M & Female -> F
Female
Salary? -> 14700
Name ? -> Lewis
SSN ? ->
181-58-9939
sex? Male -> M & Female -> F
Female
Salary? -> 16400
Name ? -> Cohen
SSN ? -> 
177-44-4557
sex? Male -> M & Female -> F
Male
Salary? -> 19000
Name ? -> Rubin
SSN ? ->
135-46-6262
sex? Male -> M & Female -> F
Female
Salary? -> 15500
Name ? -> Evans
SSN ? ->
168-56-8113
sex? Male -> M & Female -> F
Male
Salary? -> 34200
Name ? -> Harris
SSN ? ->
208-56-1654
sex? Male -> M & Female -> F
Female
Salary? -> 22800
Name ? -> $$$$$

****************************************************************************************************

****************************************************************************************************
**ENTER YOUR CHOISE**
0. INPUT INFO0
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. EXIT
****************************************************************************************************
->      2
         Davis    192-38-7282  Female     22800
         Kelly    165-64-3351    Male     19000
         Green    175-56-2251    Male     27200
         Brown    178-52-1065  Female     14700
         Lewis    181-58-9939  Female     16400
         Cohen    177-44-4557    Male     19000
         Rubin    135-46-6262  Female     15500
         Evans    168-56-8113    Male     34200
        Harris    208-56-1654  Female     22800

****************************************************************************************************

****************************************************************************************************
**ENTER YOUR CHOISE**
0. INPUT INFO0
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. EXIT
****************************************************************************************************
->      4
*/