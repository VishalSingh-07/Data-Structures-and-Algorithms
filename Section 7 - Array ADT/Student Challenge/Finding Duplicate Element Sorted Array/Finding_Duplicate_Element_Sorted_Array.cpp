// Finding the Duplicate element in an sorted array and counting duplicate element in sorted array
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

void Duplicate(struct Array arr)
{
      if(isSorted(arr)==1)
      {
            int lastduplicate = 0;
            for (int i = 0; i < arr.length;i++)
            {
                  if((arr.A[i]==arr.A[i+1] )&& (arr.A[i]!=lastduplicate))
                  {
                        
                        cout << arr.A[i]<<" ";
                        lastduplicate = arr.A[i];
      
                  }
            }

      }
      else
      {
            cout << "\nArray is unsorted" << endl;
      }
      
}

void counting(struct Array arr)
{
      if(isSorted(arr)==1)
      {
            int i, j;
            for (i = 0; i < arr.length - 1;i++)
            {
                  if(arr.A[i]==arr.A[i+1])
                  {
                        j = i + 1;
                        while(arr.A[j]==arr.A[i])
                        {
                              j++;
                        }
                        cout << arr.A[i] << " is appearing " << j - i << " times" << endl;
                        i = j - 1;
                  }
            }
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
      cout << "\nDuplicate Element in an Array are: ";
      Duplicate(arr);
      cout << "\nNumber of Times Duplicate Value Occurs" << endl;
      counting(arr);

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
Duplicate Element in an Array are: 8 15
Number of Times Duplicate Value Occurs
8 is appearing 2 times
15 is appearing 3 times
*/

