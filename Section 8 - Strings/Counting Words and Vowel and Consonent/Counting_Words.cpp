// Counting a Words in a String
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
      char s[100];
      int i, word=0;
      cout << "Enter the word: ";
      cin.get(s,100);
      for (i = 0; s[i]!='\0';i++)
      {
            // if(((s[i] == ' ') && (s[i+1]==' '))|| ((s[i-1] != ' ') && (s[i+1]== '\0')))
            // {
            //       word++;
            // }
            if(s[i] == ' ' && s[i-1] != ' ')
            {
                  word++;
            }

      }
      cout << "Number of Words: " << word + 1;

      return 0;
}