#include <bits/stdc++.h>
using namespace std;
struct Stack
{
      int size;
      int top;
      struct Node **s;
};

void stackCreate(struct Stack *st,int size)
{
      st->size=size;
      st->top=-1;
      st->s=(struct Node**)malloc(st->size*sizeof(struct Node*)); // creating array in heap memory
}

void push(struct Stack *st, Node *x)
{
      if(st->top==st->size-1)
      {
            cout<<"\nStack Overflow"<<endl;
      }
      else
      {
            st->top++;
            st->s[st->top]=x;
      }
}
struct Node *pop(struct Stack *st)
{
      struct Node *x=NULL;
      if(st->top==-1)
      {
            cout<<"\nStack Underflow"<<endl;
      }
      else
      {
            x=st->s[st->top];
            st->top--;
      }
      return x;
}
int isEmptyStack(struct Stack st)
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
int isFullStack(struct Stack st)
{
      if(st.top==st.size-1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}