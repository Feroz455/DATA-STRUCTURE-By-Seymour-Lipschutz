/*
page 317
8.10 Write a program which finds the number of connected components of an 
unordered graph G and also assigns a component number to each of its nodes. 
Assume G is input by its set V of nodes and its set E of (undirected) edges. 
Test the program using the nodes A, B, C, D, X, Y, Z, S and T and the edges:

(a) [A, X], [B, T], [Y, C], [S, Z], [D, T], [A, S], [Z, A], [D, B] and [X, S]

(b) [Z, C], [D, B], [A, X], [S, C], [D, T], [X, S], [Y, B], [T, B] and [S, Z]
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