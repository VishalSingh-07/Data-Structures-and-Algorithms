// Implementing a Binary Search 
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
int BinarySearch(struct Array arr, int key)
{
      int mid,l,h;
      l = 0;
      h = arr.length-1;
      while(l<=h)
      {
            mid = (l + h) / 2;
            if(key==arr.A[mid])
            {
                  return mid;
            }
            else if(key<arr.A[mid])
            {
                  h=mid-1;
            }
            else if(key>arr.A[mid])
            {
                  l=mid+1;
            }
      }
      return -1;
}
int Recursive_BinarySearch(int arr[], int l, int h, int key)
{
      int mid;
      if(l<=h)
      {
            mid = (l + h) / 2;
            if(key==arr[mid])
            {
                  return mid;
            }
            else if(key<arr[mid])
            {
                  return Recursive_BinarySearch(arr, l, mid - 1, key);
            }
            else if(key>arr[mid])
            {
                  return Recursive_BinarySearch(arr, mid+1, h, key);
            }
      }
      return -1;
} 
int main()
{
      int choice,result;
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
      cout << "\nEnter 1: For Binary Search using Iterative Method"<<endl;
      cout << "Enter 2: For Binary Search using Recursive Method"<<endl;
      cout << "Enter the Choice: ";
      cin >> choice;
      switch(choice)
      {
            case 1:
                  result = BinarySearch(arr, key);
                  break;
            case 2:
                  result = Recursive_BinarySearch(arr.A, 0, arr.length-1, key);
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
}