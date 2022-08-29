#include <iostream>
using namespace std;
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
      cout<<"Enter the value of first number: ";
      cin>>num1;
      cout<<"Enter the value of Second number: ";
      cin>>num2;

      swap(&num1,&num2);

      cout<<"\n After Swapping: ";
      cout<<"\n The value of num1 is : "<<num1;
      cout<<"\n The value of num2 is : "<<num2;
      
      return 0;

      // Any change donw on formal parameter does reflected in actual parameter

}