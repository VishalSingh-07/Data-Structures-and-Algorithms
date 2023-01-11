#include <bits/stdc++.h>
using namespace std;
struct Element // struct for non-zero element
{
      int i;
      int j;
      int x;
};
struct Sparse
{
      int m; // number of rows
      int n; // number of column
      int num; // number of non-zero element
      struct Element *ele; // Dynamic Array
};
void create(struct Sparse *s)
{
      cout << "Enter Dimension: ---"<<endl;
      cout << "Enter the value of m: ";
      cin >> s->m;
      cout << "Enter the value of n: ";
      cin >> s->n;

      cout << "Enter the number of non-zero element: ";
      cin >> s->num;

      // s->ele = (struct Element *)malloc(s->num*sizeof(struct Element));
      s->ele = new Element[s->num];

      cout << "Enter all non-zero elements-----" << endl;

      for (int i = 0; i < s->num;i++)
      {
            cin >> s->ele[i].i;
            cin >> s->ele[i].j;
            cin >> s->ele[i].x;
      }
}

void display(struct Sparse s)
{
      int i, j, k = 0;
      for (i = 0; i < s.m;i++)
      {
            for (j = 0; j < s.n;j++)
            {
                  if(i==s.ele[k].i && j==s.ele[k].j)
                  {
                        cout << s.ele[k++].x<<" ";
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
      struct Sparse s;
      create(&s);
      display(s);

      return 0;
}

/*
Output--

Enter Dimension: ---
Enter the value of m: 5
Enter the value of n: 5
Enter the number of non-zero element: 5
Enter all non-zero elements-----
0 0 1
1 0 1
2 0 1
3 0 1
4 0 1
1 0 0 0 0 
1 0 0 0 0 
1 0 0 0 0 
1 0 0 0 0 
1 0 0 0 0
*/