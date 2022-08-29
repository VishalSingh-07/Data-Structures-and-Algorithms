// Template Program

#include <iostream>
using namespace std;
template <class T>
class Arithmetic
{
      private:
      T a;
      T b;
      public:
      Arithmetic(T a,T b);
      T add();
      T sub();
};      
template <class T>     
Arithmetic <T> :: Arithmetic(T a,T b)
{
      this->a=a;
      this->b=b;
}
template <class T>
T Arithmetic <T> :: add()
{
      T c;
      c=a+b;
      return c;
}
template <class T>
T Arithmetic <T> :: sub()
{
      T c;
      c=a-b;
      return c;
}


int main()
{
      Arithmetic  <int> a(10,5); 
      Arithmetic <float> b(11.4,8.3);
      cout<<"Using int data types: "<<endl;
      cout<<"Sum of the number: "<<a.add()<<endl;
      cout<<"Subtract of the number: "<<a.sub()<<endl;
      cout<<"Using Float data types: "<<endl;
      cout<<"Sum of the number: "<<b.add()<<endl;
      cout<<"Subtract of the number: "<<b.sub();



      return 0;
}