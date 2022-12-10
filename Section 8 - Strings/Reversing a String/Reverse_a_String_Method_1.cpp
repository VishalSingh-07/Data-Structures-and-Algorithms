// Reverse a string using two string (Method 1) 
// Storing a original string  in reverse order in other string

#include <iostream>
using namespace std;
int main()
{
      char str[100], str2[100];
      cout << "Enter the string: ";
      cin.get(str, 100);
      int i, j;
      for (i = 0; str[i] != '\0';i++)
      {

      }
      i = i - 1; // When the above 'for' loop is executed, after it, value of i will be such that A[i] will be '\0, so we should take 1 before that
      for (j = 0; i >= 0;i--,j++)
      {
            str2[j] = str[i];
      }
      str2[j] = '\0'; // This statement is added for not getting '?' and '@' symbols as the size of B is of 10 char and the reverse string is of 3 char long, it is printing garbage value.

      cout << "Reverse String: " << str2;

      return 0;
}
/*
Output--
Enter the string: how are you?
Reverse String: ?uoy era woh
*/