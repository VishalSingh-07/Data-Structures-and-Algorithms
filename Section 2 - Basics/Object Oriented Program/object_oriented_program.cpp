#include <iostream>
using namespace std;

class Rectangle
{
      private:
      int length;
      int breadth;
      public:
      // class Rectangle(int l, int b)
      // {
      //       length=l;
      //       breadth=b;
      // }
      void initialize( int l, int b)
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
            int p;
            p=2*(length+breadth);
            return p;
      }
};

int main()
{
      Rectangle r;
      int l,b;
      cout<<"Enter the value of length: ";
      cin>>l;
      cout<<"Enter the value of breadth: ";
      cin>>b;
      r.initialize(l, b);
      int ar=r.area();
      int per=r.perimeter();

      cout<<"Area of the Rectangle : "<<ar<<endl;
      cout<<"Perimeter of the Rectangle: "<<per;


      return 0;
      
}