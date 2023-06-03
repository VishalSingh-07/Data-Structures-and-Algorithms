#include <bits/stdc++.h>
using namespace std;
struct Queue
{
      int size;
      int front;
      int rear;
      int *Q;
};
void create(struct Queue *q,int size)
{
      q->size=size;
      q->front=q->rear=-1;
      q->Q=(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int x)
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
            cout<<"Queue is Empty";
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
      int i;
      for(i=q.front+1;i<=q.rear;i++)
      {
            cout<<(char)q.Q[i]<<" ";
      }
      cout<<endl;
}

void insert(struct Queue *q1,struct Queue *q2,struct Queue *q3,char ele,int pr)
{

      if(pr==1)
      {
            enqueue(q1,ele);
      }
      else if(pr==2)
      {
            enqueue(q2,ele);
      }
      else
      {
            enqueue(q3,ele);
      }
}
int isEmpty(struct Queue *q)
{
      if(q->front==q->rear)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
int deleted(struct Queue *q1,struct Queue *q2,struct Queue *q3)
{
      int x=-1;
      if(!isEmpty(q1))
      {
            x=dequeue(q1);
      }
      else if(!isEmpty(q2))
      {
            x=dequeue(q2);
      }
      else
      {
            x=dequeue(q3);
      }
      return x;
}
int main()
{
      struct Queue q1,q2,q3;
      create(&q1,10);
      create(&q2,10);
      create(&q3,10);
      int i;
      cout<<"\nInserting Element"<<endl;
      insert(&q1,&q2,&q3,'a',1);
      insert(&q1,&q2,&q3,'b',1);
      insert(&q1,&q2,&q3,'c',2);
      insert(&q1,&q2,&q3,'d',3);
      insert(&q1,&q2,&q3,'e',2);
      insert(&q1,&q2,&q3,'f',1);
      insert(&q1,&q2,&q3,'g',2);
      insert(&q1,&q2,&q3,'h',3);
      insert(&q1,&q2,&q3,'i',2);
      insert(&q1,&q2,&q3,'j',2);

      cout<<"\nQueue 1:"<<endl;
      Display(q1);
      cout<<"\nQueue 2:"<<endl;
      Display(q2);
      cout<<"\nQueue 3:"<<endl;
      Display(q3);

      cout<<"\nDeleting Element"<<endl;
      deleted(&q1,&q2,&q3);
      deleted(&q1,&q2,&q3);
      deleted(&q1,&q2,&q3);
      deleted(&q1,&q2,&q3);
      cout<<endl;
      
      cout<<"\nQueue 1:"<<endl;
      Display(q1);
      cout<<"\nQueue 2:"<<endl;
      Display(q2);
      cout<<"\nQueue 3:"<<endl;
      Display(q3);
      
      cout<<endl;
      

      cout<<"\nInserting Element"<<endl;

      insert(&q1,&q2,&q3,'z',2);
      insert(&q1,&q2,&q3,'w',1);
      
      cout<<"\nQueue 1:"<<endl;
      Display(q1);
      cout<<"\nQueue 2:"<<endl;
      Display(q2);
      cout<<"\nQueue 3:"<<endl;
      Display(q3);
      
      return 0;
}