// Factorial of the number
#include <iostream>
using namespace std;
//using recursion
int fact(int n)
{
      if(n==0)
      {
            return 1;
      }
      else
      {
            return fact(n-1)*n;
      }
}
//using loop
int ifact(int n)
{
      int i,fact=1;
      if(n>0)
      {
            for(i=1;i<=n;i++)
            {
                  fact*=i;
            }
            
      }
      
      return fact;
      
      
}
int main()
{
      int n, r;
      cout<<"Enter the value of n: ";
      cin>>n;
      r=ifact(n);
      if(n>0)
      {
            cout<<"Factorial of the "<<n<<" is: "<<r;
            
      }
      else
      {
            cout<<"Negative number factorial cannt be exists.";
      }
      return 0;
}