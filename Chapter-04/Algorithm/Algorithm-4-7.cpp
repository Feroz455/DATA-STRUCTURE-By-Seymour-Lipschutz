#include<iostream>
#include<iomanip>
using namespace std;
int const SIZE = 3;
void OUTPUT(int DATA[][3], int x, int y)
{
    cout << "\n*************************\n";
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
           cout <<  setw(5) <<  *(*(DATA+i)+j) << " ";  
        }
        cout << endl;
    }
    return;
}
void matrix_Addition(int A[][3], int B[][3], int C[][3], int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
           C[i][j] = A[i][j] + B[i][j];
        }
    }
    return;

}
void matrix_Multip(int A[][3], int M, int C[][3], int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
           C[i][j] = A[i][j] * M;
        }
    }
    return;
}


void MATMUL(int A[][SIZE], int B[][SIZE], int C[][SIZE], int M, int P, int N)
{
    for(int I = 0; I < M; I++)
    {
        for(int J = 0; J < N; J++)
        {
            C[I][J] = 0;
            for(int K = 0; K < P; K++)
            {
                C[I][J] = C[I][J] + A[I][K] * B[K][I];
            }
        }
    }
    return;
}
int main()
{

   int x = 3 , y = 2, z = 3;
   int A[x][y] = {{1,3},{2,4},{8,9}};
   int B[y][z] ={{2,0,-4},{3,2,6}};
   int C[x][z];
   for(int i = 0; i < x; i++)
   {
       for(int j = 0; j < z; j++)
       {
          C[i][j] = 0;
           for(int k = 0; k < y; k++)
           {
               C[i][j]  += A[i][k] * B[k][j];
               //cout << A[i][k]  << " " <<  B[k][j] << " " << endl;
           }
           cout<<  C[i][j]  << " ";
       }
       cout << "\n";
   }

}

/*
int main()
{

   int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
   int B[3][3] = {{0,1,0},{1,0,1},{0,1,0}};
   int C[3][3];
   int x;
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
           C[i][j] = 0;
         for(int k = 0; k < 3; k++)
         {
             C[i][j] +=  A[i][k] * B[j][k];
            //cout << "A[" << i << "]" << "[" << k << "]" << "*" << "B[" << j << "]" << "[" << k << "]" << " = " <<  A[i][k] << " * " <<  B[j][k]  << " = "<< A[i][k] * B[j][k] << endl;
         }
         cout <<  C[i][j] << " " ;
         //x = 0;
      }
      cout << "\n";
   }
}



for(int i = 0; i < x; i++)
   {
       for(int j = 0; j < y; j++)
       {
          C[i][j] = 0;
           for(int k = 0; k < x; k++)
           {
               C[i][j]  += A[i][k] * B[k][j];
              // cout << A[i][k]  << " " <<  B[k][j] << " " << endl;
           }
           cout<<  C[i][j]  << " ";
       }
       cout << "\n";
   }
*/
