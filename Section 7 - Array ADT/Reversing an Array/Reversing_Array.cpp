// Write a program to implement reversing an array

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
// First Method:-- By taking an auxiliary array
void Reverse(struct Array *arr)
{
      int *B;
      int i, j;
      B = (int *)malloc(arr->length*sizeof(int)); // Auxiliart array in heap
      for (i = arr->length - 1, j = 0; i >= 0;i--,j++) // Copy the element of A into B in reverse order
      {
            B[j] = arr->A[i];
      }
      for (i = 0; i < arr->length; i++) // Assiging the value of B[i] to A[i]
      {
            arr->A[i] = B[i];
      }
}

// Second Method: -- 
void Reverse2(struct Array *arr)
{
      int i, j;
      for (i = 0, j = arr->length - 1; i < j;i++,j--)
      {
            swap(&arr->A[i], &arr->A[j]);
      }
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

      // cout << "\nReversing an Array using Method 1: " << endl;
      // Reverse(&arr);
      // Display(arr);

      cout << "\nReversing an Array using Method 2: " << endl;
      Reverse2(&arr);
      Display(arr);

      return 0;
}