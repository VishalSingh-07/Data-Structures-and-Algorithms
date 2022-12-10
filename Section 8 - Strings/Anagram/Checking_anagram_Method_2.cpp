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
      int h[26] = {0};
      for (i = 0; a[i] != '\0';i++)
      {
            h[a[i] - 97]++;
      }
      for (i = 0; b[i] != '\0';i++)
      {
            h[b[i] - 97]--;
            if(h[b[i]-97]<0)
            {
                  cout << "Not a Anagram" << endl;
                  break;
            }
      }
      if(b[i]=='\0')
      {
            cout << "Its Anagram" << endl;
      }
      

      return 0;
}
/*
Output--
Enter String A: decimal
Enter String B: medical
Its Anagram



Enter String A: elbow
Enter String B: below
Its Anagram


Enter String A: raj
Enter String B: jai
Not a Anagram
*/