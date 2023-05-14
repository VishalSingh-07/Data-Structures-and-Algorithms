#include <bits/stdc++.h>
using namespace std;
#define SIZE 50

int s[SIZE];
int top = -1;
int flag = 0;

int pop() {
    return (s[top--]);
}

int push(int elem) {
      if (flag == 1) 
      {
            int num;
            num = pop();
            s[++top] = elem + 10 * num;
      }
      else if (flag == 0) 
      {
            s[++top] = elem;
            flag = 1;
      }
}

int main() 
{
      char pofx[50], ch;
      int i = 0, op1, op2;
      cout << "Enter the Postfix Expression: ";
      cin.getline(pofx, 50);

      while ((ch = pofx[i++]) != '\0') 
      {
            if (isdigit(ch)) 
                  push(ch - '0');
            else if (ch == ' ')
                  flag = 0;
            else 
            {
                  flag = 0;
                  op2 = pop();
                  op1 = pop();
                  switch (ch) {
                  case '+':
                      push(op1 + op2);
                      break;
                  case '-':
                      push(op1 - op2);
                      break;
                  case '*':
                      push(op1 * op2);
                      break;
                  case '/':
                      push(op1 / op2);
                      break;
                  default:
                      cout << "Input invalid ... give proper input" << std::endl;
                      return 0;
            }
        }
    }
    cout << "Result: " << s[top] << std::endl;
    return 0;
}
/*
Enter the Postfix Expression: 10 12 + 3 4 – +
Result: 21
*/
