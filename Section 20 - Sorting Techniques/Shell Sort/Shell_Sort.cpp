#include <bits/stdc++.h>
using namespace std;

void ShellSort(vector<int>& arr, int n) 
{
      int temp,j;
      for(int gap=n/2;gap>=1;gap/=2)
      {
            for(int i=gap;i<n;i++)
            {
                  temp=arr[i];
                  j=i-gap;
                  while(j>=0 && arr[j]>temp)
                  {
                        arr[j+gap]=arr[j];
                        j=j-gap;
                  }
                  arr[j+gap]=temp;
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
      ShellSort(arr,n);
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