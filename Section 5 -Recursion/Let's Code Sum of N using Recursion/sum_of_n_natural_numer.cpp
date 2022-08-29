// Calculating the sum of the first n natural number using recursion
#include <iostream>
using namespace std;
//using recursion
int sum(int n)
{
      if(n==0)
      {
            return 0;
      }
      else
      {
            return sum(n-1)+n;
      }
}
//using loop
int Isum(int n)
{
      int i, sum=0;
      for(i=0;i<=n;i++)
      {
            sum=sum+i;
      }
      return sum;

}
//using formula
int fsum(int n)
{
      return n*(n+1)/2;
}
int main()
{
      int r;
      int n;
      cout<<"Enter the value of n: ";
      cin>>n;
      r=sum(n);
      cout<<"Sum of the first "<<n<<" is: "<<r;
}