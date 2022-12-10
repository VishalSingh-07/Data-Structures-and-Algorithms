#include <iostream>
#include <cstring>
using namespace std;
void perm(char s[], int l, int h)
{
      int i;
      if(l==h)
      {
            cout << s<<endl;
      }
      else
      {
            for (i = l; i <= h;i++)
            {
                  swap(s[l], s[i]);
                  perm(s, l + 1, h);
                  swap(s[l], s[i]);
            }
      }

}
int main()
{
      char s[100];
      cout << "Enter a String: ";
      gets(s);
      cout << "Number of Combination are: "<<endl;
      int l = 0;
      size_t h = strlen(s)-1;
      perm(s, l,h);
      return 0;
}

/*
Output
Enter a String: ABC
Number of Combination are: 
ABC
ACB
BAC
BCA
CBA
CAB
*/