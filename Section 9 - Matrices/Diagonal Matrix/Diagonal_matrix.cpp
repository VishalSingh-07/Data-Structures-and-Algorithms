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
            m->A[i - 1] = x;
      }

}

int Get(struct Matrix *m, int i, int j)
{
      if(i==j)
      {
            return m->A[i - 1];
      }
      else
      {
            return 0;
      }
}

void Display(struct Matrix *m)
{
      for (int i = 0; i < m->n;i++)
      {
            for (int j = 0; j <m->n;j++)
            {
                  if(i==j)
                  {
                        cout << m->A[i-1]<<" ";
                  }
                  else
                  {
                        cout <<"0"<<" ";
                  }
                 

            }
             cout <<"\n";
            
      }
}

int main()
{
      struct Matrix m;
      int i,j,x;
      cout << "Enter the value of n: ";
      cin >> m.n;

      m.A = (int *)malloc(m.n * sizeof(int));// creating an array in heap

      cout << "Enter the value for Diagonal Matrix: " << endl;
      for (i = 0; i < m.n;i++)
      {
            for (j = 0; j < m.n;j++)
            {
                  if(i==j)
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