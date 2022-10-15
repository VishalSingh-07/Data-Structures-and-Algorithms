#include <iostream>
using namespace std;
int main()
{
      int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};

      int *B[3];
      // B[0] = (int *)malloc(4 * sizeof(int)); for C language
      B[0] = new int[4];
      B[1] = new int[4];
      B[2] = new int[4];

      int **C;
      C = (int **)malloc(3 * sizeof(int *));
      C[0] = new int[3];
      C[1] = new int[3];
      C[2] = new int[3];

      int i, j;
      cout << "Array A"<<endl;
      for (i = 0; i < 3; i++) //  for rows
      {
            for (j = 0; j < 4;j++) //  for columns
            {
                  cout << A[i][j] <<" ";
                  
            }
            cout << endl;
      }
      cout << "\nArray B:" << endl;
      for (i = 0; i < 3;i++) //  for rows
      {
            for (j = 0; j < 4;j++) //  for columns
            {
                  cout << B[i][j] <<" ";
                  
            }
            cout << endl;
      }
      cout << "\nArray C:" << endl;
      for (i = 0; i < 3;i++) //  for rows
      {
            for (j = 0; j < 4;j++) //  for columns
            {
                  cout << C[i][j] <<" ";
                  
            }
            cout << endl;
      }

            return 0;
}