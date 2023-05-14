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
            char stackTop();
            bool isEmpty();
            int isOperand(char x);
            int precedence(char x);
            friend char* infix_to_postfix(Stack& s, char* infix);

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

char Stack:: stackTop()
{
      if(top!=NULL)
      {
            return top->data;
      }     
      return -1;
}

bool Stack:: isEmpty()
{
      return top!=NULL?false:true;
}


/*
+,-,*,/ -> Left to Right Associativity
*/
int  Stack :: isOperand(char x)
{
      if(x=='+' || x=='-' || x=='*' || x=='/')
      {
            return 0;
      }
      else
      {
            return 1;
      }
}
int  Stack :: precedence(char x)
{
      if(x=='+' || x=='-')
      {
            return 1;
      }
      else if(x=='*' || x=='/')
      {
            return 2;
      }
      return 0;
}
char *infix_to_postfix(Stack& s,char *infix)
{
      char *postfix=new char[strlen(infix)+1];
      int i=0,j=0;
      while(infix[i]!='\0')
      {
            if(s.isOperand(infix[i]))
            {
                  postfix[j++]=infix[i++];
            }
            else
            {
                  if(s.precedence(infix[i])>s.precedence(s.stackTop()))
                  {
                        s.push(infix[i++]);
                  }
                  else
                  {
                        postfix[j++]=s.pop();
                  }
            }
      }
      while(!s.isEmpty())
      {
            postfix[j++]=s.pop();
      }
      postfix[j]='\0';
      return postfix;
}

int main()
{
      char *infix=new char[100];
      Stack s1;
      cout<<"Enter the expression: ";
      cin>>infix;
      cout<<"Postfix Expression is :"<<infix_to_postfix(s1,infix);
      delete [] infix;
      
      return 0;
}