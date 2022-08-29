// Taylor Series using recursion
#include <iostream>
using namespace std;
double e(int x, int n)
{
      static double p = 1, f = 1;
      double r;
      if(n==0)
      {
            return 1;
      }
      
      else
      {
            r = e(x, n - 1);
            p = p * x;
            f = f * n;
            cout << r <<" ";
            return r + p / f;
      }
}
int main(){
      int power, terms;
      double result;
      cout << "Enter the power of the e: ";
      cin >> power;
      cout << "Enter the number of the terms: ";
      cin >> terms;
      cout << "Taylor Series is: ";
      
      result=e(power, terms);
      cout << "\n e^("<<power<<"): "<< result;
      return 0;
}