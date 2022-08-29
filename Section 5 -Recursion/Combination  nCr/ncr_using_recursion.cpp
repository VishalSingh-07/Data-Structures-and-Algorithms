// Combination formula (ncr) using recursive method
#include <iostream>
using namespace std;
int combination(int n, int r)
{
      if(r==0 || n==r)
      {
            return 1;
      }
      else
      {
            return (combination(n - 1, r - 1) + combination(n - 1, r));
      }
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