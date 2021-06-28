/*
Program Example 1.3
A chain of 28 stores,each store having 4 departments, may list its 
weekly sales(to the nearest doller) as fig 1.2. Such data  can be stored
in the computer using two-dimensional array in which the first subscript
denotes the store and the second subscript the department. If SALED is the
name given to array then 
SALES[1, 1] = 2872, SALES[1, 2] = 805, SALES[1, 3] = 3211, …,
SALES[28, 4] = 982

*/
#include <iostream>
using namespace std;
//main begin
int main()
{
    int count = 5;
    int col = 4;
    int sales[count][col];
    cout << "Enter stores sales" << endl;
    
    for (size_t i = 0; i < count; i++)
    {
       for (size_t j = 0; j < col; j++)
       {
           cin >> sales[count][col];
       }
       cout << "Enter stores sales" << endl;
    }

    cout << "St/De\t";
    for (size_t i = 1; i < count; i++)
    {
        cout << i << "\t";
    }
    cout << "\n";
     
    for (size_t i = 0; i < count; i++)
    {
        cout << i << "\t";
        for (size_t j = 0; j < col; j++)
        {
            cout<<  sales[count][col] << "\t";
        }
        cout << "\n";
    }
    getchar();
    return 0;
}
//main end
///Program end
/*
output
Enter stores sales
2872
805
3211
1560
Enter stores sales
2196
1223
2525
1744
Enter stores sales
3257
1017
3686
1951
Enter stores sales
2618
931
2333
982
Enter stores sales
154 
5698
4563
2456
Enter stores sales
St/De   1       2       3       4
0       2456    2456    2456    2456
1       2456    2456    2456    2456
2       2456    2456    2456    2456
3       2456    2456    2456    2456
4       2456    2456    2456    2456
*/
