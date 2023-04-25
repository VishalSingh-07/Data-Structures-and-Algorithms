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

void insertLast(struct Node *p, int x) 
{
      struct Node *t, *last;
      t=(struct Node *)malloc(sizeof(struct Node));
      t->data=x;
      t->next = NULL;
      
      if(first==NULL) // Insert at first
      {
            first = last = t;
      }
      else
      {
            last = p;
            while(last->next)
            {
                  last = last->next;
            }
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

int main()
{
      int A[] = {3, 5, 7};
      create(A, 3);

      Display(first);
      insertLast(first,12);
      cout << endl;
      Display(first);

      return 0;
}