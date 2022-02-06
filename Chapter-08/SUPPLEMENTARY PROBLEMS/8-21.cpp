/*
PAGE 312

8.1 Consider the undirected graph G in Fig. 8.33. Find 
(a) all simple paths from node A to node H, 
(b) the diameter of G and 
(c) the degree of each node.
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
    ADJ_list[DEST].push_back(SRC);
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
}
/*
Enter Nodes and EDGE
8
10
Enter EDGE
A B
A E
B E
B F
B G
F G
C G
C H
C D
D H
ALL PATH 
FROM -> A 
TO->  H
A B F G C H 
A B F G C D H 
A B G C H
A B G C D H
A E B F G C H
A E B F G C D H
A E B G C H
A E B G C D H 
*/