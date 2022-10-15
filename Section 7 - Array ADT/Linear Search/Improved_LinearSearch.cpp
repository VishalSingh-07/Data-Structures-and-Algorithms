// Implementing Linear Search
#include <iostream>
using namespace std;
struct Array {
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

int TranspositionLinearSearch(struct Array *arr, int key)
{
      int i;
      for (i = 0; i < arr->length;i++)
      {
            if(key==arr->A[i])
            {
                  swap(&arr->A[i], &arr->A[i - 1]);
                  return i - 1;
            }

      }
      return -1;
}
int Move_to_first_LinearSearch(struct Array *arr, int key)
{
      int i;
      for (i = 0; i < arr->length;i++)
      {
            if(key==arr->A[i])
            {
                  swap(arr->A[i], arr->A[0]);
                  return 0;
            }

      }
      return -1;
}
int main()
{
      struct Array arr;
      int i,n,key,choice,result;
      cout << "Enter the Size of an Array: ";
      cin >> arr.size;

      arr.A = (int *)malloc(arr.size * sizeof(int));// creating an array in heap
      arr.length = 0;

      cout << "Enter number(element) of numbers: ";
      cin >> n;
      cout << "Enter the element of an Array:"<<endl;
      for (i = 0; i < n;i++)
      {
            cout << "Enter the value of A[" << i << "]: ";
            cin >> arr.A[i];
      }
      arr.length = n; 
      Display(arr);

      cout << "\nEnter the element to be search in a array: ";
      cin >> key;
      cout << "Enter 1: For Transposition Linear Search Method"<<endl;
      cout << "Enter 2: For Move to first/head Linear Search Method"<<endl;
      cout << "Enter the choice: ";
      cin >> choice;
      switch(choice)
      {
            case 1: 
                  result = TranspositionLinearSearch(&arr, key);
                  break;
            case 2:
                  result = Move_to_first_LinearSearch(&arr, key);
                  break;
            default:
                  cout << "Wrong Choice";
      }
      if(result!=-1)
      {
            cout << "The element " << key << " is found at index " << result;
      }
      else
      {
            cout << "Element is not Found!!!";
      }
      Display(arr);
      return 0;
}