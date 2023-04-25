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

void ReverseLinkedList(struct Node *p)
{
    struct Node *q=NULL;
    struct Node *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    cout<<"Linked List: --"<<endl;
    Display(first);
    ReverseLinkedList(first);
    cout<<"\nReverse of Linked List"<<endl;
    Display(first);
    return 0;
}