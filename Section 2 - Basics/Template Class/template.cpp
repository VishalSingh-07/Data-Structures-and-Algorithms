/*
C++ Programming supports generic function and generic classes.
Generic function are template function and classs are template class.
*/
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
      Arithmetic(T a,T b)
      {
            this->a=a;
            this->b=b;
      }
      T add()
      {
            T c;
            c=a+b;
            return c;
      }
      T sub()
      {
            T c;
            c=a-b;
            return c;
      }

};
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

/*
//Simple program
#include <iostream>
using namespace std;
class Arithmetic
{
      private:
      int a;
      int b;
      public:
      Arithmetic(int a,int b)
      {
            this->a=a;
            this->b=b;
      }
      int add()
      {
            int c;
            c=a+b;
            return c;
      }
      int sub()
      {
            int c;
            c=a-b;
            return c;
      }

};
int main()
{
      Arithmetic a(10,5);
      cout<<"Sum of the number: "<<a.add()<<endl;
      cout<<"Subtract of the number: "<<a.sub();

      return 0;
}
*/