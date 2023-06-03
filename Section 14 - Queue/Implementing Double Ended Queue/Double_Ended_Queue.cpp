#include <bits/stdc++.h>
using namespace std;

class Deque
{
      private:
            int front;
            int rear;
            int size;
            int *Q;

      public:
            Deque()
            {
                  front=rear=-1;
                  size=10;
                  Q=new int[size];
            }
            Deque(int size)
            {
                  front=rear=-1;
                  this->size=size;
                  Q=new int[this->size];
            }
            void insertFront(int key);
            void insertRear(int key);
            void deleteFront();
            void deleteRear();
            void Display();
            int getFront();
            int getRear();
};


void Deque::insertFront(int x)
{
      if(rear==size)
      {
            cout<<"\nQueue is Full"<<endl;
      }
      else if(front==-1 && rear==-1)
      {
            front=rear=0;
            Q[rear]=x;
            rear=rear+1;
      }
      else
      {
            Q[front-1]=x;
            front=front-1;
      }
}


void Deque::insertRear(int x)
{
      if(front==-1 && rear==-1)
      {
            front=rear=0;
            Q[rear]=x;
            rear=rear+1;
      }
      else if(rear==size)
      {
            cout<<"\nQueue is Full";
      }
      else
      {
            // first assign value to x and ten move rear pointer
            Q[rear]=x;
            rear=rear+1;
      }
}


void Deque::deleteFront()
{
      if(rear==-1 && front==-1 || front==rear)
      {
            cout<<"\nQueue is Empty";
            front=rear=-1;
      }
      else
      {
            cout<<Q[front]<<" has been deleted from queue"<<endl;
            front=front+1;
      }
}

void Deque::deleteRear()
{
      if(front==-1 && rear==-1)
      {
            cout<<"\nQueue is Empty";
      }
      else
      {
            if(rear<=front)
            {
                  cout<<"\nQueue is Empty";
                  front=rear=-1;
            }
            else
            {
                  cout<<Q[rear-1]<<" has been deleted from queue"<<endl;
                  rear=rear-1;
            }
      }
}

int Deque::getFront()
{
      if(front==-1 && rear==-1)
      {
            cout<<"\nUnderFlow";
            return -1;
      }
      return Q[front];
}

int Deque::getRear()
{
      if(front==-1 && rear==-1)
      {
            cout<<"\nUnderFlow";
            return -1;
      }
      return Q[rear];
}

void Deque::Display()
{
      int i;
      // here if we do i<=rear then it will also show empty index's adress 
      for (i=front; i!=rear; i++)
      {
            cout<<Q[i]<<" ";
      }
      cout<<endl;   
}


int main()
{
      int size;
      cout<<"Enter the size: ";
      cin>>size;

      Deque dq(size);
 
      cout<<"\nInserting from front"<<endl;
      dq.insertFront(1);
      dq.insertFront(2);
      dq.insertFront(3);
      dq.insertFront(4);
      dq.Display();
    
      cout<<"\nDeleting from front"<<endl;
      dq.deleteFront();
      dq.deleteFront();
      dq.Display();
 
      cout<<"\nInserted from Rear"<<endl;
      dq.insertRear(5);
      dq.insertRear(6);
      dq.insertRear(7);
      dq.insertRear(8);
      dq.Display();
 
      cout<<"\nDeleted from Rear"<<endl;
      dq.deleteRear();
      dq.deleteRear();
      dq.Display();
 
      
      dq.insertFront(1);
      dq.insertFront(2);
      dq.insertFront(3);
      dq.insertFront(4);
      dq.insertFront(5);
      cout<<"Inserted 1,2,3,4,5 from front"<<endl;
      dq.Display();
      return 0;
}