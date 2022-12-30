// Square Band Matrix
#include <iostream>
using namespace std;
class Square_band_Matrix
{
      private:
            int n;
            int radius;
            int *A;
      public:
            Square_band_Matrix()
            {
                  n = 2;
                  radius = 2;
                  int t = n + 2*radius* n - radius*(radius + 1);
                  A = new int[t];
            }
            Square_band_Matrix(int n,int radius)
            {
                  this->n = n;
                  this->radius = radius;
                  int t = n + 2*radius* n - radius*(radius + 1);
                  A = new int[t];
            }
            void Set(int i, int j, int x);
            int Get(int i, int j);
            void Display();
            ~Square_band_Matrix()
            {
                  delete[] A;
            }
};

void Square_band_Matrix :: Set(int i, int j,int x) 
{
      int ldiff, udiff;
      ldiff = i - j;
      udiff = j - i;

      if(i==j)
      {
                  A[i - 1] = x;
      }
      else if(ldiff>=1 && ldiff<=radius)
      {
                  A[n + (ldiff - 1) * n - (ldiff - 1) * (ldiff) / 2 + i - ldiff - 1] = x;
      }
      else if (udiff >= 1 && udiff <= radius)
      {
                  A[n + radius * n - (radius - 1) * radius / 2 + (udiff - 1) * n - (udiff - 1) * (udiff) / 2 + j - udiff - 1] = x;
      }
}

int Square_band_Matrix :: Get(int i, int j)
{
      int ldiff, udiff;
      ldiff = i - j;
      udiff = j - i;
      if(i==j)
      {
                  return A[i - 1];
      }
      else if(ldiff>=1 && ldiff<=radius)
      {
                  return A[n + (ldiff - 1) * n - (ldiff - 1) * (ldiff) / 2 + i - ldiff - 1];
      }
      else if (udiff >= 1 && udiff <= radius)
      {
                  return A[n + radius * n - (radius - 1) * radius / 2 + (udiff - 1) * n - (udiff - 1) * (udiff) / 2 + j - udiff - 1];
      }
      else
      {
                  return 0;
      }
      
}

void Square_band_Matrix :: Display() 
{
      for (int i = 1; i <=n;i++)
      {
            for (int j = 1; j <= n;j++)
            {
                  int ldiff, udiff;
                  ldiff = i - j;
                  udiff = j - i;
                  if(i==j)
                  {
                        cout << A[i - 1] << " ";
                  }
                  else if(ldiff>=1 && ldiff<=radius)
                  {
                        cout << A[n + (ldiff - 1) * n - (ldiff - 1) * (ldiff) / 2 + i - ldiff - 1] << " ";
                  }
                  else if (udiff >= 1 && udiff <= radius)
                  {
                        cout<<A[n + radius * n - (radius - 1) * radius / 2 + (udiff - 1) * n - (udiff - 1) * (udiff) / 2 + j - udiff - 1]<<" ";
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

      int i, j, x,n,radius;
      cout << "Enter the value of n: ";
      cin >> n;

      cout << "Enter the Band Radius of Square Band Matrix: ";
      cin >> radius;

      Square_band_Matrix sb(n,radius);

      // if(radius>((n-1))
      // {
      //       cout << "Invalid Band Radius Entered, TRY AGAIN!" << endl;
      //       return 0;
      // }

      // int t = n + 2*radius* n - radius*(radius + 1);
      cout<<"Enter all elements of Square band Matrix: "<<endl;
      for (i = 1; i <= n;i++)
      {
            for (j = 1; j <= n;j++)
            {
                 if((i-j)<=radius && (j-i)<=radius)
                 {
                        cout << "Enter the value of A[" << i << "][" << j << "]: ";
                        cin >> x;
                        sb.Set(i, j, x);
                 }
            }
      }
      cout << "\nRequired Matrix: " << endl;
      sb.Display();
      cout<<"\nGetting the value of A[2][2]: "<<sb.Get(2, 2);

      return 0;
}
/*
Output--
Enter the value of n: 5
Enter the Band Radius of Square Band Matrix: 2
Enter all elements of Square band Matrix: 
Enter the value of A[1][1]: 1
Enter the value of A[1][2]: 2
Enter the value of A[1][3]: 3
Enter the value of A[2][1]: 2
Enter the value of A[2][2]: 2
Enter the value of A[2][3]: 3
Enter the value of A[2][4]: 4
Enter the value of A[3][1]: 3
Enter the value of A[3][2]: 3
Enter the value of A[3][3]: 3
Enter the value of A[3][4]: 4
Enter the value of A[3][5]: 5
Enter the value of A[4][2]: 4
Enter the value of A[4][3]: 4
Enter the value of A[4][4]: 4
Enter the value of A[4][5]: 5
Enter the value of A[5][3]: 5
Enter the value of A[5][4]: 5
Enter the value of A[5][5]: 5

Required Matrix:
1 2 3 0 0
2 2 3 4 0
3 3 3 4 -2030573809
0 4 4 4 5
0 0 5 5 5

Getting the value of A[2][2]: 2

*/

