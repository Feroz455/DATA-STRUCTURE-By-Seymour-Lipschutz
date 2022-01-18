/*
page 183
Procedure 6.11: TOWER(N, BEG, AUX, END)

This procedure gives a recursive solution to the Towers of Hanoi problem for N disks.

1. If N = 1, then:

(a) Write: BEG → END.

(b) Return.

[End of If structure.]
*/
#include<iomanip>
#include<iostream>
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
    TOWER(3, "A", "B", "C");
    return 0;
}
/*
Move top disk  form pag A to pag C
Move top disk  form pag A to pag B
Move top disk  form pag C to pag B
Move top disk  form pag A to pag C
Move top disk  form pag B to pag A
Move top disk  form pag B to pag C
Move top disk  form pag A to pag C
*/