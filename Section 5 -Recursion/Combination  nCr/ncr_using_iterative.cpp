// Combination formula (ncr) using iterative method
#include <iostream>
using namespace std;
int fact(int n)
{
      if(n==0)
      {
            return 1;
      }
      else
      {
            return fact(n - 1) * n;
      }
}
int combination(int n, int r)
{
      int t1, t2, t3;
      t1 = fact(n);
      t2 = fact(r);
      t3 = fact(n - r);

      return t1 / (t2 * t3);
}
int main(){
      int n,r;
      cout << "Enter the value of n: ";
      cin >> n;
      cout << "Enter the value of r: ";
      cin >> r;

      int result = combination(n, r);
      cout << "Number of Combination is : " << result;
      return 0;
}