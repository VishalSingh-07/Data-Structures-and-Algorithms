// Symmetric Matrix
#include <iostream>
using namespace std;
class Symmetric_Matrix
{
      private:
            int n;
            int *A;
      public:
            Symmetric_Matrix()
            {
                  n = 2;
                  A = new int[2];
            }
            Symmetric_Matrix(int n)
            {
                  this->n = n;
                  A = new int[n*(n+1)/2];
            }
            void Set(int i, int j, int x);
            int Get(int i, int j);
            void swap(int *x, int *y);
            void Display();
            ~Symmetric_Matrix()
            {
                  delete[] A;
            }
};

void Symmetric_Matrix :: swap(int *x,int *y)
{
      int temp;
      temp=*x;
      *x=*y;
      *y=temp;
}

// Row Major Mapping
void Symmetric_Matrix :: Set(int i, int j,int x) // Set for Row Major Mapping
{ 
      if(i>=j)
      {
            A[((i * (i - 1)) / 2) + (j - 1)] = x;
      }
}

int Symmetric_Matrix :: Get(int i, int j)// Set for Row Major Mapping
{
      if(i>=j)
      {
            return A[((i * (i - 1)) / 2) + (j - 1)];
      }
      else
      {
           return A[((j * (j - 1)) / 2) + (i - 1)]; 
      }
}

void Symmetric_Matrix :: Display() // Display for row major Mapping
{
      for (int i = 1; i <=n;i++)
      {
            for (int j = 1; j <= n;j++)
            {
                  if(i>=j)
                  {
                        cout << A[((i * (i - 1)) / 2) + (j - 1)] << " ";
                  }
                  else
                  {
                        swap(&i, &j);
                        cout << A[((i * (i - 1)) / 2) + (j - 1)] << " ";
                        swap(&i, &j);
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

      Symmetric_Matrix sm(n);

      cout<<"Enter all elements of Symmetric Matrix: "<<endl;
      for (i = 1; i <= n;i++)
      {
            for (j = 1; j <= n;j++)
            {
                  if(i>=j)
                  {
                        cout << "Enter the value of A[" << i << "][" << j << "]: ";
                        cin >> x;
                        sm.Set(i, j, x);
                  }
            }
      }
      cout << "\nRequired Matrix: " << endl;
      sm.Display();
      cout<<"\nGetting the value of A[2][2]: "<<sm.Get(2, 2);

      return 0;
}
/*
Output--
Enter the value of n: 5
Enter all elements of Symmetric Matrix: 
Enter the value of A[1][1]: 2
Enter the value of A[2][1]: 2
Enter the value of A[2][2]: 3
Enter the value of A[3][1]: 2
Enter the value of A[3][2]: 3
Enter the value of A[3][3]: 4
Enter the value of A[4][1]: 2
Enter the value of A[4][2]: 3
Enter the value of A[4][3]: 4
Enter the value of A[4][4]: 5
Enter the value of A[5][1]: 2
Enter the value of A[5][2]: 3
Enter the value of A[5][3]: 4
Enter the value of A[5][4]: 5
Enter the value of A[5][5]: 6

Required Matrix: 
2 2 2 2 2
2 3 3 3 3
2 3 4 4 4
2 3 4 5 5
2 3 4 5 6

Getting the value of A[2][2]: 3
*/