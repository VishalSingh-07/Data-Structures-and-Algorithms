// Menu Driven Program for arrays Operation

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
void Append(struct Array *arr, int x) // Adding a new element at the end of the array
{
      if(arr->length<arr->size)
      {
            arr->A[arr->length++] = x;
      }


}

void Insert(struct Array *arr, int index, int x) // Adding a new element at a given index 
{
      int i;
      if(index>=0 && index<=arr->length){
            for (i= arr->length; i > index;i--)
            {
                  arr->A[i] = arr->A[i - 1];
            }
            arr->A[index] = x;
            arr->length++;
      }

}

int  Delete(struct Array *arr, int index) // Deleting an element from an array
{
      int x = 0;
      if(index>=0 && index<=arr->length)
      {
            x = arr->A[index];
            for (int i = index; i < arr->length + 1;i++)
            {
                  arr->A[i] = arr->A[i + 1];
            }
            arr->length--;
            return x;
      }
      return 0;
}
void swap(int *x, int *y)
{
      int temp;
      temp = *x;
      *x = *y;
      *y = temp;
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
int Get(struct Array arr, int index)
{
      if(index>=0 && index<arr.length)
      {
            return arr.A[index];
      }
      return -1;
}
void Set(struct Array *arr, int index, int x)
{
      if(index>=0 && index<arr->length)
      {
            arr->A[index] = x;
      }
}
int Max(struct Array arr)
{
      int max = arr.A[0];
      int i;
      for (int i = 0; i < arr.length;i++)
      {
            if(arr.A[i]>max)
            {
                  max = arr.A[i];
            }
      }
      return max;
}
int Min(struct Array arr)
{
      int min = arr.A[0];
      int i;
      for (int i = 0; i < arr.length;i++)
      {
            if(arr.A[i]<min)
            {
                  min = arr.A[i];
            }
      }
      return min;
}
int Sum(struct Array arr)
{
      int sum = 0;
      for (int i = 0; i < arr.length;i++)
      {
            sum += arr.A[i];
      }
      return sum;
}
float Avg(struct Array arr)
{
      return (float)Sum(arr) / arr.length;
}
// First Method:-- By taking an auxiliary array
void Reverse(struct Array *arr)
{
      int *B;
      int i, j;
      B = (int *)malloc(arr->length*sizeof(int)); // Auxiliart array in heap
      for (i = arr->length - 1, j = 0; i >= 0;i--,j++) // Copy the element of A into B in reverse order
      {
            B[j] = arr->A[i];
      }
      for (i = 0; i < arr->length; i++) // Assiging the value of B[i] to A[i]
      {
            arr->A[i] = B[i];
      }
}

// Second Method: -- 
void Reverse2(struct Array *arr)
{
      int i, j;
      for (i = 0, j = arr->length - 1; i < j;i++,j--)
      {
            swap(&arr->A[i], &arr->A[j]);
      }
}
// inserting an element in the sorted array
void InsertSort(struct Array *arr, int x)
{
      int i = arr->length - 1;
      if(arr->length==arr->size)
      {
            return;
      }
      while(i>=0 && arr->A[i]>x)// For shifting element in right side of the array for inserting an element
      {
            arr->A[i+ 1] = arr->A[i];
            i--;
      }
      arr->A[i + 1] = x; // Assigning an element in the right position
      arr->length++;
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
void Rearrange(struct Array *arr) // arranging negative value of element in the left and positive value of element in the right side of array
{
      int i, j;
      i = 0;
      j = arr->length - 1;
      while(i<j)
      {
            while(arr->A[i]<0) // Stop when it found positive number
            {
                  i++;
            }
            while(arr->A[j]>=0) // Stop when it found negative number
            {
                  j--;
            }
            if(i<j) // Swapping the value of element 
            { 
                  swap(&arr->A[i], &arr->A[j]); // 
            }
      }
}


struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
      int i, j,k;
      i = j = k = 0;
      struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

      while(i<arr1->length && j<arr2->length)
      {
            if(arr1->A[i]<arr2->A[j])
            {
                  arr3->A[k++] = arr1->A[i++];
            }
            else
            {
                  arr3->A[k++] = arr2->A[j++];

            }
      }
      for (; i < arr1->length;i++)
      {
            arr3->A[k++] = arr1->A[i++];
      }
      for (; j < arr2->length;j++)
      {
            arr3->A[k++] = arr2->A[j++];
      }
      arr3->length = arr1->length + arr2->length;
      arr3->size = arr1->size + arr2->size;

      return arr3;
}
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
      int i, j,k;
      i = j = k = 0;
      struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

      while(i<arr1->length && j<arr2->length)
      {
            if(arr1->A[i]<arr2->A[j]) // When array A element is greater than array b element
            {
                  arr3->A[k++] = arr1->A[i++];
            }
            else if(arr1->A[i] ==arr2->A[j]) // If element is same on both the array, we will not take it.
            {
                  arr3->A[k++] = arr1->A[i++];
                  j++;
            }
            else // When array B element is greater than array A element
            {
                  arr3->A[k++] = arr2->A[j++];

            }
      }
      for (; i < arr1->length;i++)
      {
            arr3->A[k++] = arr1->A[i++];
      }
      for (; j < arr2->length;j++)
      {
            arr3->A[k++] = arr2->A[j++];
      }
      arr3->length = k;
      arr3->size = arr1->size + arr2->size;

      return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
      int i, j,k;
      i = j = k = 0;
      struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

      while(i<arr1->length && j<arr2->length)
      {
            if(arr1->A[i]<arr2->A[j]) // When array A element is greater than array b element
            {
                  i++;
            }
            else if(arr1->A[i] ==arr2->A[j]) // If element is same on both the array, we will not take it.
            {
                  arr3->A[k++] = arr1->A[i++];
                  j++;
            }
            else // When array B element is greater than array A element
            {
                  j++;
            }
      }
      arr3->length = k;
      arr3->size = arr1->size + arr2->size;

      return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
      int i, j,k;
      i = j = k = 0;
      struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

      while(i<arr1->length && j<arr2->length)
      {
            if(arr1->A[i]<arr2->A[j]) // When array A element is greater than array b element
            {
                  arr3->A[k++] = arr1->A[i++];
            }
            else if(arr1->A[i] ==arr2->A[j]) // If element is same on both the array, we will not take it.
            {
                  i++;
                  j++;
            }
            else // When array B element is greater than array A element
            {
                  j++;
            }
      }
      for (; i < arr1->length;i++)
      {
            arr3->A[k++] = arr1->A[i++];
      }
      arr3->length = k;
      arr3->size = arr1->size + arr2->size;

      return arr3;
      
}

