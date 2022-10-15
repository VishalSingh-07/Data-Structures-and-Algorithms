// Checking if array is sorted or not 
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Array{
      int *A;
      int size;
      int length;
};
void Display(struct Array arr) // For Display the element of array
{
      int i;
      cout << "\nElements of Array are: " << endl;
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


int main(){
      struct Array arr1, arr2, *arr3;
      int i,m,n,x,choice;
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


      if(isSorted(arr1)!=isSorted(arr2))
      {
            cout << "\nElement is not sorted, merging of an array is only work in sorted array"<<endl;
      }
      else
      {
            arr3=Merge(&arr1, &arr2);
            Display(*arr3);
      }


      
      return 0;
}
/*
Output:
Enter the Size of an Array A: 10
Enter number of numbers in Array A: 5
Enter the element of an Array A:
Enter the value of A[0]: 2
Enter the value of A[1]: 6
Enter the value of A[2]: 10
Enter the value of A[3]: 15
Enter the value of A[4]: 25

Elements of Array are: 
2 6 10 15 25 
Enter the Size of an Array B: 10
Enter number of numbers of element in Array B: 5
Enter the element of an Array B:
Enter the value of B[0]: 3
Enter the value of B[1]: 4
Enter the value of B[2]: 7
Enter the value of B[3]: 18
Enter the value of B[4]: 20

Elements of Array are: 
3 4 7 18 20 
Elements of Array are: 
2 3 4 6 7 10 15 18 20 25
*/