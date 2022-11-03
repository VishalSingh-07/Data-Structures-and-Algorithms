// Finding a pair of elements with sum k
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

void Pair_element(struct Array arr, int k) // Time complexity = O(n^2)
{
      int i,j;
      for (int i = 0; i < arr.length - 1;i++)
      {
            for (j = i + 1; j < arr.length;j++)
            {
                  if(arr.A[i]+arr.A[j] == k)
                  {
                        cout << arr.A[i] << " and " << arr.A[j] << " sum is equal to " << k << endl;
                  }
                  
            }
      }
}
void Pair_element_Hashing(struct Array arr, int k) // Time complexity = O(n)
{
      int h = max(arr);
      int l = min(arr);
      int H[h+1] = {0};
      // Size of the hash array is (max_element in an array + 1)
      for (int i = 0; i < arr.length;i++)
      {
            //first check is it in valid range then use as index 
            // it matters whether you check condition first or not 
            // assuming user input for element is from range 0 to h only
            // k-arr.A[i]>=0 --> For getting positive index,(Negative Index not include) 
            if(H[k-arr.A[i]]!=0 && k-arr.A[i]>=0 && k-arr.A[i]<=h)
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
                  Pair_element(arr,k);
                  break;
            case 2:
                  Pair_element_Hashing(arr, k);
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
Enter the value of A[0]: 6
Enter the value of A[1]: 3
Enter the value of A[2]: 8
Enter the value of A[3]: 10
Enter the value of A[4]: 16
Enter the value of A[5]: 7
Enter the value of A[6]: 5
Enter the value of A[7]: 2
Enter the value of A[8]: 9
Enter the value of A[9]: 14
Elements of Array are: 
6 3 8 10 16 7 5 2 9 14
Enter the sum of element (k):  21

Enter 1: Finding Pair Element with sum k using simple Method
Enter 2: Finding Pair Element with sum k using Hashing Method
Enter Choice: 1
16 and 5 sum is equal to 21
7 and 14 sum is equal to 21
*/