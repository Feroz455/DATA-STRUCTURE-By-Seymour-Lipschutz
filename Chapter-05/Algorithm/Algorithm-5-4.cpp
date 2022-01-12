/*
Page 30
Algorithm 5.4: INSFIRST(INFO, LINK, START, AVAIL, ITEM)
This algorithm inserts ITEM as the first node in the list.

1. [OVERFLOW?] If AVAIL = NULL, then: Write: OVERFLOW, and Exit.

2. [Remove first node from AVAIL list.]
Set NEW := AVAIL and AVAIL := LINK[AVAIL].

3. Set INFO[NEW] := ITEM. [Copies new data into new node]

4. Set LINK[NEW] := START. [New node now points to original first node.]

5. Set START := NEW. [Changes START so it points to the new node.]

6. Exit.
*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
/* NODE with variable Name, SSN, gender, salary*/
typedef struct _node
{
    string Name;
    string SSN;
    string SEX;
    int SALARY;
    _node *next;
}NODE;
/***********************/
void ADD_HEAD(NODE **HEAD,NODE X);
void ADD_TAIL(NODE **HEAD, NODE X);
void DISPLAY(NODE *START);
void SEARCH_BY_NAME(NODE *HEAD, string name);
void SEARCH_BY_SSN(NODE *HEAD, string SSN);
void SEARCH_OPTION();
int ELEMENT(NODE *START);
void PRINTLINE(int N = 50, string c = "**");
void OPTION();
void PRINT_ITEM(NODE *HEAD);
void PRINT_ITEM(NODE HEAD);
/***********************/

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
           // cout << "\nName? -> ";
            cin >> X.Name;
          while (X.Name != "$$$$$")
            {
              //  cout << "\nSSN ? -> ";
                cin >> X.SSN;
              //  cout << "\nsex? Male  or  Female -> ";
                cin >> X.SEX;
               // cout << "\nSalary? -> ";
                cin >> X.SALARY;
                /*************/
                ADD_HEAD(&HEAD,X);

                cout << "Name?\n";
                cin >> X.Name;
            }
            break;
        case '2':
            DISPLAY(HEAD);
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
            else if(s == '2')
            SEARCH_BY_SSN(HEAD, temp);
            else
            cout << "INVALID NPUT\n";
            break;
        case '6':
                cout << "\nName? -> ";
                cin >> X.Name;
                cout << "\nSSN ? -> ";
                cin >> X.SSN;
                cout << "\nsex? Male  or  Female -> ";
                cin >> X.SEX;
                cout << "\nSalary? -> ";
                cin >> X.SALARY;

                ADD_HEAD(&HEAD,X);
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
//DISPLAY DATA 
void DISPLAY(NODE *START)
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
void SEARCH_OPTION()
{
    PRINTLINE(50, "#");
    cout << "Enter your choice\n";
    cout <<"1. " <<  "SEARCH BY NAME\n";
    cout <<"2. " <<  "SEARCH BY SSN\n";
    PRINTLINE(50, "#");
}
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
    cout << setw(3) << "1. " << "INPUT INFO\n"; 
    cout << setw(3) << "2. " << "SHOW INFO\n";
    cout << setw(3) << "3. " << "DELETE INFO\n";
    cout << setw(3) << "4. " << "NUMBER OF ELEMENT\n"; 
    cout << setw(3) << "5. " << "SEARCH INFO\n";
    cout << setw(3) << "6. " << "INSERT INFO\n"; 
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
/**********************/
int main()
{
    START();
    return 0;
}
