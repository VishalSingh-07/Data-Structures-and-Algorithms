#include <iostream>
using namespace std;
int main()
{
      int length, breadth;
      //int length=0, breadth=0; It is good practice to initialize and declare an variable

      cout<<"Enter the value of length: ";
      cin>>length;
      cout<<"Enter the value of breadth: ";
      cin>>breadth;

      int area=length*breadth;

      int perimeter=2*(length+breadth);
       
      cout<<"Area of the Rectangle : "<<area<<endl;
      cout<<"Perimeter of the Rectangle: "<<perimeter;


      return 0;


}