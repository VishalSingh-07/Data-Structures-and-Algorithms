#include <bits/stdc++.h>
using namespace std;

class Node
{
      public:
            char data;
            Node *next;
};

class Stack 
{
      private:
            Node *top;
      public:
            Stack()
            {
                  top=NULL;
            }
            void push(char x);
            char pop();
            void Display();
            bool isEmpty();
            int isBalance(char *exp);

};

void Stack:: push(char x)
{
      Node *t=new Node;
      if(t==NULL)
      {
            cout<<"\nStack Overflow"<<endl;
      }
      else
      {
            t->data=x;
            t->next=top;
            top=t;
      }
}
char Stack:: pop()
{
      struct Node *p;
      char x=-1;
      if(top==NULL)
      {
            cout<<"Stack is Empty";
      }
      else
      {
            p=top;
            top=top->next;
            x=p->data;
            delete p;
      }
      return x;
}
void Stack:: Display()
{
      struct Node *p;
      p=top;
      cout<<"Stack:"<<endl;
      // print the element of the stack, starting from the top
      while(p!=NULL)
      {
            cout << "  +-----+" << endl;
            cout << "  | " <<p->data << "  |" << endl;
            p=p->next;
      }
      cout << "  +-----+" << endl;
}
bool Stack:: isEmpty()
{
      return top!=NULL?false:true;
}
int Stack:: isBalance(char *exp)
{
      int i;
      for(i=0;exp[i]!='\0';i++)
      {
            if(exp[i]=='(')
            {
                  push(exp[i]);
            }
            else if(exp[i]==')')
            {
                  if(isEmpty())
                  {
                        return 0;
                  }
                  pop();
            }
      }
      if(isEmpty())
      {
            return true;
      }
      return false;
}
int main()
{
      char *exp=new char[100];
      cout<<"Enter the expression: ";
      cin>>exp;
      Stack s1;
      if(s1.isBalance(exp))
      {
            cout<<exp<<" is balanced"<<endl;
      }
      else
      {
          cout<<exp<<" is not balanced"<<endl;  
      }
      delete [] exp;
      return 0;
}

/*
Output:

Enter the expression: ((a+b)*(c-d))
((a+b)*(c-d)) is balanced
*/