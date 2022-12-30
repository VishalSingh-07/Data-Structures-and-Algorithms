#include <iostream>
using namespace std;
class Diagonal
{
      private:
           int n;
           int *A;
      public:
            Diagonal()
            {
                  n = 2;
                  A = new int[2];
            }
            Diagonal(int n)
            {
                  this->n = n;
                  A = new int[n];
            }
            void Set(int i, int j, int x);
            int get(int i, int j);
            void Display();
            ~Diagonal()
            {
                  delete[] A;
            }
};
void Diagonal :: Set(int i, int j, int x)
{
      if(i==j)
      {
                  A[i - 1] = x;
      }
}
int Diagonal :: get(int i, int j)
{
      if(i==j)
      {
                  return A[i - 1];
      }
      else
      {
                  return 0;
      }
}

void Diagonal ::  Display()
{
      for (int i = 0; i < n;i++)
      {
                  for (int j = 0; j < n;j++)
                  {
                        if(i==j)
                        {
                              cout << A[i-1] << " ";
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
      int n,x;
      cout << "Enter the value of n: ";
      cin >> n;
      Diagonal d(n);

      for (int i = 0; i < n;i++)
      {
                  for (int j = 0; j < n;j++)
                  {
                        if(i==j)
                        {
                              cout << "Enter the value to be set at [" << i << "][" << j << "]: ";
                              cin >> x;
                              d.Set(i, j, x);
                        }
                  }
      }
      // d.Set(1, 1, 5);
      // d.Set(2, 2, 8);
      // d.Set(3, 3, 9);
      // d.Set(4, 4, 12);

      d.Display();
      cout << "Getting the value of A[2][2]: " << d.get(2, 2);
      return 0;
}