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

void Insert(Node ** bin, int index)
{
      Node *temp=new Node;
      temp->data=index;
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

void BinSort(vector<int>& arr, int n) 
{
      int maxi=findMax(arr,n);
      
      // Creating bins array
      Node **Bins=new Node *[maxi+1];
      
      // Initialize bins array with nullptr
      for(int i=0;i<maxi+1;i++)
      {
            Bins[i]=nullptr;
      }

      // update count array values based on A values
      for(int i=0;i<n;i++)
      {
            Insert(Bins,arr[i]);
      }

      // update A with Sorted Elements
      int i=0,j=0;
      while(i<maxi+1)
      {
            while(Bins[i]!=nullptr)
            {
                  arr[j++]=Delete(Bins,i);
            }
            i++;
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
      vector<int> arr={3,7,9,10,6,5,12,4,11,2};
      int n=arr.size();
      cout<<"Before Sorting: "<<endl;
      Display(arr);
      BinSort(arr,n);
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