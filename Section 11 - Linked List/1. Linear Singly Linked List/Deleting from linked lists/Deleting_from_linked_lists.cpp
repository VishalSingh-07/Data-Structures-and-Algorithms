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
int count(struct Node *p)
{
      int count = 0;
      while(p)
      {
            count++;
            p = p->next;
      }
      return count;
}

void insert(struct Node *p, int index, int x) 
{
      if(index<0 || index> count(p))
      {
            return;
      }
      struct Node *t;
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;

      if(index==0) // insert before first
      {
            t->next = first;
            first = t;
      }
      else // Inserting after given position
      {
            for (int i = 0; i < index - 1;i++)
            {
                  p = p->next;
            }
            if(p)
            {
                  t->next = p->next;
                  p->next = t;
            }
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

int Delete(struct Node *p, int index)
{
      struct Node *q=NULL;
      int x = -1;
      if(index<1 || index>count(p))
      {
            return x;
      }

      if(index==1)
      {
            q = first;
            x = first->data;
            first = first->next;
            delete q;
            return x;
      }
      else
      {
            for (int i = 0; i < index - 1;i++)
            {
                  q = p;
                  p = p->next;
            }
            if(p)
            {
                  q->next = p->next;
                  x = p->data;
                  delete p;
            }
            return x;
      }
      return -1;
}
int main()
{
      int A[] = {10,20,30,40,50};
      create(A, 5);

      Display(first);

      cout<<"\nDeleted Element is "<<Delete(first, 4);
      cout << endl;
      Display(first);
      return 0;
}