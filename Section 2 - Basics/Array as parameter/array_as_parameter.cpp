// Array cannot be passed by value, It always passed by address.
// Some compiler don't allow [], replace [] with *
#include <iostream>
using namespace std;
void func(int *a, int n)
{
      
      cout<<"Size of the array: "<<(sizeof(a)/sizeof(int))<<endl;
      
      // for(int s: a)
      // {
      //       cout<<s<<endl;
      // } we cannot use for each loop for pointer but we can use for array
      for(int i=0;i<n;i++)
      {
            cout<<a[i]<<endl;
      }
}
/*
Another way of writing this function
void func(int a[], int n)
{
      
      cout<<"Size of the array: "<<(sizeof(a)/sizeof(int))<<endl;
      
}
*/
void func1(int *a,int n)
{
      a[0]=25; // Changing the value of the array at index 0.
      a[1]=44;
      a[2]=25;

}
int main()
{
      int a[]={2,4,6,8,10};
      int n=5;

      for(int x: a)
      {
            cout<<x<<endl;
      }
      func1(a,n);

      func(a,n);
      
}