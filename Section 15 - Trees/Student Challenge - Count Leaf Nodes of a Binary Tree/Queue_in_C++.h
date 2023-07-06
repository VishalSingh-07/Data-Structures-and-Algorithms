#include <bits/stdc++.h>
using namespace std;

class Node
{
      public:
            Node *lchild;
            int data;
            Node *rchild;

};

class Queue
{
      private:
            int front;
            int rear;
            int size;
            Node  **Q; 
      public:
            Queue()
            {
                  size=10;
                  front=rear=-1;
                  Q=new Node*[size];
            }
            Queue(int size)
            {
                  this->size=size;
                  front=rear=-1;
                  Q=new Node*[this->size];
            }
            void enqueue(Node *x);
            Node* dequeue();
            void Display();
            int isEmpty();
};

void Queue:: enqueue(Node *x) // For insertion
{
      if(rear==size-1)
      {
            cout<<"\nQueue is Full";
      }
      else
      {
            rear++;
            Q[rear]=x;
      }
}
Node* Queue :: dequeue()
{
      Node* x=NULL;
      if(front==rear)
      {
            cout<<"\nQueue is Empty";
      }
      else
      {
            front++;
            x=Q[front];
      }
      return x;
}

int Queue :: isEmpty()
{
      return front==rear;
}