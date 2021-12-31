/*
Page 110
Program 
4.29
4.9 A class of student records is organized as follows:

1 Student(35), 2 Name, 3 Last, 3 First, 3 MI (Middle Initial), 2 Major

2 Test(4), 2 Final, 2 Grade

(a) How many elementary items are there?

(b) Describe a record structure—for example, a PL/1 structure 
or a Pascal record, to store the data.

(c) Describe the output of each of the following Write statements: 
(i) Write: Final[15], 
(ii) Write: Name[15] and 
(iii) Write: Test[4].

*/
#include<iostream>
#include<string>
using namespace std;
struct STUDENT
{
    struct
    {
        string FIRST;
        string LAST;
        string MI;
    }NAME;
    string Major;
    int Test[4];
    int FINAL;
    int Grade;
};

//Main from Here
int main()
{
    STUDENT student[35];
    for(int i = 0; i < 35; i++)
    {
        cin >> student[i].NAME.FIRST;
        cin >> student[i].NAME.MI;
        cin >> student[i].NAME.LAST;
        cin >> student[i].Major;
        for(int k = 0;  k < 4; k++)
        cin >> student[4].Test[k];
        cin >> student[i].FINAL;
        cin >> student[i].Grade;

    }
    cout <<student[15].Grade << endl;
    cout << student[15].NAME.FIRST << " " << student[15].NAME.MI << " " << student[15].NAME.LAST << endl;
    cout << student[4].Test[0] << " " << student[4].Test[1] ;
    cout << " " << student[4].Test[2] << " " << student[4].Test[3] << endl;
}

/*
Output

*/