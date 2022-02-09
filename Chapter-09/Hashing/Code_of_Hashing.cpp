#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000
bool HASH[MAX + 1][2];
bool search(int x)
{
    if (x >= 0)
    {
        if (HASH[x][0] == true)
        {
            return true;
        }
    }
    else
    {
        x = abs(x);
        if (x >= 0)
        {
            if (HASH[x][1] == true)
            {
                return true;
            }
        }
    }

    return false;
}
void insert(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            HASH[a[i]][0] = true;
        }
        else
        {
            HASH[abs(a[i])][1] = true;
        }
    }
}
int main()
{
    int arr[] = {-1, 9, 2, -5, 3, 1};
    int n = sizeof(arr) / sizeof(int);
    insert(arr, n);
    if (search(3))
    {
        cout << "Found ";
    }
    else
        cout << "Result not found\n";
    return 0;
}