#include <bits/stdc++.h>
using namespace std;
void BubbleSort(vector<int> &arr, int n)
{
      bool swapped;
      for(int i=0;i<n-1;i++)
      {
            swapped=false;
            for(int j=0;j<n-i-1;j++)
            {
                  if(arr[j]>arr[j+1])
                  {
                        swap(arr[j],arr[j+1]);
                        swapped=true;
                  }
            }
            if(swapped==false)
            {
                  break;
            }
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
      BubbleSort(arr,n);
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