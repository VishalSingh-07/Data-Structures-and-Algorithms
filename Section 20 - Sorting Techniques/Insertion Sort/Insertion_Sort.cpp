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

/*
Output:

Before Sorting: 
3 7 9 10 6 5 12 4 11 2 
After Sorting: 
2 3 4 5 6 7 9 10 11 12 

*/