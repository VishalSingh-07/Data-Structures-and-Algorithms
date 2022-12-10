// Reverse a string using two string (Method 2) 
// Swapping first element and last element in the array 
// i--> traverse from starting of the string
// j--> traverse from last of the string 
// Stop when i<j otherwise i++ and j--

#include <iostream>
using namespace std;
int main()
{
      char str[100];
      cout << "Enter the string: ";
      cin.get(str, 100);
      int i, j;
      char temp;
      for (j = 0; str[j] != '\0';j++)
      {

      }
      j = j - 1;
      for (i = 0; i < j;i++,j--)
      {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
      }
      cout << "Reverse String: " << str;

      return 0;
}
/*
Output--
Enter the string: how are you?
Reverse String: ?uoy era woh
*/