/*
page 94
Algorithm A : This algorithm executes a breadth-first search on a
graph G beginning at a starting node A.

1. Initialize all nodes to the ready state (STATUS = 1).

2. Put the starting node A in QUEUE and change its status to the
waiting state (STATUS = 2).

3. Repeat Steps 4 and 5 until QUEUE is empty:

4.     Remove the front node N of QUEUE. Process N and change the
status of N to the processed state (STATUS = 3).

5.    Add to the rear of QUEUE all the neighbors of N that are in
the steady state (STATUS = 1), and change their status to the waiting state (STATUS = 2).

[End of Step 3 loop.]

6. Exit.
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;
void Breath_First_print(list<int> A, list<int> X[], int SRC)
{
    int visit[A.size()] = {0};
    queue<int> Q;
    Q.push(SRC);
    visit[Q.front()] = 1;
    while (!Q.empty())
    {
        list<int>::iterator ptr = X[Q.front()].begin();

        while (ptr != X[Q.front()].end())
        {
            if (visit[*ptr] != 1)
            {
                Q.push(*ptr);
                visit[*ptr] = 1;
            }
            ptr++;
        }
        cout << char(Q.front() + 65) << "   ";
        Q.pop();
    }
    cout << "\n\n";
}
void Breath_First_Search(list<int> A, list<int> X[], int SRC, int DEST)
{
    int visit[A.size()] = {0}, NEW , PREV;
    queue<int> Q, ORIG;
    Q.push(SRC);
    visit[Q.front()] = 1;
    NEW = PREV = -1;
    while (!Q.empty())
    {
        list<int>::iterator ptr = X[Q.front()].begin();

        while (ptr != X[Q.front()].end())
        {
            if (visit[*ptr] != 1)
            {
                Q.push(*ptr);
                visit[*ptr] = 1;
                ORIG.push(Q.front());
            }
            ptr++;
        }
        if (Q.front() == DEST)
        {
            while (!ORIG.empty())
            {
                NEW = ORIG.front();
                if(PREV != NEW)
                {
                    cout << char(NEW+65) << " ";
                }
                PREV = NEW;
                ORIG.pop();
            }
            return;
        }
        Q.pop();
    }
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
    cout << "Enter Sorce and destination\n";
    cin >> n >> m;
    Breath_First_print(A, X, n - 65);
    Breath_First_Search(A, X, n - 65, m - 65);
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
Enter Sorce and destination
A J
A -> F -> C -> B -> D -> G -> E -> J
*/
