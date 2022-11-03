// Finding Duplicate Element in an Sorted Array using Hashing
#include <iostream>
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
int max(struct Array arr)
{
      int max = arr.A[0];
      for (int i = 0; i < arr.length;i++)
      {
            if(max<arr.A[i])
            {
                  max = arr.A[i];
            }
      }
      return max;
};
int min(struct Array arr)
{
      int min = arr.A[0];
      for (int i = 0; i < arr.length;i++)
      {
            if(min>arr.A[i])
            {
                  min = arr.A[i];
            }
      }
      return min;
};
void Duplicate_Hashing(struct Array arr) // Finding Duplicate element using Hashing
{
      if(isSorted(arr)==1)
      {

            int h = max(arr);
            int l = min(arr);
            int H[h+1] = {0};
            // Size of the hash array is (max_element in an array + 1)
            for (int i = 0; i < arr.length;i++) 
            {
                  H[arr.A[i]]++;
            }
            for (int i = l; i < h+1;i++)
            {
                  if(H[i]>1)
                  {
                        cout << i << " is duplicated " << H[i]<< " times" << endl;
                  }
            }
      }
      else
      {
            cout << "\nArray is unsorted" << endl;
      }
      
}


int main()
{
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
      cout << "\nNumber of Times Duplicate Value Occurs" << endl;
      Duplicate_Hashing(arr);

      return 0;
}

/*
Output:
Enter the Size of an Array: 15
Enter number of numbers: 10
Enter the element of an Array:
Enter the value of A[0]: 3
Enter the value of A[1]: 6
Enter the value of A[2]: 8
Enter the value of A[3]: 8
Enter the value of A[4]: 10
Enter the value of A[5]: 12
Enter the value of A[6]: 15
Enter the value of A[7]: 15
Enter the value of A[8]: 15
Enter the value of A[9]: 20
Elements of Array are: 
3 6 8 8 10 12 15 15 15 20
Number of Times Duplicate Value Occurs
8 is duplicated 2 times
15 is duplicated 3 times
*/

