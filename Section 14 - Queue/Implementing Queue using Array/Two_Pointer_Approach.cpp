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

struct Queue
{
      int size;
      int front;
      int rear;
      int *Q;
};

void create(struct Queue *q, int size)
{
      q->size=size;
      q->front=q->rear=-1;
      // q->Q=(int*)malloc(q->size*sizeof(int));
      q->Q=new int[q->size];
}
void enqueue(struct Queue *q, int x) // For insertion
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
int dequeue(struct Queue *q)
{
      int x=-1;
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
void Display(struct Queue q)
{
      cout<<"\nElement of Queue is: "<<endl;
      for(int i=q.front+1;i<=q.rear;i++)
      {
            cout<<q.Q[i]<<" ";
      }
      cout<<endl;
}
int main()
{
      struct Queue q;
      int size,choice,x;
      cout<<"Enter the size of Queue: ";
      cin>>size;
      create(&q,size);
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
                      enqueue(&q,x);
                      break;
                  case 2:
                      x=dequeue(&q);
                      if(x!=-1)
                      {
                        cout<<x<<" is delete from queue"<<endl;
                      }
                      break;
                  case 3:
                      Display(q);
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