// Finding Single Missing Element in an Natural Number in Sorted Array
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

int Missing_Natural_Number(struct Array arr)
{
      int sum=0,s=0,missing_number,n;
      for (int i = 0; i < arr.length;i++)
      {
            sum = sum + arr.A[i];
      }
      n = arr.A[arr.length - 1];
      cout << n << endl;
      s = n * (n + 1) / 2;
      if(s==sum)
      {
            cout << "\nNo missing value" << endl;
            return 0;
      }
      else
      {
            missing_number = s - sum;
            return missing_number;
            
      }
      
}

int main()
{
      Array arr = {{1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12}, 50, 11};
      cout << "Missing value in array is :  " << Missing_Natural_Number(arr);

      return 0;
}

/*
Output:
Missing value in array is :  8
*/

