/*
page 213
6.2  Write a program which gives the solution to the Towers 
of Hanoi problem for n disks. Test the program using (a) n = 3 and (b) n = 4
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

    cout << "\n\n" << endl;

    TOWER(4, "A", "B", "C");
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



Move top disk  form pag A to pag B
Move top disk  form pag A to pag C
Move top disk  form pag B to pag C
Move top disk  form pag A to pag B
Move top disk  form pag C to pag A
Move top disk  form pag C to pag B
Move top disk  form pag A to pag B
Move top disk  form pag A to pag C
Move top disk  form pag B to pag C
Move top disk  form pag B to pag A
Move top disk  form pag C to pag A
Move top disk  form pag B to pag C
Move top disk  form pag A to pag B
Move top disk  form pag A to pag C
Move top disk  form pag B to pag C
*/