// returning an array using pointer and malloc functino
#include <iostream>
using namespace std;
int* func(int n)
{
      int *p;
      //p=(int*)malloc(n*sizeof(int));
      p= new int[n]; // style of writing malloc function

      for(int i=0;i<n;i++)
      {
            p[i]=i+1;
      }

      return p;
}

int main()
{

      int *a;
      int s;
      cout<<"Enter the value of s: ";
      cin>>s;
      a=func(s);
      
      for(int i=0;i<s;i++)
      {
            cout<<a[i]<<endl;

      }
      return 0;

}