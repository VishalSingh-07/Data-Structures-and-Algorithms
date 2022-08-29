#include <stdio.h>
int add(int a, int b)
{
      int c;
      c=a+b;
      a++;
      printf("\n %d",a);
      return c;
      

}
int main()
{
      int num1,num2;
      int z;
      printf("Enter the value of first number: ");
      scanf("%d",&num1);
      printf("Enter the value of Second number: ");
      scanf("%d",&num2);

      add(num1,num2);

      printf("\n %d",num1);

      // printf("The addition of two number is : %d",z);



      return 0;

}