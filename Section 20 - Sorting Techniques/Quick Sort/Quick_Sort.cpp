#include <bits/stdc++.h>
using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) 
{
      int pivot = arr[low];
      int i = low, j = high;
      do {
            // Find element on the left side greater than the pivot
            do {
                  i++;
            } while (arr[i] <= pivot);

            // Find element on the right side smaller than the pivot
            do {
                  j--;
            } while (arr[j] > pivot);

            // Swap elements if they are out of place
            if (i < j) {
                  swap(arr[i], arr[j]);
            }
      } while (i < j);

      // Swap pivot to its correct position
      swap(arr[low], arr[j]);
      return j;
}

// Recursive function to perform quicksort
void QuickSort(vector<int>& arr, int low, int high) 
{
      if (low < high) 
      {
            // Get the pivot index
            int j = partition(arr, low, high);

            // Recursively sort the subarrays
            QuickSort(arr, low, j);
            QuickSort(arr, j + 1, high);
      }
}
void Display(vector<int> arr)
{
      for(int num: arr)
      {
            cout<<num<<" ";
      }
}
int main()
{
      vector<int> arr={3,7,9,10,6,5,12,4,11,2};
      int n=arr.size();
      cout<<"Before Sorting: "<<endl;
      Display(arr);
      QuickSort(arr,0,n);
      cout<<endl;
      cout<<"After Sorting: "<<endl;
      Display(arr);
      return 0;
}

/*
Output:

Before Sorting: 
3 7 9 10 6 5 12 4 11 2 
After Sorting: 
2 3 4 5 6 7 9 10 11 12 

*/