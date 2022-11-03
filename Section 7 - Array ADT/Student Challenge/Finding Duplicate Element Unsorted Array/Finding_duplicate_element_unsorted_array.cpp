// Finding Duplicate Element in a unSorted Array
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

void Duplicate_unsorted(struct Array arr)
{
      int i,j;
      if(isSorted(arr)!=1)
      {
            for (i = 0; i < arr.length - 1;i++)
            {
                  int count = 1;
                  if(arr.A[i]!=-1)
                  {
                        for (j = i + 1; j < arr.length;j++)
                        {
                              if(arr.A[i]==arr.A[j])
                              {
                                    count++;
                                    arr.A[j] = -1;
                              }
                        }
                        if(count>1)
                        {
                              cout << arr.A[i] << " is duplicated " << count << " times" << endl;
                        }
                  }
            }
      }
      else
      {
            cout << "\nArray is sorted" << endl;
      }
      
}


int main()
{
      struct Array arr;
      int i,n,x,choice;
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
      Duplicate_unsorted(arr);

      return 0;
}

/*
Output:
Enter the Size of an Array: 15
Enter number of numbers: 10
Enter the element of an Array:
Enter the value of A[0]: 8
Enter the value of A[1]: 3
Enter the value of A[2]: 6
Enter the value of A[3]: 4
Enter the value of A[4]: 6
Enter the value of A[5]: 5
Enter the value of A[6]: 6
Enter the value of A[7]: 8
Enter the value of A[8]: 2
Enter the value of A[9]: 7
Elements of Array are: 
8 3 6 4 6 5 6 8 2 7
Number of Times Duplicate Value Occurs
8 is duplicated 2 times
6 is duplicated 3 times
*/

