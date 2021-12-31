/*
Page 106
Program
4.17 A professor keeps the following data for each student in a class of 20 students:

Name (Last, First, MI), Three Tests, Final, Grade
*/
#include<iostream>
#include<string>
using namespace std;
struct Student
{
     struct NAME
    {
        string Last;
        string First;
        string Middle_Initial;
    }Name;
    int Test[3];
    int FINAL[3];
    char GRADE[2];
};

//Main from Here
int main()
{
    Student STU[20];
}

/*
Output

*/