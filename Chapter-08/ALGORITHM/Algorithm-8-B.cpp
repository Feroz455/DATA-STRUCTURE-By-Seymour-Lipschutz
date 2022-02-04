/*
page 297
Algorithm B : This algorithm executes a depth-first search on a
graph G beginning at a starting node A.

1. Initialize all nodes to the ready state (STATUS = 1).

2. Push the starting node A onto STACK and change its status to
the waiting state (STATUS = 2).

3. Repeat Steps 4 and 5 until STACK is empty.

4.          Pop the top node N of STACK. Process N and change its
status to the processed state (STATUS = 3).

5.          Push onto STACK all the neighbors of N that are still
in the ready state (STATUS = 1), and change their status to the
waiting state (STATUS = 2).

[End of Step 3 loop.]

6. Exit.
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
void Breath_First_print(list<int> A, list<int> X[], int SRC)
{
    int visit[A.size()] = {0}, temp;
    stack<int> Q;
    Q.push(SRC);
    visit[Q.top()] = 1;
    while (!Q.empty())
    {
        temp = Q.top();
        list<int>::iterator ptr = X[temp].begin();
        cout << char(temp + 65) << "   ";
        Q.pop();
        while (ptr != X[temp].end())
        {
            if (visit[*ptr] != 1)
            {
                Q.push(*ptr);
                visit[*ptr] = 1;
            }
            ptr++;
        }
    }
    cout << "\n\n";
}
int main()
{
    list<int> A;
    list<int> X[2000];
    int EDGE, NODE, SRC, DEST;
    char n, m;
    cout << "Enter Nodes and EDGE\n";
    cin >> NODE >> EDGE;
    for (int i = 0; i < EDGE; i += 1)
    {
        cin >> n >> m;
        SRC = n - 65;
        DEST = m - 65;
        X[SRC].push_back(DEST);
    }
    for (int i = 0; i < NODE; i++)
    {
        A.push_back(i);
    }
    cout << "Size " << A.size() << endl;
    cout << "Enter Sorce \n";
    cin >> n;
    Breath_First_print(A, X, n - 65);
}
/*
Enter Nodes and EDGE
9
17 
A F
A C
A B
B G
B C
C F
D C
E D
E C
E J
F D
G C
G E
J D
J K
K E
K G
Size 9
Enter Sorce
J
J   K   G   C   F   E   D  
*/