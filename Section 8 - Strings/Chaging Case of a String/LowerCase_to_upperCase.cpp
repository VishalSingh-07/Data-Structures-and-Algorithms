// Changing LowerCase letter to UpperCase Letter
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
      char s[100];
      cout << "Enter the word (LowerCase): ";
      cin >> s;
      int i;
      for (i = 0; s[i] !='\0';i++)
      {
            s[i] = s[i] - 32;
      }
      cout << "UpperCase String: " << s;
      return 0;

}

/*
Output--
Enter the word (LowerCase): welcome
UpperCase String: WELCOME
*/