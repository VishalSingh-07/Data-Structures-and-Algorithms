// Finding Max and Min in a Single Scan
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
void Max_Min(struct Array arr)
{
      int min, max;
      min = arr.A[0];
      max = arr.A[0];
      for (int i = 1; i < arr.length;i++)
      {
            if(arr.A[i]<min)
            {
                  min = arr.A[i];
            }
            else if(arr.A[i]>max)
            {
                  max = arr.A[i];
            }

      }
      cout << "\nMaximum element in an array is " << max << endl;
      cout << "Minumum element in an array is " << min << endl;
}

int main()
{
      struct Array arr;
      int i,n;
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

      Max_Min(arr);

      return 0;
}

/*
Note:
10,9,8,7,2,1
Number of comparation == n - 1 (Best Case)

1,2,3,5,8,9,10
Number of Comparation == 2(n - 1) (Worst Case)
*/


/*
Output:--
Enter the Size of an Array: 15
Enter number of numbers: 10
Enter the element of an Array:
Enter the value of A[0]: 5
Enter the value of A[1]: 8
Enter the value of A[2]: 3
Enter the value of A[3]: 9
Enter the value of A[4]: 6
Enter the value of A[5]: 2
Enter the value of A[6]: 10
Enter the value of A[7]: 7
Enter the value of A[8]: -1
Enter the value of A[9]: 4
Elements of Array are: 
5 8 3 9 6 2 10 7 -1 4 
Maximum element in an array is 10
Minumum element in an array is -1
*/