#include <iostream>
using namespace std;

struct Rectangle
{
      int length;
      int breadth;
};
void initialize(struct Rectangle *r, int l, int b)
{
      r->length=l;
      r->breadth=b;
}
int area(struct Rectangle r)
{
      return r.length*r.breadth;
}
int perimeter(struct Rectangle r)
{
      int p;
      p=2*(r.length+r.breadth);
      return p;
}
int main()
{
      struct  Rectangle r;
      int l,b;
      cout<<"Enter the value of length: ";
      cin>>l;
      cout<<"Enter the value of breadth: ";
      cin>>b;
      
      initialize(&r,l, b);
      int ar=area(r);
      int peri=perimeter(r);

      cout<<"Area of the Rectangle : "<<ar<<endl;
      cout<<"Perimeter of the Rectangle: "<<peri;


      return 0;
      
}