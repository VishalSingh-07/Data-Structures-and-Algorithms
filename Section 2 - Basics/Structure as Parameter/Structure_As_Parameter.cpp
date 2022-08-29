// Passing using call by value
#include <iostream>
using namespace std;
#include <stdlib.h>

struct Rectangle
{
      int length;
      int breadth;
};
void func(struct Rectangle r1) // seperate object
{
      r1.length++; // it does not change the value of actual parameter of structure.
      cout<<"Length: "<<r1.length<<endl;
      cout<<"Breadth: "<<r1.breadth<<endl;
}
int main()
{
      struct Rectangle r={10,5};

      func(r);
      cout<<"Length: "<<r.length<<"  and breadth: "<<r.breadth;
      return 0;
}