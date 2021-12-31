/*
Page 102
Program
4.9 Using the bubble sort algorithm, Algorithm 4.4, 
find the number C of comparisons and the number D of 
interchanges which alphabetize the n = 6 letters in PEOPLE
*/
#include<iostream>
#include<iomanip>
using namespace std;
/*********************************/
template<typename T>
void Bubble_Sort(T DATA[], int N)
{
    int K, PTR;
    T CHANGE;
     N = N - 1;
    for(K = 0; K < N; K++)
    {
        PTR = 0;
        while(PTR < (N - K))
        {
            if(DATA[PTR] > DATA[PTR+1])
            {
                CHANGE = DATA[PTR];
                DATA[PTR] = DATA[PTR+1];
                DATA[PTR+1] = CHANGE;
                cout << CHANGE << " ";
            }
            
            PTR++;
        }
    }
    return;
}

void Bubble(char DATA[], int N)
{
    char CHANGE;
     N = N - 1;
    for(int K = 0; K < N; K++)
    {
        for(int PTR = 0; PTR < N - K; PTR++)
        {
            if(DATA[PTR]> DATA[PTR+1])
            {
                CHANGE = DATA[PTR];
                DATA[PTR] = DATA[PTR+1];
                DATA[PTR+1] = CHANGE;
            }
        }
    }
    return;
}
//Main from Here
int main()
{   
    char D[7] = {"PEOPLE"};
    for(int i = 0; i < 7; i++)
    {
        cout << D[i];
    }
    cout << "\n";
    Bubble_Sort(D,7);
    for(int i = 0; i < 7; i++)
    {
        cout << D[i] << endl;
    }
}

/*
Output
PEOPLE
P P P P P P P P O O O L L E E 
E
E
L
O
P
P

*/