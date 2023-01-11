#include <iostream>
using namespace std;

struct Term
{
      int coeff;
      int Expo;
};
struct Poly
{
      int n;
      struct Term *terms;
};
void create(struct Poly *p)
{
      cout << "Enter the number of terms: ";
      cin >> p->n;
      p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

      cout << "Enter Terms: " << endl;
      for (int i = 0; i < p->n;i++)
      {
            cin >> p->terms[i].coeff >> p->terms[i].Expo;
      }
}

void display(struct Poly p)
{
      int i;
      for (int i = 0; i < p.n;i++)
      {
            cout << p.terms[i].coeff << "x^" << p.terms[i].Expo;
            if(i!=(p.n)-1)
            {
                  cout << " + ";
            }
      }
      cout << endl;
}

struct Poly *add (struct Poly *p1, struct Poly *p2)
{
      int i, j, k;
      struct Poly *sum;
      sum = (struct Poly *)malloc(sizeof(struct Poly));

      sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

      i = j = k = 0;

      while(i<p1->n && j<p2->n)
      {
            if(p1->terms[i].Expo >p2->terms[j].Expo)
            {
                  sum->terms[k++] = p1->terms[i++];
            }
            else if(p1->terms[i].Expo < p2->terms[j].Expo)
            {
                  sum->terms[k++] = p2->terms[j++];
            }
            else
            {
                  sum->terms[k].Expo = p1->terms[i].Expo;
                  sum->terms[k++].coeff = p1->terms[i++].coeff+p2->terms[j++].coeff;
                  
            }
      }

      for (; i < p1->n;i++)
      {
            sum->terms[k++]= p1->terms[i];
      }
       for (; j < p2->n;j++)
      {
            sum->terms[k++]= p2->terms[j];
      }

      sum->n = k;

      return sum;
}
int main()
{
      struct Poly p1,p2,*p3;

      create(&p1);
      cout << "First Polynomial--" << endl;
      display(p1);

      create(&p2);
      cout << "Second Polynomial--" << endl;
      display(p2);

      p3 = add(&p1, &p2);
      cout << "Sum Polynomial--" << endl;
      display(*p3);

      return 0;
}

/*
Output--
Enter the number of terms: 3
Enter Terms: 
1 5
1 3
1 1
First Polynomial--
1x^5 + 1x^3 + 1x^1
Enter the number of terms: 3
Enter Terms: 
1 4
1 2
1 0
Second Polynomial--
1x^4 + 1x^2 + 1x^0
Sum Polynomial--
1x^5 + 1x^4 + 1x^3 + 1x^2 + 1x^1 + 1x^0
*/