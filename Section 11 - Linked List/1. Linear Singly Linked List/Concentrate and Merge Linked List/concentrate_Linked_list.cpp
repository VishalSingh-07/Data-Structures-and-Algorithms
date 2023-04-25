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

void conCat(struct Node *p,struct Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    q=NULL;
} 

int main()
{
    int A[] = {2,9,6,8};
    create(A, 4);
    cout<<"\nFirst Linked List: "<<endl;
    Display(first);
    int B[] = {10,4,7};
    create2(B, 3);
    cout<<"\nSecond Linked List: "<<endl;
    Display(second);
    conCat(first,second);
    cout<<"\nConcentrate Linked List: "<<endl;
    Display(third);

    return 0;
}