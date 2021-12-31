/*
Page 106
Program
4.16 The following is a list of entries, with level numbers, in a student’s record:
1 Student 2 Number 2 Name 3 Last 3 First 3 MI (Middle Initial) 2 Sex
2 Birthday 3 Day 3 Month 3 Year 2 SAT 3 Math 3 Verbal
(a) Draw the corresponding hierarchical structure.
(b) Which of the items are elementary items?
*/
#include<iostream>
#include<string>
using namespace std;
struct Student
{
    int Number;
    struct NAME
    {
        string Last;
        string First;
        string Middle_Initial;
    }Name;
    char Sex;
    struct Birthday
    {
        int Day;
        int Month;
        int Year;
    };
    struct S
    {
        string Math;
        string Verbal;
    }SAT;  
};

/*
Output

*/