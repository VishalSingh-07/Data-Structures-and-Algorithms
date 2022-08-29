#include <iostream>
using namespace std;
int main()
{
      int a=10;
      int &r=a; //reference is always intialize and declare at a same time
      // Reference is actually another name of the variable
      r=25;
      
      int b=30;
      r=b;

      cout<<a<<endl<<r<<endl;


      // reference do not take memory. So conceptually a reference doesn't consume memory.


      return 0;


}