#include <iostream>
using namespace std;
void swap(int &x, int &y)
{
      int temp;
      temp=x;
      x=y;
      y=temp;
     

}
int main()
{
      int num1,num2;
      int z;
      cout<<"Enter the value of first number: ";
      cin>>num1;
      cout<<"Enter the value of Second number: ";
      cin>>num2;

      swap(num1,num2);

      cout<<"After Swapping: "<<endl;
      cout<<"The value of num1 is : "<<num1<<endl;
      cout<<"The value of num2 is :"<<num2<<endl;





      return 0;

}
/*

void swap(int &x, y) // not possible
void swap(int &x, *y) // yes it is possible
*/