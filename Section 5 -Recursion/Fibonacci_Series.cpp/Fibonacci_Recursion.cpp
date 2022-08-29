// Fibonacci Series using Recursion method
#include <iostream>
using namespace std;
int fib(int n)
{
      if(n<=1)
      {
            return n;
      }
      else
      {
            return (fib(n - 2) + fib(n - 1));
      }
     
}
int main(){
      int terms;
      cout << "Enter the number of terms:";
      cin >> terms;
      int result = fib(terms);
      cout << "The value of " << terms << " terms in the fibonacci Series is: "<<result;
      return 0;
}