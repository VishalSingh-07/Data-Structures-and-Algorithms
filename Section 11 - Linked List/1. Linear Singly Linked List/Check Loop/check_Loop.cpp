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

int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        // q=q!=NULL?q->next:NULL;
        q=q!=NULL?q->next:q;

    }while(p!=NULL && q!=NULL && p!=q);
    if(p==q)
    {
        return true;
    }   
    else
    {
        return false;
    }
}

int main()
{
    struct Node *t1,*t2;
    int A[] = {10,20,30,40,50};
    create(A, 5);
    t1=first->next->next; // Pointing on 30
    t2=first->next->next->next->next; // pointing on null
    t2->next=t1;
    if(isLoop(first)==true)
    {
        cout<<"\nLinked List has a Loop"<<endl;
    }
    else
    {
        cout<<"\nLinked List has not a Loop"<<endl;
    }

    return 0;
}