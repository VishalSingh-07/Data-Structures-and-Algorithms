/*
Implementation of Queue using Linked List

Front --> For deletion
Rear --> For Insertion

Time complexity -
Insertion -> O(1)
Deletion -> O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
      public:
            int data;
            Node *next;
};
class Queue
{
      private:
            Node *front;
            Node *rear;
      public:
            Queue()
            {
                  front=rear=NULL;
            }
            void enqueue(int x);
            int dequeue();
            void Display();
};


void Queue :: enqueue(int x) // For insertion
{
      Node *t;
      t=new Node;
      if(t==NULL)
      {
            cout<<"\nQueue is Full";
      }
      else
      {
            t->data=x;
            t->next=NULL;
            if(front==NULL)
            {
                  front=rear=t;
            }
            else
            {
                  rear->next=t;
                  rear=t;
            }
      }
}
int Queue::dequeue()
{
      int x=-1;
      Node *p;
      if(front==NULL)
      {
            cout<<"\nQueue is Empty";
      }
      else
      {
            p=front;
            front=front->next;
            x=p->data;
            delete (p);
      }
      return x;
}
void Queue::Display()
{
      struct Node *p=front;
      cout<<"\nElement of Queue is: "<<endl;
      while(p)
      {
            cout<<p->data<<" ";
            p=p->next;
      }
      cout<<endl;
}
int main()
{
      Queue q;
      int choice,x;
      while(choice!=4)
      {
            cout<<endl;
            cout<<endl;
            cout << "Enter 1: For Enqueue"<<endl;
            cout << "Enter 2: For Dequeue"<<endl;
            cout << "Enter 3: For Display"<<endl;
            cout << "Enter 4: For Exit"<<endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice) 
            {
                  case 1:
                      cout << "Enter the value to be pushed: ";
                      cin>>x;
                      q.enqueue(x);
                      break;
                  case 2:
                      x=q.dequeue();
                      if(x!=-1)
                      {
                        cout<<x<<" is delete from queue"<<endl;
                      }
                      break;
                  case 3:
                      q.Display();
                      break;
                  case 4:
                      exit(0);
                      break;
                  default:
                      cout << "Invalid choice." << endl;
                      break;
            }
      }
      return 0;
}