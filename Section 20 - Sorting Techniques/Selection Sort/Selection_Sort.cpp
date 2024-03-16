#include <bits/stdc++.h>
using namespace std;
void SelectionSort(vector<int> &arr, int n)
{
      int i,j,k;
      for(i=0;i<n-1;i++)
      {
            for(j=k=i;j<n;j++)
            {
                  if(arr[j]<arr[k])
                  {
                        k=j;
                  }
            }
            swap(arr[i],arr[k]);
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
      SelectionSort(arr,n);
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