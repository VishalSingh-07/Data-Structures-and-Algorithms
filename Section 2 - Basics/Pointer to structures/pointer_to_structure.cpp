#include <iostream>
using namespace std;

struct Rectangle
{
      int length;
      int breadth;

};
int main()
{
      struct Rectangle r={10,5};

      cout<<"Length of the rectangle :"<<r.length<<endl;
      cout<<"Breadth of the rectangle :"<<r.breadth<<endl;
      
      /*
      for Just a variable use Dot operator
      for Pointer variable use arrow(->)
      */

      // Pointer to Structure
      
      Rectangle *p=&r;
      cout<<"Length of the rectangle :"<<p->length<<endl;
      cout<<"Breadth of the rectangle :"<<p->breadth<<endl;
      

      // Creating the object for heap (Dynamic Allocation)

      struct Rectangle *d;
      //d=(struct Rectangle *)malloc(sizeof(struct Rectangle)); // For C language
      d=new Rectangle; // For c++ language
      int a=d->length=15;
      int b=d->breadth=25;

      cout<<"Length of the rectangle :"<<a<<endl;
      cout<<"Breadth of the rectangle :"<<b<<endl;


      return 0;
}