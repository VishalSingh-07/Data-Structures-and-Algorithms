// Fibonacci Series using Memorization Method
#include <iostream>
using namespace std;
int f[100];
int fib(int n)
{
      if(n<=1)
      {
            f[n] = n;
            return n;
      }
      else
      {
            if(f[n-2]==-1)
            {
                  f[n - 2] = fib(n - 2);
            }
            if(f[n-1]==-1)
            {
                  f[n - 1] = fib(n - 1);
            }
            f[n] = f[n - 2] + f[n - 1];
            return f[n - 2] + f[n - 1];
      }

      
}
int main(){
      int terms;
      int i;
      for (i = 0; i < 100;i++)
      {
            f[i] = -1;
      }
      cout << "Enter the number of terms:";
      cin >> terms;
      int result = fib(terms);
      cout << "The value of " << terms << " terms in the fibonacci Series is: "<<result;
      return 0;
}