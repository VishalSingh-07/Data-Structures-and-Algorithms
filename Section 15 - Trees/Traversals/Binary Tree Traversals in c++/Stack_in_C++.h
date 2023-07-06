#include <bits/stdc++.h>
using namespace std;

class Stack
{
      private:
            int size;
            int top;
            Node **s; // pointer to dynamically created array
      public:
            Stack(int size)
            {
                  this->size=size;
                  top=-1;
                  s=new Node*[size]; // creating array in heap memory
            }
            ~Stack() 
            {
                  delete[] s;
            }
            void push(Node *x);
            Node* pop();
            bool isEmptyStack();
            bool isFullStack();
};
void Stack :: push(Node *x)
{
      if(top==size-1)
      {
            cout<<"\nStack Overflow"<<endl;
      }
      else
      {
            top++;
            s[top]=x;
      }
}
Node* Stack :: pop()
{
      Node *x=NULL;
      if(top==-1)
      {
            cout<<"\nStack Underflow"<<endl;
      }
      else
      {
            x=s[top];
            top--;
      }
      return x;
}
bool Stack :: isEmptyStack()
{
      if(top==-1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
bool Stack :: isFullStack()
{
      if(top==size-1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
