// Reverse a string using two string (Method 3) 

// GFG Answer for Reversing an string

#include <iostream>
using namespace std;
string reverseWord(string str)
{
      int n = str.length();
      for (int i = 0; i < n / 2;i++)
      {
            swap(str[i], str[n - i - 1]);
      }
      return str;
}
int main()
{
      string str,result;
      cout << "Enter the string: ";
      getline(cin, str);
      result = reverseWord(str);
      cout << "Reverse String: " << result;

      return 0;
}
/*
Output--
Enter the string: how are you?
Reverse String: ?uoy era woh
*/