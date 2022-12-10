// Finding a Duplicate in a String using Compare with other letters
#include <iostream>
using namespace std;
int main()
{
      char str[100];
      cout << "Enter a String: ";
      gets(str);
      int i, j;
      cout << "Number of Times Duplicate Value Occurs--"<<endl;
      for (i = 0; str[i] != '\0';i++)
      {
            if (str[i] != -1)
            {
                  int count = 1;
                  for (j = i + 1; str[j] != '\0';j++)
                  {
                        if(str[i]==str[j])
                        {
                              str[j] = -1;
                              count++;
                        }

                  }
                  if(count>1)
                  {
                        cout << str[i] << " is appearing " << count<< " times" << endl;
                  }
            }
      }

      return 0;
}
/*
Output--
Enter a String: Hello World
Number of Times Duplicate Value Occurs--
l is appearing  3 times
o is appearing  2 times
*/