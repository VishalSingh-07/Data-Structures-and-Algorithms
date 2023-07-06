#include <bits/stdc++.h>
using namespace std;

struct Node{
      struct Node *lchild;
      int data;
      struct Node *rchild;
};

struct Queue
{
      int size;
      int front;
      int rear;
      Node **Q; // store pointer of type node
};

void create(struct Queue *q, int size)
{
      q->size=size;
      q->front=q->rear=-1;
      q->Q=(Node**)malloc(q->size*sizeof(Node*));
      // q->Q = new Node*[q->size];
}
void enqueue(struct Queue *q, Node *x) // For insertion
{
      if(q->rear==q->size-1)
      {
            cout<<"\nQueue is Full";
      }
      else
      {
            q->rear++;
            q->Q[q->rear]=x;
      }
}
Node* dequeue(struct Queue *q)
{
      Node* x=NULL;
      if(q->front==q->rear)
      {
            cout<<"\nQueue is Empty";
      }
      else
      {
            q->front++;
            x=q->Q[q->front];
      }
      return x;
}
int isEmpty(struct Queue q)
{
      return q.front==q.rear;
}
