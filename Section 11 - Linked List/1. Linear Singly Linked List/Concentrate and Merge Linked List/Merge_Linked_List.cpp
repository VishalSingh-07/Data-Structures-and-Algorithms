#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first=NULL,*second=NULL,*third=NULL;

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

void create2(int A[], int n) // creating a linked list
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node)); // creating a new node
    second->data = A[0]; 
    second->next = NULL; 
    last = second;
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
        if(p->data<x)
        {
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}

void merge(struct Node *first,struct Node *second)
{
    struct Node*last;
    if(first->data<second->data)
    {
        third=last=first;
        first=first->next;
        last->next=NULL;
    }
    else
    {
        third=last=second;
        second=second->next;
        last->next=NULL;
    }
    while(first!=NULL && second!=NULL)
    {
        if(first->data<second->data) 
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else // first->data > second->data
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    if(first!=NULL)
    {
        last->next=first;
    }
    else
    {
        last->next=second;
    }
} 

int main()
{
    int A[] = {10,20,30,40,50};
    create(A, 4);
    cout<<"\nFirst Linked List: "<<endl;
    Display(first);
    int B[] = {5,15,25,35,45};
    create2(B, 3);
    cout<<"\nSecond Linked List: "<<endl;
    Display(second);
    if(isSorted(first)==true && isSorted(second)==true)
    {
        merge(first,second);
        cout<<"\nMerge Linked List: "<<endl;
        Display(third);
    }
    else
    {
        cout<<"\nLinked List is not sorted"<<endl;
    }
    

    return 0;
}