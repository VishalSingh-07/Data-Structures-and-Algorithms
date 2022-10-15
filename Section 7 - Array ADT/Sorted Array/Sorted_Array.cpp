// Checking if array is sorted or not 
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
void swap(int *x, int *y)
{
      int temp;
      temp = *x;
      *x = *y;
      *y = temp;
}
// inserting an element in the sorted array
void InsertSort(struct Array *arr, int x)
{
      int i = arr->length - 1;
      if(arr->length==arr->size)
      {
            return;
      }
      while(i>=0 && arr->A[i]>x)// For shifting element in right side of the array for inserting an element
      {
            arr->A[i+ 1] = arr->A[i];
            i--;
      }
      arr->A[i + 1] = x; // Assigning an element in the right position
      arr->length++;
}
int isSorted(struct Array arr) // Checking whether an array is Sorted or not
{
      int i;
      for (i = 0; i < arr.length - 2;i++)
      {
            if(arr.A[i]>arr.A[i+1])
            {
                  return false;
            }

      }
      return true;
}
int main(){
      struct Array arr;
      int i,n,x,choice;
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
      label:
      cout << "\nEnter 1: Inserting an element in a array in sorted position" << endl;
      cout << "Enter 2: checking if an array is sorted" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
            case 1:
                  cout << "\nEnter the value of element to be insert: ";
                  cin >> x;
                  InsertSort(&arr, x);
                  Display(arr);
                  break;
            
            case 2:
                  if(isSorted(arr)==1)
                  {
                        cout << "\nArray is Sorted";
                  }
                  else
                  {
                        cout << "\nArray is not Sorted";
                  }
            
                  break;
      
            default:
                  cout << "Wrong Choice";
                  break;
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