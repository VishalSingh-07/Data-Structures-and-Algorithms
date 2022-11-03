// Finding Single missing element in specific range in Sorted Array
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
int Missing_Specific_Range_Number(struct Array arr)
{
      int diff,i;
      diff = arr.A[0] - 0;
      for (i = 0; i < arr.length;i++)
      {
            if(arr.A[i]-i!=diff)
            {

                  return (diff + i);
            }
      }
      return -1;
}

int main()
{
      Array arr = {{6,7,8,9,10,11,13,14,15,16,17}, 50, 11};
      cout << "Missing value in array is :  " << Missing_Specific_Range_Number(arr);

      return 0;
}

/*
Output:
Missing value in array is :  12
*/

