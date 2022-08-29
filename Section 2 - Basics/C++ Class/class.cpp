#include <iostream>
using namespace std;
class Rectangle
{
      private:
      int length;
      int breadth;

      public:
      Rectangle()
      {
            length=breadth=0;
      }
      Rectangle(int l, int b)
      {
            length=l;
            breadth=b;
      }
      int area()
      {
            return length*breadth;
      }
      int perimeter()
      {
            return 2*(length+breadth);
      }
      void setlength(int l)
      {
            length=l;
      }
      void setbreadth(int b)
      {
            breadth=b;
      }
      int getlength(int l)
      {
            return length;
      }
      int getbreadth(int b)
      {
            return breadth;
      }
      ~Rectangle()
      {
            cout<<"Destructor"<<endl;
      }

};

int main()
{
      Rectangle r1(10,5);
      cout<<"Area of Rectangle: "<<r1.area()<<endl;
      cout<<"Perimeter of Rectangle: "<<r1.perimeter()<<endl;
}