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

void removeDuplicate(struct Node *p) // Removing dupicate in sorted order
{
    // p-> head pointer and q->tail pointer
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;

        }
    }
}

int main()
{
    // int A[] = {10,20,20,20,30,40,50};
    // create(A, 7);
    int A[]={1,1,2};
    create(A,3);

    if(isSorted(first)==true)
    {   
        cout<<"\nRemoving Duplicate------"<<endl;
        cout<<"\n\nBefore Linked List: "<<endl;
        Display(first);
        
        cout<<"\n\nAfter Linked List: "<<endl;
        removeDuplicate(first);
        Display(first);

    }
    else
    {
        cout<<"\nLinked List is not Sorted"<<endl;
    }
    
    return 0;
}