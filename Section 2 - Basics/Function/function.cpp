#include <iostream>
using namespace std;
int add(int a, int b)
{
      int c;
      c=a+b;
      return c;

}
// One function cannot access the variable of another function.
int main()
{
      int num1,num2;
      int z;
      cout<<"Enter the value of first number: ";
      cin>>num1;
      cout<<"Enter the value of Second number: ";
      cin>>num2;

      z=add(num1,num2);

      cout<<"The addition of two number is : "<<z;
      
      return 0;

}