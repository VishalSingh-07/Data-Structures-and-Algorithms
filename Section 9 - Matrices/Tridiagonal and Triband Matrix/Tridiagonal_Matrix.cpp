// Symmetric Matrix
#include <iostream>
using namespace std;
class Tridiagonal_Matrix
{
      private:
            int n;
            int *A;
      public:
            Tridiagonal_Matrix()
            {
                  n = 2;
                  A = new int[3*n-2];
            }
            Tridiagonal_Matrix(int n)
            {
                  this->n = n;
                  A = new int[3*n-2];
            }
            void Set(int i, int j, int x);
            int Get(int i, int j);
            void Display();
            ~Tridiagonal_Matrix()
            {
                  delete[] A;
            }
};

void Tridiagonal_Matrix :: Set(int i, int j,int x) 
{ 
      if(i-j==1) // Lower Diagonal
      {
                  A[i - 2] = x;
      }
      else if(i-j==0) // Main Diagonal
      {
                  A[n - 1 + i - 1] = x;
      }
      else if(i-j==-1) // Upper Diagonal
      {
                  A[2 * n - 1 + i - 1] = x;
      }
      
}

int Tridiagonal_Matrix :: Get(int i, int j)
{
      if(i-j==1) // Lower Diagonal
      {
                  return A[i - 2];
      }
      else if(i-j==0) // Main Diagonal
      {
                  return A[n - 1 + i - 1];
      }
      else if(i-j==-1) // Upper Diagonal
      {
                  return A[2 * n - 1 + i - 1];
      }
      else
      {
                  return 0;
      }
      
}

void Tridiagonal_Matrix :: Display() 
{
      for (int i = 1; i <=n;i++)
      {
            for (int j = 1; j <= n;j++)
            {
                  if(i-j==1) // Lower Diagonal
                  {
                        cout << A[i - 2] << " ";
                  }
                  else if(i-j==0) // Main Diagonal
                  {
                        cout << A[n - 1 + i - 1] << " ";
                  }
                  else if(i-j==-1) // Upper Diagonal
                  {
                        cout << A[2 * n - 1 + i - 1] << " ";
                  }
                  else
                  {
                        cout << "0 ";
                  }
                 
            }
            cout << endl;
      }
}

int main()
{

      int i, j, x,n;
      cout << "Enter the value of n: ";
      cin >> n;

      Tridiagonal_Matrix td(n);

      cout<<"Enter all elements of Symmetric Matrix: "<<endl;
      for (i = 1; i <= n;i++)
      {
            for (j = 1; j <= n;j++)
            {
                  if(i-j==1) // Lower Diagonal
                  {
                        cout << "Enter the value of A[" << i << "][" << j << "]: ";
                        cin >> x;
                        td.Set(i, j, x);
                  }
                  else if(i-j==0) // Main Diagonal
                  {
                        cout << "Enter the value of A[" << i << "][" << j << "]: ";
                        cin >> x;
                        td.Set(i, j, x);
                  }
                  else if(i-j==-1) // Upper Diagonal
                  {
                        cout << "Enter the value of A[" << i << "][" << j << "]: ";
                        cin >> x;
                        td.Set(i, j, x);
                  }
            }
      }
      cout << "\nRequired Matrix: " << endl;
      td.Display();
      cout<<"\nGetting the value of A[2][2]: "<<td.Get(2, 2);

      return 0;
}
/*
Output--
Enter the value of n: 5
Enter all elements of Symmetric Matrix: 
Enter the value of A[1][1]: 1
Enter the value of A[1][2]: 2
Enter the value of A[2][1]: 3
Enter the value of A[2][2]: 4
Enter the value of A[2][3]: 5
Enter the value of A[3][2]: 6
Enter the value of A[3][3]: 7
Enter the value of A[3][4]: 8
Enter the value of A[4][3]: 9
Enter the value of A[4][4]: 1
Enter the value of A[4][5]: 2
Enter the value of A[5][4]: 3
Enter the value of A[5][5]: 4

Required Matrix: 
1 2 0 0 0 
3 4 5 0 0 
0 6 7 8 0
0 0 9 1 2
0 0 0 3 4

Getting the value of A[2][2]: 4
*/