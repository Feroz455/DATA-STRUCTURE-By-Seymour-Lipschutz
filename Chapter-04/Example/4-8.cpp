#include<iostream>
using namespace std;
int Global_J = 6;
/**************Print Array****************/
template<typename T>
void PRINT(T A[], int j)
{
    cout << "\n**************************\n";
    for(int i = 1; i <= j; i++)
    {
        cout << A[i-1] << " ";
        if(i % 4 == 0)
        cout << "\n";
    }
}
/***********************************/
template<typename T>
void INSERT(T LA[],int N, int K, T ITEM)
{
    int J = N;
    while(J >= K)
    {
        LA[J+1] = LA[J];
        J--;
    }
    LA[K] = ITEM;
    Global_J += 1;
}

template<typename T>
void INSERT(T LA[],T ITEM)
{
    INSERT<T>(LA,Global_J,Global_J,ITEM);
}
/***********************************/
template<typename T>
void Bubble(T DATA[], int N)
{
    T CHANGE;
    for(int K = 0; K < N; K++)
    {
        for(int PTR = 0; PTR < N - K; PTR++)
        {
            if(DATA[PTR]> DATA[PTR+1])
            {
                CHANGE = DATA[PTR];
                DATA[PTR] = DATA[PTR+1];
                DATA[PTR+1] = CHANGE;
            }
        }
    }
    return;
}
template<typename T>
int LINEAR(T DATA[], int N, T ITEM)
{
    int K = 0;
    int LOC = -1;
    while(LOC == -1 && K <= N)
    {
        if(ITEM == DATA[K])
            LOC = K ;
        K++;
    }
    return LOC+1;
}
template<typename T>
void INPUT(T DATA[], int j)
{

    for(int i = 0; i < j; i++)
    {
        cin >> DATA[i];
        if(DATA[i] == "$$$")
        {
            Global_J = i;
            return ;
        }
        
    }
}
void CHECK(int ck)
{
    if(ck != 0)
    {
        cout << "\nItem Found at " << ck  << endl;
    }
    else 
    cout << "\nItem not found\n";
}

int main()
{
    
    string NAME[100];
    INPUT<string>(NAME,Global_J);
    PRINT<string>(NAME,Global_J);
    
    CHECK(LINEAR<string>(NAME,Global_J, "Paual"));

    INSERT<string>(NAME, Global_J, Global_J, "FERSOUS");
    PRINT<string>(NAME,Global_J);
    CHECK(LINEAR<string>(NAME,Global_J, "Susan"));
    
    PRINT<string>(NAME,Global_J);
    return 0;
}
/*
Mary 
jane 
Diane
Susan
Karen
Edith

**************************
Mary jane Diane Susan
Karen Edith
Item not found

**************************
Mary jane Diane Susan
Karen Edith FERSOUS
Item Found at 4

**************************
Mary jane Diane Susan 
Karen Edith FERSOUS
*/