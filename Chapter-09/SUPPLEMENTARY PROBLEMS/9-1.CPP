/*
page 9-1
9.1   Write a subprogram RANDOM(DATA, N, K) which assigns N random integers between 1 and K to the array DATA.
*/
#include<iostream>
#include<time.h>
using namespace std;
void RANDOM(int ARRAY[], int N, int K)
{
    srand(time(0));
    for(int i = 0; i < K; i++)
    {
        ARRAY[i] = rand()%N;
    }
    return;

}
int main()
{
    int K = 10 , N = 10;
    int ARRAY[K];
    RANDOM(ARRAY, N, K);
    for(int i: ARRAY)
    {
        cout << i << " ";
    }
}
/*
6 6 7 4 5 2 0 7 7 2
*/