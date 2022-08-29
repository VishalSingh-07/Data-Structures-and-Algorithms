// Taylor Series using Horner's Rule (Recursion)
#include <iostream>
using namespace std;
double e(int x, int n )
{
      static double s = 1;
      if(n==0)
      {
            return s;
      }
      else
      {
            
            s = 1 + (double)x / n * (s);
            return e(x, n - 1);
      }
}
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