/*
1. The struct Node struct defines a node in the linked list. It has two fields: data and next.

2. The top pointer points to the top of the stack.

3. The Display() function prints the elements of the stack, starting from the top.

4. The push() function pushes a new element onto the stack.

5. The pop() function pops the top element off the stack.

6. The peek() function returns the top element of the stack without popping it.

7. The isEmpty() function returns true if the stack is empty, and false otherwise.

8. The isFull() function returns true if the stack is full, and false otherwise.
*/


#include <bits/stdc++.h>
using namespace std;
struct Node
{
      int data;
      struct Node *next;
}*top=NULL;

void Display()
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

void push(int x)
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
int pop()
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
int peek(int pos)
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
int stackTop()
{
      if(top!=NULL)
      {
            return top->data;
      }     
      return -1;
}
bool isEmpty()
{
      return top!=NULL?false:true;
}
bool isFull() 
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
                      push(x);
                      break;
                  case 2:
                      x=pop();
                      if(x!=-1)
                      {
                        cout<<x<<" is pop from stack"<<endl;
                      }
                      break;
                  case 3:
                      int pos;
                      cout<<"Enter the position: ";
                      cin>>pos;  
                      x=peek(pos);
                      if(x!=-1)
                      {
                        cout<<"peek value is "<<x<<endl;
                      }
                      break;
                  case 4:
                      x=stackTop();
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
                      x=isEmpty();
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
                      x=isFull();
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
                      Display();
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