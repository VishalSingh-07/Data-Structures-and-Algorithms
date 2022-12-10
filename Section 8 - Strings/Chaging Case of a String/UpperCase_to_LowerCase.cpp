// Changing Upper Case letter to Lower Case Letter
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
      char s[100];
      cout << "Enter the word (UpperCase): ";
      cin >> s;
      int i;
      for (i = 0; s[i] !='\0';i++)
      {
            s[i] = s[i] + 32;
      }
      cout << "LowerCase String: " << s;
      return 0;

}

/*
Output--
Enter the word (UpperCase): WELCOME
LowerCase String: welcome
*/