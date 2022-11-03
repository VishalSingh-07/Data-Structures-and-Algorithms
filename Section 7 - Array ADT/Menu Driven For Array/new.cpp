// Menu Driven Program for arrays Operation

#include <iostream>
using namespace std;
//Note:  Class name should always start with capital letters. But I'm too lazy to change the entire code so I'm leaving it it like that only.
//By contrast member names should start by small letters.
class Array{
      private:
            int *A;
            int size;
            int n;

      public:
            int length;
            Array()
            {
                  cout << "Enter the size of Array: ";
                  cin >> size;
                  cout << "Enter number of numbers in array : ";
                  cin >> n;
                  length = n;
                  A = new int[size];
            }
            Array(int sz) 
            {
                  size = sz;
                  cout << "Enter number of numbers in array : ";
                  cin >> n;
                  length = n;
                  A = new int[size];
            }
            

            ~Array()
            //This is called a destructor. They are member functions in a class that delete an object.
            //They are called when the class object goes out of scope such as when the function ends, the program ends, a delete variable is called etc
            {
                  delete[] A; //Since this gets allocated in heap it should be deleted at the end of the program. Hence we are specifying it in a destructor.
            }
            void input();
            void Display();
            void Append( int x);
            void Insert( int index, int x);
            int Delete(int index);
            void swap(int *x, int *y);
            int BinarySearch(int key);
            int Recursive_BinarySearch(int l, int h, int key);
            int Get(int index);
            void Set(int index, int x);
            int Max();
            int Min();
            int Sum();
            float Avg();
            void Reverse();
            void InsertSort(int x);
            int isSorted();
            void Rearrange();
            Array *Merge(Array arr2);
            Array *Union(Array arr2);
            Array *Intersection(Array arr2);
            Array *Difference(Array arr2);
            bool setMembership(int key);
            Array *unionOnUnsortedArray(Array arr2);
            Array *intersectionOnUnsortedArray(Array arr2);
            Array *differenceOnUnsortedArray(Array arr2);
            

};
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

void Array :: input()
{
      int i;
      cout << "Enter the element of an Array:"<<endl;
      for (i = 0; i < n;i++)
      {
            cout << "Enter the value of Arr[" << i << "]: ";
            cin >> A[i];
      }

}

void Array :: Display() // For Display the element of array
{
      int i;
      cout << "Elements of Array are: " << endl;
      for (i = 0; i < length;i++)
      {
            cout << A[i]<<" ";
      }
}
int Array :: isSorted() // Checking whether an array is Sorted or not
{
      int i;
      for (i = 0; i < length - 2;i++)
      {
            if(A[i]>A[i+1])
            {
                  return false;
            }

      }
      return true;
}
Array* Array :: Merge(Array arr2)
{
      int i, j,k;
      i = j = k = 0;
      Array *arr3 = new Array(length + arr2.length);

      while(i<length && j<arr2.length)
      {
            if(A[i] < arr2.A[j])
            {
                  arr3->A[k++] = A[i++];
            }
            else
            {
                  arr3->A[k++] = arr2.A[j++];

            }
      }
      for (; i < length;i++)
      {
            arr3->A[k++] = A[i];
      }
      for (; j < arr2.length;j++)
      {
            arr3->A[k++] = arr2.A[j];
      }
      arr3->length =length + arr2.length;
      arr3->size = size + arr2.size;

      return arr3;
}
Array* Array :: Union(Array arr2)
{
      int i, j,k;
      i = j = k = 0;
      Array *arr3 = new Array(length + arr2.length);

      while(i<length && j<arr2.length)
      {
            if(A[i]<arr2.A[j]) // When array A element is greater than array b element
            {
                  arr3->A[k++] = A[i++];
            }
            else if(A[i] ==arr2.A[j]) // If element is same on both the array, we will not take it.
            {
                  arr3->A[k++] = A[i++];
                  j++;
            }
            else // When array B element is greater than array A element
            {
                  arr3->A[k++] = arr2.A[j++];

            }
      }
      for (; i < length;i++)
      {
            arr3->A[k++] = A[i];
      }
      for (; j < arr2.length;j++)
      {
            arr3->A[k++] = arr2.A[j];
      }
      arr3->length = k;
      arr3->size = size + arr2.size;

      return arr3;
}

Array* Array :: Intersection(Array arr2)
{
      int i, j,k;
      i = j = k = 0;
      Array *arr3 = new Array(length + arr2.length);

      while(i<length && j<arr2.length)
      {
            if(A[i]<arr2.A[j]) // When array A element is greater than array b element
            {
                  i++;
            }
            else if(A[i] ==arr2.A[j]) // If element is same on both the array, we will not take it.
            {
                  arr3->A[k++] = A[i++];
                  j++;
            }
            else // When array B element is greater than array A element
            {
                  j++;
            }
      }
      arr3->length = k;
      arr3->size = size + arr2.size;

      return arr3;
}

Array* Array :: Difference(Array arr2)
{
      int i, j,k;
      i = j = k = 0;
      Array *arr3 = new Array(length + arr2.length);

      while(i<length && j<arr2.length)
      {
            if(A[i]<arr2.A[j]) // When array A element is greater than array b element
            {
                  arr3->A[k++] = A[i++];
            }
            else if(A[i] ==arr2.A[j]) // If element is same on both the array, we will not take it.
            {
                  i++;
                  j++;
            }
            else // When array B element is greater than array A element
            {
                  j++;
            }
      }
      for (; i < length;i++)
      {
            arr3->A[k++] = A[i++];
      }
      arr3->length = k;
      arr3->size = size + arr2.size;

      return arr3;
      
}

