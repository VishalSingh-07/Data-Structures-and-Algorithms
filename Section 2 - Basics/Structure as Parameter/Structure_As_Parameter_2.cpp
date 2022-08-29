// Passing using call by address
#include <iostream>
using namespace std;
#include <stdlib.h>

struct Rectangle
{
      int length;
      int breadth;
};
void func(struct Rectangle *r1){
      r1->length++; // it actually change the value of actual parameter of structure.
      cout<<"Length: "<<r1->length<<endl;
      cout<<"Breadth: "<<r1->breadth<<endl;
}
int main()
{
      struct Rectangle r={10,5};

      func(&r);
      cout<<"Length: "<<r.length<<"  and breadth: "<<r.breadth;
      return 0;
}