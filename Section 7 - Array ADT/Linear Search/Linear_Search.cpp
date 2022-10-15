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
int LinearSearch(struct Array arr, int key)
{
      int i;
      for (i = 0; i < arr.length;i++)
      {
            if(key==arr.A[i])
            {
                  return i;
            }

      }
      return -1;
}
int main()
{
      struct Array arr;
      int i,n,key;
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
      int result=LinearSearch(arr, key);
      if(result!=-1)
      {
            cout << "The element " << key << " is found at index " << result;
      }
      else
      {
            cout << "Element is not Found!!!";
      }

      return 0;
}