bool setMembership(struct Array arr, int key)
{
      int i;
      for (i = 0; i < arr.length;i++)
      {
            if(key==arr.A[i])
            {
                  return true;
            }

      }
      return false;

}
// searching in the array
bool elementPresentOrNot(int arr[], int l, int x)
{
    for(int i=0; i<l; i++)
    {
        if(arr[i]==x)
            return true;
    }
    return false;
}

// For unsorted Array

/*
For Union in unsorted Array:
First  copy all the elements of A to C and then
copy those element of B in C that is 
not present in c
*/
struct Array* unionOnUnsortedArray(struct Array *arr1,struct Array *arr2)
{
      int i,j,k;
      i = j = k = 0;
      struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
      for (i; i < arr1->length;i++)
      {
            arr3->A[k++] = arr1->A[i];
            arr3->length++;
      }

      for (j; j < arr2->length;j++)
      {
            if(!elementPresentOrNot(arr3->A,arr3->length,arr2->A[j]))
            {
                  arr3->A[k++] = arr2->A[j];
                  arr3->length++;
            }
      }
      return arr3;
}

/*
Intersection approach for unsorted array --
copy those element of  A to C which is present in B.
*/
struct Array* intersectionOnUnsortedArray(struct Array *arr1,struct Array *arr2)
{
      int i, j, k;
      k = 0;
      struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
      for (i = 0; i < arr1->length;i++)
      {
            if (elementPresentOrNot(arr2->A, arr2->length,arr1->A[i]))
            {
                  arr3->A[k++] = arr1->A[i];
                  arr3->length++;
            }
      }
      return arr3;
}

/*
Differnece approach for unsorted array
Copy those element of A to C which is not present in B.
*/
struct Array* differenceOnUnsortedArray(struct Array *arr1,struct Array *arr2)
{
      int i, j, k;
      k = 0;
      struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
      for (i = 0; i < arr1->length;i++)
      {
            if (!elementPresentOrNot(arr2->A, arr2->length,arr1->A[i]))
            {
                  arr3->A[k++] = arr1->A[i];
                  arr3->length++;
            }
      }
      return arr3;
}

