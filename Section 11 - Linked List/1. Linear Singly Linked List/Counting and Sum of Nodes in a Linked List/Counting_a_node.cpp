#include <bits/stdc++.h>
using namespace std;
struct Node
{
      int data;
      struct Node *next;
} *first=NULL;
void create(int A[], int n)
{
      int i;
      struct Node *t, *last;
      first = (struct Node *)malloc(sizeof(struct Node));
      first->data = A[0];
      first->next = NULL;
      last = first;

      for (i = 1; i < n;i++)
      {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
      }
}

void RDisplay(struct Node *p)
{
      if(p!=NULL)
      {
            cout << p->data<<" "; 
            RDisplay(p->next);
      }
}

int count(struct Node *p)
{
      int count = 0;
      while(p!=0)
      {
            count++;
            p=p->next;
      }
      return count;
}


int Rcount(struct Node *p) // Recursive Function 
{
      if(p==0)
      {
            return 0;
      }
      return Rcount(p->next) + 1;
}

int main()
{
      int A[] = {3, 5, 7, 10, 15,8,12,20};
      create(A, 8);
      RDisplay(first);
      cout << "\nNumber of nodes is " << Rcount(first);

      return 0;
}