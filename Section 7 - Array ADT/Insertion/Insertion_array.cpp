// Inserting an element in an array
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

void Append(struct Array *arr, int x) // Adding a new element at the end of the array
{
      if(arr->length<arr->size)
      {
            arr->A[arr->length++] = x;
      }


}

void Insert(struct Array *arr, int index, int x) // Adding a new element at a given index 
{
      int i;
      if(index>=0 && index<=arr->length){
            for (i= arr->length; i > index;i--)
            {
                  arr->A[i] = arr->A[i - 1];
            }
            arr->A[index] = x;
            arr->length++;
      }

}
int main(){
      struct Array arr;
      int i,n,x;
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
      cout << "\nEnter 1: For adding element at the end of an array (Append)" << endl;
      cout << "Enter 2: For adding element at a given index (Insert)" << endl;
      cout << "Enter the Choice: ";
      cin >> choice;

      if(choice==1)
      {
            cout << "\nWant to add new element in the array: ---" << endl;
            cout << "Enter the new element which you want to insert into array: ";
            cin >> x;
            Append(&arr, x);
            Display(arr);

      }
      else if (choice == 2)
      {
            cout << "\nWant to add new element at a given index : ---" << endl;
            cout << "Enter the new element which you want to insert into array: ";
            cin >> x;
            cout << "Enter the index which you want to add yours element: ";
            cin >> index;
            Insert(&arr, index,x);
            Display(arr);
      }

            return 0;
}