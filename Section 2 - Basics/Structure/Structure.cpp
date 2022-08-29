// Practice : Structure

#include <iostream>
using namespace std;

struct Rectangle
{
      int length;
      int breadth; 
      char x; // allocating 4 bytes but only using 1 byte
}; //r1,r2,r3;

// struct Rectangle r1,r2,r3;
int main()
{
      struct Rectangle r1,r2,r3;
      r1={10,5};
      
      // r1.length=20;
      // r1.breadth=99; Changing the value of the struct variable

      cout<<"Size of the struct: "<<sizeof(r1)<<endl;
      cout<<"Length of rectangle r1: "<<r1.length<<endl;
      cout<<"Breadth of rectangle r1: "<<r1.breadth;

      



      return 0;

}