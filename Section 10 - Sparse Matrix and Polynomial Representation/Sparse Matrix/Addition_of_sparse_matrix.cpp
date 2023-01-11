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
struct Sparse * add(struct Sparse *s1, struct Sparse *s2)
{
      struct Sparse *sum;
      int i=0, j=0, k = 0;
      if(s1->m!=s2->m || s1->n!=s2->n)
      {
            return 0;
      }
      sum = (struct Sparse *)malloc(sizeof(struct Sparse));
      // sum = new Sparse;

      sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

      // sum->ele = new Element[s1->num + s2->num];

      sum->m = s1->m;
      sum->n = s1->n;

      while(i<s1->num && j<s2->num)
      {
            if(s1->ele[i].i < s2->ele[j].i) // if s2 row is greater
            {
                  sum->ele[k++] = s1->ele[i++];
            }
            else if(s1->ele[i].i > s2->ele[j].i) // s1 row is greater
            {
                sum->ele[k++] = s2->ele[j++];  
            }

            else // both row are equal
            {
                  if(s1->ele[i].j<s2->ele[j].j) // row of s1 and s2 is same but column of s1 is less than s2
                  {
                        sum->ele[k++] = s1->ele[i++];
                  }
                  else if(s1->ele[i].j>s2->ele[j].j) //row of s1 and s2 is same but column of s2 is less than s1
                  {
                        sum->ele[k++] = s2->ele[j++];
                  }
                  else
                  {
                        sum->ele[k ] = s1->ele[i++]; // copy comple s1 struct elm elements
                        sum->ele[k++].x = sum->ele[k].x + s2->ele[j++].x; // add s1 and s2 values


                  }

            }
      }

      // Remaining Elements
      for (; i < s1->num;i++)
      {
            sum->ele[k++] = s1->ele[i];
      }
      for (; j < s2->num;j++)
      {
            sum->ele[k++] = s2->ele[j];
      }
      
      sum->num = k;

      return sum;
}

int main()
{
      struct Sparse s1,s2,*s3;
      create(&s1);
      cout << "First Matrix: " << endl;
      display(s1);
      create(&s2);
      cout << "Second Matrix: " << endl;
      display(s2);

      s3 = add(&s1, &s2);
      cout << "Sum Matrix: " << endl;
      display(*s3);

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
Enter all non-zero elements-----
0 0 2
1 0 2
2 0 2
3 0 2
4 0 2
Second Matrix:
2 0 0 0 0
2 0 0 0 0
2 0 0 0 0
2 0 0 0 0
2 0 0 0 0
Sum Matrix:
3 0 0 0 0
2 1 0 0 0
2 0 1 0 0
2 0 0 1 0
2 0 0 0 1
*/
// or
/*
Output
Enter Dimension: ---
Enter the value of m: 5
Enter the value of n: 5
Enter the number of non-zero element: 5
Enter all non-zero elements-----
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
Enter all non-zero elements-----
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