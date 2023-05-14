#include <bits/stdc++.h>
using namespace std;

class Node
{
      public:
            int data;
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
            void push(int x);
            int pop();
            void Display();
            int peek(int pos);
            int stackTop();
            bool isEmpty();
            bool isFull();

};

void Stack:: push(int x)
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
int Stack:: pop()
{
      struct Node *p;
      int x=-1;
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

int Stack:: peek(int pos)
{
      Node *p=top;
      for(int i=0;i<pos-1 && p!=NULL;i++)
      {
            p=p->next;
      }
      if(p!=NULL)
      {
            return p->data;
      }
      return -1;
}

int Stack:: stackTop()
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
bool Stack:: isFull()
{
      struct Node* p = top;
      while (p != NULL && p->next != NULL) {
        p = p->next;
      }
      return p == NULL;
}


int main()
{
      int choice,x;
      Stack s1;
      while(choice!=8)
      {
            cout<<endl;
            cout<<endl;
            cout << "Enter 1: For Push"<<endl;
            cout << "Enter 2: For Pop"<<endl;
            cout << "Enter 3: For Peek"<<endl;
            cout << "Enter 4: For Stack Top"<<endl;
            cout << "Enter 5: For isEmpty"<<endl;
            cout << "Enter 6: For isFull"<<endl;
            cout << "Enter 7: For Display"<<endl;
            cout << "Enter 8: For Exit"<<endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice) 
            {
                  case 1:
                      cout << "Enter the value to be pushed: ";
                      cin>>x;
                      s1.push(x);
                      break;
                  case 2:
                      x=s1.pop();
                      if(x!=-1)
                      {
                        cout<<x<<" is pop from stack"<<endl;
                      }
                      break;
                  case 3:
                      int pos;
                      cout<<"Enter the position: ";
                      cin>>pos;  
                      x=s1.peek(pos);
                      if(x!=-1)
                      {
                        cout<<"peek value is "<<x<<endl;
                      }
                      else
                      {
                        cout<<"Invalid Position: Out of Range";
                      }
                      break;
                  case 4:
                      x=s1.stackTop();
                      if(x==-1)
                      {
                        cout<<"Stack Underflow"<<endl;
                      }
                      else
                      {
                        cout<<"Stack Top is "<<x<<endl;
                      }
                      break;
                  case 5:
                      x=s1.isEmpty();
                      if(x==1)
                      {
                        cout<<"Stack is Empty"<<endl;
                      }
                      else
                      {
                        cout<<"Stack is not Empty"<<endl;
                      }
                      break;
                  case 6:
                      x=s1.isFull();
                      if(x==1)
                      {
                        cout<<"Stack is Full"<<endl;
                      }
                      else
                      {
                        cout<<"Stack is not Full"<<endl;
                      }
                      break;
                  case 7:
                      s1.Display();
                      break;
                  case 8:
                      exit(0);
                      break;
                  default:
                      cout << "Invalid choice." << endl;
                      break;
            }
      }
      return 0;
}