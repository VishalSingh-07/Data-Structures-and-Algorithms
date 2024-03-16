## Count Sort

Counting Sort is a non-comparison-based sorting algorithm that works well when there is limited range of input values. It is particularly efficient when the range of input values is small compared to the number of elements to be sorted. The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.


#### Counting Sort Algorithm:
* Declare an auxiliary array `countArray[]` of size `max(inputArray[])+1 `and initialize it with 0.
* Traverse array `inputArray[]` and map each element of `inputArray[]` as an index of `countArray[]` array, i.e., execute `countArray[inputArray[i]]++` for `0 <= i < N`.
* Calculate the prefix sum at every index of array `inputArray[]`.
* Create an array `outputArray[]` of size N.
* Traverse array `inputArray[]` from end and update `outputArray[ countArray[ inputArray[i] ] – 1] = inputArray[i]`. Also, update `countArray[ inputArray[i] ] = countArray[ inputArray[i] ]- –` .

#### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &arr, int n)
{
      int maximum=INT_MIN;
      for(int i=0;i<n;i++)
      {
            if(arr[i]>maximum)
            {
                  maximum=arr[i];
            }
      }
      return maximum;
}

void CountSort(vector<int>& arr, int n) 
{
      int maxi=findMax(arr,n);
      vector<int> count(maxi+1,0);
      for(int i=0;i<n;i++){
            count[arr[i]]++;
      }
      int i=0,j=0;
      while(i<maxi+1){
            if(count[i]>0){
                  arr[j++]=i;
                  count[i]--;
            }
            else{
                  i++;
            }
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
      CountSort(arr,n);
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



#### Complexity Analysis of Count Sort:

**Time Complexity:** O(n)

**Auxiliary Space:** O(Largest Element in an Array)


**Advantage of Counting Sort:**
* Counting sort generally performs faster than all comparison-based sorting algorithms, such as merge sort and quicksort, if the range of input is of the order of the number of input.
* Counting sort is easy to code
* Counting sort is a stable algorithm.


**Disadvantage of Counting Sort:**
* Counting sort doesn’t work on decimal values.
* Counting sort is inefficient if the range of values to be sorted is very large.
* Counting sort is not an In-place sorting algorithm, It uses extra space for sorting the array elements.