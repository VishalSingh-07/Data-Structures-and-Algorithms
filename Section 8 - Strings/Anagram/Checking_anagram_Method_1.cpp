// Checking whether 2 strings are anagram (distinct letter) using For loop
#include <iostream>
using namespace std;
int main()
{
      char a[100], b[100];
      cout << "Enter String A: ";
      gets(a);
      cout << "Enter String B: ";
      gets(b);
      int i, j;
      for (i = 0; a[i] != '\0';i++)
      {
            for (j = 0; b[j] != '\0';j++)
            {
                  if(a[i]==b[j])
                  {
                        break;
                  }
            }
            if(b[j]=='\0')
            {
                  break;
            }
      }
      if(a[i]=='\0')
      {
            cout << "Its an anagram" << endl;
      }
      else
      {
            cout << "Its not an anagram" << endl;
      }

      return 0;
}
/*
Output--
Enter String A: elbow
Enter String B: below
Its an anagram


Enter String A: decimal
Enter String B: medical
Its an anagram
*/