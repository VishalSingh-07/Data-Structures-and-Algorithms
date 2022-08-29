#include <iostream>
using namespace std;

int main()
{
      int n;
      cout<<"Enter the size of array: ";
      cin>>n;
      //   int a[n]={2,4,6,8,10,14,25}; it gives error we can't initialize an array with n but we can created; 
      int a[n];
      // a[0]=12;
      // a[1]=25;
      // a[4]=22;
      
      cout<<"Enter the element of array: "<<endl;
      for(int i=0;i<n;i++) // assigning the element of array using for loop
      {
            cout<<"Enter the value of the of the element a["<<i<<"]: ";
            cin>>a[i];
      }



      cout<<"Size of the Array: "<<sizeof(a)<<endl;
      
      cout<<a[1]<<endl;
      cout<<a[9]; // if print this it give zero as output
      
      for(int i=0;i<10;i++) // print the element of array using loop
      {
            cout<<a[i]<<endl;
      }
      
      for(int x:a) // Using for each loop to print the element of array
      {
            cout<<x<<endl;
      }


      return 0;
}