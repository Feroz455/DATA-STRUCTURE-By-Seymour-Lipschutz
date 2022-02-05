/*
page 303
8.4 Consider the (directed) graph G in Fig. 8.22. 
(a) Find all the simple paths from X to Z. 
(b) Find all the simple paths from Y to Z. 
(c) Find indeg(Y) and outdeg(Y). 
(d) Are there any sources or sinks?
(a) There are three simple paths from X to Z: (X, Z), (X, W, Z) and (X, Y, W, Z).

(b) There is only one simple path from Y to Z: (Y, W, Z).

(c) Since two edges enter Y (i.e., end at Y), we have indeg(Y) = 2. 
Since only one edge leaves Y (i.e., begins at Y), outdeg(Y) = 1.

(d) X is a source, since no edge enters X (i.e., indeg(X) = 0) 
but some edges leave X (i. e., outdeg(X) > 0). There are no sinks, 
since each node has a nonzero outdegree (i.e., each node is the initial point of some edge).
*/
#include <iostream>
#include <list>
using namespace std;
class GRAPH
{
    int NODE;
    list<int> *ADJ_list;
    void Print_All_Path_Util(int SRC, int DEST, bool visited[], int PATH[], int &path_index);

public:
    GRAPH(int NODE)
    {
        this->NODE = NODE;
        ADJ_list = new list<int>[NODE];
    }
    void Add_Edge(int SRC, int DEST);
    void print_All_Path(int SRC, int DEST);
};
void GRAPH::Add_Edge(int SRC, int DEST)
{
    ADJ_list[SRC].push_back(DEST);
}
void GRAPH::print_All_Path(int SRC, int DEST)
{

    bool visited[NODE] = {false};
    int PATH[NODE];
    int path_index = 0;
    Print_All_Path_Util(SRC, DEST, visited, PATH, path_index);
}
void GRAPH::Print_All_Path_Util(int SRC, int DEST, bool visited[], int PATH[], int &path_index)
{
    visited[SRC] = true;
    PATH[path_index] = SRC;
    path_index++;
    if (SRC == DEST)
    {
        for (int i = 0; i < path_index; i++)
            cout << char(PATH[i] + 65) << " ";
        cout << endl;
    }
    else
    {
        list<int>::iterator ptr = ADJ_list[SRC].begin();
        while (ptr != ADJ_list[SRC].end())
        {
            if (visited[*ptr] == false)
            {
                Print_All_Path_Util(*ptr, DEST, visited, PATH, path_index);
            }
            ptr++;
        }
    }
    path_index--;
    visited[SRC] = false;
}
int main()
{
    int NODE, EDGE, SRC, DEST;
    char n, m;
    cout << "Enter Nodes and EDGE\n";
    cin >> NODE >> EDGE;
    GRAPH GRP(NODE);
    cout << "Enter EDGE\n";
    for (int i = 0; i < EDGE; i++)
    {
        cin >> n >> m;
        SRC = n - 65;
        DEST = m - 65;
        GRP.Add_Edge(SRC, DEST);
    }
    cout << "ALL PATH \nFROM -> ";
    cin >> n;
    cout << "TO->  ";
    cin >> m;
    SRC = n - 65;
    DEST = m - 65;
    GRP.print_All_Path(SRC, DEST);
    cout << "ALL PATH \nFROM -> ";
    cin >> n;
    cout << "TO->  ";
    cin >> m;
    SRC = n - 65;
    DEST = m - 65;
    GRP.print_All_Path(SRC, DEST);
}
/*
Enter Nodes and EDGE
6 8
A B
A D
B C
B E
C F
C E
D E
E F
A F

Enter Nodes and EDGE
4 7
Enter EDGE
A B
A C
A D
B D
C B
D C
C D
ALL PATH
FROM -> A
TO->  C
A B D C
A C
A D C
ALL PATH
FROM -> B
TO->  C
B D C
*/
