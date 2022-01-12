/*
Page 121
Program 
Algorithm 5.2 SEARCH(INFO, LINK, START, ITEM, LOC)
LIST is a linked list in memory. This algorithm finds the location LOC 
of the node where ITEM first appears in LIST, or sets LOC = NULL.

1. Set PTR := START.

2. Repeat Step 3 while PTR ≠ NULL:

3.       If ITEM = INFO[PTR], then:

Set LOC := PTR, and Exit.

Else:

Set PTR := LINK[PTR]. [PTR now points to the next node.]

[End of If structure.]

[End of Step 2 loop.]

4. [Search is unsuccessful.] Set LOC := NULL.

5. Exit

6. Return.
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
void SEARCH_BY_NAME(NODE *HEAD, string name);
void SEARCH_BY_SSN(NODE *HEAD, string name);
int ELEMENT(NODE *START);
void SEARCH_OPTION();
void PRINT_ITEM(NODE *HEAD);

/********************************************/


void PROCESS_LINKED_LIST(NODE *head)
{
    return;
}
void START(NODE *HEAD)
{
    char c, s;
    string temp;
    int check, NUM = 0;

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
            cout<< "\nNUMBER OF REORD STORED IS \""  << ELEMENT(HEAD) << "\""<< endl; 
            break;
        case '5':
            SEARCH_OPTION();
            cout << "--> ";
            cin >> s;
            s = tolower(s);
            if(s == '1')
                SEARCH_BY_NAME(HEAD,temp);
            else 
                if(s == '2')
                    SEARCH_BY_SSN(HEAD, temp);
            else
                cout << "INVALID NPUT\n";
            break;
        case '9':
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
       PRINT_ITEM(HEAD);
        HEAD = HEAD->next;
    }
    return;
    
}
/***********************************/
void SEARCH_OPTION()
{
    PRINTLINE(50, "#");
    cout << "Enter your choice\n";
    cout <<"1. " <<  "SEARCH BY NAME\n";
    cout <<"2. " <<  "SEARCH BY SSN\n";
    PRINTLINE(50, "#");

}
void SEARCH_BY_NAME(NODE *HEAD, string name)
{
    int LOC = 0, CHECK = 0;
    NODE *PTR = HEAD;

    PRINTLINE(50, "_");
    cout << "Enter Name\n";
    cin >> name;
    PRINTLINE(50, "_");
    while (PTR->next != NULL)
    {
        if(PTR->Name == name)
        {
            cout << "ITEM FOUND AT " << LOC + 1 << "th POSITION\n";
            PRINT_ITEM(PTR);
            CHECK = 1;
            break;
        }
        PTR = PTR->next;
        LOC++;  
    }
    if(CHECK == 0)
    cout << "ITEM NOT FOUND\n";
    return ;
}
void SEARCH_BY_SSN(NODE *HEAD, string SSN)
{
    int LOC = 0, CHECK = 0;
    NODE *PTR = HEAD;

    PRINTLINE(50, "_");
    cout << "Enter SSN\n";
    cin >> SSN;
    PRINTLINE(50, "_");
    while (PTR->next != NULL)
    {
        if(PTR->SSN == SSN)
        {
            cout << "ITEM FOUND AT " << LOC + 1 << "th POSITION\n";
            PRINT_ITEM(PTR);
             cout << "SALARAY WILL BE "  << ((PTR->SALARY*0.05) + PTR->SALARY) << endl; 
            CHECK = 1;
            break;
        }
        PTR = PTR->next;
        LOC++;  
    }
    if(CHECK == 0)
    cout << "ITEM NOT FOUND\n";
    return ;
}
/***********************************/
int ELEMENT(NODE *START)
{
    int NUM = 0 ; 
    NODE *PTR = START;
    while (PTR->next != NULL)
    {
        NUM++;
        PTR = PTR->next;
    }
    return NUM;
    
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
    cout << setw(3) << "4. " << "NUMBER OF ELEMENT\n"; 
    cout << setw(3) << "5. " << "SEARCH INFO\n";
    cout << setw(3) << "9. " << "EXIT";
    return;
}
void PRINT_ITEM(NODE *HEAD)
{
        cout << setw(14) << HEAD->Name ;
        cout << setw(15) << HEAD->SSN ;
        cout << setw(8) << HEAD->SEX ;
        cout << setw(10) << HEAD->SALARY << "\n";
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



**ENTER YOUR CHOISE**
0. INPUT INFO0
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. NUMBER OF ELEMENT
5. EXIT
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
4. NUMBER OF ELEMENT
5. EXIT
****************************************************************************************************
->      4

NUMBER OF REORD STORED IS "9"

****************************************************************************************************

****************************************************************************************************
**ENTER YOUR CHOISE**
0. INPUT INFO0
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. NUMBER OF ELEMENT
5. EXIT
****************************************************************************************************
->      4

NUMBER OF REORD STORED IS "9"
*/