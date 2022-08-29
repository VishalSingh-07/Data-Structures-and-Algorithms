// Practice : Pointer
#include <iostream>
using namespace std;

struct Rectangle
{
      int length;
      int breadth;
};
int main()
{
      int a=10;
      int *p; // declaration of pointer
      cout<<"value of a: "<<a<<endl;
      
      p=&a; // accesing the address of a

      cout<<"Using Pointer, the value of a: "<<*p<<endl;
      cout<<"Address of a: "<<p<<endl;
      cout<<"Address of a: "<<&a<<endl;

      // Pointer to an Array
      // whenever you declare anything in your program, it is going to be created inside the stack frame for that function.
      int b[5]={2,4,5,67,6};
      int *c;
      c=b; // because name of the array itself is the starting address or base address.   

      // c=&b[0]; Wrong Syntax, Compiler may give error.

      for (int i=0;i<5;i++) // using for loop to printing array element
      {
            cout<<b[i]<<endl;
      }

      cout<<"Printing the array of element using pointer: "<<endl;

      for(int i=0;i<5;i++)
      {
            cout<<c[i]<<endl;

      }


      // Creating array in heap using pointer
     
      int *d;
      //d=(int*)malloc(5*sizeof(int)); // for C language
      d=new int[5]; // for c++ language
      
      d[0]=1,d[1]=12,d[2]=15, d[3]=18, d[4]=19, d[5]=90, d[7]=190;       
      
      cout<<"Printing the element of array in heap using pointer: "<<endl;
      for(int i=0;i<5;i++)
      {
            cout<<d[i]<<endl;

      }
      

      delete [] d; // it is used in c++ languages.Deleting the array of heap
      /*
      Now the next thing about dynamic allocation C. Here we have dynamically created the memory for an array in a heap.
      So by using new we made a request for memory and he so then we have finished using it.
      We should also delete that memory because we are creating an array here.
      So we should use the square brackets opening and closing square, because these are I will give us space
      */

     // free(d); // for c language
     // deallocating the memory in heap, we use delete [] p or free(p).
     
     int *p1;
     char *p2;
     float *p3;
     double *p4;
     struct Rectangle *p5;

     cout<<"Size of Pointer: "<<endl;
     cout<<sizeof(p1)<<endl;
     cout<<sizeof(p2)<<endl;
     cout<<sizeof(p3)<<endl;
     cout<<sizeof(p4)<<endl;
     cout<<sizeof(p5)<<endl;

     // Important thing
     /*
     Whatever the data type of pointer is going to take same amount of memory.
     So whatever the type of pointer may be in the latest compilers, the pointers are taking eight bytes.
     So whatever the type of pointer is, it is independent size of a point that is independent of its data type.
     */

      return 0;
}