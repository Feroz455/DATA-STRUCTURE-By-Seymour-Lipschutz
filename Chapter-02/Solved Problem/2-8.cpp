/*
Page 36
Program
 (a) Write a procedure FIND(DATA, N, LOC1, LOC2) which finds the location LOC1 
 of the largest element and the location LOC2 of the second largest element in 
 an array DATA with n > 1 elements.

(b) Why not let FIND also find the values of the largest and second largest elements? 

*/
#include<iostream>
using namespace std;


template<typename T>
void FIND(T DATA[], int N, int &LOC1, int &LOC2)
{
    T FIRST  = DATA[1];
    T SECOND = DATA[2];
    if (FIRST < SECOND)
    {
        swap<T>(FIRST, SECOND);
        LOC1 = 2; 
        LOC2 = 1;
    }
    for (int i = 0; i < N; i++)
    {
        if (FIRST < DATA[i])
        {
            SECOND = FIRST;
            FIRST = DATA[i];
            LOC2 = LOC1;
            LOC1 = i;
        }
        else 
        if(SECOND < DATA[i])
        {
            SECOND = DATA[i];
            LOC2 = i;
        }

    }
}
//main begin
int main()
{
    int LOC1, LOC2;
    int DATA[] = {2289 ,5827 ,10253 ,26079 ,12679 ,28840 ,30895 ,19785 ,4761 ,7614};
    FIND<int> (DATA,(sizeof(DATA)/sizeof(int)),LOC1,LOC2);
    cout << "LOC1 = "  << LOC1 << "  LOC2 = " << LOC2 << endl;
    cout << "Leargest number is  " << DATA[LOC1] << "\nSecond leargest is " << DATA[LOC2] << endl;

    getchar();
    return 0;
}
//main end
///Program end

/*
output
LOC1 = 6  LOC2 = 5       
Leargest number is  30895
Second leargest is 28840 
*/