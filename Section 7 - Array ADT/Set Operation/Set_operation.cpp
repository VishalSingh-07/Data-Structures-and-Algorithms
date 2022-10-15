/*
Set Operation
1. Union-- 
      The union of two sets is a set containing all elements that are in A or in B (possibly both). 
      For example, {1,2}∪{2,3}={1,2,3}. 
      Thus, we can write x∈(A∪B) if and only if (x∈A) or (x∈B). Note that A∪ B=B∪ A.
2. Intersection--
      The intersection of sets is a subset of each set forming the intersection, 
      (A ∩ B) ⊂ A and (A ∩ B) ⊂ B. 
      For example- 
      A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} , 
      B = {2, 4, 7, 12, 14} , 
      A ∩ B = {2, 4, 7}.

3. Difference--
      If A = {1, 2, 3, 4, 5, 6} and B = {3, 4, 5, 6, 7, 8}, 
      then find A – B and B – A. A – B = {1, 2} 
      since the elements 1, 2 are there in A but not in B. 
      Similarly, B – A = {7, 8}, since the elements 7 and 8 belong to B and not to A.

4. Set Membership --
      It means belong to particular array or Searching operation
*/

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


int main(){
      struct Array arr1, arr2, *arr3;
      int i,m,n,x,choice, choice2;
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
      cout <<"\nEnter 1: For Union "<<endl;
      cout << "Enter 2: For Intersection" << endl;
      cout << "Enter 3: For Difference" << endl;
      cout << "Enter 4: For SetMembership (Belong to array or not)" << endl;
      cout << "Enter 5: For Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
                  case 1:
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
                  case 2:
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
                  case 3:
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
                  case 4:

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
                  
                  case 5:

                        exit(0);

                  default:
                        cout << "Wrong Choice"<<endl;
                        break;
      }
      return 0;
}

/*
Output:--

--------------------------------------------Sorted Array------------------------------------

--------------For Union Operation---------------

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
Enter the value of B[1]: 6
Enter the value of B[2]: 7
Enter the value of B[3]: 15
Enter the value of B[4]: 20
Elements of Array are: 
3 6 7 15 20 
Enter 1: For Union 
Enter 2: For Intersection
Enter 3: For Difference
Enter 4: For Exit
Enter your choice: 1

Array A & B is Sorted Array

Union Operation (A U B)-----
Elements of Array are:
2 3 6 7 10 15 20 25



-------------------------------------------------------------------------------------------------------------------------------


------------------------ For Intersection Operation---------------

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
Enter the value of B[1]: 6
Enter the value of B[2]: 7
Enter the value of B[3]: 15
Enter the value of B[4]: 20
Elements of Array are: 
3 6 7 15 20 
Enter 1: For Union 
Enter 2: For Intersection
Enter 3: For Difference
Enter 4: For Exit
Enter your choice: 2

Array A & B is Sorted Array

Intersection Operation (A intersection B)-----
Elements of Array are:
6 15


--------------------------------------------------------------------------------------------------------------------------------


----------------------- For Difference Operation -------------------

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
Enter the value of B[1]: 6
Enter the value of B[2]: 7
Enter the value of B[3]: 15
Enter the value of B[4]: 20
Elements of Array are: 
3 6 7 15 20 
Enter 1: For Union 
Enter 2: For Intersection
Enter 3: For Difference
Enter 4: For Exit
Enter your choice: 3

Array A & B is Sorted Array

Difference Operation (A - B)-----
Elements of Array are:
2 10 25

*/