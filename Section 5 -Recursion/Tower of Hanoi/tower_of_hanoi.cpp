// Tower of Hanoi
#include <iostream>
using namespace std;
void TOH(int n, int A, int B, int C)
{
      if(n>0)
      {
            TOH(n - 1, A, C, B);
            cout << "Move from Tower " << A << " to " << C<< "  --- ("<<A<<","<<C<<")"<<endl;
            TOH(n - 1, B, A, C);
      }
}
int main(){

      int n;
      cout << "Enter the number of disk: ";
      cin >> n;
      TOH(n, 1, 2, 3);

      return 0;
}