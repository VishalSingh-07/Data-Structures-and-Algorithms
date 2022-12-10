// Toggling Case -- Upper to Lower and Lower to Upper
#include <iostream>
using namespace std;
int main()
{
      char s[100];
      cout << "Enter the word: ";
      cin >> s;
      int i;
      for (i = 0; s[i] !='\0';i++)
      {
            if(s[i]>=65 && s[i]<=90) // For UpperCase
            {
                  s[i] += 32; // Upper Case to LowerCase
            }
            else if(s[i]>=97 && s[i]<=122) // For LowerCase
            {
                  s[i] = s[i] - 32; // LowerCase to UpperCase
            }
      }
      cout << "Toggling Case: " << s;
      return 0;
}
/*
Enter the word: wELCOME
Toggling Case: Welcome
*/