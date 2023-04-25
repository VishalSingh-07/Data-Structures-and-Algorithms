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
int LengthLinked(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

void ReverseLinkedList(struct Node *p)
{
    // int n=LengthLinked(p);
    int *Arr,i=0;
    Arr=(int*)malloc(sizeof(int)*LengthLinked(p));
    while(p!=NULL)
    {
        Arr[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    while(p!=NULL)
    {
        p->data=Arr[i];
        i--;
        p=p->next;
    }
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