int main()
{
      struct Array arr1,arr2,*arr3;
      int i,m,n,x,choice,choice2,index,result,key;
      int min_element, max_element, sum,get_element;
      float avg;
      cout << "Enter the Size of an Array A: ";
      cin >> arr1.size;

      arr1.A = (int *)malloc(arr1.size * sizeof(int));// creating an array in heap
      arr1.length = 0;

      cout << "Enter number of numbers in Array A: ";
      cin >> m;
      cout << "Enter the element of an Array A:"<<endl;
      for (i = 0; i < m;i++)
      {
            cout << "Enter the value of A[" << i << "]: ";
            cin >> arr1.A[i];
      }
      arr1.length = m;
      Display(arr1);

      cout << "\nEnter the Size of an Array B: ";
      cin >> arr2.size;

      arr2.A = (int *)malloc(arr2.size * sizeof(int));// creating an array in heap
      arr2.length = 0;

      cout << "Enter number of numbers of element in Array B: ";
      cin >> n;
      cout << "Enter the element of an Array B:"<<endl;
      for (i = 0; i < n;i++)
      {
            cout << "Enter the value of B[" << i << "]: ";
            cin >> arr2.A[i];
      }
      arr2.length = n;
      Display(arr2);
      cout << "\nEnter 1: To Insert an element in an Array"<<endl;
      cout << "Enter 2: To Append an element in an Array" << endl;
      cout << "Enter 3: To Delete an element in an Array" << endl;
      cout << "Enter 4: For Searching an element using Binary Search " << endl;
      cout << "Enter 5: For Searching an element using Recursive Binary Search" << endl;
      cout << "Enter 6:To Get an element" << endl;
      cout << "Enter 7: To Set an element" << endl;
      cout << "Enter 8: To find max element in an Array" << endl;
      cout << "Enter 9: To find min element in an Array" << endl;
      cout << "Enter 10: To find sum of the  element in an Array" << endl;
      cout << "Enter 11: To find averge of element in an Array" << endl;
      cout << "Enter 12: To Reverse an Array"<<endl;
      cout << "Enter 13: Insert an element in sorted way" << endl;
      cout << "Enter 14: To Check an array is sorted or not" << endl;
      cout << "Enter 15: Merge two array" << endl;
      cout <<"Enter 16: For Union "<<endl;
      cout << "Enter 17: For Intersection" << endl;
      cout << "Enter 18: For Difference" << endl;
      cout << "Enter 19: For SetMembership (Belong to array or not)" << endl;
      cout << "Enter 20: For Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
                  case 1:
                        cout << "\nWhich Array you want to be Insert--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              cout << "\nWant to add new element at a given index : ---" << endl;
                              cout << "Enter the new element which you want to insert into array: ";
                              cin >> x;
                              cout << "Enter the index which you want to add yours element: ";
                              cin >> index;
                              Insert(&arr1, index,x);
                              Display(arr1);

                        }
                        else
                        {
                              cout << "\nWant to add new element at a given index : ---" << endl;
                              cout << "Enter the new element which you want to insert into array: ";
                              cin >> x;
                              cout << "Enter the index which you want to add yours element: ";
                              cin >> index;
                              Insert(&arr2, index,x);
                              Display(arr2);
                        }
                        break;
                  case 2:
                        cout << "\nWhich Array you want to be Append--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              cout << "\nWant to add new element in the array 1: ---" << endl;
                              cout << "Enter the new element which you want to insert into array 1: ";
                              cin >> x;
                              Append(&arr1, x);
                              Display(arr1);

                        }
                        else
                        {
                              cout << "\nWant to add new element in the array 2: ---" << endl;
                              cout << "Enter the new element which you want to insert into array 2: ";
                              cin >> x;
                              Append(&arr2, x);
                              Display(arr2);

                        }
                        
                        break;
                  case 3:

                        cout << "\nWhich Array you want to be Delete an element--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              cout << "\nWant to delete an element at a given index : ---" << endl;
                              cout << "Enter the index which you want to delete yours element: ";
                              cin >> index;
                              int result=Delete(&arr1, index);
                              if(result!=0)
                              {
                                    cout << result << " is successfully delete from an Array"<<endl;
                              }
                              else
                              {
                                    cout << "Wrong Index. Please! Give the Correct Index"<<endl;
                              }
                              Display(arr1);

                        }
                        else
                        {
                              cout << "\nWant to delete an element at a given index : ---" << endl;
                              cout << "Enter the index which you want to delete yours element: ";
                              cin >> index;
                              int result=Delete(&arr2, index);
                              if(result!=0)
                              {
                                    cout << result << " is successfully delete from an Array"<<endl;
                              }
                              else
                              {
                                    cout << "Wrong Index. Please! Give the Correct Index"<<endl;
                              }
                              Display(arr2);
                        }


                        break;
                  case 4:
                        cout << "\nWhich Array you want to be search an element--";
                        cout << "\nEnter the element to be search in a array: ";
                        cin >> key;
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        if(choice2==1)
                        {
                              result = BinarySearch(arr1, key);
                        }
                        else
                        {
                              result = BinarySearch(arr1, key);

                        }
                        if(result!=-1)
                        {
                              cout << "The element " << key << " is found at index " << result;
                        }
                        else
                        {
                              cout << "Element is not Found!!!";
                        }
                  
                        break;
                  case 5:

                        cout << "\nWhich Array you want to be search an element--";
                        cout << "\nEnter the element to be search in a array: ";
                        cin >> key;
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        if(choice2==1)
                        {
                              result = Recursive_BinarySearch(arr1.A,0,arr1.length-1,key);
                        }
                        else
                        {
                              result = Recursive_BinarySearch(arr2.A,0,arr2.length-1,key);

                        }
                        if(result!=-1)
                        {
                              cout << "The element " << key << " is found at index " << result;
                        }
                        else
                        {
                              cout << "Element is not Found!!!";
                        }
                        break;
                  case 6:
                        cout << "\nWhich Array you want to be Get an element--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              cout << "Enter the index of the element you want to get: ";
                              cin >> index;
                              get_element=Get(arr1, index);
                              cout << "The element at index " << index << " is: " << get_element;

                        }
                        else
                        {
                              cout << "Enter the index of the element you want to get: ";
                              cin >> index;
                              get_element=Get(arr2, index);
                              cout << "The element at index " << index << " is: " << get_element;
                        }
                        

                        break;
                  case 7:
                        cout << "\nWhich Array you want to be Set an element--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              cout << "Enter the index of the element you want to set: ";
                              cin >> index;
                              cout << "Enter the value of element to be set: ";
                              cin >> x;
                              Set(&arr1, index,x);
                              Display(arr1);
                              

                        }
                        else
                        {
                              cout << "Enter the index of the element you want to set: ";
                              cin >> index;
                              cout << "Enter the value of element to be set: ";
                              cin >> x;
                              Set(&arr2, index,x);
                              Display(arr2);
                              
                        }
                        break;
                  case 8:

                        cout << "\nWhich Array you want to be Max an element--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              max_element = Max(arr1);
                              cout << "Maxiumum element in the array is: " << max_element;
                              

                        }
                        else
                        {
                              max_element = Max(arr2);
                              cout << "Maxiumum element in the array is: " << max_element;
                              
                        }
                        break;
                  case 9:
                        cout << "\nWhich Array you want to be Min an element--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              min_element = Min(arr1);
                              cout << "Minumum element in the array is: " << min_element;
                        }
                        else
                        {
                              min_element = Min(arr2);
                              cout << "Minumum element in the array is: " << min_element;  
                        }
                        break;
                  case 10:
                        cout << "\nWhich Array you want to be Sum of an element--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              sum = Sum(arr1);
                              cout << "Sum of the Array is : " << sum;

                        }
                        else
                        {
                              sum = Sum(arr2);
                              cout << "Sum of the Array is : " << sum;
                              
                        }
                        break;
                  case 11:
                        cout << "\nWhich Array you want to be Average of an element--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              avg = Avg(arr1);
                              cout << "Average of the Array is : " << avg;
                              

                        }
                        else
                        {
                              avg = Avg(arr2);
                              cout << "Average of the Array is : " << avg;
                              
                        }
                        break;
                  case 12:
                        cout << "\nWhich Array you want to be Reverse--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              cout << "\nReversing an Array using Method 1: " << endl;
                              Reverse(&arr1);
                              Display(arr1);
                        }
                        else
                        {
                              cout << "\nReversing an Array using Method 1: " << endl;
                              Reverse(&arr2);
                              Display(arr2);
                        }
                        break;
                  case 13:
                        cout << "\nWhich Array you want to be Insert(Sorted Position) in an element--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              if(isSorted(arr1)==1)
                              {
                                    cout << "\nEnter the value of element to be insert: ";
                                    cin >> x;
                                    InsertSort(&arr1, x);
                                    Display(arr1);
                              
                              }
                              else
                              {
                                    cout << "\n Array is unsorted array" << endl;
                              }
                        }
                        else
                        {
                              if(isSorted(arr2)==1)
                              {
                                    cout << "\nEnter the value of element to be insert: ";
                                    cin >> x;
                                    InsertSort(&arr1, x);
                                    Display(arr1);
                              }
                              else
                              {
                                    cout << "\n Array is unsorted array" << endl;

                              }

                        }
                        
                        
                        break;
                  case 14:
                        cout << "\nWhich Array you want to be Check Sorting--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              if(isSorted(arr1)==1)
                              {
                                    cout << "\nArray is Sorted";
                              }
                              else
                              {
                                    cout << "\nArray is not Sorted";
                              }

                        }
                        else
                        {
                              if(isSorted(arr2)==1)
                              {
                                    cout << "\nArray is Sorted";
                              }
                              else
                              {
                                    cout << "\nArray is not Sorted";
                              }
                        }
                        break;
                  case 15:
                        if(isSorted(arr1)!=isSorted(arr2))
                        {
                              cout << "\nElement is not sorted, merging of an array is only work in sorted array"<<endl;
                        }
                        else
                        {
                              arr3=Merge(&arr1, &arr2);
                              Display(*arr3);
                        }

                        break;
                  case 16:
                        {
                              if(isSorted(arr1)==1 && isSorted(arr2)==1)
                              {
                                    cout << "\nArray A & B is Sorted Array"<<endl;
                                    arr3 = Union(&arr1, &arr2);
                                    cout << "\nUnion Operation (A U B)-----"<<endl;
                                    Display(*arr3);
                              }
                              else
                              {
                                    int y = isSorted(arr1);
                                    int z = isSorted(arr2);
                                    cout << y << " " << z;
                                    cout << "\nArray A & B is UnSorted Array HIII"<<endl;
                                    arr3=unionOnUnsortedArray(&arr1, &arr2);
                                    cout << "\nUnion Operation (A U B)-----"<<endl;
                                    Display(*arr3);
                              }
                              break;
                        }
                  case 17:
                        {
                              if(isSorted(arr1) == 1 && isSorted(arr2)==1)
                              {
                                    cout << "\nArray A & B is Sorted Array"<<endl;
                                    arr3 = Intersection(&arr1, &arr2);
                                    cout << "\nIntersection Operation (A intersection B)-----"<<endl;
                                    Display(*arr3);
                              }
                              else
                              {
                                    cout << "\nArray A & B is UnSorted Array"<<endl;
                                    arr3 = intersectionOnUnsortedArray(&arr1, &arr2);
                                    cout << "\nIntersection Operation (A intersection B)-----"<<endl;
                                    Display(*arr3);

                              }
                              break;
                        }
                  case 18:
                        {
                              if(isSorted(arr1)==1 && isSorted(arr2)==1)
                              {
                                    cout << "\nArray A & B is Sorted Array"<<endl;
                                    arr3 = Difference(&arr1, &arr2);
                                    cout << "\nDifference Operation (A - B)-----"<<endl;
                                    Display(*arr3);
                              }
                              else
                              {
                                    cout << "\nArray A & B is UnSorted Array"<<endl;
                                    arr3 = differenceOnUnsortedArray(&arr1, &arr2);
                                    cout << "\nDifference Operation (A - B)-----"<<endl;
                                    Display(*arr3);
                              }
                              break;
                        }
                  case 19:

                        cout << "Enter the element to be search or belong: ";
                        cin >> x;

                        cout << "\nWhich Array you want to be searched--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              if(setMembership(arr1,x)==true)
                              {
                                    cout << x << " belong to the array A";
                              }
                              else
                              {
                                    cout << x << "not  belong to the array A";
                                    
                              }
                        }
                        else
                        {
                              if(setMembership(arr2,x)==true)
                              {
                                    cout << x << " belong to the array A";
                              }
                              else
                              {
                                    cout << x << "not  belong to the array A";
                                    
                              }
                        
                        }
                  
                  case 20:

                        exit(0);

                  default:
                        cout << "Wrong Choice"<<endl;
                        break;
      }

      return 0;
}