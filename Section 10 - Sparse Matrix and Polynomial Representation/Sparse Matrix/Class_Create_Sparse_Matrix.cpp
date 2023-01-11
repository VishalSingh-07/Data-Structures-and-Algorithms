#include <iostream>
using namespace std;
class Element
{
      public:
            int i;
            int j;
            int x;
};  

class Sparse
{
      private:
            int m; // number of rows
            int n; // number of column
            int num; // number of non-zero element
            Element *ele;
      
      public:
            Sparse(int m, int n, int num)
            {
                  this->m = m;
                  this->n = n;
                  this->num = num;
                  ele = new Element[this->num];
            }

            ~Sparse()
            {
                  delete[] ele;
            }
            void read()
            {
                  cout << "Enter non-zero element: - "<<endl;
                  for (int i = 0; i < num;i++)
                  {
                        cin >> ele[i].i >> ele[i].j >> ele[i].x;
                  }
            }
            void Display()
            {
                  int k = 0;
                  for (int i = 0; i < m;i++)
                  {
                        for (int j = 0; j < n;j++)
                        {
                              if(ele[k].i==i && ele[k].j==j)
                              {
                                    cout << ele[k++].x << " ";
                              }
                              else
                              {
                                    cout << "0 ";
                              }

                        }
                        cout << endl;
                  }
            }
};

int main()
{
            int m, n, num;
            cout << "Enter Dimension: ---" << endl;
            cout << "Enter the value of m: ";
            cin >> m;
            cout << "Enter the value of n: ";
            cin >> n;

            cout << "Enter the number of non-zero element: ";
            cin >> num;

            Sparse s1(m,n,num);
            s1.read();
            s1.Display();
            return 0;
}

/*
Output--
Enter Dimension: ---
Enter the value of m: 5
Enter the value of n: 5
Enter the number of non-zero element: 5
Enter non-zero element: - 
0 0 1
1 1 1
2 2 1
3 3 1
4 4 1
1 0 0 0 0 
0 1 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1
*/