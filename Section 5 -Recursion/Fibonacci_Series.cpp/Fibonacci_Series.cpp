// Fibonacci Series using Iterative Method
#include <iostream>
using namespace std;
int fib(int n)
{
      int a = 0, b = 1, sum = 0;
      if(n<=1)
      {
            return n;
      }
      else
      {
            cout << a;
            cout << " "<<b<<" ";
            for (int i = 2; i <=n;i++)
            {
                  sum = a + b;
                  a = b;
                  b = sum;
                  cout << sum<<" ";
            }
            return sum;
      }
}
int main(){
      int terms;
      cout << "Enter the number of terms:";
      cin >> terms;
      cout << "Fibonacci Series is: ";
      int result = fib(terms);
      cout << "The value of " << terms << " terms in the fibonacci Series is: "<<result;
      return 0;
}