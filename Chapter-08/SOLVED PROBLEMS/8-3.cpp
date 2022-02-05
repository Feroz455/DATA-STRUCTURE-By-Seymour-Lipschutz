/*
page 303
8.3 Consider the connected graph G in Fig. 8.21. 
(a) Find all simple paths from node A to node F. 
(b) Find the distance between A and F. 
(c) Find the diameter of G. 
(The diameter of G is the maximum distance existing between 
any two of its nodes.)
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
        GRP.Add_Edge(DEST, SRC);
    }
    cout << "ALL PATH FROM -> \n";
    cin >> n;
    cout << "TO->  \n";
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





***********************************
Enter Nodes and EDGE
6 8
Enter EDGE
A B
A D
B C
B E
C F
C E
D E
E F
ALL PATH FROM ->
A F
TO->
A B C F
A B C E F
A B E C F
A B E F
A D E B C F
A D E C F
A D E F
*/
