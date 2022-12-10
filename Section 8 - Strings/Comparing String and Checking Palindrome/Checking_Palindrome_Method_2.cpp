// Checking a Palindrome of a string
/*
A==B is same as &A[0] == &B[0] ( hence false )
Array name decays to a pointer to the first element.
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
      char str[100],str2[100];
      cout << "Enter a string: ";
      gets(str);
      int i, j;
      for (i = 0; str[i] != '\0';i++)
      {

      }
      i = i - 1;
      for (j = 0; i >= 0;i--,j++)
      {
            str2[j] = str[i];
      }
      str2[j] = '\0';
      if(strcmp(str,str2)==0)
      {
            cout << "String is Palindrome";
      }
      else
      {
            cout << "String is not Palindrome";
      }
      return 0;
}