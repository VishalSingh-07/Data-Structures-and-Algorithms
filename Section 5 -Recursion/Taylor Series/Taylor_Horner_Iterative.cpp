// Taylor Series using Horner's Rule (Iterative)
#include <iostream>
using namespace std;
double e(int x, int n )
{
      double s = 1;
      int i;
      double num = 1, den = 1;
      for (i = 1; i <= n;i++)
      {
            num*= x;
            den *= i;
            s += num / den;
      }
      return s;
}

// Another Method
// double e(int x, int n )
// {
//       double s = 1;
//       int i;
//       for (i = n; n > 0; n--)
//       {
//             s = 1 + (double)x / n * (s);
//       }
//       return s;
// }
int main(){
      int power, terms;
      double result;
      cout << "Enter the power of the e: ";
      cin >> power;
      cout << "Enter the number of the terms: ";
      cin >> terms;
      
      result=e(power, terms);
      cout << "e^("<<power<<"): "<< result;
      return 0;
}