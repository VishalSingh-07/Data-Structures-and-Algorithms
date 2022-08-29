#include <iostream>
using namespace std;
int area(int l, int b)
{
      return l*b;
}
int perimeter(int l, int b)
{
      return 2*(l+b);
}
int main()
{
      int length, breadth;
      //int length=0, breadth=0; It is good practice to initialize and declare an variable

      cout<<"Enter the value of length: ";
      cin>>length;
      cout<<"Enter the value of breadth: ";
      cin>>breadth;

      int ar=area(length, breadth);
      int peri=perimeter(length,breadth);

      cout<<"Area of the Rectangle : "<<ar<<endl;
      cout<<"Perimeter of the Rectangle: "<<peri;

      return 0;
}