## Insertion Sort

Insertion sort is a simple sorting algorithm that works similarly to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed in the correct position in the sorted part.

### Insertion Sort Algorithm

To sort an array of size N in ascending order iterate over the array and compare the current element (key) to its predecessor, if the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.

Working of Insertion Sort algorithm
Consider an example: `arr[]: {12, 11, 13, 5, 6}`

| 12 | 11 | 13 | 5 | 6 |
|----|----|----|---|---|

 
#### First Pass:

Initially, the first two elements of the array are compared in insertion sort.

| 12 | 11 | 13 | 5 | 6 |
|----|----|----|---|---|


Here, **12 is greater than 11** hence they are not in the ascending order and 12 is not at its correct position. Thus, swap 11 and 12.
So, for now 11 is stored in a sorted sub-array.

| 11 | 12 | 13 | 5 | 6 |
|----|----|----|---|---|
   

#### Second Pass:

Now, move to the next two elements and compare them

| 11 | 12 | 13 | 5 | 6 |
|----|----|----|---|---|


Here, **13 is greater than 12**, thus both elements seems to be in ascending order, hence, no swapping will occur. 12 also stored in a sorted sub-array along with 11

#### Third Pass:

Now, two elements are present in the sorted sub-array which are 11 and 12

Moving forward to the next two elements which are 13 and 5

| 11 | 12 | 13 | 5 | 6 |
|----|----|----|---|---|


Both 5 and 13 are not present at their correct place so swap them

| 11 | 12 | 5 | 13 | 6 |
|----|----|----|---|---|
  

After swapping, elements 12 and 5 are not sorted, thus swap again

| 11 | 5 | 12 | 13 | 6 |
|----|----|----|---|---|


Here, again 11 and 5 are not sorted, hence swap again

| 5 | 11 | 12 | 13 | 6 |
|----|----|----|---|---| 

Here, `5` is at its correct position


#### Fourth Pass:

Now, the elements which are present in the sorted sub-array are 5, 11 and 12

Moving to the next two elements 13 and 6

| 5 | 11 | 12 | 13 | 6 |
|----|----|----|---|---| 


Clearly, they are not sorted, thus perform swap between both

| 5 | 11 | 12 | 6 | 13 |
|---|----|----|---|----| 


Now, 6 is smaller than 12, hence, swap again

| 5 | 11 | 6 | 12 | 13 |
|---|----|---|----|----| 
  

Here, also swapping makes 11 and 6 unsorted hence, swap again

| 5 | 6  | 11 | 12 | 13 |
|---|----|----|----|----| 
  

Finally, **the array is completely sorted.**

#### Code
```cpp
#include <bits/stdc++.h>
using namespace std;
void InsertionSort(vector<int> &arr, int n)
{
      int i,j,x;
      for(i=1;i<n;i++)
      {
            j=i-1;
            x=arr[i];
            while(j>-1 && arr[j]>x)
            {
                  arr[j+1]=arr[j];
                  j--;
            }
            arr[j+1]=x;
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
      InsertionSort(arr,n);
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



#### Complexity Analysis of Insertion Sort:

**Time Complexity:** O(n<sup>2</sup>)

**Auxiliary Space:** O(1)

**Characteristics of Insertion Sort**

* This algorithm is one of the simplest algorithms with a simple implementation
* Basically, Insertion sort is efficient for small data values
* `Insertion sort is adaptive in nature`, i.e. it is appropriate for data sets that are already partially sorted.