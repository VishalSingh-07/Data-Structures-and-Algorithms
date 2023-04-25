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

int max(struct Node *p)
{
      int max = INT_MIN;
      while(p)
      {
            if(p->data>max)
            {
                  max = p->data;
                  
            }
            p = p->next;
      }
      return max;
}

int rmax(struct Node *p)
{
      int x = 0;
      if(p==0)
      {
            return INT_MIN;
      }
      x = rmax(p->next);
      return x > p->data ? x : p->data;
}

int min(struct Node *p)
{
      int min = INT_MAX;
      while(p)
      {
            if(p->data<min)
            {
                  min = p->data;
                  
            }
            p = p->next;
      }
      return min;
}

int rmin(struct Node *p)
{
      int x = 0;
      if(p==0)
      {
            return INT_MAX;
      }
      x = rmax(p->next);
      return x < p->data ? x : p->data;
}

int main()
{
      int A[] = {3, 5, 7, 10, 15,8,12,20};
      create(A, 8);
      RDisplay(first);
      cout << "\nMax Element: " << rmax(first) << endl;
      cout << "Min Element: " << rmin(first) << endl;

      return 0;
}