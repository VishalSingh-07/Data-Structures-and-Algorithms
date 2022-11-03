// Finding a pair of elements with sum k in sorted array
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

void Pair_element_Sorted(struct Array arr, int k) // Time complexity = O(n^2)
{
      int i, j;
      i = 0, j = arr.length - 1;
      while(i<j)
      {
            if(arr.A[i] + arr.A[j] == k)
            {
                  cout << arr.A[i] << " and " << arr.A[j] << " sum is equal to " << k << endl;
                  i++;
                  j--;
            }
            if(arr.A[i] + arr.A[j] < k)
            {
                  i++;
            }
            else // arr.A[i] + arr.A[j] > k
            {
                  j--;
            }
      }
}
// void Pair_element_Sorted_loop(struct Array arr, int k) // Time complexity = O(n^2)
// {
//       int i, j;
//       for (i = 0, j = arr.length - 1; i < j;)
//       {
//             if(arr.A[i] + arr.A[j] == k)
//             {
//                   cout << arr.A[i] << " and " << arr.A[j] << " sum is equal to " << k << endl;
//                   i++;
//                   j--;
//             }
//             if(arr.A[i] + arr.A[j] < k)
//             {
//                   i++;
//             }
//             else // arr.A[i] + arr.A[j] > k
//             {
//                   j--;
//             }
//       }
// }

void Pair_element_Hashing_sorted(struct Array arr, int k) // Time complexity = O(n)
{
      int h = max(arr);
      int l = min(arr);
      int H[h+1] = {0};
      // Size of the hash array is (max_element in an array + 1)
     
      for (int i = 0; i < arr.length;i++)
      {
            int index = k - arr.A[i];
            if(index>=0 && H[index]!=0) // First check whether its a valid index 
            {
                  cout << arr.A[i] << " and " << k - arr.A[i] << " sum is equal to " << k << endl;

            }
            H[arr.A[i]]++;
      }
      
}
int main()
{
      struct Array arr;
      int i,n,choice,k;
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
      cout << "\nEnter the sum of element (k):  ";
      cin >> k;    

      cout << "\nEnter 1: Finding Pair Element with sum k using simple Method" << endl;
      cout << "Enter 2: Finding Pair Element with sum k using Hashing Method" << endl;
      cout << "Enter Choice: ";
      cin >> choice;



      switch(choice)
      {
            case 1:
                  if(isSorted(arr)==1)
                  {
                        Pair_element_Sorted(arr,k);
                  }
                  else
                  {
                        cout << "\nArray is not Sorted" << endl;
                  }
                  
                  break;
            case 2:
                  if(isSorted(arr)==1)
                  {
                        Pair_element_Hashing_sorted(arr, k);
                  }
                  else
                  {
                        cout << "\nArray is not Sorted" << endl;
                  }
                  break;

            default:
                  cout << "Wrong Choice";
      }

      

      return 0;
}

/*
Output:--
Enter the Size of an Array: 15
Enter number of numbers: 10
Enter the element of an Array:
Enter the value of A[0]: 1
Enter the value of A[1]: 3
Enter the value of A[2]: 4
Enter the value of A[3]: 5
Enter the value of A[4]: 6
Enter the value of A[5]: 8
Enter the value of A[6]: 9
Enter the value of A[7]: 10
Enter the value of A[8]: 12
Enter the value of A[9]: 14
Elements of Array are: 
1 3 4 5 6 8 9 10 12 14
Enter the sum of element (k):  10

Enter 1: Finding Pair Element with sum k using simple Method
Enter 2: Finding Pair Element with sum k using Hashing Method
Enter Choice: 1
1 and 9 sum is equal to 10
4 and 6 sum is equal to 10
*/