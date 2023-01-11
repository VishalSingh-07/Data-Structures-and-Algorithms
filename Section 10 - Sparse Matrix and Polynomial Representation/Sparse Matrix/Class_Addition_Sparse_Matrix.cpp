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

            Sparse operator+(Sparse &s);

            friend istream & operator >>(istream &is, Sparse &s); // for read

            friend ostream &operator<<(ostream &os, Sparse &s); // for display


};

Sparse Sparse :: operator+(Sparse &s)
{
      int i=0, j=0, k = 0; // i for referrring elements of array of struct Element pointed by elm  in sparse structure pointed by s1 and j for s2 and k for sum
      if(m!=s.m || n!=s.n)
      {
            Sparse(0,0,0);
      }
      Sparse *sum = new Sparse(m, n, num + s.num);
      sum->ele = new Element[num + s.num];

      sum->m = m;
      sum->n = n;

      while(i<num && j<s.num)
      {
            if(ele[i].i < s.ele[j].i) // if s2 row is greater
            {
                  sum->ele[k++] = ele[i++];
            }
            else if(ele[i].i > s.ele[j].i) // s1 row is greater
            {
                sum->ele[k++] = s.ele[j++];  
            }

            else // both row are equal
            {
                  if(ele[i].j<s.ele[j].j) // row of s1 and s2 is same but column of s1 is less than s2
                  {
                        sum->ele[k++] = ele[i++];
                  }
                  else if(ele[i].j>s.ele[j].j) //row of s1 and s2 is same but column of s2 is less than s1
                  {
                        sum->ele[k++] = s.ele[j++];
                  }
                  else
                  {
                        sum->ele[k ] = ele[i]; // copy comple s1 struct elm elements
                        sum->ele[k++].x = ele[i++].x + s.ele[j++].x; // add s1 and s2 values


                  }

            }
      }

      // Remaining Elements
      for (; i < num;i++)
      {
            sum->ele[k++] = ele[i];
      }
      for (; j < s.num;j++)
      {
            sum->ele[k++] = s.ele[j];
      }
      
      sum->num = k;

      return *sum;
}

istream & operator >>(istream &is, Sparse &s)
{
      cout << "Enter non-zero element: - "<<endl;
      for (int i = 0; i < s.num;i++)
      {
            cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
      }

      return is;
}
ostream &operator<<(ostream &os, Sparse &s)
{
      int k = 0;
      for (int i = 0; i < s.m;i++)
      {
            for (int j = 0; j < s.n;j++)
            {
                  if(s.ele[k].i==i && s.ele[k].j==j)
                  {
                        cout << s.ele[k++].x << " ";
                  }
                  else
                  {
                        cout << "0 ";
                  }
                  
            }
            cout << endl;
      }

      return os;
}
int main()
{
            int m1,n1,num1,m2,n2,num2;
            cout << "Enter Dimension: ---" << endl;
            cout << "Enter the value of m: ";
            cin >> m1;
            cout << "Enter the value of n: ";
            cin >> n1;

            cout << "Enter the number of non-zero element: ";
            cin >> num1;

            Sparse s1(m1,n1,num1);
            cin >> s1;
            cout << "First Matrix: " << endl;
            cout << s1;

            cout << "Enter Dimension: ---" << endl;
            cout << "Enter the value of m: ";
            cin >> m2;
            cout << "Enter the value of n: ";
            cin >> n2;

            cout << "Enter the number of non-zero element: ";
            cin >> num2;

            Sparse s2(m2,n2,num2);
            cin >> s2;
            cout << "Second Matrix: " << endl;
            cout << s2;

            Sparse sum = s1 + s2;
            cout << "Sum Matrix: " << endl;
            cout << sum;

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
First Matrix: 
1 0 0 0 0 
0 1 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
Enter Dimension: ---
Enter the value of m: 5 
Enter the value of n: 5
Enter the number of non-zero element: 5
Enter non-zero element: -
0 0 5
1 1 5
2 2 5
3 3 5
4 4 5
Second Matrix:
5 0 0 0 0
0 5 0 0 0
0 0 5 0 0
0 0 0 5 0
0 0 0 0 5
Sum Matrix:
6 0 0 0 0
0 6 0 0 0
0 0 6 0 0
0 0 0 6 0
0 0 0 0 6
*/