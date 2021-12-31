/* 
Page 110
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

4.10 Consider the data structure in Solved Problem 4.18. Write a procedure which

(a) Finds the average of the sophomore GPA scores

(b) Finds the number of biology majors

(c) Finds the number of CUM scores exceeding K

*/
#include<iostream>
#include<string>
struct Student
{
    struct
    {
        string Last;
        string First;
        string Middle_Initial;
    }Name;
    string Major;
    struct 
    {
        string Math;
        string Verbal;
    }SAT;
    float GPA[4];
    //Cumulative Grade point average
    float CUM; 
};
using namespace std;
//Main from Here
int main()
{
    Student STU[200];
          
    int SUM = 0;
    int BIO = 0;
    int C = 0, K;
    for(int i = 0; i < 200; i++)
    {
        cin >> STU[i].Name.First;
        cin >> STU[i].Name.Middle_Initial;
        cin >> STU[i].Name.Last;
        cin >> STU[i].Major;
        cin >> STU[i].SAT.Math;
        cin >> STU[i].SAT.Verbal;
        for(int j = 0;  j < 4; j++)
        {
            cin >> STU[i].GPA[j];
        }
        cin >> STU[i].CUM;
    }
    cout << "Enter Value of K\n";
    cin > K ;

        for(int i = 0; i < 200; i++)
        {
            SUM += STU[i].GPA[1];
            if(STU[i].Major == "biology")
            BIO++;
            if(STU[i].CUM > K )
            C++;

        } 
        SUM = SUM / 200;
         cout << "\nAverage of the sophomore GPA scores\n" << SUM << endl;
         cout << "\nNumber of Biology majors = " << BIO << endl;
         cout << "\nNumber of CUM scores exceeding " << K << " = " << C << endl;
}
/*
Output

*/