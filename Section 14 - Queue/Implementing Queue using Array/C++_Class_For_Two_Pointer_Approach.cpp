/*
Two Pointer are: Front and rear
Front --> For deletion
Rear --> For Insertion

Time complexity -
Insertion -> O(1)
Deletion -> O(1)

*/
#include <bits/stdc++.h>
using namespace std;

class Queue
{
      private:
            int front;
            int rear;
            int size;
            int *Q;
      public:
            Queue()
            {
                  size=10;
                  front=rear=-1;
                  Q=new int[size];
            }
            Queue(int size)
            {
                  this->size=size;
                  front=rear=-1;
                  Q=new int[this->size];
            }
            void enqueue(int x);
            int dequeue();
            void Display();
};

void Queue:: enqueue(int x) // For insertion
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
int Queue :: dequeue()
{
      int x=-1;
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
void Queue :: Display()
{
      cout<<"\nElement of Queue is: "<<endl;
      for(int i=front+1;i<=rear;i++)
      {
            cout<<Q[i]<<" ";
      }
      cout<<endl;
}
int main()
{
      int size,choice,x;
      cout<<"Enter the size of Queue: ";
      cin>>size;
      Queue q(size);
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