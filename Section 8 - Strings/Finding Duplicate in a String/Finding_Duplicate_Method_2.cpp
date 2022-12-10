// Finding a Duplicate in a String using Hash table
#include <iostream>
using namespace std;
int main()
{
      char str[100];
      cout << "Enter a String: ";
      gets(str);
      int H[26] = {0},i;
      for (i = 0; str[i] != '\0';i++)
      {

            H[str[i] - 97]++; // writing program for lowercase word only
      }
      cout << "Number of Times Duplicate Value Occurs--" << endl;
      for (i = 0; i < 26;i++)
      {
            if(H[i]>1)
            {
                  char k = i + 97;
                  cout << k << " is appearing " << H[i] << " times" << endl;
            }
      }
      return 0;
}
/*
Output--
Enter a String: finding
Number of Times Duplicate Value Occurs--
i is appearing 2 times
n is appearing 2 times
*/