/*
Page  149
5.2 The following list of names is assigned (in order) to a linear array INFO:
Mary, June, Barbara, Paula, Diana, Audrey, Karen, Nancy, Ruth, Eileen, Sandra, Helen
That is, INFO[1] = Mary, INFO[2] = June,…, INFO[12] = Helen. Assign values to an array 
LINK and a variable START so that INFO, LINK and START form an alphabetical listing of 
the names
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string INFO[] = {"Mary", "June", "Barbara", "Paula", "Diana", "Audrey", "Karen", "Nancy", "Ruth", "Eileen", "Sandra", "Helen"};
   
    int START = 5;
    int LINK[12] = {7, 6, 4, 8, 9, 2, 0, 3, 10, 11, -1, 1};
    while (START != -1)
    {
        cout << INFO[START] << endl;
        START = LINK[START];
    }
    

}
/*
Mary   
June   
Barbara, 
Paula  
Diana  
Audrey 
Karen  
Nancy  
Ruth   
Eileen 
Sandra 
Helen

8
7    
5    
9    
10   
3    
1    
4    
11   
12   
0    
2

OUTPUT
Audrey 
Barbara
Diana  
Eileen 
Helen  
June   
Karen  
Mary   
Nancy  
Paula  
Ruth   
Sandra
*/