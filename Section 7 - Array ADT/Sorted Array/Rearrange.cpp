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
void Rearrange(struct Array *arr) // arranging negative value of element in the left and positive value of element in the right side of array
{
      int i, j;
      i = 0;
      j = arr->length - 1;
      while(i<j)
      {
            while(arr->A[i]<0) // Stop when it found positive number
            {
                  i++;
            }
            while(arr->A[j]>=0) // Stop when it found negative number
            {
                  j--;
            }
            if(i<j) // Swapping the value of element 
            { 
                  swap(&arr->A[i], &arr->A[j]); // 
            }
      }
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

      cout << "\n Rearrange an array : (Negative on left side and Positive on right side) -- " << endl;
      Rearrange(&arr);
      Display(arr);      
      return 0;
}