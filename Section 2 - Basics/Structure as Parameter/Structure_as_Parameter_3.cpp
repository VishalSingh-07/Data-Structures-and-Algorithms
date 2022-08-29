// Create a variable of type structure on heap inside a function and return,
#include <iostream>
using namespace std;
#include <stdlib.h>

struct Rectangle
{
      int length;
      int breadth;
};
struct Rectangle* func()
{
      struct Rectangle *p;
      p=new Rectangle;
      //p=(struct Rectangle *)malloc(sizeof(struct Rectangle));
      p->length=15;
      p->breadth=7;

      return p;
}

int main()
{
      struct Rectangle *ptr=func();

      cout<<"Length: "<<ptr->length<<"  and breadth: "<<ptr->breadth;
      return 0;
}