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

struct Node * LinearSearch(struct Node *p, int key)
{
      while(p!=NULL)
      {
            if(p->data==key)
            {
                  return p;
            }
            p = p->next;
      }
      return NULL;
}

struct Node * Recursive_LinearSearch(struct Node *p, int key)
{
      if(p==NULL)
      {
            return NULL;
      }
      if(p->data==key)
      {
            return p;
      }
      return Recursive_LinearSearch(p->next, key);
}


int main()
{
      struct Node *temp;
      int A[] = {3, 5, 7, 10, 25,8,32,2};
      create(A, 8);

      Display(first);

      int search;

      cout << "\nEnter the value to be searched: ";
      cin >> search;

      temp = LinearSearch(first, search);
      // temp = Recursive_LinearSearch(first, search);
      
      if(temp)
      {
            cout << "Key is found " << temp->data;
      }
      else
      {
            cout << "Key is not found";
      }

      return 0;
}