bool Array :: setMembership(int key)
{
      int i;
      for (i = 0; i < length;i++)
      {
            if(key==A[i])
            {
                  return true;
            }

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
Array* Array :: unionOnUnsortedArray(Array arr2)
{
      int i,j,k;
      i = j = k = 0;
      Array *arr3 = new Array(length + arr2.length);
      for (i; i < length;i++)
      {
            arr3->A[k++] = A[i];
            arr3->length++;
      }

      for (j; j < arr2.length;j++)
      {
            if(!elementPresentOrNot(arr3->A,arr3->length,arr2.A[j]))
            {
                  arr3->A[k++] = arr2.A[j];
                  arr3->length++;
            }
      }
      return arr3;
}

/*
Intersection approach for unsorted array --
copy those element of  A to C which is present in B.
*/
Array* Array :: intersectionOnUnsortedArray(Array arr2)
{
      int i, j, k;
      k = 0;
      Array *arr3 = new Array(length + arr2.length);
      for (i = 0; i < length;i++)
      {
            if (elementPresentOrNot(arr2.A, arr2.length,A[i]))
            {
                  arr3->A[k++] = A[i];
                  arr3->length++;
            }
      }
      return arr3;
}

/*
Differnece approach for unsorted array
Copy those element of A to C which is not present in B.
*/
Array* Array :: differenceOnUnsortedArray(Array arr2)
{
      int i, j, k;
      k = 0;
      Array *arr3 = new Array(length + arr2.length);
      for (i = 0; i < length;i++)
      {
            if (!elementPresentOrNot(arr2.A, arr2.length,A[i]))
            {
                  arr3->A[k++] = A[i];
                  arr3->length++;
            }
      }
      return arr3;
}
int main()
{
      Array *arr1, *arr2, *arr3;
      int choice, choice2,index,x;
      int result, key;
      int sizeA, sizeB;
      int min_element, max_element, sum,get_element;
      float avg;
      cout << "Enter the Details for Array A:--- "<<endl;
      cout << "Enter the size of Array A: ";
      cin >> sizeA;
      arr1 = new Array(sizeA);
      arr1->input();
      arr1->Display();
      cout << "\nEnter the Details for Array B: --- "<<endl;
      cout << "Enter the size of Array B: ";
      cin >> sizeB;
      arr2 = new Array(sizeB);
      arr2->input();
      arr2->Display();
      // label:
      cout << "\nEnter 1: Merge two array" << endl;
      cout <<"Enter 2: For Union "<<endl;
      cout << "Enter 3: For Intersection" << endl;
      cout << "Enter 4: For Difference" << endl;
      cout << "Enter 5: For SetMembership (Belong to array or not)" << endl;
      cout << "Enter 6: For Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
       switch (choice)
      {
                   case 1:
                        if(arr1->isSorted()!=arr2->isSorted())
                        {
                              cout << "\nElement is not sorted, merging of an array is only work in sorted array"<<endl;
                        }
                        else
                        {
                              arr3= arr1->Merge(*arr2);
                              arr3->Display();
                        }

                        break;
                 
                  case 2:
                        {
                              if(arr1->isSorted()==1 && arr2->isSorted()==1)
                              {
                                    cout << "\nArray A & B is Sorted Array"<<endl;
                                    arr3 = arr1->Union(*arr2);
                                    cout << "\nUnion Operation (A U B)-----"<<endl;
                                    arr3->Display();
                              }
                              else
                              {
                                    cout << "\nArray A & B is UnSorted Array HIII"<<endl;
                                    arr3=arr1->unionOnUnsortedArray(*arr2);
                                    cout << "\nUnion Operation (A U B)-----"<<endl;
                                    arr3->Display();
                              }
                              break;
                        }
                  case 3:
                        {
                              if(arr1->isSorted() == 1 && arr2->isSorted()==1)
                              {
                                    cout << "\nArray A & B is Sorted Array"<<endl;
                                    arr3 = arr1->Intersection(*arr2);
                                    cout << "\nIntersection Operation (A intersection B)-----"<<endl;
                                    arr3->Display();
                              }
                              else
                              {
                                    cout << "\nArray A & B is UnSorted Array"<<endl;
                                    arr3 = arr1->intersectionOnUnsortedArray(*arr2);
                                    cout << "\nIntersection Operation (A intersection B)-----"<<endl;
                                    arr3->Display();

                              }
                              break;
                        }
                  case 4:
                        {
                              if(arr1->isSorted()==1 && arr2->isSorted()==1)
                              {
                                    cout << "\nArray A & B is Sorted Array"<<endl;
                                    arr3 = arr1->Difference(*arr2);
                                    cout << "\nDifference Operation (A - B)-----"<<endl;
                                    arr3->Display();
                              }
                              else
                              {
                                    cout << "\nArray A & B is UnSorted Array"<<endl;
                                    arr3 = arr1->differenceOnUnsortedArray(*arr2);
                                    cout << "\nDifference Operation (A - B)-----"<<endl;
                                    arr3->Display();
                              }
                              break;
                        }
                  case 5:
                        cout << "Enter the element to be search or belong: ";
                        cin >> x;

                        cout << "\nWhich Array you want to be searched--";
                        cout << "\nEnter 1: For Array A";
                        cout << "\nEnter 2: For Array B";
                        cout << "\nEnter choice: ";
                        cin >> choice2;
                        if(choice2==1)
                        {
                              if(arr1->setMembership(x)==true)
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
                              if(arr2->setMembership(x)==true)
                              {
                                    cout << x << " belong to the array A";
                              }
                              else
                              {
                                    cout << x << "not  belong to the array A";
                                    
                              }
                        
                        }
                  
                  case 6:

                        exit(0);
            default:

                  cout << "Wrong Choice";

      }
      return 0;
}
