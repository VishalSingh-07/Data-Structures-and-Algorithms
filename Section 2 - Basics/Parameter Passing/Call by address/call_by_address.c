#include <stdio.h>
void swap(int *x, int *y)
{
      int temp;
      temp=*x;
      *x=*y;
      *y=temp;
     

}
int main()
{
      int num1,num2;
      int z;
      printf("Enter the value of first number: ");
      scanf("%d",&num1);
      printf("Enter the value of Second number: ");
      scanf("%d",&num2);

      swap(&num1,&num2);

      printf("\n After Swapping: ");
      printf("\n The value of num1 is : %d",num1);
      printf("\n The value of num2 is : %d",num2);





      return 0;

}