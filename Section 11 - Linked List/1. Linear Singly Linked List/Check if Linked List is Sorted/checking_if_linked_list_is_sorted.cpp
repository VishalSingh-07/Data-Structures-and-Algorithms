#include <bits/stdc++.h>
using namespace std;
struct Node
{
      int data;
      struct Node *next;
} *first=NULL;

void create(int A[], int n) // creating a linked list
{
      int i;
      struct Node *t, *last;
      first = (struct Node *)malloc(sizeof(struct Node)); // creating a new node
      first->data = A[0]; 
      first->next = NULL; 
      last = first;

      for (i = 1; i < n;i++)
      {
            t=(struct Node *)malloc(sizeof(struct Node)); // creating a temp new node
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
      }
}

void Display(struct Node *p)
{
      while(p!=NULL)
      {
            cout << p->data << " ";
            p = p->next;
      }
}

bool isSorted(struct Node *p)
{
    int x=INT_MIN;
    while(p!=NULL)
    {
        if(x>p->data)
        {
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}

int main()
{
    int A[] = {1, 5, 7, 10, 15};
    create(A, 5);
    Display(first);
    
    bool checkSorting=isSorted(first);
    if(checkSorting==true)
    {
        cout<<"\nLinked List is Sorted"<<endl;
    }
    else
    {
        cout<<"\nLinked List is not Sorted"<<endl;
    }

    return 0;
}