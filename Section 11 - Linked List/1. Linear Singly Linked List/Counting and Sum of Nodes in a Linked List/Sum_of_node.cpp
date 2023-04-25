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
int sum(struct Node *p)
{
      int sum = 0;
      while(p!=NULL)
      {
            sum += p->data;
            p = p->next;
      }
      return sum;
}

int rsum(struct Node *p) // recursive function
{
      if(p==0)
      {
            return 0;
      }
      return rsum(p->next) + p->data;
}

int main()
{
      int A[] = {3, 5, 7, 10, 15,8,12,20};
      create(A, 8);
      RDisplay(first);
      cout << "\nSum of all nodes is " << rsum(first);

      return 0;
}