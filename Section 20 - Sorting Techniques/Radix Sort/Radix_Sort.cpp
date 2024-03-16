#include <bits/stdc++.h>
using namespace std;

struct Node
{
      int data;
      struct Node *next;
};

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

int countDigits(int x)
{
      int count=0;
      while(x!=0)
      {
            x=x/10;
            count++;
      }
      return count;
}

void initializeBins(Node **p, int n)
{
      for(int i=0;i<n;i++)
      {
            p[i]=nullptr;
      }
}

void Insert(Node ** bin, int value, int index)
{
      Node *temp=new Node;
      temp->data=value;
      temp->next=nullptr;

      if(bin[index]==nullptr)
      {
            bin[index]=temp;
      }
      else
      {
            Node *p=bin[index];
            while(p->next!=nullptr)
            {
                  p=p->next;
            }
            p->next=temp;
      }
}

int Delete(Node ** bin, int index)
{
      Node *p=bin[index];
      bin[index]=bin[index]->next;
      int x=p->data;
      delete p;
      return x;
}

int getBinIndex(int x, int index)
{
      return (int)(x/pow(10,index))%10;
}

void RadixSort(vector<int>& arr, int n) 
{
      int maxi=findMax(arr,n);
      int Passes=countDigits(maxi);

      // Creating bins array
      Node **Bins=new Node *[10];
      
      // Initialize bins array with nullptr
      initializeBins(Bins,10);

      // update bins and arr for nPass times
      for(int pass=0;pass<Passes;pass++)
      {
            // Update bins based on array value
            for(int i=0;i<n;i++)
            {
                  int binIndex=getBinIndex(arr[i],pass);
                  Insert(Bins,arr[i],binIndex);
            }

            // Update arr with sorted elements from bin
            int i=0,j=0;
            while(i<10)
            {
                  while(Bins[i]!=nullptr)
                  {
                        arr[j++]=Delete(Bins,i);
                  }
                  i++;
            }
            // Initialize bins with nullptr again
            initializeBins(Bins,10);
      }

      // Delete heap memory
      delete []  Bins; 
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
      vector<int> arr={237, 146, 259, 348, 152, 163, 235, 48, 36, 62};

      int n=arr.size();
      cout<<"Before Sorting: "<<endl;
      Display(arr);
      RadixSort(arr,n);
      cout<<endl;
      cout<<"After Sorting: "<<endl;
      Display(arr);
      return 0;
}

/*
Output:

Before Sorting: 
237 146 259 348 152 163 235 48 36 62 
After Sorting: 
36 48 62 146 152 163 235 237 259 348 

*/