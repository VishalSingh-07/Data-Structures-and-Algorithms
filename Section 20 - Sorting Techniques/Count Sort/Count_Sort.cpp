#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &arr, int n)
{
      int maximum=INT_MIN;
      for(int i=0;i<n;i++)
      {
            if(arr[i]>maximum)
            {
                  maximum=arr[i];
            }
      }
      return maximum;
}

void CountSort(vector<int>& arr, int n) 
{
      int maxi=findMax(arr,n);
      vector<int> count(maxi+1,0);
      for(int i=0;i<n;i++){
            count[arr[i]]++;
      }
      int i=0,j=0;
      while(i<maxi+1){
            if(count[i]>0){
                  arr[j++]=i;
                  count[i]--;
            }
            else{
                  i++;
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
      CountSort(arr,n);
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