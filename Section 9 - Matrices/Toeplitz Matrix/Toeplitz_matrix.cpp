// Program for Toeplitz Matrix
#include <iostream>
using namespace std;

struct Matrix
{
      int *A;
      int n;
};

void Set(struct Matrix *m, int i, int j,int x)
{
      if(i==j)
      {
            m->A[i - j] = x;
      }
      else if(j>i)
      {
            m->A[j - i] = x;
      }
      else if(i>j)
      {
            m->A[m->n + i - j] = x;
      }

}

int Get(struct Matrix *m, int i, int j)
{
      if(i==j)
      {
            return m->A[i - j];
      }
      else if(j>i)
      {
            return m->A[j - i];
      }
      else if(i>j)
      {
            return m->A[m->n + i - j];
      }
}

void Display(struct Matrix *m)
{
      for (int i = 1; i <= m->n;i++)
      {
            for (int j = 1; j <= m->n;j++)
            {
                  if(i==j)
                  {
                        cout << m->A[i-j]<<" ";
                  }
                  else if(j>i)
                  {
                        cout <<m->A[j - i]<<" ";
                  }
                  else if(i>j)
                  {
                        cout<< m->A[m->n + i - j]<<" ";
                  }
                 

            }
             cout <<"\n";
            
      }
}

int main()
{
      struct Matrix m;
      int i,j,x;
      cout << "Enter the dimension of square matrix: ";
      cin >> m.n;

      m.A = (int *)malloc((m.n+ m.n -1) * sizeof(int));// creating an array in heap

      cout << "Enter the value for  Matrix: " << endl;
      for (i = 1; i <=m.n;i++)
      {
            for (j = 1; j <= m.n;j++)
            {
                  if(i==1 || j==1)
                  {
                        cout << "Enter the value of A[" << i << "]"
                             << "[" << j << "]: ";
                        cin>>x;
                        Set(&m, i, j, x);
                  }
                  
            }
      }

      // Set(&m, 1, 1, 5);
      // Set(&m, 2, 2, 8);
      // Set(&m, 3, 3, 9);
      // Set(&m, 4, 4, 12);

      Display(&m);

      cout << "Getting the value of m[2][2]: " << Get(&m, 2, 2);

      return 0;
}

/*
Output--
Enter the dimension of square matrix: 5
Enter the value for  Matrix: 
Enter the value of A[1][1]: 1
Enter the value of A[1][2]: 2
Enter the value of A[1][3]: 3
Enter the value of A[1][4]: 4
Enter the value of A[1][5]: 5
Enter the value of A[2][1]: 6
Enter the value of A[3][1]: 7
Enter the value of A[4][1]: 8
Enter the value of A[5][1]: 9
1 2 3 4 5 
6 1 2 3 4 
7 6 1 2 3 
8 7 6 1 2
9 8 7 6 1
Getting the value of m[2][2]: 1
*/