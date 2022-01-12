/*
Page 123
Program 
Algorithm 5.3: SRCHSL(INFO, LINK, START, ITEM, LOC)
LIST is a sorted list in memory. This algorithm finds the location LOC 
of the node where ITEM first appears in LIST, or sets LOC = NULL.

1. Set PTR := START.

2. Repeat Step 3 while PTR ≠ NULL:

3.       If ITEM < INFO[PTR], then:

Set PTR := LINK[PTR]. [PTR now points to next node.]

Else if ITEM = INFO[PTR], then:

Set LOC := PTR, and Exit. [Search is successful.]

Else:

Set LOC := NULL, and Exit. [ITEM now exceeds INFO[PTR].]

[End of If structure.]

[End of Step 2 loop.]

4. Set LOC := NULL.

5. Exit.

The complexity of this algorithm is still the same as that of other 
linear search algorithms; that is, the worst-case running time is 
proportional to the number n of elements in LIST, and the average-
case running time is approximately proportional to n/2
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
void START();
void PRINTLINE(int N = 50, string c = "**");
void OPTION();
void PROCESS(NODE *HEAD);
void INPUT(NODE *HEAD);
//void DELETEINFO(NODE *HEAD);
void SEARCH_BY_NAME(NODE *HEAD, string name);
void SEARCH_BY_SSN(NODE *HEAD, string name);
int ELEMENT(NODE *START);
void SEARCH_OPTION();
void PRINT_ITEM(NODE *HEAD);
void PRINT_ITEM(NODE HEAD);
void ADD_HEAD(NODE **HEAD,NODE X);
void INSERT(NODE **START, NODE X);
void ADD_TAIL(NODE **HEAD, NODE X);
/********************************************/

//Main from Here
int main()
{
    START();
    return 0;

}

