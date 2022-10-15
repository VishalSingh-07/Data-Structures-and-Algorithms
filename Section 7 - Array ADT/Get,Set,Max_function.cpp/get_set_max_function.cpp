// Implementing Get, Set, Max, Min, Sum, Avg Function in Array

#include <iostream>
#include <stdlib.h>
using namespace std;
struct Array{
      int *A;
      int size;
      int length;
};
void Display(struct Array arr) // For Display the element of array
{
      int i;
      cout << "Elements of Array are: " << endl;
      for (i = 0; i < arr.length;i++)
      {
            cout << arr.A[i]<<" ";
      }
}
int Get(struct Array arr, int index)
{
      if(index>=0 && index<arr.length)
      {
            return arr.A[index];
      }
      return -1;
}
void Set(struct Array *arr, int index, int x)
{
      if(index>=0 && index<arr->length)
      {
            arr->A[index] = x;
      }
}
int Max(struct Array arr)
{
      int max = arr.A[0];
      int i;
      for (int i = 0; i < arr.length;i++)
      {
            if(arr.A[i]>max)
            {
                  max = arr.A[i];
            }
      }
      return max;
}
int Min(struct Array arr)
{
      int min = arr.A[0];
      int i;
      for (int i = 0; i < arr.length;i++)
      {
            if(arr.A[i]<min)
            {
                  min = arr.A[i];
            }
      }
      return min;
}
int Sum(struct Array arr)
{
      int sum = 0;
      for (int i = 0; i < arr.length;i++)
      {
            sum += arr.A[i];
      }
      return sum;
}
float Avg(struct Array arr)
{
      return (float)Sum(arr) / arr.length;
}

int main(){
      struct Array arr;
      int i,n,x;
      int min_element, max_element, sum,get_element;
      float avg;
      cout << "Enter the Size of an Array: ";
      cin >> arr.size;

      arr.A = (int *)malloc(arr.size * sizeof(int));// creating an array in heap
      arr.length = 0;

      cout << "Enter number of numbers: ";
      cin >> n;
      cout << "Enter the element of an Array:"<<endl;
      for (i = 0; i < n;i++)
      {
            cout << "Enter the value of A[" << i << "]: ";
            cin >> arr.A[i];
      }
      arr.length = n;
      Display(arr);
      int choice, index;
      label:
      cout << "\nEnter 1: For Get() -- To find the element in the array using index" << endl;
      cout << "Enter 2: For Set() -- Setting another value of element in the array at a given index" << endl;
      cout << "Enter 3: For Max() -- Finding  the Maximum element in the array"<<endl;
      cout << "Enter 4: For Min() -- Finding the Minimum element in the array"<<endl;
      cout << "Enter 5: For Sum() -- Finding the sum of the element in the array"<<endl;
      cout << "Enter 6: For Avg() -- Finding the Avg of the element in the array"<<endl;
      cout << "Enter the Choice: ";
      cin >> choice;
      switch(choice)
      {
            case 1:
                  cout << "Enter the index of the element you want to get: ";
                  cin >> index;
                  get_element=Get(arr, index);
                  cout << "The element at index " << index << " is: " << get_element;
                  break;
            case 2:
                  cout << "Enter the index of the element you want to set: ";
                  cin >> index;
                  cout << "Enter the value of element to be set: ";
                  cin >> x;
                  Set(&arr, index,x);
                  Display(arr);
                  break;
            
            case 3:
                  max_element = Max(arr);
                  cout << "Maxiumum element in the array is: " << max_element;
                  break;
            
            case 4:
                  min_element = Min(arr);
                  cout << "Minumum element in the array is: " << min_element;
                  break;
            
            case 5:
                  sum = Sum(arr);
                  cout << "Sum of the Array is : " << sum;
                  break;
            
            case 6:
                  avg = Avg(arr);
                  cout << "Average of the Array is : " << avg;
                  break;
                  
            default:
                  cout << "Wrong Choice";
      }
      cout << "\nPress 1: To continue"<<endl;
      cout << "Press 2: To exit"<<endl;
      int choice2;
      cin >> choice2;
      if(choice2==1){
            goto label;
      }
      else{
            exit(0);
      }

      return 0;
}