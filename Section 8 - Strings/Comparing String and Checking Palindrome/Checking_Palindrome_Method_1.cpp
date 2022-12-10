// Checking a Palindrome of a string
/*
Method 1:-
1. storing a original string to temp variable
2. Reversing a original string
3. Compare temp variable and reversed string
4. if it is equal then string is Palindrome
5. if it is not equal then string is not palindrome
*/
#include <iostream>
using namespace std;
int main()
{
      string str;
      cout << "Enter a string: ";
      getline(cin,str);

      int n = str.length();
      string temp = str;
      for (int i = 0; i < n / 2;i++)
      {
            swap(str[i], str[n - i - 1]);
      }

      if(str==temp)
      {
            cout << temp << " is a palindrome string";
      }
      else
      {
            cout << temp << " is not a palindrome string";
      }
      

      return 0;
}