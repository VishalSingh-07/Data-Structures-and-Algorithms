#include <iostream>
using namespace std;
class Lower_triangular
{
      private:
            int n;
            int *A;
      public:
            Lower_triangular()
            {
                  n = 2;
                  A = new int[2*(2+1)/2];
            }
            Lower_triangular(int n)
            {
                  this->n = n;
                  A = new int[n*(n+1)/2];
            }
            void RSet(int i, int j, int x);
            void CSet(int i, int j, int x);
            int RGet(int i, int j);
            int CGet(int i, int j);
            void RDisplay();
            void CDisplay();
            ~Lower_triangular()
            {
                  delete[] A;
            }
};

// Row Major Mapping

void Lower_triangular :: RSet(int i, int j,int x) // Set for Row Major Mapping
{ 
      if(i>=j)
      {
            A[((i * (i - 1)) / 2) + (j - 1)] = x;
      }

}

int Lower_triangular :: RGet(int i, int j)// Set for Row Major Mapping
{
      if(i>=j)
      {
            return A[((i * (i - 1)) / 2) + (j - 1)];
      }
      else
      {
            return 0;
      }
}

void Lower_triangular :: RDisplay() // Display for row major Mapping
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
                        cout << "0 ";
                  }
                 
            }
            cout << endl;
      }
}

// Column Major Mapping
void Lower_triangular :: CSet(int i, int j,int x) // Set for Column Major Mapping
{ 
      if(i>=j)
      {
            int t = (n * (j - 1) - ((j - 2)*(j - 1) / 2)) + (i - j);
            A[t]= x;
      }

}

int Lower_triangular :: CGet(int i, int j)// Set for Column Major Mapping
{
      int t = (n * (j - 1) - ((j - 2)*(j - 1) / 2)) + (i - j);
      if(i>=j)
      {
            return A[t];
      }
      else
      {
            return 0;
      }
}

void Lower_triangular :: CDisplay() // Display for Column major Mapping
{
      
      for (int i = 1; i <=n;i++)
      {
            for (int j = 1; j <= n;j++)
            {
                  
                  if(i>=j)
                  {
                        int t = (n * (j - 1) - ((j - 2)*(j - 1) / 2)) + (i - j);
                        cout << A[t] << " ";
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

      int i, j, x, choice, n;
      cout << "Enter the value of n: ";
      cin >> n;

      Lower_triangular Lt(n);

      cout<<"Choose the Method: \n"<<endl;
      cout<<"Enter 1: Row Major Mapping"<<endl;
      cout<<"Enter 2: Column Major Mapping"<<endl;
      cout<<"Enter 3: For Exit"<<endl;
      cout<<"Enter your Choice: ";
      cin >> choice;

      switch (choice)
      {
            case 1:
                  cout<<"Enter all elements of Lower Triangular Matrix: "<<endl;
                  for (i = 1; i <= n;i++)
                  {
                        for (j = 1; j <= n;j++)
                        {
                              if(i>=j)
                              {
                                    cout << "Enter the value of A[" << i << "][" << j << "]: ";
                                    cin >> x;
                                    Lt.RSet(i, j, x);

                              }

                        }
                  }
                  cout << "\nRequired Matrix: " << endl;
                  Lt.RDisplay();
                  cout<<"\nGetting the value of A[2][2]: "<<Lt.RGet(2, 2);
                  break;
            
            case 2:
                 cout<<"Enter all elements of Lower Triangular Matrix: "<<endl;
                  for (i = 1; i <= n;i++)
                  {
                        for (j = 1; j <= n;j++)
                        {
                              if(i>=j)
                              {
                                    cout << "Enter the value of A[" << i << "][" << j << "]: ";
                                    cin >> x;
                                    Lt.CSet(i, j, x);

                              }

                        }
                  }
                  cout << "\nRequired Matrix: " << endl;
                  Lt.CDisplay();
                  cout<<"\nGetting the value of A[2][2]: "<<Lt.CGet(2, 2);
                  break;
            
            case 3:
                  exit(0);
                  break;
      
            default:
                  printf("\nWrong Choice");
                  break;
      }
      return 0;
}