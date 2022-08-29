// Calculationg (m)^n using recursion
#include <iostream>
using namespace std;
// Slower Recursive Function
int pow(int m,int n)
{
      if(n==0)
      {
            return 1;
      }
      else
      {
            return pow(m,n-1)*m; 
      }
}
// Faster Recursive Function
int powerful(int m, int n)
{
      if(n==0)
      {
            return 1;
      }
      else if(n%2==0)
      {
            return powerful(m*m,n/2);
      }
      else
      {
            return (m*powerful(m*m,(n-1)/2));
      }
}
int main()
{
      int base, exponent;
      int cal;
      cout<<"Enter the value of base: ";
      cin>>base;
      cout<<"Enter the value of exponent: ";
      cin>>exponent;

      cal=powerful(base,exponent);

      cout<<"Power of "<<base<<"^"<<exponent<<" is : "<<cal;

      return 0;
}