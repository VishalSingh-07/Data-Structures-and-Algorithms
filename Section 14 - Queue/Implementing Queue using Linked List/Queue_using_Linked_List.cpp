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

struct Node
{
      int data;
      struct Node *next;
}*front=NULL,*rear=NULL;


void enqueue(int x) // For insertion
{
      struct Node *t;
      t=(struct Node*) malloc(sizeof(struct Node));
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
int dequeue()
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
void Display()
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
                      enqueue(x);
                      break;
                  case 2:
                      x=dequeue();
                      if(x!=-1)
                      {
                        cout<<x<<" is delete from queue"<<endl;
                      }
                      break;
                  case 3:
                      Display();
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