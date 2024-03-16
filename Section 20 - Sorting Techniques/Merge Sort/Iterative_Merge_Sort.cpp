#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) 
{
      int i=low, j=mid+1,k=low;
      int temp[high+1];
      while(i<=mid && j<=high)
      {
            if(arr[i]<arr[j])
            {
                  temp[k++]=arr[i++];
            }
            else
            {
                  temp[k++]=arr[j++];
            }
      }
      while(i<=mid)
      {
           temp[k++]=arr[i++]; 
      }
      while(j<=high)
      {
            temp[k++]=arr[j++];
      }
      for(int i=low;i<=high;i++)
      {
            arr[i]=temp[i];
      }
}


void mergeSort(vector<int>& arr, int n) 
{
      int p,i,low,mid,high;
      for(p=2;p<=n;p=p*2)
      {
            for(int i=0;i+p-1<=n;i=i+p)
            {
                  low=i;
                  high=i+p-1;
                  mid=(low+high)/2;
                  merge(arr,low,mid,high);
            }
      }
      if(p/2 < n) // For odd array list
      {
            merge(arr,0,p/2-1,n);
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
      // vector<int> arr={3,7,9,10,6,5,12,4,11,2};
      vector<int> arr={11,13,7,12,16,9,24,5,10,3};
      int n=arr.size();
      cout<<"Before Sorting: "<<endl;
      Display(arr);
      mergeSort(arr,n);
      cout<<endl;
      cout<<"After Sorting: "<<endl;
      Display(arr);
      return 0;
}

/*
Output:

Before Sorting: 
11 13 7 12 16 9 24 5 10 3 
After Sorting: 
3 5 7 9 10 11 12 13 16 24 

*/