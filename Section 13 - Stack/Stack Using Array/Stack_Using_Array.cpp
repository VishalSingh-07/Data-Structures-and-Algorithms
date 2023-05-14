#include <bits/stdc++.h>
using namespace std;
struct Stack
{
      int size;
      int top;
      int *s; // pointer to dynamically created array
};

void create(struct Stack *st)
{
      cout<<"Enter the size of Stack: ";
      cin>>st->size;
      st->top=-1;
      st->s=(int*)malloc(st->size*sizeof(int)); // creating array in heap memory
}
void Display(struct Stack st)
{
      cout<<"Stack:"<<endl;
      // print the element of the stack, starting from the top
      for(int i=st.top;i>=0;i--)
      {
            cout << "  +-----+" << endl;
            cout << "  | " << st.s[i] << "  |" << endl;
      }
      cout << "  +-----+" << endl;
}

void push(struct Stack *st, int x)
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
int pop(struct Stack *st)
{
      int x=-1;
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
int peek(struct Stack st, int pos)
{
      int x=-1;
      if(st.top-pos+1<0)
      {
            cout<<"\nInvalid Position"<<endl;
      }
      else
      {
            x=st.s[st.top-pos+1];
      }
      return x;
}
int stackTop(struct Stack st)
{
      if(st.top==-1)
      {
            return -1;
      }
      
      return st.s[st.top];
      
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
      if(st.top==st.size-1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
int main()
{
      struct Stack st;
      int choice,x;
      create(&st);
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
                      push(&st,x);
                      break;
                  case 2:
                      x=pop(&st);
                      if(x!=-1)
                      {
                        cout<<x<<" is pop from stack"<<endl;
                      }
                      break;
                  case 3:
                      int pos;
                      cout<<"Enter the position: ";
                      cin>>pos;  
                      x=peek(st, pos);
                      if(x!=-1)
                      {
                        cout<<"peek value is "<<x<<endl;
                      }
                      break;
                  case 4:
                      x=stackTop(st);
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
                      x=isEmpty(st);
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
                      x=isFull(st);
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
                      Display(st);
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