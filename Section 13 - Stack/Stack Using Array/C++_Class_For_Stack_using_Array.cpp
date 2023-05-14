#include <bits/stdc++.h>
using namespace std;

class Stack
{
      private:
            int size;
            int top;
            int *s; // pointer to dynamically created array
      public:
            Stack(int size)
            {
                  this->size=size;
                  top=-1;
                  s=new int[size]; // creating array in heap memory
            }
            ~Stack() 
            {
                  delete[] s;
            }
            void push(int x);
            int pop();
            int peek(int pos);
            int stackTop();
            bool isEmpty();
            bool isFull();
            void display();
};
void Stack :: push(int x)
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
int Stack :: pop()
{
      int x=-1;
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
int Stack :: peek(int pos)
{
      int x=-1;
      if(top-pos+1<0)
      {
            cout<<"\nInvalid Position"<<endl;
      }
      else
      {
            x=s[top-pos+1];
      }
      return x;
}
int Stack :: stackTop()
{
      if(top==-1)
      {
            return -1;
      }
      
      return s[top];

}
bool Stack :: isEmpty()
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
bool Stack :: isFull()
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
void Stack :: display()
{
      cout<<"Stack:"<<endl;
      // print the element of the stack, starting from the top
      for(int i=top;i>=0;i--)
      {
            cout << "  +-----+" << endl;
            cout << "  | " << s[i] << "  |" << endl;
      }
      cout << "  +-----+" << endl;
}

int main()
{
      int size,choice,x;
      cout<<"Enter the size of stack: ";
      cin>>size;
      Stack s1(size);
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
                      s1.display();
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