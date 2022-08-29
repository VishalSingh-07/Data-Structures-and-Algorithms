#include <iostream>
using namespace std;
int add(int a, int b)
{
      int c;
      c=a+b;
      a++;
      printf("\n %d",a); // print 11
      return c;
      

}
int main()
{
      int num1,num2;
      int z;
      cout<<"Enter the value of first number: ";
      cin>>num1; // 10
      cout<<"Enter the value of Second number: ";
      cin>>num2; // 12

      add(num1,num2);

      printf("\n %d",num1); //10

      // Any changes done on formal parameter does not reflected in actual parameter.

      // printf("The addition of two number is : %d",z);



      return 0;

}