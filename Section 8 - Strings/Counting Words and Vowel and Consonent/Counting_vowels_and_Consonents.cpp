// Counting the vowel and consonents in the String
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
      char s[100];
      int i, vcount=0, ccount=0;
      cout << "Enter the word: ";
      cin.get(s,100);
      for (i = 0; s[i]!='\0';i++)
      {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                  vcount++;
            }
            else if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))
            {
                  ccount++;
            }

      }
      cout << "Vowel : " << vcount << endl;
      cout << "Consonent: " << ccount << endl;

      return 0;
}