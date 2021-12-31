/* 
Page 107
Program
4.18 A college uses the following structure for a graduating class:
    1.Student(200)
        2. Name
            3. Last
            3. First
            3. Middle Initial
        2. Major
        2. SAT
            3. Verbal
            3. Math
        2. GPA(4)
        2. CUM
*/
#include<iostream>
#include<string>
struct Student
{
    struct NAME
    {
        string Last;
        string First;
        string Middle_Initial;
    }Name;
    string Major;
    struct S
    {
        string Math;
        string Verbal;
    }SAT;
    float GPA[4];
    float CUM; 
};
using namespace std;
//Main from Here
int main()
{
    /*
    Student STU[200];
    STU[8].Major;
    STU[45].GPA[2];
    */
   

}

/*
Output

*/