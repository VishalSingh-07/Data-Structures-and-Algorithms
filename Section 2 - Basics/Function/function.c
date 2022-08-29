#include <stdio.h>
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
      printf("Enter the value of first number: ");
      scanf("%d",&num1);
      printf("Enter the value of Second number: ");
      scanf("%d",&num2);

      z=add(num1,num2);

      printf("The addition of two number is : %d",z);
       

      


      return 0;

}