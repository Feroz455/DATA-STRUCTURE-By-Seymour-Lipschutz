/*
Page  110
Program 
4.7 The following is a list of entries, with level numbers, in a file of employee records:
        1.Employee(200)
            2. SSN(Social Security Number)
            2. Name
                3. Last
                3. First
                3. MI(Middle Initial)
            2. Address
                3. Street
                3. Area
                    4. City
                    4. State
                    4. ZIP
            2. Age
            2. Salary
            2. Dependents

(a) Draw the corresponding hierarchical structure.
(b) Which of the items are elementary items?

(c) Describe a record structure—for example, a PL/l structure or a Pascal record—to store the data.

*/
#include<iostream>
#include<string>
struct EMPLOYEE
{
    long int SSN;
    struct 
    {
        string First;
        string Last;
        string MI;
    }NAME;
    struct 
    {
        string Street;
        struct 
        {
            string CITY;
            string State;
            string ZIP;
        }Area;
        
    }Address;
    int age;
    int salary;
    string Dependents;
    
};

using namespace std;
//Main from Here
int main()
{
    EMPLOYEE EMP[200];
    for(int i = 0;  i < 200; i++)
    {
        cout << "Enter First Name\n";
        cin >> EMP[i].NAME.First;
        cout << "Enter MI Name\n";
        cin >> EMP[i].NAME.MI;
        cout << "Enter last Name\n";
        cin >> EMP[i].NAME.Last;

        cout << "AGE?\n";
        cin >>EMP[i].age;
        cout << "SSN?\n";
        cin >>EMP[i].SSN;
        cout << "STREET? \n";
        cin >> EMP[i].Address.Street;
        cout <<"City Name?\n"
        cin >> EMP[i].Address.Area.CITY;
        cout << "SATATE?"
        cin >> EMP[i].Address.Area.State ;
        cout << "ZIP ?\n"
        cout << EMP[i].Address.Area.ZIP;
        cout << "SALARY?\n";
        cin >> EMP[i].salary;

        cout << "DEPENDENTS?\n";
        cin >> EMP[i].Dependents;
    }
    return 0;

}

/*
Output

*/