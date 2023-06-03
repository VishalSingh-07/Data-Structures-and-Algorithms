#include <bits/stdc++.h>
using namespace std;
struct Stack
{
      int size;
      int top;
      int *s;
}s1,s2;

void create(struct Stack *st)
{
      cout<<"Enter the size of queue required: ";
      cin>>st->size;
      st->s = (int *)malloc(sizeof(int)*st->size);
      st->top=-1;
}

void Display(struct Stack st)
{
      int i;
      for(int i=st.top;i>=0;i--)
      {
            cout<<st.s[i]<<" ";
      }
}

void Push(struct Stack *st , int val)
{
	if(st->top==st->size-1)
      {
		printf("Stack Overflow\n");
	}
	else
      {
		st->top++;
		st->s[st->top] = val;
	}
}
int Pop(struct Stack *st)
{
	int val;
	if(st->top==-1)
      {
		printf("\nStack Underflow\n");
	}
	else
      {
		val = st->s[st->top];
		st->top--;
	}
      return val;
}

int isEmpty(struct Stack st)
{
	if(st.top==-1)
      {
		return 1;
	}
	else
      {
		return 0;
	}
}
 
int isFull(struct Stack st)
{
	if(st.top == st.size-1)
      {
		return 1;
	}
	else
      {
		return 0;
	}
}

void Enqueue(struct Stack *st , int val)
{
	Push(&s1,val);
}

int Dequeue()
{
	int val =-1;
	if(isEmpty(s2))
      {
		if(isEmpty(s1))
            {
			cout<<"\nQueue is Empty"<<endl;
		}
	      else
            {
		      while(!isEmpty(s1))
                  {
			      Push(&s2,Pop(&s1));
			}
		}
	}
	val = Pop(&s2);
	return val;
}
int main()
{
      create(&s1);
	create(&s2);
 
      Enqueue(&s1,12);
      Enqueue(&s1,50);
      Enqueue(&s1,134);
      Enqueue(&s1,56);
 	
      cout<<"\nStack 1:"<<endl;
      Display(s1);

      cout<<"\nStack 2:"<<endl;
      Display(s2);
	
      cout<<"\nElement Deleted:"<<Dequeue()<<endl;

      cout<<"\nStack 1:"<<endl;
      Display(s1);

      cout<<"\nStack 2:"<<endl;
      Display(s2);
 
      return 0;
}