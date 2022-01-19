/*
page 212
6.19 Show that the recursive solution to the Towers of Hanoi problem in 
Sec. 6.8 requires f (n) = 2n – 1 moves for n disks. Show that no other 
solution uses fewer than f (n) moves
*/
#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;
void TOWER(int N, string  BEG, string AUX, string END)
{
    if(N > 0)
    {
        TOWER(N-1, BEG, END, AUX);
        cout << "Move top disk  form pag " << BEG  << " to pag " << END << endl;
        TOWER(N-1, AUX, BEG, END); 
    }
}
int main()
{
    int N;
    cout << "Enter disk number\n";
    cin >> N;
    TOWER(N, "A", "B", "C");
    cout << "number of move need\n" << pow(2, N) - 1;
    return 0;
}
/*
Enter disk number
5
Move top disk  form pag A to pag C
Move top disk  form pag A to pag B
Move top disk  form pag C to pag B
Move top disk  form pag A to pag C
Move top disk  form pag B to pag A
Move top disk  form pag B to pag C
Move top disk  form pag A to pag C
Move top disk  form pag A to pag B
Move top disk  form pag C to pag B
Move top disk  form pag C to pag A
Move top disk  form pag B to pag A
Move top disk  form pag C to pag B
Move top disk  form pag A to pag C
Move top disk  form pag A to pag B
Move top disk  form pag C to pag B
Move top disk  form pag A to pag C
Move top disk  form pag B to pag A
Move top disk  form pag B to pag C
Move top disk  form pag A to pag C
Move top disk  form pag B to pag A
Move top disk  form pag C to pag B
Move top disk  form pag C to pag A
Move top disk  form pag B to pag A
Move top disk  form pag B to pag C
Move top disk  form pag A to pag C
Move top disk  form pag A to pag B
Move top disk  form pag C to pag B
Move top disk  form pag A to pag C
Move top disk  form pag B to pag A
Move top disk  form pag B to pag C
Move top disk  form pag A to pag C
number of move need
31
*/