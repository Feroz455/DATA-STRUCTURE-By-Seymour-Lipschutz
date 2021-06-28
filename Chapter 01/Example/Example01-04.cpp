/*
Program 

*/
#include <iostream>
using namespace std;

struct Name
{
    string First;
    string Middle;
    string last;
};


struct Area
{
    string city;
    string state;
    int zip;
};
struct Address
{
    string street;
    Area *area =  new Area;
};
struct Employee
{
    string SSN;
    Address *address = new Address;
    Name *name = new Name;
    int Age;
    float Salary;
    string Dependents;
    Employee *next;
};
//main begin
int main()
{
    Employee *head;
    Employee Firoz;
    head = &Firoz;
    cout << "Enter details of Firoz\n";

    cout << "Enter SSN \n";
    cin >> head->SSN;
    cout << "Enter First name\n";
    cin >> head->name->First;
    cout << "Enter Middle Name\n";
    cin >> head->name->Middle;
    cout << "Enter last name\n";
    cin >> head->name->last;

    cout << "Enter Address \n";
    cout << "Street \n";
    cin >> head->address->street;
    cout << "City \n";
    cin >> head->address->area->city ;
    cout << "state \n";
    cin >> head->address->area->state;
    cout << "ZIP \n";
    cin >> head->address->area->zip;

    cout << "Enter age \n";
    cin >> head->Age;

    cout << "Enter salary\n";
    cin >> head->Salary;

    cout << "Dependents\n";
    cin >> head->Dependents;

    getchar();
    return 0;
}
//main end
///Program end

/*
output
Enter details of Firoz
Enter SSN
Np-5452125
Enter First name
Mohammad
Enter Middle Name
Firoz
Enter last name
Mahmud
Enter Address 
Street        
Dhaka-Narayanganj
City 
Narayanganj
state 
Dhaka     
ZIP 
1421
Enter age 
22
Enter salary
8000
Dependents
Nothing
*/
