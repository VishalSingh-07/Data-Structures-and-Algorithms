// Finding Multiple Missing Element in unsorted Array
#include <iostream>
using namespace std;
struct Array{
      int A[100];
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

int main()
{
      Array arr = {{3,7,4,9,12,6,1,11,2,10}, 50, 10};
      int l = 1;  // Lowest element in arr
      int h = 12; // Largest element in arr
      int H[h] = {0};
      for (int i = 0; i < arr.length;i++) // For Hash table/ Bitset
      {
            H[arr.A[i]]++;
      }
      cout << "Missing value in array is : ";
      for (int i = l; i < h;i++)
      {
            if(H[i]==0)
            {
                  cout << i << " ";
            }

      }
            

      return 0;
}

/*
Note:
For Hash table: We need space that is equal to largest element in array arr.
*/

/*
Output:
Missing value in array is : 5 8 
*/

