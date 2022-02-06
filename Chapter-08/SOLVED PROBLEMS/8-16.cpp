/*
page 310
8.16 Suppose G is a finite undirected graph. Then G consists of a finite number 
of disjoint connected components. Describe an algorithm which finds the number 
NCOMP of connected components of G. Furthermore, the algorithm should assign a 
component number COMP(N) to every node N in the same connected component of G 
such that the component numbers range from 1 to NCOMP.

The general idea of the algorithm is to use a breadth-first or depth-first search 
to find all nodes N reachable from a starting node A and to assign them the same 
component number. The algorithm follows.

Algorithm P8.16 : Finds the connected components of an undirected graph G.

1. Initially set COMP(N) := 0 for every node N in G, and initially set L := 0.

2. Find a node A such that COMP(A) = 0. If no such node A exists, then:

Set NCOMP := L, and Exit.

Else:

Set L := L + 1 and set COMP(A) := L.

3. Find all nodes N in G which are reachable from A (using a breadth- first search 
or a depth-first search) and set COMP(N) = L for each such node N.

4. Return to Step 2.
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;
void Breath_First_print(list<int> A, list<int> X[], int SRC, bool visit[])
{

    queue<int> Q;
    Q.push(SRC);
    visit[Q.front()] = true;
    while (!Q.empty())
    {
        list<int>::iterator ptr = X[Q.front()].begin();

        while (ptr != X[Q.front()].end())
        {
            if (visit[*ptr] != true)
            {
                Q.push(*ptr);
                visit[*ptr] = true;
            }
            ptr++;
        }
        cout << char(Q.front() + 65) << "   ";
        Q.pop();
    }
    cout << "\n\n";
}
void count_grap(list<int> A, list<int> X[], int NODE)
{
    bool visit[A.size()] = {0};
    int count = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(visit[i] == false)
        {
            Breath_First_print(A, X, i, visit);
            count++;
        }
    }
    cout<< "NUMBER OF CONNECTED GRAPH = " << count << " \n";

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
        X[DEST].push_back(SRC);
    }
    for (int i = 0; i < NODE; i++)
    {
        A.push_back(i);
    }
    count_grap(A, X, NODE);
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
A   F   C   B   D   E   G   J   K   

H

I

NUMBER OF CONNECTED GRAPH = 3
Enter Nodes and EDGE
6 5
A B
A C
B D
C D
E F
A   B   C   D

E   F

NUMBER OF CONNECTED GRAPH = 2
*/