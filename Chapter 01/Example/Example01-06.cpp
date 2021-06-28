/*
Program 

*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Employee
{
    string name;
    string Address;
    string TelNumber;
    int age;
    char Sex;
    Employee *next;
};

//main begin
int main()
{
    Employee *Head;
    Head = new Employee;
    void *AD = Head;
    int i;
    string area, name;
    cout << "Want to Add new member yes = 1 \n no = 0 : ";
    cin >> i;
    getchar();
    while (i)
    {
        // cout << "Enter Name\n";
        getline(cin, Head->name);
        // cout << "Enter Addressn\n";
        getline(cin, Head->Address);
        //  cout << "Enter Telephone number\n";
        cin >> Head->TelNumber;
        // cout << "Enter age\n";
        cin >> Head->age;
        // cout << "Enter sex \n";
        cin >> Head->Sex;
        cout << "Want to Add new member yes = 1 \n no = 0: \n  ";
        cin >> i;
        getchar();
        if (i != 0)
        {
            Head->next = new Employee;
            Head = Head->next;
            cout << "Hello\n";
        }
        else
        {
            Head->next = NULL;
            break;
        }
        cout << "i = " << i << endl;
    }
    Head = (Employee *)AD;
    /*******************************/
    /******* a)
    * Suppose the orgsnizstion want to announce a meeting though
    * a mailing.Then one word traverse 
    * the file to obtain Name and Address for each member */
    cout << "Meeting \n";
    while (Head != NULL)
    {
        cout << Head->name << "\t";
        cout << Head->Address << endl;
        Head = Head->next;
        if (Head->next == NULL)
        {
            cout << Head->name << "\t";
            cout << Head->Address << endl;
            break;
        }
    }
    /** b)
 *  Suppose one wants to find the names of all members living in
 *  a certain area. Again one would traverse the file to obtain the data.*/

    Head = (Employee *)AD;
    size_t found;
    cout << "Enter State \n";
    getline(cin, area);
    while (Head != NULL)
    {
        found = Head->Address.find(area);
        if (found != string::npos)
        {
            cout << Head->name << "\t";
            cout << Head->Address << endl;
            break;
        }
        if (Head->next == NULL)
        {
            found = Head->next->Address.find(area);
            if (found != string::npos)
            {
                cout << Head->name << "\t";
                cout << Head->Address << endl;
                break;
            }
        }
        Head = Head->next;
    }
    /*
*(c) Suppose one wants to obtain Address for a given Name.
*Then one would search the file for the record containing Name.
*/
    Head = (Employee *)AD;
    cout << "Enter Employee Name\n";
    getline(cin, name);
    getchar();
    while (Head != NULL)
    {
        if (((Head->name).compare(name)) == 0)
        {
            cout << name << "'s Address is " << Head->Address << endl;
            break;
        }

        if (Head->next == NULL)
        {
            if (((Head->next->name).compare(name)) == 0)
                cout << name << "'s Address is " << Head->Address << endl;
            break;
        }
        Head = Head->next;
    }

    /**
     *(d) Suppose a new person joins the organization.
     *Then one would insert his or her record into the file.
     */

    Head->next = new Employee;
    Head = Head->next;
    // cout << "Enter Name\n";
    getline(cin, Head->name);
    // cout << "Enter Addressn\n";
    getline(cin, Head->Address);
    //  cout << "Enter Telephone number\n";
    cin >> Head->TelNumber;
    // cout << "Enter age\n";
    cin >> Head->age;
    // cout << "Enter sex \n";
    cin >> Head->Sex;
    Head->next = NULL;

    /**
     * (e) Suppose a member dies. Then one would delete his or her record from the file.
     * 
     */

    Head = (Employee *)AD;
    cout << "Enter Employee Name Who died\n";
    getline(cin, name);
    getchar();
    while (Head != NULL)
    {
        if (((Head->name).compare(name)) == 0)
        {
            Head = Head->next->next;
            break;
        }

        if (Head->next == NULL)
        {
            if (((Head->next->name).compare(name)) == 0)
                Head->next = NULL;
            break;
        }
        Head = Head->next;
    }
    /**
 * (f) Suppose a member has moved and has a new address and telephone number. 
 * Given the name of the member, one would first need to search for the record
 *  in the file. Then one would perform the “update”—i.e., change items in the 
 * record with the new data.
 */
    Head = (Employee *)AD;
    cout << "Enter Employee Name\n";
    getline(cin, name);
    getchar();
    while (Head != NULL)
    {
        if (((Head->name).compare(name)) == 0)
        {
            cout << "Enter Addressn\n";
            getline(cin, Head->Address);
            cout << "Enter Telephone number\n";
            cin >> Head->TelNumber;
            break;
        }

        if (Head->next == NULL)
        {
            if (((Head->next->name).compare(name)) == 0)
            {
                cout << "Enter Addressn\n";
                getline(cin, Head->next->Address);
                cout << "Enter Telephone number\n";
                cin >> Head->next->TelNumber;
                break;
            }
        }
        Head = Head->next;
    }
    /**
     *(g) Suppose one wants to find the number 
     of members 65 or older. Again one would
      traverse the file, counting such members.
     */

    int age;
    Head = (Employee *)AD;
    cout << "Enter Employees age\n";
    cin >> age;
    getchar();
    while (Head != NULL)
    {
        if (Head->age >= age)
        {
            cout << Head->name << " " << Head->Address << " " << Head->age
                 << Head->Sex << " " << Head->TelNumber << " \n";
        }
        if (Head->next == NULL)
        {
            if (Head->next->age >= age)
                cout << Head->next->name << " " << Head->next->Address << " "
                     << Head->next->age << Head->next->Sex << " " << Head->next->TelNumber
                     << " \n";
            break;
        }
        Head = Head->next;
    }

    getchar();
    return 0;
}
//main end
///Program end

/*
output
Want to new member yes = 1 
 no = 0 : 1
Mohammad Firoz Mahmud
Delpara, Kutubpur ,Fatulla,Narayanganj
01236597
22
M
Want to new member yes = 1 
 no = 0
1
Maliha Rahman
Sugonda point Chottogram
123654789
19
F
*/
