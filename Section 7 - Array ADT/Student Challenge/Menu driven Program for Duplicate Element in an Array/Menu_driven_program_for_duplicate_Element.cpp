// Menu Driven Program for Duplicate Element in an Array
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
void Duplicate_sorted(struct Array arr)
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

void Duplicate_unsorted(struct Array arr)
{
      int i,j;
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
void Duplicate_Hashing(struct Array arr) // Finding Duplicate element using Hashing
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


int main()
{
      struct Array arr;
      int i,n,choice;
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

      cout << "\nEnter 1: Finding Duplicate using simple Method" << endl;
      cout << "Enter 2: Finding Duplicate using Hashing Method" << endl;
      cout << "Enter Choice: ";
      cin >> choice;

      switch(choice)
      {
            case 1:
                  if(isSorted(arr)==1)
                  {
                        cout << "Array is Sorted" << endl;
                        cout << "\nDuplicate Element in an Array are: ";
                        Duplicate_sorted(arr);
                        cout << "\nNumber of Times Duplicate Value Occurs" << endl;
                        counting(arr);
                  }
                  else
                  {
                        cout << "Array is UnSorted" << endl;
                        cout<< "\nNumber of Times Duplicate Value Occurs" << endl;
                        Duplicate_unsorted(arr);

                  }
                  break;
            case 2:
                  cout<< "\nNumber of Times Duplicate Value Occurs" << endl;
                  Duplicate_Hashing(arr);
                  break;

            default:
                  cout << "Wrong Choice";
      }

      

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
Enter 1: Finding Duplicate using simple Method
Enter 2: Finding Duplicate using Hashing Method
Enter Choice: 2

Number of Times Duplicate Value Occurs
6 is duplicated 3 times
8 is duplicated 2 times
*/