void START()
{
    char c, s;
    string temp;
    int check, NUM = 0;
    NODE *HEAD = NULL, X;
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
        case '1':
                cout << "\nName? -> ";
                cin >> X.Name;
                while (X.Name != "$$$$$")
                    {
                        cout << "\nSSN ? -> ";
                        cin >> X.SSN;
                        cout << "\nsex? Male  or  Female -> ";
                        cin >> X.SEX;
                        cout << "\nSalary? -> ";
                        cin >> X.SALARY;
                        /*************/
                        INSERT(&HEAD,X);
                        cout << "Name?\n";
                        cin >> X.Name;
                    }
            break;
        case '2':
            PROCESS(HEAD);
            break;
        case '3':
            cout << "CUMMING SOON\n";
          //  DELETEINFO(HEAD);
            break;
        case '4':
            cout<< "\nNUMBER OF RECORD STORED IS \""  << ELEMENT(HEAD) << "\""<< endl; 
            break;
        case '5':
                SEARCH_OPTION();
                cout << "--> ";
                cin >> s;
                s = tolower(s);
                if(s == '1')
                SEARCH_BY_NAME(HEAD,temp);
                else if(s == '2')
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
/***************************/
void PROCESS_LINKED_LIST(NODE *head)
{
    return;
}
//INSERT DATA INTO LIST SORTED 
void INSERT(NODE **START, NODE X)
{
    NODE *NEW, *OLD, *CUR, *PTR = *START;
    if(*START == NULL)
    {
        ADD_TAIL(START, X);
        return;
    }
    if(PTR->Name > X.Name)
    {
        ADD_HEAD(START, X);
        return;
    }
    int CHECK = 0;
    while(PTR->Name < X.Name)
    {
       
        if(PTR->next == NULL)
        {
            ADD_TAIL(START, X);
            return;
        }
        PTR = PTR->next;
        CHECK++;

    }
    PTR = *START;
    while (CHECK-- != 1)
    {
        PTR = PTR->next;
    }
    NEW = new NODE;
    NEW->Name = X.Name;
    NEW->SALARY = X.SALARY;
    NEW->SEX = X.SEX;
    NEW->SSN = X.SSN;
    NEW->next = NULL;
    
    NEW->next = PTR->next;
    PTR->next = NEW;
    return;
}
//ADD ITEM INFRONT OF LIST
void ADD_HEAD(NODE **HEAD,NODE X)
{

    PRINT_ITEM(X);
    NODE *PTR;
    PTR = new NODE;

    PTR->Name = X.Name;
    PTR->SALARY = X.SALARY;
    PTR->SEX = X.SEX;
    PTR->SSN = X.SSN;
    PTR->next = *HEAD;
    *HEAD = PTR;
    return;
}
//ADD DATA END OF THE LIST
void ADD_TAIL(NODE **HEAD, NODE X)
{
    NODE *PTR, *END = *HEAD;
    PTR = new NODE;

    PTR->Name = X.Name;
    PTR->SALARY = X.SALARY;
    PTR->SEX = X.SEX;
    PTR->SSN = X.SSN;
    PTR->next = NULL;

    if(*HEAD == NULL)
    {
        *HEAD = PTR;
        return;
    }
    while(END->next != NULL)
    {
        END = END->next;
    }
    END->next = PTR;
    return;
}


//GET INPUT DATA FROM USER
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
/*****************************/

//DISPLAY DATA 
void PROCESS(NODE *START)
{
    if(START == NULL)
    {
        cout << "LIST IS EMPTY\n";
        return;
    }
    NODE *HEAD = START;
        PRINTLINE(50, "_");
        cout << "\n" << setw(14) << "NAME" ;
        cout << setw(15) << "SSN" ;
        cout << setw(8) << "SEX" ;
        cout << setw(10) << "SALARY";
        PRINTLINE(50, "_");
    while (HEAD != NULL)
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
void SEARCH_BY_NAME(NODE *HEAD, string Name)
{
    int LOC = 0, CHECK = 0;
    NODE *PTR = HEAD;

    PRINTLINE(50, "_");
    cout << "Enter name\n";
    cin >> Name;
    PRINTLINE(50, "_");
    while (PTR != NULL)
    {
        if(PTR->Name == Name)
        {
            cout << "ITEM FOUND AT " << LOC + 1 << "th POSITION\n";
            PRINT_ITEM(PTR);
            int S = PTR->SALARY ;
            cout << "Salary incress = " <<  S + (S*0.05) << " $" << endl; 
            return;
        }
        if(PTR->Name > Name)
        {
            cout << "ITEM NOT FOUND\n";
            return;
        }
        PTR = PTR->next;
        LOC++;  
    }
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
    while (PTR != NULL)
    {
        if(PTR->SSN == SSN)
        {
            cout << "ITEM FOUND AT " << LOC + 1 << "th POSITION\n";
            PRINT_ITEM(PTR);
            return;
        }
        if(PTR->SSN > SSN)
        {
            cout << "ITEM NOT FOUND\n";
            return;
        }
        PTR = PTR->next;
        LOC++;  
    }
    cout << "ITEM NOT FOUND\n";
    return ;
}
/***********************************/
int ELEMENT(NODE *START)
{
    int NUM = 0 ; 
    NODE *PTR = START;
    while (PTR != NULL)
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
void PRINT_ITEM(NODE HEAD)
{
        cout << setw(14) << HEAD.Name ;
        cout << setw(15) << HEAD.SSN ;
        cout << setw(8) << HEAD.SEX ;
        cout << setw(10) << HEAD.SALARY << "\n";
        return;
}
/*
Output
**ENTER YOUR CHOISE**
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. NUMBER OF ELEMENT
5. SEARCH INFO
9. EXIT
****************************************************************************************************
->      2

__________________________________________________

          NAME            SSN     SEX    SALARY
__________________________________________________
         Brown    178-52-1065  Female     14700
         Cohen    177-44-4557    Male     19000
         Davis    192-38-7282  Female     22800
         Evans    168-56-8113    Male     34200
         Green    172-56-2251    Male     27200
        Harris    208-56-1654  Female     22800
         Kelly    165-64-3351    Male     19000
         Lewis    181-58-9939  Female     16400
         Rubin    135-46-6262  Female     15500

****************************************************************************************************

****************************************************************************************************
**ENTER YOUR CHOISE**
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. NUMBER OF ELEMENT
5. SEARCH INFO
9. EXIT
****************************************************************************************************
->      4

NUMBER OF REORD STORED IS "9"

****************************************************************************************************

****************************************************************************************************
**ENTER YOUR CHOISE**
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. NUMBER OF ELEMENT
5. SEARCH INFO
9. EXIT
****************************************************************************************************
->      2

__________________________________________________

          NAME            SSN     SEX    SALARY
__________________________________________________
         Brown    178-52-1065  Female     14700
         Cohen    177-44-4557    Male     19000
         Davis    192-38-7282  Female     22800
         Evans    168-56-8113    Male     34200
         Green    172-56-2251    Male     27200
        Harris    208-56-1654  Female     22800
         Kelly    165-64-3351    Male     19000
         Lewis    181-58-9939  Female     16400
         Rubin    135-46-6262  Female     15500

****************************************************************************************************

****************************************************************************************************
**ENTER YOUR CHOISE**
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. NUMBER OF ELEMENT
5. SEARCH INFO
9. EXIT
****************************************************************************************************
->      5

##################################################
Enter your choice
1. SEARCH BY NAME
2. SEARCH BY SSN

##################################################
--> 1

__________________________________________________
Enter name
Green

__________________________________________________
ITEM FOUND AT 5th POSITION
         Green    172-56-2251    Male     27200
Salary incress = 28560 $

****************************************************************************************************

****************************************************************************************************
**ENTER YOUR CHOISE**
1. INSERT INFO
2. SHOW INFO
3. DELETE INFO
4. NUMBER OF ELEMENT
5. SEARCH INFO
9. EXIT
****************************************************************************************************
->      9
*/