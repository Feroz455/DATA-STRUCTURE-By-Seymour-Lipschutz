/*
page 71
program
Algortithm 4.1

*/
#include<iostream>
using namespace std;
void TRAVESING(int LA[], int UB, int LB)
{
    cout << "TRAVESING\n";
    for(int i = LB; i < UB; i++)
    {
        cout << LA[i] << endl;
    }
    cout << "\n\n\n";
    return;
}
void RAVESING(int LA[], int UB, int LB)
{
    cout << "RAVESING\n";
    for(int i = UB; i >= LB; i--)
    {
        cout << LA[i] << endl;
    }
    cout << "\n\n\n";
    return;
}
int main()
{
    int LA[100];
    cout << "Enter 10 integer number\n";
    for(int i = 0; i <= 10; i++)
    {
        cin >> LA[i];
    }
    cout << "\n\n\n";
    TRAVESING(LA, 10, 0);
    RAVESING(LA, 10, 0);
    
    return 0;
}
/*
output
Enter 10 integer number
201
202
203
204
205
206
207
208
209
210
211



TRAVESING
201
202
203
204
205
206
207
208
209
210



RAVESING
211
210
209
208
207
206
205
204
203
202
201
*/