#include <iostream>
using namespace std;

class Term
{
      public:
            int coeff;
            int Expo;
};
class Polynomial
{
      private:
            int n;
            Term *terms;
      
      public:
            Polynomial(int n)
            {
                  this->n = n;
                  terms = new Term[this->n];
            }

            ~Polynomial()
            {

            }

            Polynomial operator+(Polynomial &p);

            friend istream & operator >>(istream &is, Polynomial &s); // for read

            friend ostream &operator<<(ostream &os, Polynomial &s); // for display
};

Polynomial Polynomial :: operator+ (Polynomial &p)
{
      int i, j, k;
      Polynomial *sum = new Polynomial(n + p.n);

      i = j = k = 0;

      while(i<n && j<p.n)
      {
            if(terms[i].Expo >p.terms[j].Expo)
            {
                  sum->terms[k++] = terms[i++];
            }
            else if(terms[i].Expo < p.terms[j].Expo)
            {
                  sum->terms[k++] = p.terms[j++];
            }
            else
            {
                  sum->terms[k].Expo = terms[i].Expo;
                  sum->terms[k++].coeff = terms[i++].coeff+p.terms[j++].coeff;
                  
            }
      }

      for (; i < n;i++)
      {
            sum->terms[k++]= terms[i];
      }
       for (; j < p.n;j++)
      {
            sum->terms[k++]= p.terms[j];
      }

      sum->n = k;

      return *sum;
}

istream & operator >>(istream &is, Polynomial &p)
{
      cout << "Enter Terms: " << endl;
      for (int i = 0; i < p.n;i++)
      {
            cin >> p.terms[i].coeff >> p.terms[i].Expo;
      }

      return is;
}

ostream &operator<<(ostream &os, Polynomial &p)
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

      return os;
}

int main()
{
      int m, n;
      cout << "Enter the number of Terms: ";
      cin >> m;
      Polynomial p1(m);
      cin >> p1;
      cout << "First Polynomial--" << endl;
      cout<<p1;

      cout << "Enter the number of Terms: ";
      cin >> n;
      Polynomial p2(n);
      cin >> p2;
      cout << "Second Polynomial--" << endl;
      cout<<p2;

      Polynomial p3 = p1 + p2;
      cout << "Sum Polynomial--" << endl;
      cout << p3;

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