## Quick Sort

QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

#### Code
```cpp
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
```

**Output**
``` 
Before Sorting: 
3 7 9 10 6 5 12 4 11 2 
After Sorting: 
2 3 4 5 6 7 9 10 11 12 
```



#### Complexity Analysis of Quick Sort:

**Time Complexity:**
*  **Case 1: When pivot element is first element**
   * Best Case: if partitioning is in middle [O(nlogn)]
   * Worst Case: if partitioning is on any end [O(n<sup>2</sup>)] (Already Sorted)
   * Average Case: O(nlogn)
  
*  **Case 2: When pivot element is middle element**
   * Best Case: [O(nlogn)] (Sorted List)
   * Worst Case:[O(n<sup>2</sup>)] (partitioning at any end)
   * Average Case: O(nlogn)

**Auxiliary Space:** O(1)


**Advantages of Quick Sort:**
* It is a divide-and-conquer algorithm that makes it easier to solve problems.
* It is efficient on large data sets.
* It has a low overhead, as it only requires a small amount of memory to function.

**Disadvantages of Quick Sort:**
* It has a worst-case time complexity of O(n<sup>2</sup>), which occurs when the pivot is chosen poorly.
* It is not a good choice for small data sets.
* It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot’s position (without considering their original positions).