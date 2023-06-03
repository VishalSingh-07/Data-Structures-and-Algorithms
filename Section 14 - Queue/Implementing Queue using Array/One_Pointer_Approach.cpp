/*
Single Pointer Approach: 

Rear --> For Insertion and Deletion

Time complexity -
Insertion -> O(1)
Deletion -> O(n)
*/
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
      int size;
      int rear;
      int *Q;
};

void create(struct Queue *q, int size)
{
      q->size=size;
      q->rear=-1;
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
      if(q->rear==-1)
      {
            cout<<"\nQueue is Empty";
      }
      else
      {
            x=q->Q[0];
            for(int i=0;i<q->rear;i++)
            {
                  q->Q[i]=q->Q[i+1];
            }
            q->rear--;
      }
      return x;
}
void Display(struct Queue q)
{
      cout<<"\nElement of Queue is: "<<endl;
      for(int i=0;i<=q.rear;i++)
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