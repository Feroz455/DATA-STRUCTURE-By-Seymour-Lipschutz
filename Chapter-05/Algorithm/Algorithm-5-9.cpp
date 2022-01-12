/*
Page 137
Algorithm 5.8: DEL(INFO, LINK, START, AVAIL, LOC, LOCP)
This algorithm deletes the node N with location LOC. LOCP is the location of the node which precedes N or, when N is the first node, LOCP = NULL.

1. If LOCP = NULL, then:

Set START := LINK[START]. [Deletes first node.]

Else:

Set LINK[LOCP] := LINK[LOC]. [Deletes node N.]

[End of If structure.]

2. [Return deleted node to the AVAIL list.]
Set LINK[LOC] := AVAIL and AVAIL := LOC.

3. Exit.
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
void DELETE(NODE ** HEAD, string key);
void DELETE(NODE ** HEAD, int key);
/********************************************/


void PROCESS_LINKED_LIST(NODE *head)
{
    return;
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
                INSERT(&HEAD,X);

                cout << "Name?\n";
                cin >> X.Name;
            }
            break;
        case '2':
            PROCESS(HEAD);
            break;
        case '3':
            cout << "Enter SSN number to delete\n";
            cin >> temp;
            DELETE(&HEAD, temp);
            break;
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
//INSERT DATA INTO LIST SORTED 

//ALGORITHM 6 & 7 is fully developed here 
void INSERT(NODE **START, NODE X)
{
    NODE *NEW, *OLD, *CUR, *PTR = *START;\
    //If List is empty then insert record into head
    if(*START == NULL)
    {
        ADD_TAIL(START, X);
        return;
    }
    //if head is greater then new record then insert data after head 
    if(PTR->SSN > X.SSN)
    {
        ADD_HEAD(START, X);
        return;
    }
    /*

    */
    int CHECK = 0;
    //find posision for new record to insert into list
    while(PTR->SSN < X.SSN)
    {
        //if record is smaller then last record in the list then new recod should be added into the end of the list
        if(PTR->next == NULL)
        {
            ADD_TAIL(START, X);
            return;
        }
        PTR = PTR->next;
        CHECK++;

    }
    //find previous node address to insert new node 
    PTR = *START;
    while (CHECK-- != 1)
    {
        PTR = PTR->next;
    }
    //inserting new node into the list
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
void DELETE(NODE **HEAD, int SS)
{
    NODE *PTR = *HEAD, *PREV;
    if(*HEAD == NULL)
    {
        cout << "UNDER FLOW\n";
        return;
    }
    else 
    if(SS == 1 )
    {
    PTR = *HEAD;
    *HEAD = PTR ->next;
    delete PTR;
    PTR = NULL;
    }
    else
    while(SS-- != 1)
    {
        PREV = PTR;
        PTR = PTR->next;
    }
    PREV->next = PTR->next;
    PRINT_ITEM(PTR);
    delete PTR;
    return;
}
void DELETE(NODE ** HEAD, string key)
{
    
    // Store head node
    NODE* temp = *HEAD;
    NODE* prev = NULL;
    
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->SSN == key)
    {
        *HEAD = temp->next; // Changed head

        PRINT_ITEM(temp);
        cout << "THIS RECOD HAS BEEN DELETED\n";
        delete temp;            // free old head
        return;
    }

    // Else Search for the key to be deleted, 
    // keep track of the previous node as we
    // need to change 'prev->next' */
    else
    {
    while (temp != NULL && temp->SSN != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
    {
        cout << "ITEM NOT FOUND IN THE LIST\n";
        return;
    }


    // Unlink the node from linked list
    prev->next = temp->next;

    PRINT_ITEM(temp);
    cout << "THIS RECOD HAS BEEN DELETED\n";
    // Free memory
    delete temp;
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

//Main from Here
int main()
{
    START();
    return 0;

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
    cout << setw(3) << "6. " << "DELETE RECORD\n";

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

*/